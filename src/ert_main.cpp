#include <stdio.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "HarnessControl.h"

static HarnessControl HarnessControl_Obj;

// Imposta stdin non bloccante (Linux)
void setNonBlockingStdin() {
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void rt_OneStep(const HarnessControl::ExtU_HarnessControl_T *input, HarnessControl::ExtY_HarnessControl_T& output)
{
    static boolean_T OverrunFlag{ false };

    if (OverrunFlag) {
        HarnessControl_Obj.getRTM()->setErrorStatus("Overrun");
        output = {};
        return;
    } 

    OverrunFlag = true;

    HarnessControl_Obj.setExternalInputs(input);
    HarnessControl_Obj.step();
    output = HarnessControl_Obj.getExternalOutputs();
    
    OverrunFlag = false;
    return;
}

int_T main(int_T argc, const char *argv[])
{
    (void)(argc);
    (void)(argv);

    // ✅ Input da tastiera atomico
    std::atomic<bool> buttonPressed(false);

    // ✅ Thread per leggere tastiera (non bloccante)
    std::thread inputThread([&buttonPressed]() {
        setNonBlockingStdin();
        char c;
        printf(">>> Premi 'F' per attivare button (1.0), 'R' per resettare (0.0)\n");
        fflush(stdout);
        
        while (true) {
            ssize_t n = read(STDIN_FILENO, &c, 1);
            if (n > 0) {
                if (c == 'F' || c == 'f') {
                    buttonPressed.store(true);
                    printf("🔘 BUTTON ATTIVATO (1.0)\n");
                } else if (c == 'R' || c == 'r') {
                    buttonPressed.store(false);
                    printf("🔘 BUTTON RESET (0.0)\n");
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });

    // Initialize model
    HarnessControl_Obj.initialize();

    HarnessControl::ExtU_HarnessControl_T input{};
    HarnessControl::ExtY_HarnessControl_T output{};

    input.Button = 0.0;
    input.State_a.position = 0.0;
    input.State_a.velocity = 5.0;

    printf("Starting simulation (0.1s base rate, print 1Hz)...\n");

    int step_count = 0;
    auto last_print = std::chrono::steady_clock::now();

    // Simulation loop
    while (HarnessControl_Obj.getRTM()->getErrorStatus() == nullptr) {
        // ✅ Aggiorna button da input tastiera
        input.Button = buttonPressed.load() ? 1.0f : 0.0f;
        input.State_a.position += input.State_a.velocity * 0.1; // Simula position
        input.State_a.velocity += output.Out1 * 0.00001;        // Simula velocity con Out1 come accelerazione
        // Single step
        rt_OneStep(&input, output);
        step_count++;

        // ✅ PRINT OGNI SECONDO (10 step x 0.1s)
        auto now = std::chrono::steady_clock::now();
        auto elapsed_print = std::chrono::duration_cast<std::chrono::seconds>(now - last_print).count();
        
        if (elapsed_print >= 1 || step_count == 1) {
            printf("[%3d] Button: %.1f | pos: %.2f | vel: %.2f | Out1: %.3f\n",
                   step_count, input.Button, input.State_a.position, 
                   input.State_a.velocity, output.Out1);
            fflush(stdout);
            last_print = now;
        }
        
        // Sleep 100ms (base rate)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    inputThread.detach();  // Thread continua in background

    if (HarnessControl_Obj.getRTM()->getErrorStatus() != nullptr) {
        printf("ERROR: %s\n", HarnessControl_Obj.getRTM()->getErrorStatus());
    }

    HarnessControl_Obj.terminate();
    printf("Simulation terminated.\n");
    return 0;
}
