//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// File: Architecture.h
//
// Code generated for Simulink model 'Architecture'.
//
// Model version                  : 1.21
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Dec  2 15:01:37 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Architecture_h_
#define Architecture_h_
#include <cmath>
#include "rtwtypes.h"
#include "Architecture_types.h"
#include "Control.h"

// Class declaration for model Architecture
class Architecture final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_Architecture_T {
    real_T Control_p;                  // '<Root>/Control'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_Architecture_T {
    real_T State_position;             // '<Root>/State_position'
    real_T State_velocity;             // '<Root>/State_velocity'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_Architecture_T {
    real_T Torque;                     // '<Root>/Torque'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_Architecture_T {
    const char_T *errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      struct {
        uint32_T TID[2];
      } TaskCounters;
    } Timing;

    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const aErrorStatus);
    const char_T** getErrorStatusPointer();
  };

  // Copy Constructor
  Architecture(Architecture const&) = delete;

  // Assignment Operator
  Architecture& operator= (Architecture const&) & = delete;

  // Move Constructor
  Architecture(Architecture &&) = delete;

  // Move Assignment Operator
  Architecture& operator= (Architecture &&) = delete;

  // Real-Time Model get method
  Architecture::RT_MODEL_Architecture_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_Architecture_T *pExtU_Architecture_T)
  {
    Architecture_U = *pExtU_Architecture_T;
  }

  // Root outports get method
  const ExtY_Architecture_T &getExternalOutputs() const
  {
    return Architecture_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  Architecture();

  // Destructor
  ~Architecture();

  // private data and function members
 private:
  // External inputs
  ExtU_Architecture_T Architecture_U;

  // External outputs
  ExtY_Architecture_T Architecture_Y;

  // Block signals
  B_Architecture_T Architecture_B;

  // model instance variable for '<Root>/Control'
  Control ControlMDLOBJ1;

  // Real-Time Model
  RT_MODEL_Architecture_T Architecture_M;
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
//  '<Root>' : 'Architecture'

#endif                                 // Architecture_h_

//
// File trailer for generated code.
//
// [EOF]
//
