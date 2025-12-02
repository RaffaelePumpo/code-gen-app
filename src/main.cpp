#include "Architecture.h"
#include <iostream>

int main() {
    // Create an Architecture instance
    Architecture arch;
    
    // Simulate a starting state
    double position = 0.0;
    double velocity = 10.0;
    
    std::cout << "Initial State:" << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Velocity: " << velocity << std::endl;
    
    // Call Architecture methods with the simulated state
    Architecture::ExtU_Architecture_T inputs;
    inputs.State_position = position;
    inputs.State_velocity = velocity;
    arch.setExternalInputs(&inputs);
    auto outputs = arch.getExternalOutputs();
    
    // Simulate a few iterations
    for (int i = 0; i < 50; ++i) {
        arch.step();
        std::cout << "\nStep " << (i + 1)  << std::endl;
        outputs = arch.getExternalOutputs();
        std::cout << "Torque Output: " << outputs.Torque << std::endl;
        // Create with torque output next step state
        position = outputs.Torque * 0.1; // Simplified state update
        velocity = outputs.Torque * 0.2; // Simplified state update
        std::cout << "Position: " << position << std::endl;
        std::cout << "Velocity: " << velocity << std::endl;
        inputs.State_position = position;
        inputs.State_velocity = velocity;
        arch.setExternalInputs(&inputs);  
        
    }
    
    return 0;
}