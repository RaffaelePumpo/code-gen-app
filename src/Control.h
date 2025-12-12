//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Control.h
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
#ifndef Control_h_
#define Control_h_
#include <cmath>
#include "rtwtypes.h"
#include "Control_types.h"
#include "LQR.h"
#include "Fault.h"
#include "Manager_1.h"
#include <cstring>

// Class declaration for model Control
class Control final
{
  // public data and function members
 public:
  // Block signals for model 'Control'
  struct B_Control_T {
    real_T read_d;                     // '<Root>/Fault'
    real_T LQR_l;                      // '<S1>/LQR'
    real_T pressed_m;                  // '<Root>/Fault'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Control_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // model initialize function
  void initialize();

  // Copy Constructor
  Control(Control const&) = delete;

  // Assignment Operator
  Control& operator= (Control const&) & = delete;

  // Move Constructor
  Control(Control &&) = delete;

  // Move Assignment Operator
  Control& operator= (Control &&) = delete;

  // Real-Time Model get method
  Control::RT_MODEL_Control_T * getRTM();

  // model step function
  void Control_manage(real_T *rty_Torque);

  // model step function
  void Control_LQRcontrol(const State *rtu_State);

  // model step function
  void Control_clicked(const real_T *rtu_buttonValue);

  // Constructor
  Control();

  // Destructor
  ~Control();

  // private data and function members
 private:
  // Block signals
  B_Control_T Control_B;

  // model instance variable for '<Root>/Fault'
  Fault FaultMDLOBJ1;

  // model instance variable for '<Root>/Manager'
  Manager_1 ManagerMDLOBJ2;

  // model instance variable for '<S1>/LQR'
  LQR LQRMDLOBJ1;

  // Real-Time Model
  RT_MODEL_Control_T Control_M;
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
//  '<Root>' : 'Control'
//  '<S1>'   : 'Control/Controller'

#endif                                 // Control_h_

//
// File trailer for generated code.
//
// [EOF]
//
