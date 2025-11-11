//
// File: autocode.cpp
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

#include "autocode.h"
#include "flight/global_defs.h"
#include <cmath>
#include <cstring>
#include "rtwtypes.h"

//===========*
//  Constants *
// ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      // do nothing
#else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

namespace bfs
{
  // Model step function
  void Autocode::Run(const SysData &sys, const SensorData &sensor, const NavData
                     &nav, const TelemData &telem, VmsData *ctrl)
  {
    int32_T i;
    real32_T DiscreteTransferFcn_tmp_b;
    real32_T rtb_DeadZone_e;
    real32_T rtb_DeadZone_n;
    real32_T rtb_DiscreteTransferFcn;
    real32_T rtb_DiscreteTransferFcn_o;
    real32_T rtb_Polynomial;
    real32_T rtb_Polynomial1;
    real32_T rtb_Polynomial2;
    real32_T rtb_Subtract1_e;
    real32_T rtb_Subtract1_n;
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T rtb_RelationalOperator_j;
    UNUSED_PARAMETER(sys);
    UNUSED_PARAMETER(telem);

    // Polyval: '<S355>/Polynomial1' incorporates:
    //   DataTypeConversion: '<S355>/Data Type Conversion8'
    //   Inport: '<Root>/Sensor Data'
    rtb_Polynomial1 = 0.00097703957F * static_cast<real32_T>(sensor.inceptor.ch
      [5]) - 1.0F;

    // Polyval: '<S355>/Polynomial2' incorporates:
    //   DataTypeConversion: '<S355>/Data Type Conversion10'
    //   Inport: '<Root>/Sensor Data'
    rtb_Polynomial2 = 0.00097703957F * static_cast<real32_T>(sensor.inceptor.ch
      [6]) - 1.0F;

    // SwitchCase: '<S2>/Switch Case' incorporates:
    //   Constant: '<S355>/Constant1'
    //   DataTypeConversion: '<S355>/Data Type Conversion1'
    //   DataTypeConversion: '<S355>/Data Type Conversion3'
    //   Inport: '<Root>/Sensor Data'
    //   Product: '<S355>/Product'
    //   Rounding: '<S355>/Floor'
    rtPrevAction = rtDW.SwitchCase_ActiveSubsystem;
    switch (static_cast<int32_T>(std::floor(static_cast<real32_T>
              (sensor.inceptor.ch[1]) * 0.00097703957F))) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     default:
      rtAction = 2;
      break;
    }

    rtDW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      if (rtAction != rtPrevAction) {
        // InitializeConditions for IfAction SubSystem: '<S2>/Attitude Feedback' incorporates:
        //   ActionPort: '<S6>/Action Port'

        // InitializeConditions for SwitchCase: '<S2>/Switch Case' incorporates:
        //   Delay: '<S271>/UD'
        //   Delay: '<S327>/UD'
        //   DiscreteIntegrator: '<S278>/Integrator'
        //   DiscreteIntegrator: '<S334>/Integrator'
        //   DiscreteTransferFcn: '<S238>/Discrete Transfer Fcn'
        rtDW.Integrator_DSTATE_h = 0.0F;
        rtDW.UD_DSTATE_n = 0.0F;
        rtDW.Integrator_DSTATE_hh = 0.0F;
        rtDW.UD_DSTATE_o = 0.0F;
        rtDW.DiscreteTransferFcn_states_n = 0.0F;

        // End of InitializeConditions for SubSystem: '<S2>/Attitude Feedback'
      }

      // Outputs for IfAction SubSystem: '<S2>/Attitude Feedback' incorporates:
      //   ActionPort: '<S6>/Action Port'

      // Outport: '<Root>/VMS Data' incorporates:
      //   Constant: '<S6>/Constant4'
      //   SignalConversion generated from: '<S6>/Mode'
      ctrl->mode = 2;

      // Sum: '<S236>/Subtract' incorporates:
      //   Constant: '<S236>/Constant'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S236>/Product'
      //   UnitConversion: '<S239>/Unit Conversion'

      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Subtract1_e = 30.0F * rtb_Polynomial1 * 0.0174532924F - nav.pitch_rad;

      // Sum: '<S287>/Sum' incorporates:
      //   Delay: '<S271>/UD'
      //   DiscreteIntegrator: '<S278>/Integrator'
      //   Gain: '<S283>/Proportional Gain'
      //   Sum: '<S271>/Diff'
      rtb_DeadZone_e = (0.8F * rtb_Subtract1_e + rtDW.Integrator_DSTATE_h) +
        (0.0F - rtDW.UD_DSTATE_n);

