//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: LQR.cpp
//
// Code generated for Simulink model 'LQR'.
//
// Model version                  : 1.9
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Dec  2 15:01:31 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "LQR.h"
#include "rtwtypes.h"

// Output and update for referenced model: 'LQR'
void LQR::LQR_control(const real_T *rtu_State_position, const real_T
                      *rtu_State_velocity, real_T *rty_Torque)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/control' incorporates:
  //   SubSystem: '<Root>/Subsystem'

  // Gain: '<S1>/Gain' incorporates:
  //   SignalConversion generated from: '<S1>/Gain'

  *rty_Torque = *rtu_State_position * -0.0 + *rtu_State_velocity * -0.0;

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/control' 
}

const char_T* LQR::RT_MODEL_LQR_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void LQR::RT_MODEL_LQR_T::setErrorStatus(const char_T* const aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** LQR::RT_MODEL_LQR_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void LQR::RT_MODEL_LQR_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
LQR::LQR() :
  LQR_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
LQR::~LQR() = default;

// Real-Time Model get method
LQR::RT_MODEL_LQR_T * LQR::getRTM()
{
  return (&LQR_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
