//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Sensing.cpp
//
// Code generated for Simulink model 'Sensing'.
//
// Model version                  : 1.9
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Fri Dec  5 10:50:46 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Sensing.h"
#include "rtwtypes.h"

// Output and update for referenced model: 'Sensing'
void Sensing::Sensing_decode(const real_T *rtu_State_position, const real_T
  *rtu_State_velocity, real_T *rty_SensorsDecoded_position, real_T
  *rty_SensorsDecoded_velocity)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/decode' incorporates:
  //   SubSystem: '<Root>/Function-Call Subsystem'

  // SignalConversion generated from: '<S1>/SensorsDecoded_Outport_1'
  *rty_SensorsDecoded_position = *rtu_State_position;

  // SignalConversion generated from: '<S1>/SensorsDecoded_Outport_1'
  *rty_SensorsDecoded_velocity = *rtu_State_velocity;

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/decode' 
}

const char_T* Sensing::RT_MODEL_Sensing_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void Sensing::RT_MODEL_Sensing_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** Sensing::RT_MODEL_Sensing_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void Sensing::RT_MODEL_Sensing_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
Sensing::Sensing() :
  Sensing_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Sensing::~Sensing() = default;

// Real-Time Model get method
Sensing::RT_MODEL_Sensing_T * Sensing::getRTM()
{
  return (&Sensing_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
