//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Sensing.h
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
#ifndef Sensing_h_
#define Sensing_h_
#include <cmath>
#include "rtwtypes.h"
#include "Sensing_types.h"
#include <cstring>

// Class declaration for model Sensing
class Sensing final
{
  // public data and function members
 public:
  // Real-time Model Data Structure
  struct RT_MODEL_Sensing_T {
    const char_T **errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus) const;
    const char_T** getErrorStatusPointer() const;
    void setErrorStatusPointer(const char_T** aErrorStatusPointer);
  };

  // Copy Constructor
  Sensing(Sensing const&) = delete;

  // Assignment Operator
  Sensing& operator= (Sensing const&) & = delete;

  // Move Constructor
  Sensing(Sensing &&) = delete;

  // Move Assignment Operator
  Sensing& operator= (Sensing &&) = delete;

  // Real-Time Model get method
  Sensing::RT_MODEL_Sensing_T * getRTM();

  // model step function
  void Sensing_decode(const real_T *rtu_State_position, const real_T
                      *rtu_State_velocity, real_T *rty_SensorsDecoded_position,
                      real_T *rty_SensorsDecoded_velocity);

  // Constructor
  Sensing();

  // Destructor
  ~Sensing();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_Sensing_T Sensing_M;
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
//  '<Root>' : 'Sensing'
//  '<S1>'   : 'Sensing/Function-Call Subsystem'

#endif                                 // Sensing_h_

//
// File trailer for generated code.
//
// [EOF]
//
