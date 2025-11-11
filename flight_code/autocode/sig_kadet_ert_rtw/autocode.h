//
// File: autocode.h
//
// Code generated for Simulink model 'sig_kadet'.
//
// Model version                  : 2.27
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Thu Oct 30 09:47:39 2025
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

// Class declaration for model sig_kadet
namespace bfs
{
  class Autocode
  {
    // public data and function members
   public:
    // Block signals and states (default storage) for system '<Root>'
    struct DW {
      real_T UnitDelay1_DSTATE;        // '<S65>/Unit Delay1'
      real32_T Integrator_DSTATE;      // '<S47>/Integrator'
      real32_T UD_DSTATE;              // '<S40>/UD'
      real32_T UnitDelay_DSTATE;       // '<S65>/Unit Delay'
      real32_T Integrator_DSTATE_g;    // '<S219>/Integrator'
      real32_T UD_DSTATE_f;            // '<S212>/UD'
      real32_T Integrator_DSTATE_i;    // '<S109>/Integrator'
      real32_T UD_DSTATE_c;            // '<S102>/UD'
      real32_T Integrator_DSTATE_m;    // '<S165>/Integrator'
      real32_T UD_DSTATE_b;            // '<S158>/UD'
      real32_T DiscreteTransferFcn_states;// '<S69>/Discrete Transfer Fcn'
      real32_T Integrator_DSTATE_h;    // '<S278>/Integrator'
      real32_T UD_DSTATE_n;            // '<S271>/UD'
      real32_T Integrator_DSTATE_hh;   // '<S334>/Integrator'
      real32_T UD_DSTATE_o;            // '<S327>/UD'
      real32_T DiscreteTransferFcn_states_n;// '<S238>/Discrete Transfer Fcn'
      int8_T SwitchCase_ActiveSubsystem;// '<S2>/Switch Case'
      int8_T SwitchCase1_ActiveSubsystem;// '<S2>/Switch Case1'
    };

    // model initialize function
    void initialize();

    // model step function
    void Run(const SysData &sys, const SensorData &sensor, const NavData &nav,
             const TelemData &telem, VmsData *ctrl);

    // Constructor
    Autocode();

    // Destructor
    ~Autocode();

