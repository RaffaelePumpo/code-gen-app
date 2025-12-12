//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Manager_1.h
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
#ifndef Manager_1_h_
#define Manager_1_h_
#include <cmath>
#include "rtwtypes.h"
#include "Manager_1_types.h"
#include "EmergencyT.h"
#include <cstring>

// Class declaration for model Manager_1
class Manager_1 final
{
  // public data and function members
 public:
  // Real-time Model Data Structure
  struct RT_MODEL_Manager_1_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // Copy Constructor
  Manager_1(Manager_1 const&) = delete;

  // Assignment Operator
  Manager_1& operator= (Manager_1 const&) & = delete;

  // Move Constructor
  Manager_1(Manager_1 &&) = delete;

  // Move Assignment Operator
  Manager_1& operator= (Manager_1 &&) = delete;

  // Real-Time Model get method
  Manager_1::RT_MODEL_Manager_1_T * getRTM();

  // model step function
  void Manager_1_manage(const real_T *rtu_Torque, real_T *rty_Input);

  // model step function
  void Manager_1_clicked(const real_T *rtu_buttonValue);

  // Constructor
  Manager_1();

  // Destructor
  ~Manager_1();

  // Service port set method
  void set_Button(EmergencyT *Button_arg);

  // private data and function members
 private:
  EmergencyT *Button;

  // Real-Time Model
  RT_MODEL_Manager_1_T Manager_1_M;
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
//  '<Root>' : 'Manager_1'
//  '<S1>'   : 'Manager_1/pressed'
//  '<S2>'   : 'Manager_1/read'

#endif                                 // Manager_1_h_

//
// File trailer for generated code.
//
// [EOF]
//
