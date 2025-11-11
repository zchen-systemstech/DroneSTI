//
// File: autocode.h
//
// Code generated for Simulink model 'baseline'.
//
// Model version                  : 8.3
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Wed Nov  5 09:12:42 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: NXP->Cortex-M4
// Code generation objective: Execution efficiency
// Validation result: Not run
//
#ifndef autocode_h_
#define autocode_h_
#include "rtwtypes.h"
#include "flight/global_defs.h"
#include <array>

// Class declaration for model baseline
namespace bfs
{
  class Autocode
  {
    // public data and function members
   public:
    // model initialize function
    static void initialize();

    // model step function
    void Run(SysData sys, SensorData sensor, NavData nav, TelemData telem,
             VmsData *ctrl);

    // Constructor
    Autocode();

    // Destructor
    ~Autocode();

    // private data and function members
   private:
    // private member function(s) for subsystem '<S6>/remap'
    static void remap(real32_T rtu_raw_in, real32_T rtu_in_min, real32_T
                      rtu_in_max, real32_T rtu_out_min, real32_T rtu_out_max,
                      real32_T *rty_norm_out);

    // private member function(s) for subsystem '<S8>/remap_with_deadband'
    static void remap_with_deadband(real32_T rtu_raw_in, real32_T rtu_in_min,
      real32_T rtu_in_max, real32_T rtu_out_min, real32_T rtu_out_max, real32_T
      rtu_deadband, real32_T *rty_norm_out);
  };
}

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Cast' : Eliminate redundant data type conversion
//  Block '<S2>/Cast To Boolean' : Eliminate redundant data type conversion
//  Block '<S2>/Cast To Boolean1' : Eliminate redundant data type conversion
//  Block '<S2>/Cast To Single1' : Eliminate redundant data type conversion
//  Block '<S2>/Cast To Single3' : Eliminate redundant data type conversion


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
//  '<Root>' : 'baseline'
//  '<S1>'   : 'baseline/PWM'
//  '<S2>'   : 'baseline/To VMS Data'
//  '<S3>'   : 'baseline/command selection'
//  '<S4>'   : 'baseline/determine arm and mode selection'
//  '<S5>'   : 'baseline/PWM/remap'
//  '<S6>'   : 'baseline/command selection/e-stop'
//  '<S7>'   : 'baseline/command selection/mode_norm'
//  '<S8>'   : 'baseline/command selection/pitch_norm_deadband'
//  '<S9>'   : 'baseline/command selection/roll_norm_deadband'
//  '<S10>'  : 'baseline/command selection/throttle_norm'
//  '<S11>'  : 'baseline/command selection/yaw_norm_deadband'
//  '<S12>'  : 'baseline/command selection/e-stop/remap'
//  '<S13>'  : 'baseline/command selection/mode_norm/remap'
//  '<S14>'  : 'baseline/command selection/pitch_norm_deadband/remap_with_deadband'
//  '<S15>'  : 'baseline/command selection/roll_norm_deadband/remap_with_deadband'
//  '<S16>'  : 'baseline/command selection/throttle_norm/remap'
//  '<S17>'  : 'baseline/command selection/yaw_norm_deadband/remap_with_deadband'
//  '<S18>'  : 'baseline/determine arm and mode selection/arm logic'
//  '<S19>'  : 'baseline/determine arm and mode selection/arm logic/Compare To Constant'

#endif                                 // autocode_h_

//
// File trailer for generated code.
//
// [EOF]
//