    // private data and function members
   private:
    // Block states
    DW rtDW;
  };
}

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S40>/DTDup' : Unused code path elimination
//  Block '<S102>/DTDup' : Unused code path elimination
//  Block '<S158>/DTDup' : Unused code path elimination
//  Block '<S212>/DTDup' : Unused code path elimination
//  Block '<S271>/DTDup' : Unused code path elimination
//  Block '<S327>/DTDup' : Unused code path elimination
//  Block '<S64>/Gain' : Eliminated nontunable gain of 1
//  Block '<S6>/Gain' : Eliminated nontunable gain of 1
//  Block '<S7>/Gain1' : Eliminated nontunable gain of 1
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S355>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S355>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S355>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S355>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S355>/Data Type Conversion9' : Eliminate redundant data type conversion


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
//  '<Root>' : 'sig_kadet'
//  '<S1>'   : 'sig_kadet/Control Allocation'
//  '<S2>'   : 'sig_kadet/Control Laws'
//  '<S3>'   : 'sig_kadet/Sensor Processing'
//  '<S4>'   : 'sig_kadet/Control Laws/Airspeed Hold'
//  '<S5>'   : 'sig_kadet/Control Laws/Altitude Hold'
//  '<S6>'   : 'sig_kadet/Control Laws/Attitude Feedback'
//  '<S7>'   : 'sig_kadet/Control Laws/Manual'
//  '<S8>'   : 'sig_kadet/Control Laws/Manual Throttle'
//  '<S9>'   : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller'
//  '<S10>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Anti-windup'
//  '<S11>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/D Gain'
//  '<S12>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/External Derivative'
//  '<S13>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Filter'
//  '<S14>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Filter ICs'
//  '<S15>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/I Gain'
//  '<S16>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Ideal P Gain'
//  '<S17>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Ideal P Gain Fdbk'
//  '<S18>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Integrator'
//  '<S19>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Integrator ICs'
//  '<S20>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/N Copy'
//  '<S21>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/N Gain'
//  '<S22>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/P Copy'
//  '<S23>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Parallel P Gain'
//  '<S24>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Reset Signal'
//  '<S25>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Saturation'
//  '<S26>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Saturation Fdbk'
//  '<S27>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Sum'
//  '<S28>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Sum Fdbk'
//  '<S29>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tracking Mode'
//  '<S30>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tracking Mode Sum'
//  '<S31>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tsamp - Integral'
//  '<S32>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tsamp - Ngain'
//  '<S33>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/postSat Signal'
//  '<S34>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/preSat Signal'
//  '<S35>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S36>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S37>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S38>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/D Gain/Internal Parameters'
//  '<S39>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/External Derivative/Error'
//  '<S40>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Filter/Differentiator'
//  '<S41>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Filter/Differentiator/Tsamp'
//  '<S42>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Filter/Differentiator/Tsamp/External Ts'
//  '<S43>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S44>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/I Gain/Internal Parameters'
//  '<S45>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Ideal P Gain/Passthrough'
//  '<S46>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S47>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Integrator/Discrete'
//  '<S48>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Integrator ICs/Internal IC'
//  '<S49>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S50>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/N Gain/Passthrough'
//  '<S51>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/P Copy/Disabled'
//  '<S52>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S53>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Reset Signal/Disabled'
//  '<S54>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Saturation/Enabled'
//  '<S55>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Saturation Fdbk/Disabled'
//  '<S56>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Sum/Sum_PID'
//  '<S57>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Sum Fdbk/Disabled'
//  '<S58>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tracking Mode/Disabled'
//  '<S59>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S60>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tsamp - Integral/External Ts'
//  '<S61>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S62>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/postSat Signal/Forward_Path'
//  '<S63>'  : 'sig_kadet/Control Laws/Airspeed Hold/PID Controller/preSat Signal/Forward_Path'
//  '<S64>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback'
//  '<S65>'  : 'sig_kadet/Control Laws/Altitude Hold/Latch Initial Value'
//  '<S66>'  : 'sig_kadet/Control Laws/Altitude Hold/PID Controller'
//  '<S67>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller'
//  '<S68>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller'
//  '<S69>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Yaw Damper'
//  '<S70>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/Angle Conversion'
//  '<S71>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller'
//  '<S72>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup'
//  '<S73>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/D Gain'
//  '<S74>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/External Derivative'
//  '<S75>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Filter'
//  '<S76>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Filter ICs'
//  '<S77>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/I Gain'
//  '<S78>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain'
//  '<S79>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain Fdbk'
//  '<S80>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Integrator'
//  '<S81>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Integrator ICs'
//  '<S82>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/N Copy'
//  '<S83>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/N Gain'
//  '<S84>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/P Copy'
//  '<S85>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Parallel P Gain'
//  '<S86>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Reset Signal'
//  '<S87>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Saturation'
//  '<S88>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Saturation Fdbk'
//  '<S89>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Sum'
//  '<S90>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Sum Fdbk'
//  '<S91>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode'
//  '<S92>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode Sum'
//  '<S93>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Integral'
//  '<S94>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Ngain'
//  '<S95>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/postSat Signal'
//  '<S96>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/preSat Signal'
//  '<S97>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S98>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S99>'  : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S100>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/D Gain/Internal Parameters'
//  '<S101>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/External Derivative/Error'
//  '<S102>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Filter/Differentiator'
//  '<S103>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Filter/Differentiator/Tsamp'
//  '<S104>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Filter/Differentiator/Tsamp/External Ts'
//  '<S105>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S106>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/I Gain/Internal Parameters'
//  '<S107>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S108>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S109>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Integrator/Discrete'
//  '<S110>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Integrator ICs/Internal IC'
//  '<S111>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S112>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/N Gain/Passthrough'
//  '<S113>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/P Copy/Disabled'
//  '<S114>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S115>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Reset Signal/Disabled'
//  '<S116>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Saturation/Enabled'
//  '<S117>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S118>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Sum/Sum_PID'
//  '<S119>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Sum Fdbk/Disabled'
//  '<S120>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode/Disabled'
//  '<S121>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S122>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Integral/External Ts'
//  '<S123>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S124>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/postSat Signal/Forward_Path'
//  '<S125>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Pitch Controller/PID Controller/preSat Signal/Forward_Path'
//  '<S126>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/Angle Conversion'
//  '<S127>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller'
//  '<S128>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Anti-windup'
//  '<S129>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/D Gain'
//  '<S130>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/External Derivative'
//  '<S131>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Filter'
//  '<S132>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Filter ICs'
//  '<S133>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/I Gain'
//  '<S134>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain'
//  '<S135>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain Fdbk'
//  '<S136>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Integrator'
//  '<S137>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Integrator ICs'
//  '<S138>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/N Copy'
//  '<S139>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/N Gain'
//  '<S140>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/P Copy'
//  '<S141>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Parallel P Gain'
//  '<S142>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Reset Signal'
//  '<S143>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Saturation'
//  '<S144>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Saturation Fdbk'
//  '<S145>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Sum'
//  '<S146>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Sum Fdbk'
//  '<S147>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode'
//  '<S148>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode Sum'
//  '<S149>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Integral'
//  '<S150>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Ngain'
//  '<S151>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/postSat Signal'
//  '<S152>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/preSat Signal'
//  '<S153>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S154>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S155>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S156>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/D Gain/Internal Parameters'
//  '<S157>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/External Derivative/Error'
//  '<S158>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Filter/Differentiator'
//  '<S159>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Filter/Differentiator/Tsamp'
//  '<S160>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Filter/Differentiator/Tsamp/External Ts'
//  '<S161>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S162>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/I Gain/Internal Parameters'
//  '<S163>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S164>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S165>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Integrator/Discrete'
//  '<S166>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Integrator ICs/Internal IC'
//  '<S167>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S168>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/N Gain/Passthrough'
//  '<S169>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/P Copy/Disabled'
//  '<S170>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S171>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Reset Signal/Disabled'
//  '<S172>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Saturation/Enabled'
//  '<S173>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S174>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Sum/Sum_PID'
//  '<S175>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Sum Fdbk/Disabled'
//  '<S176>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode/Disabled'
//  '<S177>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S178>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Integral/External Ts'
//  '<S179>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S180>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/postSat Signal/Forward_Path'
//  '<S181>' : 'sig_kadet/Control Laws/Altitude Hold/Attitude Feedback/Roll Controller/PID Controller/preSat Signal/Forward_Path'
//  '<S182>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Anti-windup'
//  '<S183>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/D Gain'
//  '<S184>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/External Derivative'
//  '<S185>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Filter'
//  '<S186>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Filter ICs'
//  '<S187>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/I Gain'
//  '<S188>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Ideal P Gain'
//  '<S189>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Ideal P Gain Fdbk'
//  '<S190>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Integrator'
//  '<S191>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Integrator ICs'
//  '<S192>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/N Copy'
//  '<S193>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/N Gain'
//  '<S194>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/P Copy'
//  '<S195>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Parallel P Gain'
//  '<S196>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Reset Signal'
//  '<S197>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Saturation'
//  '<S198>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Saturation Fdbk'
//  '<S199>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Sum'
//  '<S200>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Sum Fdbk'
//  '<S201>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tracking Mode'
//  '<S202>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tracking Mode Sum'
//  '<S203>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tsamp - Integral'
//  '<S204>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tsamp - Ngain'
//  '<S205>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/postSat Signal'
//  '<S206>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/preSat Signal'
//  '<S207>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S208>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S209>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S210>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/D Gain/Internal Parameters'
//  '<S211>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/External Derivative/Error'
//  '<S212>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Filter/Differentiator'
//  '<S213>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Filter/Differentiator/Tsamp'
//  '<S214>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Filter/Differentiator/Tsamp/External Ts'
//  '<S215>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S216>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/I Gain/Internal Parameters'
//  '<S217>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Ideal P Gain/Passthrough'
//  '<S218>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S219>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Integrator/Discrete'
//  '<S220>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Integrator ICs/Internal IC'
//  '<S221>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S222>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/N Gain/Passthrough'
//  '<S223>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/P Copy/Disabled'
//  '<S224>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S225>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Reset Signal/Disabled'
//  '<S226>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Saturation/Enabled'
//  '<S227>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Saturation Fdbk/Disabled'
//  '<S228>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Sum/Sum_PID'
//  '<S229>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Sum Fdbk/Disabled'
//  '<S230>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tracking Mode/Disabled'
//  '<S231>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S232>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tsamp - Integral/External Ts'
//  '<S233>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S234>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/postSat Signal/Forward_Path'
//  '<S235>' : 'sig_kadet/Control Laws/Altitude Hold/PID Controller/preSat Signal/Forward_Path'
//  '<S236>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller'
//  '<S237>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller'
//  '<S238>' : 'sig_kadet/Control Laws/Attitude Feedback/Yaw Damper'
//  '<S239>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/Angle Conversion'
//  '<S240>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller'
//  '<S241>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup'
//  '<S242>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/D Gain'
//  '<S243>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/External Derivative'
//  '<S244>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Filter'
//  '<S245>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Filter ICs'
//  '<S246>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/I Gain'
//  '<S247>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain'
//  '<S248>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain Fdbk'
//  '<S249>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Integrator'
//  '<S250>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Integrator ICs'
//  '<S251>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/N Copy'
//  '<S252>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/N Gain'
//  '<S253>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/P Copy'
//  '<S254>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Parallel P Gain'
//  '<S255>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Reset Signal'
//  '<S256>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Saturation'
//  '<S257>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Saturation Fdbk'
//  '<S258>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Sum'
//  '<S259>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Sum Fdbk'
//  '<S260>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode'
//  '<S261>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode Sum'
//  '<S262>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Integral'
//  '<S263>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Ngain'
//  '<S264>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/postSat Signal'
//  '<S265>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/preSat Signal'
//  '<S266>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S267>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S268>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S269>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/D Gain/Internal Parameters'
//  '<S270>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/External Derivative/Error'
//  '<S271>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Filter/Differentiator'
//  '<S272>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Filter/Differentiator/Tsamp'
//  '<S273>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Filter/Differentiator/Tsamp/External Ts'
//  '<S274>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S275>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/I Gain/Internal Parameters'
//  '<S276>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S277>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S278>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Integrator/Discrete'
//  '<S279>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Integrator ICs/Internal IC'
//  '<S280>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S281>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/N Gain/Passthrough'
//  '<S282>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/P Copy/Disabled'
//  '<S283>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S284>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Reset Signal/Disabled'
//  '<S285>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Saturation/Enabled'
//  '<S286>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S287>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Sum/Sum_PID'
//  '<S288>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Sum Fdbk/Disabled'
//  '<S289>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode/Disabled'
//  '<S290>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S291>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Integral/External Ts'
//  '<S292>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S293>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/postSat Signal/Forward_Path'
//  '<S294>' : 'sig_kadet/Control Laws/Attitude Feedback/Pitch Controller/PID Controller/preSat Signal/Forward_Path'
//  '<S295>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/Angle Conversion'
//  '<S296>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller'
//  '<S297>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Anti-windup'
//  '<S298>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/D Gain'
//  '<S299>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/External Derivative'
//  '<S300>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Filter'
//  '<S301>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Filter ICs'
//  '<S302>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/I Gain'
//  '<S303>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain'
//  '<S304>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain Fdbk'
//  '<S305>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Integrator'
//  '<S306>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Integrator ICs'
//  '<S307>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/N Copy'
//  '<S308>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/N Gain'
//  '<S309>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/P Copy'
//  '<S310>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Parallel P Gain'
//  '<S311>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Reset Signal'
//  '<S312>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Saturation'
//  '<S313>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Saturation Fdbk'
//  '<S314>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Sum'
//  '<S315>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Sum Fdbk'
//  '<S316>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode'
//  '<S317>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode Sum'
//  '<S318>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Integral'
//  '<S319>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Ngain'
//  '<S320>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/postSat Signal'
//  '<S321>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/preSat Signal'
//  '<S322>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S323>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S324>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S325>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/D Gain/Internal Parameters'
//  '<S326>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/External Derivative/Error'
//  '<S327>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Filter/Differentiator'
//  '<S328>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Filter/Differentiator/Tsamp'
//  '<S329>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Filter/Differentiator/Tsamp/External Ts'
//  '<S330>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S331>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/I Gain/Internal Parameters'
//  '<S332>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S333>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S334>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Integrator/Discrete'
//  '<S335>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Integrator ICs/Internal IC'
//  '<S336>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S337>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/N Gain/Passthrough'
//  '<S338>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/P Copy/Disabled'
//  '<S339>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S340>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Reset Signal/Disabled'
//  '<S341>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Saturation/Enabled'
//  '<S342>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S343>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Sum/Sum_PID'
//  '<S344>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Sum Fdbk/Disabled'
//  '<S345>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode/Disabled'
//  '<S346>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S347>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Integral/External Ts'
//  '<S348>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S349>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/postSat Signal/Forward_Path'
//  '<S350>' : 'sig_kadet/Control Laws/Attitude Feedback/Roll Controller/PID Controller/preSat Signal/Forward_Path'
//  '<S351>' : 'sig_kadet/Control Laws/Manual/Angle Conversion'
//  '<S352>' : 'sig_kadet/Control Laws/Manual/Angle Conversion1'
//  '<S353>' : 'sig_kadet/Control Laws/Manual/Angle Conversion2'
//  '<S354>' : 'sig_kadet/Sensor Processing/Analog Input Mapping'
//  '<S355>' : 'sig_kadet/Sensor Processing/Pilot Stick Mapping'

#endif                                 // autocode_h_

//
// File trailer for generated code.
//
// [EOF]
//
