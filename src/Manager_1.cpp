//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Manager_1.cpp
//
// Code generated for Simulink model 'Manager_1'.
//
// Model version                  : 1.16
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Fri Dec 12 11:42:10 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Manager_1.h"
#include "rtwtypes.h"
#include "EmergencyT.h"

// Output and update for referenced model: 'Manager_1'
void Manager_1::Manager_1_manage(const real_T *rtu_Torque, real_T *rty_Input)
{
  real_T rtb_read;

  // RootInportFunctionCallGenerator generated from: '<Root>/manage' incorporates:
  //   SubSystem: '<Root>/read'

  // FunctionCaller: '<S2>/read'
  Button->read(&rtb_read);

  // Switch: '<S2>/Switch'
  if (rtb_read > 0.0) {
    *rty_Input = 0.0;
  } else {
    *rty_Input = *rtu_Torque;
  }

  // End of Switch: '<S2>/Switch'
  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/manage' 
}

// Output and update for referenced model: 'Manager_1'
void Manager_1::Manager_1_clicked(const real_T *rtu_buttonValue)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/clicked' incorporates:
  //   SubSystem: '<Root>/pressed'

  // FunctionCaller: '<S1>/Pressed'
  Button->pressed(*rtu_buttonValue);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/clicked' 
}

const char_T* Manager_1::RT_MODEL_Manager_1_T::getErrorStatus() const
{
  return (*(errorStatus));
}

void Manager_1::RT_MODEL_Manager_1_T::setErrorStatus(const char_T* const
  aErrorStatus) const
{
  (*(errorStatus) = aErrorStatus);
}

const char_T** Manager_1::RT_MODEL_Manager_1_T::getErrorStatusPointer() const
{
  return errorStatus;
}

void Manager_1::RT_MODEL_Manager_1_T::setErrorStatusPointer(const char_T
  ** aErrorStatusPointer)
{
  (errorStatus = aErrorStatusPointer);
}

// Constructor
Manager_1::Manager_1() :
  Button(),
  Manager_1_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Manager_1::~Manager_1() = default;

// Real-Time Model get method
Manager_1::RT_MODEL_Manager_1_T * Manager_1::getRTM()
{
  return (&Manager_1_M);
}

void Manager_1::set_Button(EmergencyT *Button_arg)
{
  Button = Button_arg;
}

//
// File trailer for generated code.
//
// [EOF]
//
