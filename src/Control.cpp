//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Control.cpp
//
// Code generated for Simulink model 'Control'.
//
// Model version                  : 1.8
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Dec  2 15:01:35 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Control.h"
#include "rtwtypes.h"
#include "Sensing.h"
#include "LQR.h"

// Output and update for referenced model: 'Control'
void Control::Control_Sensingdecode(const real_T *rtu_State_position, const
  real_T *rtu_State_velocity)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/Sensingdecode'

  // ModelReference generated from: '<Root>/Sensing'
  SensingMDLOBJ2.Sensing_decode(rtu_State_position, rtu_State_velocity,
    &Control_B.position, &Control_B.velocity);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Sensingdecode' 
}

// Output and update for referenced model: 'Control'
void Control::Control_LQRcontrol(real_T *rty_Torque)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/LQRcontrol'

  // ModelReference generated from: '<Root>/LQR'
  LQRMDLOBJ1.LQR_control(&Control_B.position, &Control_B.velocity, rty_Torque);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/LQRcontrol' 
}

// Model initialize function
void Control::initialize()
{
  // Model Initialize function for ModelReference Block: '<Root>/LQR'

  // Set error status pointer for ModelReference Block: '<Root>/LQR'
  LQRMDLOBJ1.getRTM()->setErrorStatusPointer((&Control_M)->getErrorStatusPointer
    ());

  // Model Initialize function for ModelReference Block: '<Root>/Sensing'

  // Set error status pointer for ModelReference Block: '<Root>/Sensing'
  SensingMDLOBJ2.getRTM()->setErrorStatusPointer((&Control_M)
    ->getErrorStatusPointer());
}

const char_T* Control::RT_MODEL_Control_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void Control::RT_MODEL_Control_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** Control::RT_MODEL_Control_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void Control::RT_MODEL_Control_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
Control::Control() :
  Control_B(),
  Control_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Control::~Control() = default;

// Real-Time Model get method
Control::RT_MODEL_Control_T * Control::getRTM()
{
  return (&Control_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