      // Saturate: '<S285>/Saturation' incorporates:
      //   DeadZone: '<S268>/DeadZone'
      if (rtb_DeadZone_e > 0.34906584F) {
        rtb_DiscreteTransferFcn = 0.34906584F;
        rtb_DeadZone_e -= 0.34906584F;
      } else {
        if (rtb_DeadZone_e < -0.34906584F) {
          rtb_DiscreteTransferFcn = -0.34906584F;
        } else {
          rtb_DiscreteTransferFcn = rtb_DeadZone_e;
        }

        if (rtb_DeadZone_e >= -0.34906584F) {
          rtb_DeadZone_e = 0.0F;
        } else {
          rtb_DeadZone_e -= -0.34906584F;
        }
      }

      // Merge generated from: '<S2>/Merge' incorporates:
      //   Constant: '<S236>/Constant1'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S236>/Product1'
      //   Saturate: '<S285>/Saturation'
      //   SignalConversion generated from: '<S6>/Actuator Cmds'
      //   Sum: '<S236>/Subtract1'
      rtb_Polynomial1 = rtb_DiscreteTransferFcn - nav.gyro_radps[1] * 0.15F;

      // Gain: '<S275>/Integral Gain'
      rtb_Subtract1_e *= 0.2F;

      // Switch: '<S266>/Switch1' incorporates:
      //   Constant: '<S266>/Clamping_zero'
      //   Constant: '<S266>/Constant'
      //   Constant: '<S266>/Constant2'
      //   RelationalOperator: '<S266>/fix for DT propagation issue'
      if (rtb_DeadZone_e > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      // Switch: '<S266>/Switch2' incorporates:
      //   Constant: '<S266>/Clamping_zero'
      //   Constant: '<S266>/Constant3'
      //   Constant: '<S266>/Constant4'
      //   RelationalOperator: '<S266>/fix for DT propagation issue1'
      if (rtb_Subtract1_e > 0.0F) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      // Switch: '<S266>/Switch' incorporates:
      //   Constant: '<S266>/Clamping_zero'
      //   Constant: '<S266>/Constant1'
      //   Logic: '<S266>/AND3'
      //   RelationalOperator: '<S266>/Equal1'
      //   RelationalOperator: '<S266>/Relational Operator'
      //   Switch: '<S266>/Switch1'
      //   Switch: '<S266>/Switch2'
      if ((rtb_DeadZone_e != 0.0F) && (rtPrevAction == rtAction)) {
        rtb_Subtract1_n = 0.0F;
      } else {
        rtb_Subtract1_n = rtb_Subtract1_e;
      }

      // End of Switch: '<S266>/Switch'

      // Sum: '<S237>/Subtract' incorporates:
      //   Constant: '<S237>/Constant'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S237>/Product'
      //   UnitConversion: '<S295>/Unit Conversion'

      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Polynomial2 = 45.0F * rtb_Polynomial2 * 0.0174532924F - nav.roll_rad;

      // Sum: '<S343>/Sum' incorporates:
      //   Delay: '<S327>/UD'
      //   DiscreteIntegrator: '<S334>/Integrator'
      //   Gain: '<S339>/Proportional Gain'
      //   Sum: '<S327>/Diff'
      rtb_DeadZone_e = (0.5F * rtb_Polynomial2 + rtDW.Integrator_DSTATE_hh) +
        (0.0F - rtDW.UD_DSTATE_o);

      // Saturate: '<S341>/Saturation' incorporates:
      //   DeadZone: '<S324>/DeadZone'
      if (rtb_DeadZone_e > 0.34906584F) {
        rtb_DiscreteTransferFcn = 0.34906584F;
        rtb_DeadZone_e -= 0.34906584F;
      } else {
        if (rtb_DeadZone_e < -0.34906584F) {
          rtb_DiscreteTransferFcn = -0.34906584F;
        } else {
          rtb_DiscreteTransferFcn = rtb_DeadZone_e;
        }

        if (rtb_DeadZone_e >= -0.34906584F) {
          rtb_DeadZone_e = 0.0F;
        } else {
          rtb_DeadZone_e -= -0.34906584F;
        }
      }

      // Sum: '<S237>/Subtract1' incorporates:
      //   Constant: '<S237>/Constant1'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S237>/Product1'
      //   Saturate: '<S341>/Saturation'
      rtb_Subtract1_e = rtb_DiscreteTransferFcn - nav.gyro_radps[0] * 0.15F;

      // Gain: '<S331>/Integral Gain'
      rtb_Polynomial2 *= 0.2F;

      // DiscreteTransferFcn: '<S238>/Discrete Transfer Fcn' incorporates:
      //   Inport: '<Root>/Navigation Filter Data'
      rtb_DiscreteTransferFcn_o = nav.gyro_radps[2] - -0.9608F *
        rtDW.DiscreteTransferFcn_states_n;
      rtb_DiscreteTransferFcn = -0.065F * rtb_DiscreteTransferFcn_o + 0.065F *
        rtDW.DiscreteTransferFcn_states_n;

      // Outport: '<Root>/VMS Data' incorporates:
      //   SignalConversion generated from: '<S6>/Aux'
      std::memset(&ctrl->aux[0], 0, 24U * sizeof(real32_T));

      // Update for DiscreteIntegrator: '<S278>/Integrator' incorporates:
      //   Constant: '<S236>/Constant2'
      //   Product: '<S291>/Uintegral*Ts Prod Out'
      rtDW.Integrator_DSTATE_h += rtb_Subtract1_n * 0.02F;

      // Update for Delay: '<S271>/UD'
      rtDW.UD_DSTATE_n = 0.0F;

      // Switch: '<S322>/Switch1' incorporates:
      //   Constant: '<S322>/Clamping_zero'
      //   Constant: '<S322>/Constant'
      //   Constant: '<S322>/Constant2'
      //   RelationalOperator: '<S322>/fix for DT propagation issue'
      if (rtb_DeadZone_e > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      // Switch: '<S322>/Switch2' incorporates:
      //   Constant: '<S322>/Clamping_zero'
      //   Constant: '<S322>/Constant3'
      //   Constant: '<S322>/Constant4'
      //   RelationalOperator: '<S322>/fix for DT propagation issue1'
      if (rtb_Polynomial2 > 0.0F) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      // Switch: '<S322>/Switch' incorporates:
      //   Constant: '<S322>/Clamping_zero'
      //   Constant: '<S322>/Constant1'
      //   Logic: '<S322>/AND3'
      //   RelationalOperator: '<S322>/Equal1'
      //   RelationalOperator: '<S322>/Relational Operator'
      //   Switch: '<S322>/Switch1'
      //   Switch: '<S322>/Switch2'
      if ((rtb_DeadZone_e != 0.0F) && (rtPrevAction == rtAction)) {
        rtb_Polynomial2 = 0.0F;
      }

      // Update for DiscreteIntegrator: '<S334>/Integrator' incorporates:
      //   Constant: '<S237>/Constant2'
      //   Product: '<S347>/Uintegral*Ts Prod Out'
      //   Switch: '<S322>/Switch'
      rtDW.Integrator_DSTATE_hh += rtb_Polynomial2 * 0.02F;

      // Update for Delay: '<S327>/UD'
      rtDW.UD_DSTATE_o = 0.0F;

      // Update for DiscreteTransferFcn: '<S238>/Discrete Transfer Fcn'
      rtDW.DiscreteTransferFcn_states_n = rtb_DiscreteTransferFcn_o;

      // End of Outputs for SubSystem: '<S2>/Attitude Feedback'
      break;

     case 1:
      if (rtAction != rtPrevAction) {
        // InitializeConditions for IfAction SubSystem: '<S2>/Altitude Hold' incorporates:
        //   ActionPort: '<S5>/Action Port'

        // InitializeConditions for SwitchCase: '<S2>/Switch Case' incorporates:
        //   Delay: '<S212>/UD'
        //   DiscreteIntegrator: '<S219>/Integrator'
        //   UnitDelay: '<S65>/Unit Delay'
        //   UnitDelay: '<S65>/Unit Delay1'
        rtDW.UnitDelay1_DSTATE = 1.0;
        rtDW.UnitDelay_DSTATE = 0.0F;
        rtDW.Integrator_DSTATE_g = 0.0F;
        rtDW.UD_DSTATE_f = 0.0F;

        // End of InitializeConditions for SubSystem: '<S2>/Altitude Hold'

        // SystemReset for IfAction SubSystem: '<S2>/Altitude Hold' incorporates:
        //   ActionPort: '<S5>/Action Port'

        // SystemReset for Atomic SubSystem: '<S5>/Attitude Feedback'
        // SystemReset for SwitchCase: '<S2>/Switch Case' incorporates:
        //   Delay: '<S102>/UD'
        //   Delay: '<S158>/UD'
        //   DiscreteIntegrator: '<S109>/Integrator'
        //   DiscreteIntegrator: '<S165>/Integrator'
        //   DiscreteTransferFcn: '<S69>/Discrete Transfer Fcn'
        rtDW.Integrator_DSTATE_i = 0.0F;
        rtDW.UD_DSTATE_c = 0.0F;
        rtDW.Integrator_DSTATE_m = 0.0F;
        rtDW.UD_DSTATE_b = 0.0F;
        rtDW.DiscreteTransferFcn_states = 0.0F;

        // End of SystemReset for SubSystem: '<S5>/Attitude Feedback'
        // End of SystemReset for SubSystem: '<S2>/Altitude Hold'
      }

      // Outputs for IfAction SubSystem: '<S2>/Altitude Hold' incorporates:
      //   ActionPort: '<S5>/Action Port'

      // Switch: '<S65>/Switch' incorporates:
      //   Inport: '<Root>/Navigation Filter Data'
      //   UnitDelay: '<S65>/Unit Delay'
      //   UnitDelay: '<S65>/Unit Delay1'
      if (rtDW.UnitDelay1_DSTATE > 0.0) {
        rtb_Polynomial = nav.alt_rel_m;
      } else {
        rtb_Polynomial = rtDW.UnitDelay_DSTATE;
      }

      // End of Switch: '<S65>/Switch'

      // Sum: '<S5>/Subtract' incorporates:
      //   Inport: '<Root>/Navigation Filter Data'
      rtb_DeadZone_e = rtb_Polynomial - nav.alt_rel_m;

      // Sum: '<S228>/Sum' incorporates:
      //   Delay: '<S212>/UD'
      //   DiscreteIntegrator: '<S219>/Integrator'
      //   Gain: '<S224>/Proportional Gain'
      //   Sum: '<S212>/Diff'
      rtb_Subtract1_n = (0.02F * rtb_DeadZone_e + rtDW.Integrator_DSTATE_g) +
        (0.0F - rtDW.UD_DSTATE_f);

      // Saturate: '<S226>/Saturation'
      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      if (rtb_Subtract1_n > 0.17453292F) {
        rtb_DiscreteTransferFcn = 0.17453292F;
      } else if (rtb_Subtract1_n < -0.17453292F) {
        rtb_DiscreteTransferFcn = -0.17453292F;
      } else {
        rtb_DiscreteTransferFcn = rtb_Subtract1_n;
      }

      // Outputs for Atomic SubSystem: '<S5>/Attitude Feedback'
      // Sum: '<S67>/Subtract' incorporates:
      //   Constant: '<S67>/Constant'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S67>/Product'
      //   Saturate: '<S226>/Saturation'
      //   UnitConversion: '<S70>/Unit Conversion'
      DiscreteTransferFcn_tmp_b = 30.0F * rtb_DiscreteTransferFcn *
        0.0174532924F - nav.pitch_rad;

      // Sum: '<S118>/Sum' incorporates:
      //   Delay: '<S102>/UD'
      //   DiscreteIntegrator: '<S109>/Integrator'
      //   Gain: '<S114>/Proportional Gain'
      //   Sum: '<S102>/Diff'
      rtb_DeadZone_n = (0.8F * DiscreteTransferFcn_tmp_b +
                        rtDW.Integrator_DSTATE_i) + (0.0F - rtDW.UD_DSTATE_c);

      // Saturate: '<S116>/Saturation' incorporates:
      //   DeadZone: '<S99>/DeadZone'
      if (rtb_DeadZone_n > 0.34906584F) {
        rtb_DiscreteTransferFcn = 0.34906584F;
        rtb_DeadZone_n -= 0.34906584F;
      } else {
        if (rtb_DeadZone_n < -0.34906584F) {
          rtb_DiscreteTransferFcn = -0.34906584F;
        } else {
          rtb_DiscreteTransferFcn = rtb_DeadZone_n;
        }

        if (rtb_DeadZone_n >= -0.34906584F) {
          rtb_DeadZone_n = 0.0F;
        } else {
          rtb_DeadZone_n -= -0.34906584F;
        }
      }

      // Merge generated from: '<S2>/Merge' incorporates:
      //   Constant: '<S67>/Constant1'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S67>/Product1'
      //   Saturate: '<S116>/Saturation'
      //   Sum: '<S67>/Subtract1'
      rtb_Polynomial1 = rtb_DiscreteTransferFcn - nav.gyro_radps[1] * 0.15F;

      // RelationalOperator: '<S97>/Relational Operator' incorporates:
      //   Constant: '<S97>/Clamping_zero'
      rtb_RelationalOperator_j = (rtb_DeadZone_n != 0.0F);

      // Gain: '<S106>/Integral Gain'
      DiscreteTransferFcn_tmp_b *= 0.2F;

      // Switch: '<S97>/Switch1' incorporates:
      //   Constant: '<S97>/Clamping_zero'
      //   Constant: '<S97>/Constant'
      //   Constant: '<S97>/Constant2'
      //   RelationalOperator: '<S97>/fix for DT propagation issue'
      if (rtb_DeadZone_n > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      // Switch: '<S97>/Switch2' incorporates:
      //   Constant: '<S97>/Clamping_zero'
      //   Constant: '<S97>/Constant3'
      //   Constant: '<S97>/Constant4'
      //   RelationalOperator: '<S97>/fix for DT propagation issue1'
      if (DiscreteTransferFcn_tmp_b > 0.0F) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      // Sum: '<S68>/Subtract' incorporates:
      //   Constant: '<S68>/Constant'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S68>/Product'
      //   UnitConversion: '<S126>/Unit Conversion'

      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Polynomial2 = 45.0F * rtb_Polynomial2 * 0.0174532924F - nav.roll_rad;

      // Sum: '<S174>/Sum' incorporates:
      //   Delay: '<S158>/UD'
      //   DiscreteIntegrator: '<S165>/Integrator'
      //   Gain: '<S170>/Proportional Gain'
      //   Sum: '<S158>/Diff'
      rtb_DeadZone_n = (0.5F * rtb_Polynomial2 + rtDW.Integrator_DSTATE_m) +
        (0.0F - rtDW.UD_DSTATE_b);

      // Saturate: '<S172>/Saturation' incorporates:
      //   DeadZone: '<S155>/DeadZone'
      if (rtb_DeadZone_n > 0.34906584F) {
        rtb_DiscreteTransferFcn = 0.34906584F;
        rtb_DeadZone_n -= 0.34906584F;
      } else {
        if (rtb_DeadZone_n < -0.34906584F) {
          rtb_DiscreteTransferFcn = -0.34906584F;
        } else {
          rtb_DiscreteTransferFcn = rtb_DeadZone_n;
        }

        if (rtb_DeadZone_n >= -0.34906584F) {
          rtb_DeadZone_n = 0.0F;
        } else {
          rtb_DeadZone_n -= -0.34906584F;
        }
      }

      // Sum: '<S68>/Subtract1' incorporates:
      //   Constant: '<S68>/Constant1'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Product: '<S68>/Product1'
      //   Saturate: '<S172>/Saturation'
      rtb_Subtract1_e = rtb_DiscreteTransferFcn - nav.gyro_radps[0] * 0.15F;

      // Gain: '<S162>/Integral Gain'
      rtb_Polynomial2 *= 0.2F;

      // DiscreteTransferFcn: '<S69>/Discrete Transfer Fcn' incorporates:
      //   Inport: '<Root>/Navigation Filter Data'
      rtb_DiscreteTransferFcn_o = nav.gyro_radps[2] - -0.9608F *
        rtDW.DiscreteTransferFcn_states;
      rtb_DiscreteTransferFcn = -0.065F * rtb_DiscreteTransferFcn_o + 0.065F *
        rtDW.DiscreteTransferFcn_states;

      // Switch: '<S97>/Switch' incorporates:
      //   Constant: '<S97>/Constant1'
      //   Logic: '<S97>/AND3'
      //   RelationalOperator: '<S97>/Equal1'
      //   Switch: '<S97>/Switch1'
      //   Switch: '<S97>/Switch2'
      if (rtb_RelationalOperator_j && (rtPrevAction == rtAction)) {
        DiscreteTransferFcn_tmp_b = 0.0F;
      }

      // Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
      //   Constant: '<S67>/Constant2'
      //   Product: '<S122>/Uintegral*Ts Prod Out'
      //   Switch: '<S97>/Switch'
      rtDW.Integrator_DSTATE_i += DiscreteTransferFcn_tmp_b * 0.02F;

      // Update for Delay: '<S102>/UD'
      rtDW.UD_DSTATE_c = 0.0F;

      // Switch: '<S153>/Switch1' incorporates:
      //   Constant: '<S153>/Clamping_zero'
      //   Constant: '<S153>/Constant'
      //   Constant: '<S153>/Constant2'
      //   RelationalOperator: '<S153>/fix for DT propagation issue'
      if (rtb_DeadZone_n > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      // Switch: '<S153>/Switch2' incorporates:
      //   Constant: '<S153>/Clamping_zero'
      //   Constant: '<S153>/Constant3'
      //   Constant: '<S153>/Constant4'
      //   RelationalOperator: '<S153>/fix for DT propagation issue1'
      if (rtb_Polynomial2 > 0.0F) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      // Switch: '<S153>/Switch' incorporates:
      //   Constant: '<S153>/Clamping_zero'
      //   Constant: '<S153>/Constant1'
      //   Logic: '<S153>/AND3'
      //   RelationalOperator: '<S153>/Equal1'
      //   RelationalOperator: '<S153>/Relational Operator'
      //   Switch: '<S153>/Switch1'
      //   Switch: '<S153>/Switch2'
      if ((rtb_DeadZone_n != 0.0F) && (rtPrevAction == rtAction)) {
        rtb_Polynomial2 = 0.0F;
      }

      // Update for DiscreteIntegrator: '<S165>/Integrator' incorporates:
      //   Constant: '<S68>/Constant2'
      //   Product: '<S178>/Uintegral*Ts Prod Out'
      //   Switch: '<S153>/Switch'
      rtDW.Integrator_DSTATE_m += rtb_Polynomial2 * 0.02F;

      // Update for Delay: '<S158>/UD'
      rtDW.UD_DSTATE_b = 0.0F;

      // Update for DiscreteTransferFcn: '<S69>/Discrete Transfer Fcn'
      rtDW.DiscreteTransferFcn_states = rtb_DiscreteTransferFcn_o;

      // End of Outputs for SubSystem: '<S5>/Attitude Feedback'

      // DeadZone: '<S209>/DeadZone'
      if (rtb_Subtract1_n > 0.17453292F) {
        rtb_Subtract1_n -= 0.17453292F;
      } else if (rtb_Subtract1_n >= -0.17453292F) {
        rtb_Subtract1_n = 0.0F;
      } else {
        rtb_Subtract1_n -= -0.17453292F;
      }

      // End of DeadZone: '<S209>/DeadZone'

      // Gain: '<S216>/Integral Gain'
      rtb_DeadZone_e *= 0.002F;

      // Outport: '<Root>/VMS Data' incorporates:
      //   Constant: '<S5>/Constant4'
      //   SignalConversion generated from: '<S5>/Aux'
      //   SignalConversion generated from: '<S5>/Mode'
      ctrl->mode = 2;
      std::memset(&ctrl->aux[0], 0, 24U * sizeof(real32_T));

      // Update for UnitDelay: '<S65>/Unit Delay1' incorporates:
      //   Constant: '<S65>/Constant'
      rtDW.UnitDelay1_DSTATE = 0.0;

      // Update for UnitDelay: '<S65>/Unit Delay'
      rtDW.UnitDelay_DSTATE = rtb_Polynomial;

      // Switch: '<S207>/Switch1' incorporates:
      //   Constant: '<S207>/Clamping_zero'
      //   Constant: '<S207>/Constant'
      //   Constant: '<S207>/Constant2'
      //   RelationalOperator: '<S207>/fix for DT propagation issue'
      if (rtb_Subtract1_n > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      // Switch: '<S207>/Switch2' incorporates:
      //   Constant: '<S207>/Clamping_zero'
      //   Constant: '<S207>/Constant3'
      //   Constant: '<S207>/Constant4'
      //   RelationalOperator: '<S207>/fix for DT propagation issue1'
      if (rtb_DeadZone_e > 0.0F) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      // Switch: '<S207>/Switch' incorporates:
      //   Constant: '<S207>/Clamping_zero'
      //   Constant: '<S207>/Constant1'
      //   Logic: '<S207>/AND3'
      //   RelationalOperator: '<S207>/Equal1'
      //   RelationalOperator: '<S207>/Relational Operator'
      //   Switch: '<S207>/Switch1'
      //   Switch: '<S207>/Switch2'
      if ((rtb_Subtract1_n != 0.0F) && (rtPrevAction == rtAction)) {
        rtb_DeadZone_e = 0.0F;
      }

      // Update for DiscreteIntegrator: '<S219>/Integrator' incorporates:
      //   Constant: '<S5>/Constant2'
      //   Product: '<S232>/Uintegral*Ts Prod Out'
      //   Switch: '<S207>/Switch'
      rtDW.Integrator_DSTATE_g += rtb_DeadZone_e * 0.02F;

      // Update for Delay: '<S212>/UD'
      rtDW.UD_DSTATE_f = 0.0F;

      // End of Outputs for SubSystem: '<S2>/Altitude Hold'
      break;

     default:
      // Outputs for IfAction SubSystem: '<S2>/Manual' incorporates:
      //   ActionPort: '<S7>/Action Port'

      // Outport: '<Root>/VMS Data' incorporates:
      //   Constant: '<S7>/Constant3'
      //   SignalConversion generated from: '<S7>/Mode'
      ctrl->mode = 0;

      // UnitConversion: '<S351>/Unit Conversion' incorporates:
      //   Constant: '<S7>/Constant2'
      //   Product: '<S7>/Product2'

      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Subtract1_e = 20.0F * rtb_Polynomial2 * 0.0174532924F;

      // Merge generated from: '<S2>/Merge' incorporates:
      //   Constant: '<S7>/Constant'
      //   Product: '<S7>/Product'
      //   SignalConversion generated from: '<S7>/Actuator Cmds'
      //   UnitConversion: '<S353>/Unit Conversion'

      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_Polynomial1 = 20.0F * rtb_Polynomial1 * 0.0174532924F;

      // Merge generated from: '<S2>/Merge' incorporates:
      //   Constant: '<S7>/Constant1'
      //   DataTypeConversion: '<S355>/Data Type Conversion6'
      //   Polyval: '<S355>/Polynomial'
      //   Product: '<S7>/Product1'
      //   SignalConversion generated from: '<S7>/Actuator Cmds'
      //   UnitConversion: '<S352>/Unit Conversion'

      // Unit Conversion - from: deg to: rad
      // Expression: output = (0.0174533*input) + (0)
      rtb_DiscreteTransferFcn = (0.00097703957F * static_cast<real32_T>
        (sensor.inceptor.ch[4]) - 1.0F) * 20.0F * 0.0174532924F;

      // Outport: '<Root>/VMS Data' incorporates:
      //   SignalConversion generated from: '<S7>/Aux'
      std::memset(&ctrl->aux[0], 0, 24U * sizeof(real32_T));

      // End of Outputs for SubSystem: '<S2>/Manual'
      break;
    }

    // End of SwitchCase: '<S2>/Switch Case'

    // Outport: '<Root>/VMS Data' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion'
    //   Polyval: '<S1>/Polynomial'
    //   Polyval: '<S1>/Polynomial1'
    //   Polyval: '<S1>/Polynomial2'
    //   Polyval: '<S1>/Polynomial3'
    ctrl->sbus.cnt[0] = static_cast<int16_T>(std::floor(((1144.3219F *
      rtb_Polynomial1 + 167.225357F) * rtb_Polynomial1 + 1558.7489F) *
      rtb_Polynomial1 + 1026.63831F));
    ctrl->sbus.cnt[1] = static_cast<int16_T>(std::floor(((-930.322083F *
      rtb_DiscreteTransferFcn + 148.612793F) * rtb_DiscreteTransferFcn -
      1476.11499F) * rtb_DiscreteTransferFcn + 1006.01617F));
    ctrl->sbus.cnt[2] = static_cast<int16_T>(std::floor(((1097.2782F *
      rtb_Subtract1_e + 173.191559F) * rtb_Subtract1_e + 1642.60229F) *
      rtb_Subtract1_e + 1054.30469F));
    ctrl->sbus.cnt[3] = static_cast<int16_T>(std::floor(((930.582947F *
      rtb_Subtract1_e + 132.665451F) * rtb_Subtract1_e + 1620.14795F) *
      rtb_Subtract1_e + 1011.10437F));
    for (i = 0; i < 12; i++) {
      ctrl->sbus.cnt[i + 4] = 0;
    }

    // SwitchCase: '<S2>/Switch Case1' incorporates:
    //   Constant: '<S355>/Constant2'
    //   Inport: '<Root>/Sensor Data'
    //   RelationalOperator: '<S355>/GreaterThan1'
    rtPrevAction = rtDW.SwitchCase1_ActiveSubsystem;
    if (sensor.inceptor.ch[2] > 1024) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    rtDW.SwitchCase1_ActiveSubsystem = rtAction;
    if (rtAction == 0) {
      if (rtPrevAction != 0) {
        // InitializeConditions for IfAction SubSystem: '<S2>/Airspeed Hold' incorporates:
        //   ActionPort: '<S4>/Action Port'

        // InitializeConditions for SwitchCase: '<S2>/Switch Case1' incorporates:
        //   Delay: '<S40>/UD'
        //   DiscreteIntegrator: '<S47>/Integrator'
        rtDW.Integrator_DSTATE = 0.0F;
        rtDW.UD_DSTATE = 0.0F;

        // End of InitializeConditions for SubSystem: '<S2>/Airspeed Hold'
      }

      // Outputs for IfAction SubSystem: '<S2>/Airspeed Hold' incorporates:
      //   ActionPort: '<S4>/Action Port'

      // Sum: '<S56>/Sum' incorporates:
      //   Constant: '<S4>/Constant1'
      //   Delay: '<S40>/UD'
      //   DiscreteIntegrator: '<S47>/Integrator'
      //   Gain: '<S52>/Proportional Gain'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Sum: '<S40>/Diff'
      //   Sum: '<S4>/Subtract'
      rtb_Subtract1_n = ((17.0F - nav.ias_mps) * 0.09F + rtDW.Integrator_DSTATE)
        + (0.0F - rtDW.UD_DSTATE);

      // Saturate: '<S54>/Saturation' incorporates:
      //   DeadZone: '<S37>/DeadZone'
      if (rtb_Subtract1_n > 1.0F) {
        rtb_Polynomial = 1.0F;
        rtb_Subtract1_n--;
      } else {
        if (rtb_Subtract1_n < 0.0F) {
          rtb_Polynomial = 0.0F;
        } else {
          rtb_Polynomial = rtb_Subtract1_n;
        }

        if (rtb_Subtract1_n >= 0.0F) {
          rtb_Subtract1_n = 0.0F;
        }
      }

      // End of Saturate: '<S54>/Saturation'

      // Gain: '<S44>/Integral Gain' incorporates:
      //   Constant: '<S4>/Constant1'
      //   Inport: '<Root>/Navigation Filter Data'
      //   Sum: '<S4>/Subtract'
      rtb_Polynomial2 = (17.0F - nav.ias_mps) * 0.02F;

      // Switch: '<S35>/Switch1' incorporates:
      //   Constant: '<S35>/Clamping_zero'
      //   Constant: '<S35>/Constant'
      //   Constant: '<S35>/Constant2'
      //   RelationalOperator: '<S35>/fix for DT propagation issue'
      if (rtb_Subtract1_n > 0.0F) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      // Switch: '<S35>/Switch2' incorporates:
      //   Constant: '<S35>/Clamping_zero'
      //   Constant: '<S35>/Constant3'
      //   Constant: '<S35>/Constant4'
      //   RelationalOperator: '<S35>/fix for DT propagation issue1'
      if (rtb_Polynomial2 > 0.0F) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      // Switch: '<S35>/Switch' incorporates:
      //   Constant: '<S35>/Clamping_zero'
      //   Constant: '<S35>/Constant1'
      //   Logic: '<S35>/AND3'
      //   RelationalOperator: '<S35>/Equal1'
      //   RelationalOperator: '<S35>/Relational Operator'
      //   Switch: '<S35>/Switch1'
      //   Switch: '<S35>/Switch2'
      if ((rtb_Subtract1_n != 0.0F) && (rtPrevAction == rtAction)) {
        rtb_Polynomial2 = 0.0F;
      }

      // Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
      //   Constant: '<S4>/Constant2'
      //   Product: '<S60>/Uintegral*Ts Prod Out'
      //   Switch: '<S35>/Switch'
      rtDW.Integrator_DSTATE += rtb_Polynomial2 * 0.02F;

      // Update for Delay: '<S40>/UD'
      rtDW.UD_DSTATE = 0.0F;

      // End of Outputs for SubSystem: '<S2>/Airspeed Hold'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Manual Throttle' incorporates:
      //   ActionPort: '<S8>/Action Port'

      // Gain: '<S8>/Gain' incorporates:
      //   Constant: '<S355>/Constant3'
      //   DataTypeConversion: '<S355>/Data Type Conversion11'
      //   Product: '<S355>/Product1'
      rtb_Polynomial = static_cast<real32_T>(sensor.inceptor.ch[3]) *
        0.000488519785F;

      // End of Outputs for SubSystem: '<S2>/Manual Throttle'
    }

    // End of SwitchCase: '<S2>/Switch Case1'

    // Outport: '<Root>/VMS Data' incorporates:
    //   BusCreator generated from: '<Root>/VMS Data'
    //   Constant: '<Root>/Constant'
    //   Constant: '<S1>/Constant'
    //   Constant: '<S1>/Constant1'
    //   Constant: '<S1>/Constant4'
    //   Constant: '<S1>/Constant5'
    //   DataTypeConversion: '<S1>/Data Type Conversion1'
    //   Gain: '<Root>/Gain'
    //   Gain: '<S354>/Gain'
    //   Inport: '<Root>/Sensor Data'
    //   Polyval: '<S1>/Polynomial4'
    //   RelationalOperator: '<S355>/GreaterThan'
    ctrl->motors_enabled = (sensor.inceptor.ch[0] > 1024);
    ctrl->waypoint_reached = false;
    ctrl->throttle_cmd_prcnt = 100.0F * rtb_Polynomial;
    ctrl->sbus.ch17 = false;
    ctrl->sbus.ch18 = false;
    ctrl->sbus.cmd[0] = rtb_Polynomial1;
    ctrl->sbus.cmd[1] = rtb_DiscreteTransferFcn;
    ctrl->sbus.cmd[2] = rtb_Subtract1_e;
    ctrl->sbus.cmd[3] = rtb_Subtract1_e;
    for (i = 0; i < 12; i++) {
      ctrl->sbus.cmd[i + 4] = 0.0F;
    }

    ctrl->pwm.cnt[0] = static_cast<int16_T>(std::floor(1000.0F * rtb_Polynomial
      + 1000.0F));
    ctrl->pwm.cmd[0] = rtb_Polynomial;
    for (i = 0; i < 7; i++) {
      ctrl->pwm.cnt[i + 1] = 0;
      ctrl->pwm.cmd[i + 1] = 0.0F;
    }

    ctrl->analog.val[0] = 0.0F;
    ctrl->analog.val[1] = 0.0F;
  }

  // Model initialize function
  void Autocode::initialize()
  {
    // Start for SwitchCase: '<S2>/Switch Case'
    rtDW.SwitchCase_ActiveSubsystem = -1;

    // Start for SwitchCase: '<S2>/Switch Case1'
    rtDW.SwitchCase1_ActiveSubsystem = -1;

    // SystemInitialize for IfAction SubSystem: '<S2>/Altitude Hold'
    // InitializeConditions for UnitDelay: '<S65>/Unit Delay1'
    rtDW.UnitDelay1_DSTATE = 1.0;

    // End of SystemInitialize for SubSystem: '<S2>/Altitude Hold'
  }

  // Constructor
  Autocode::Autocode():
    rtDW()
  {
    // Currently there is no constructor body generated.
  }

  // Destructor
  Autocode::~Autocode()
  {
    // Currently there is no destructor body generated.
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
