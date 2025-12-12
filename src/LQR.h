//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: LQR.h
//
// Code generated for Simulink model 'LQR'.
//
// Model version                  : 1.15
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Fri Dec 12 11:41:32 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef LQR_h_
#define LQR_h_
#include <cmath>
#include "rtwtypes.h"
#include "LQR_types.h"
#include <cstring>

// Class declaration for model LQR
class LQR final
{
  // public data and function members
 public:
  // Real-time Model Data Structure
  struct RT_MODEL_LQR_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // Copy Constructor
  LQR(LQR const&) = delete;

  // Assignment Operator
  LQR& operator= (LQR const&) & = delete;

  // Move Constructor
  LQR(LQR &&) = delete;

  // Move Assignment Operator
  LQR& operator= (LQR &&) = delete;

  // Real-Time Model get method
  LQR::RT_MODEL_LQR_T * getRTM();

  // model step function
  void LQR_control(const real_T *rtu_State_position, const real_T
                   *rtu_State_velocity, real_T *rty_Torque);

  // Constructor
  LQR();

  // Destructor
  ~LQR();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_LQR_T LQR_M;
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
//  '<Root>' : 'LQR'
//  '<S1>'   : 'LQR/Subsystem'

#endif                                 // LQR_h_

//
// File trailer for generated code.
//
// [EOF]
//
