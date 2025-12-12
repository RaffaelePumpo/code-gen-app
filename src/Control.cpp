//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Control.cpp
//
// Code generated for Simulink model 'Control'.
//
// Model version                  : 1.56
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Fri Dec 12 11:42:31 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Control.h"
#include "rtwtypes.h"
#include "Control_types.h"
#include "Manager_1.h"
#include "LQR.h"

// Output and update for referenced model: 'Control'
void Control::Control_manage(real_T *rty_Torque)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/manage'

  // ModelReference generated from: '<Root>/Manager'
  ManagerMDLOBJ2.Manager_1_manage(&Control_B.LQR_l, rty_Torque);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/manage' 
}

// Output and update for referenced model: 'Control'
void Control::Control_LQRcontrol(const State *rtu_State)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/LQRcontrol'

  // ModelReference generated from: '<S1>/LQR'
  LQRMDLOBJ1.LQR_control(&rtu_State->position, &rtu_State->velocity,
    &Control_B.LQR_l);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/LQRcontrol' 
}

// Output and update for referenced model: 'Control'
void Control::Control_clicked(const real_T *rtu_buttonValue)
{
  // RootInportFunctionCallGenerator generated from: '<Root>/clicked'

  // ModelReference generated from: '<Root>/Manager'
  ManagerMDLOBJ2.Manager_1_clicked(rtu_buttonValue);

  // End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/clicked' 
}

// Model initialize function
void Control::initialize()
{
  // Initialize service port pointer for Block: '<Root>/Manager'
  ManagerMDLOBJ2.set_Button(&FaultMDLOBJ1.get_Button());

  // Model Initialize function for ModelReference Block: '<S1>/LQR'

  // Set error status pointer for ModelReference Block: '<S1>/LQR'
  LQRMDLOBJ1.getRTM()->setErrorStatusPointer((&Control_M)->getErrorStatusPointer
    ());

  // Model Initialize function for ModelReference Block: '<Root>/Fault'

  // Set error status pointer for ModelReference Block: '<Root>/Fault'
  FaultMDLOBJ1.getRTM()->setErrorStatusPointer((&Control_M)
    ->getErrorStatusPointer());

  // Model Initialize function for ModelReference Block: '<Root>/Manager'

  // Set error status pointer for ModelReference Block: '<Root>/Manager'
  ManagerMDLOBJ2.getRTM()->setErrorStatusPointer((&Control_M)
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
