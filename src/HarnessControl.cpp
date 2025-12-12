//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: HarnessControl.cpp
//
// Code generated for Simulink model 'HarnessControl'.
//
// Model version                  : 1.29
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Fri Dec 12 11:42:58 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "HarnessControl.h"
#include "Control.h"

// Model step function
void HarnessControl::step()
{
  // FunctionCallGenerator: '<Root>/Function-Call Generator'
  // ModelReference generated from: '<Root>/Control' incorporates:
  //   Inport: '<Root>/Button'
  //   Inport: '<Root>/State'
  //   Outport: '<Root>/Out1'

  ControlMDLOBJ1.Control_manage(&HarnessControl_Y.Out1);
  ControlMDLOBJ1.Control_LQRcontrol(&HarnessControl_U.State_a);
  // End of Outputs for FunctionCallGenerator: '<Root>/Function-Call Generator'

  // FunctionCallGenerator: '<Root>/Function-Call Generator' incorporates:
  //   SubSystem: '<Root>/Function-Call Subsystem'

  // FunctionCallGenerator: '<S1>/Function-Call Generator'
  // RelationalOperator: '<S2>/FixPt Relational Operator' incorporates:
  //   Inport: '<Root>/Button'
  //   UnitDelay: '<S2>/Delay Input1'
  //
  //  Block description for '<S2>/Delay Input1':
  //
  //   Store in Global RAM

  if (HarnessControl_U.Button != HarnessControl_DW.DelayInput1_DSTATE) {
    // ModelReference generated from: '<Root>/Control' incorporates:
    //   Inport: '<Root>/State'
    //   Outport: '<Root>/Out1'

    ControlMDLOBJ1.Control_clicked(&HarnessControl_U.Button);
  }

  // End of RelationalOperator: '<S2>/FixPt Relational Operator'
  // End of Outputs for FunctionCallGenerator: '<S1>/Function-Call Generator'

  // Update for UnitDelay: '<S2>/Delay Input1' incorporates:
  //   Inport: '<Root>/Button'
  //
  //  Block description for '<S2>/Delay Input1':
  //
  //   Store in Global RAM

  HarnessControl_DW.DelayInput1_DSTATE = HarnessControl_U.Button;

  // End of Outputs for FunctionCallGenerator: '<Root>/Function-Call Generator'
}

// Model initialize function
void HarnessControl::initialize()
{
  // Model Initialize function for ModelReference Block: '<Root>/Control'

  // Set error status pointer for ModelReference Block: '<Root>/Control'
  ControlMDLOBJ1.getRTM()->setErrorStatusPointer((&HarnessControl_M)
    ->getErrorStatusPointer());
  ControlMDLOBJ1.initialize();
}

// Model terminate function
void HarnessControl::terminate()
{
  // (no terminate code required)
}

const char_T* HarnessControl::RT_MODEL_HarnessControl_T::getErrorStatus() const
{
  return (errorStatus);
}

void HarnessControl::RT_MODEL_HarnessControl_T::setErrorStatus(const char_T*
  const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

const char_T** HarnessControl::RT_MODEL_HarnessControl_T::getErrorStatusPointer()
{
  return &errorStatus;
}

// Constructor
HarnessControl::HarnessControl() :
  HarnessControl_U(),
  HarnessControl_Y(),
  HarnessControl_DW(),
  HarnessControl_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
HarnessControl::~HarnessControl() = default;

// Real-Time Model get method
HarnessControl::RT_MODEL_HarnessControl_T * HarnessControl::getRTM()
{
  return (&HarnessControl_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
