#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/IEncoders.h>
#include <yarp/dev/ITorqueControl.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "HarnessControl.h"


using namespace yarp::os;
using namespace yarp::dev;

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
int main(int argc, char* argv[])
{

    Network yarp;
    if (!yarp.checkNetwork()) {
        fprintf(stderr, "YARP server non raggiungibile\n");
        return 1;
    }

    // Apri controlboard verso Gazebo (gazebo-yarp-plugins)
    Property options;
    options.put("device", "remote_controlboard");
    options.put("remote", "/singlePendulumGazebo/body");
    options.put("local",  "/harnessControl/pendulum");


    PolyDriver driver(options);
    if (!driver.isValid()) {
        fprintf(stderr, "Errore apertura remote_controlboard\n");
        return 1;
    }

    IEncoders* encs = nullptr;
    ITorqueControl* itorque = nullptr;
    IControlMode* ictrl = nullptr;

    driver.view(encs);
    driver.view(itorque);
    driver.view(ictrl);

    if (!encs || !itorque || !ictrl) {
        fprintf(stderr, "Interfacce YARP non disponibili\n");
        return 1;
    }

    int axes = 0;
    encs->getAxes(&axes);
    int j = 0; // indice del giunto da controllare

    // Create a Thread wait for button F for setting button value to 1.0
        std::atomic<bool> buttonPressed(false);
    // Thread per leggere tastiera (non bloccante)
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
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    });

    // Initialize model
    HarnessControl_Obj.initialize();
    HarnessControl::ExtU_HarnessControl_T input{};
    HarnessControl::ExtY_HarnessControl_T output{};

    input.Button = 0.0;

    ictrl->setControlMode(j, VOCAB_CM_TORQUE);

    while (HarnessControl_Obj.getRTM()->getErrorStatus() == nullptr) {
        // leggi posizione e velocità da YARP (Gazebo)
        double pos = 0.0, speed = 0.0;
        encs->getEncoder(j, &pos);         // posizione [deg]
        encs->getEncoderSpeed(j, &speed);  // velocità [deg/s]
        // Converti in radianti 
        pos = pos * 3.141592653589793 / 180.0;
        speed = speed * 3.141592653589793 / 180.0;

        
        input.State_a.position = pos;
        input.State_a.velocity = speed;
        input.Button = buttonPressed.load() ? 1.0f : 0.0f;

        // step del modello
        rt_OneStep(&input, output);

        // invia il comando verso Gazebo tramite torque control
        double tau = output.Out1;
        itorque->setRefTorque(j, tau);

        // rispetta il tuo sample time (es. 10 ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ictrl->setControlMode(j, VOCAB_CM_IDLE);

    driver.close();
    HarnessControl_Obj.terminate();
    return 0;
}
