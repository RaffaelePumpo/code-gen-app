//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Fault.cpp
//
// Code generated for Simulink model 'Fault'.
//
// Model version                  : 1.21
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Dec  9 14:54:40 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Fault.h"
#include "rtwtypes.h"

// Output and update for referenced model: 'Fault'
void Fault::pressed(real_T rtu_buttonValue)
{
  // Outputs for Function Call SubSystem: '<Root>/pressed'
  // SignalConversion generated from: '<S1>/buttonValue'
  Fault_B.TmpSignalConversionAtbuttonValu = rtu_buttonValue;

  // End of Outputs for SubSystem: '<Root>/pressed'
}

// Output and update for referenced model: 'Fault'
void Fault::read(real_T *rty_buttonPressed)
{
  // Outputs for Function Call SubSystem: '<Root>/read'
  // SignalConversion generated from: '<S2>/buttonPressed' incorporates:
  //   SignalConversion generated from: '<S2>/clicked'

  *rty_buttonPressed = Fault_B.TmpSignalConversionAtbuttonValu;

  // End of Outputs for SubSystem: '<Root>/read'
}

const char_T* Fault::RT_MODEL_Fault_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void Fault::RT_MODEL_Fault_T::setErrorStatus(const char_T* const aErrorStatus)
  const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** Fault::RT_MODEL_Fault_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void Fault::RT_MODEL_Fault_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
Fault::Fault() :
  Fault_B(),
  Button(*this),
  Fault_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Fault::~Fault() = default;

// Real-Time Model get method
Fault::RT_MODEL_Fault_T * Fault::getRTM()
{
  return (&Fault_M);
}

EmergencyT & Fault::get_Button()
{
  return Button;
}

FaultButtonT::FaultButtonT(Fault &aProvider): Fault_mProvider{ aProvider }
{
}

void FaultButtonT::pressed(real_T buttonValue)
{
  Fault_mProvider.pressed(buttonValue);
}

void FaultButtonT::read(real_T *buttonPressed)
{
  Fault_mProvider.read(buttonPressed);
}

//
// File trailer for generated code.
//
// [EOF]
//
