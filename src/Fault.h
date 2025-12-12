//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Fault.h
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
#ifndef Fault_h_
#define Fault_h_
#include <cmath>
#include "rtwtypes.h"
#include "Fault_types.h"
#include "EmergencyT.h"
#include <cstring>

// Class declaration for model Fault
// Forward declaration
class Fault;
class FaultButtonT : public EmergencyT
{
  // public data and function members
 public:
  FaultButtonT(Fault &aProvider);
  virtual void pressed(real_T buttonValue);
  virtual void read(real_T *buttonPressed);

  // private data and function members
 private:
  Fault &Fault_mProvider;
};

class Fault final
{
 public:
  // Block signals for model 'Fault'
  struct B_Fault_T {
    real_T TmpSignalConversionAtbuttonValu;// '<S1>/buttonValue'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Fault_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // model step function
  void pressed(real_T rtu_buttonValue);

  // model step function
  void read(real_T *rty_buttonPressed);

  // Copy Constructor
  Fault(Fault const&) = delete;

  // Assignment Operator
  Fault& operator= (Fault const&) & = delete;

  // Move Constructor
  Fault(Fault &&) = delete;

  // Move Assignment Operator
  Fault& operator= (Fault &&) = delete;

  // Real-Time Model get method
  Fault::RT_MODEL_Fault_T * getRTM();

  // Constructor
  Fault();

  // Destructor
  ~Fault();

  // Service port get method
  EmergencyT & get_Button();
 private:
  // Block signals
  B_Fault_T Fault_B;
  FaultButtonT Button;

  // Real-Time Model
  RT_MODEL_Fault_T Fault_M;
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
//  '<Root>' : 'Fault'
//  '<S1>'   : 'Fault/pressed'
//  '<S2>'   : 'Fault/read'

#endif                                 // Fault_h_

//
// File trailer for generated code.
//
// [EOF]
//
