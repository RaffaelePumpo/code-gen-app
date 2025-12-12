//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: HarnessControl.h
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
#ifndef HarnessControl_h_
#define HarnessControl_h_
#include <cmath>
#include "rtwtypes.h"
#include "HarnessControl_types.h"
#include "Control.h"

// Class declaration for model HarnessControl
class HarnessControl final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_HarnessControl_T {
    real_T DelayInput1_DSTATE;         // '<S2>/Delay Input1'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_HarnessControl_T {
    real_T Button;                     // '<Root>/Button'
    State State_a;                     // '<Root>/State'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_HarnessControl_T {
    real_T Out1;                       // '<Root>/Out1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_HarnessControl_T {
    const char_T *errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
    const char_T** getErrorStatusPointer();
  };

  // Copy Constructor
  HarnessControl(HarnessControl const&) = delete;

  // Assignment Operator
  HarnessControl& operator= (HarnessControl const&) & = delete;

  // Move Constructor
  HarnessControl(HarnessControl &&) = delete;

  // Move Assignment Operator
  HarnessControl& operator= (HarnessControl &&) = delete;

  // Real-Time Model get method
  HarnessControl::RT_MODEL_HarnessControl_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_HarnessControl_T *pExtU_HarnessControl_T)
  {
    HarnessControl_U = *pExtU_HarnessControl_T;
  }

  // Root outports get method
  const ExtY_HarnessControl_T &getExternalOutputs() const
  {
    return HarnessControl_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  HarnessControl();

  // Destructor
  ~HarnessControl();

  // private data and function members
 private:
  // External inputs
  ExtU_HarnessControl_T HarnessControl_U;

  // External outputs
  ExtY_HarnessControl_T HarnessControl_Y;

  // Block states
  DW_HarnessControl_T HarnessControl_DW;

  // model instance variable for '<Root>/Control'
  Control ControlMDLOBJ1;

  // Real-Time Model
  RT_MODEL_HarnessControl_T HarnessControl_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'HarnessControl'
//  '<S1>'   : 'HarnessControl/Function-Call Subsystem'
//  '<S2>'   : 'HarnessControl/Function-Call Subsystem/Detect Change'

#endif                                 // HarnessControl_h_

//
// File trailer for generated code.
//
// [EOF]
//
