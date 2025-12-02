//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Architecture.cpp
//
// Code generated for Simulink model 'Architecture'.
//
// Model version                  : 1.21
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Dec  2 15:01:37 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Architecture.h"
#include "Control.h"

static void rate_scheduler(Architecture::RT_MODEL_Architecture_T *const
  Architecture_M);

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(Architecture::RT_MODEL_Architecture_T *const
  Architecture_M)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Architecture_M->Timing.TaskCounters.TID[1])++;
  if ((Architecture_M->Timing.TaskCounters.TID[1]) > 99) {// Sample time: [0.1s, 0.0s] 
    Architecture_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Model step function
void Architecture::step()
{
  // HiddenFcnCallGenerator: '<Root>/Control'
  // ModelReference generated from: '<Root>/Control' incorporates:
  //   Inport generated from: '<Root>/State_Inport_1'
  //
  ControlMDLOBJ1.Control_Sensingdecode(&Architecture_U.State_position,
    &Architecture_U.State_velocity);
                 // End of Outputs for HiddenFcnCallGenerator: '<Root>/Control'
  if ((&Architecture_M)->Timing.TaskCounters.TID[1] == 0) {
    // HiddenFcnCallGenerator: '<Root>/Control'
    // ModelReference generated from: '<Root>/Control' incorporates:
    //   Inport generated from: '<Root>/State_Inport_1'
    //
    ControlMDLOBJ1.Control_LQRcontrol(&Architecture_B.Control_p);
                 // End of Outputs for HiddenFcnCallGenerator: '<Root>/Control'

    // Outport generated from: '<Root>/Out Bus Element'
    Architecture_Y.Torque = Architecture_B.Control_p;
  }

  rate_scheduler((&Architecture_M));
}

// Model initialize function
void Architecture::initialize()
{
  // Model Initialize function for ModelReference Block: '<Root>/Control'

  // Set error status pointer for ModelReference Block: '<Root>/Control'
  ControlMDLOBJ1.getRTM()->setErrorStatusPointer((&Architecture_M)
    ->getErrorStatusPointer());
  ControlMDLOBJ1.initialize();
}

// Model terminate function
void Architecture::terminate()
{
  // (no terminate code required)
}

const char_T* Architecture::RT_MODEL_Architecture_T::getErrorStatus() const
{
  return (errorStatus);
}

void Architecture::RT_MODEL_Architecture_T::setErrorStatus(const char_T* const
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

const char_T** Architecture::RT_MODEL_Architecture_T::getErrorStatusPointer()
{
  return &errorStatus;
}

// Constructor
Architecture::Architecture() :
  Architecture_U(),
  Architecture_Y(),
  Architecture_B(),
  Architecture_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Architecture::~Architecture() = default;

// Real-Time Model get method
Architecture::RT_MODEL_Architecture_T * Architecture::getRTM()
{
  return (&Architecture_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
