//
// File: autocode.cpp
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

#include "autocode.h"
#include "rtwtypes.h"
#include "flight/global_defs.h"
#include <cstring>
#include <cmath>
#include <array>

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
  //
  // Output and update for atomic system:
  //    '<S6>/remap'
  //    '<S7>/remap'
  //    '<S10>/remap'
  //
  void Autocode::remap(real32_T rtu_raw_in, real32_T rtu_in_min, real32_T
                       rtu_in_max, real32_T rtu_out_min, real32_T rtu_out_max,
                       real32_T *rty_norm_out)
  {
    *rty_norm_out = (rtu_raw_in - rtu_in_min) * (rtu_out_max - rtu_out_min) /
      (rtu_in_max - rtu_in_min) + rtu_out_min;
  }
}

namespace bfs
{
  //
  // Output and update for atomic system:
  //    '<S8>/remap_with_deadband'
  //    '<S9>/remap_with_deadband'
  //    '<S11>/remap_with_deadband'
  //
  void Autocode::remap_with_deadband(real32_T rtu_raw_in, real32_T rtu_in_min,
    real32_T rtu_in_max, real32_T rtu_out_min, real32_T rtu_out_max, real32_T
    rtu_deadband, real32_T *rty_norm_out)
  {
    real32_T in_avg;
    real32_T in_deadband_low;
    real32_T in_deadband_range;
    real32_T out_avg;
    in_avg = (rtu_in_min + rtu_in_max) / 2.0F;
    out_avg = (rtu_out_min + rtu_out_max) / 2.0F;
    in_deadband_range = (rtu_in_max - rtu_in_min) * rtu_deadband / 2.0F;
    in_deadband_low = in_avg - in_deadband_range;
    in_avg += in_deadband_range;
    if (rtu_raw_in < in_deadband_low) {
      *rty_norm_out = (rtu_raw_in - in_deadband_low) * (rtu_out_max - out_avg) /
        (in_deadband_low - rtu_in_min) + out_avg;
    } else if ((rtu_raw_in > in_deadband_low) && (rtu_raw_in < in_avg)) {
      *rty_norm_out = out_avg;
    } else {
      *rty_norm_out = (rtu_raw_in - in_avg) * (rtu_out_max - out_avg) /
        (rtu_in_max - in_avg) + out_avg;
    }
  }
}

namespace bfs
{
  // Model step function
  void Autocode::Run(SysData sys, SensorData sensor, NavData nav, TelemData
                     telem, VmsData *ctrl)
  {
    std::array<real32_T, 16> rtb_cmd;
    std::array<real32_T, 8> rtb_raw_out;
    int32_T i;
    real32_T rtb_norm_out;
    real32_T rtb_norm_out_m;
    boolean_T rtb_Compare;
    UNUSED_PARAMETER(sys);
    UNUSED_PARAMETER(nav);
    UNUSED_PARAMETER(telem);

    // Saturate: '<S3>/Saturation5' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion7'
    //   Inport: '<Root>/Sensor Data'
    if (sensor.inceptor.ch[4] > 1810) {
      i = 1810;
    } else if (sensor.inceptor.ch[4] < 174) {
      i = 174;
    } else {
      i = sensor.inceptor.ch[4];
    }

    // MATLAB Function: '<S7>/remap' incorporates:
    //   Constant: '<S7>/Constant'
    //   Constant: '<S7>/Constant1'
    //   Constant: '<S7>/Constant2'
    //   Constant: '<S7>/Constant3'
    //   Saturate: '<S3>/Saturation5'
    remap(static_cast<real32_T>(i), 174.0F, 1810.0F, 0.0F, 1.0F, &rtb_norm_out_m);

    // Saturate: '<S3>/Saturation' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion5'
    //   Inport: '<Root>/Sensor Data'
    if (sensor.inceptor.ch[0] > 1810) {
      i = 1810;
    } else if (sensor.inceptor.ch[0] < 174) {
      i = 174;
    } else {
      i = sensor.inceptor.ch[0];
    }

    // MATLAB Function: '<S10>/remap' incorporates:
    //   Constant: '<S10>/Constant'
    //   Constant: '<S10>/Constant1'
    //   Constant: '<S10>/Constant2'
    //   Constant: '<S10>/Constant3'
    //   Saturate: '<S3>/Saturation'
    remap(static_cast<real32_T>(i), 174.0F, 1810.0F, 0.0F, 100.0F, &rtb_norm_out);

    // Saturate: '<S3>/Saturation1' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion4'
    //   Inport: '<Root>/Sensor Data'
    if (sensor.inceptor.ch[2] > 1810) {
      i = 1810;
    } else if (sensor.inceptor.ch[2] < 174) {
      i = 174;
    } else {
      i = sensor.inceptor.ch[2];
    }

    // SignalConversion generated from: '<S2>/Bus Creator' incorporates:
    //   Constant: '<S3>/Constant'
    //   Constant: '<S8>/Constant'
    //   Constant: '<S8>/Constant1'
    //   Constant: '<S8>/Constant2'
    //   Constant: '<S8>/Constant3'
    //   MATLAB Function: '<S8>/remap_with_deadband'
    //   Saturate: '<S3>/Saturation1'
    remap_with_deadband(static_cast<real32_T>(i), 174.0F, 1810.0F, -1.0F, 1.0F,
                        0.1F, &rtb_cmd[1]);

    // Saturate: '<S3>/Saturation2' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion3'
    //   Inport: '<Root>/Sensor Data'
    if (sensor.inceptor.ch[1] > 1810) {
      i = 1810;
    } else if (sensor.inceptor.ch[1] < 174) {
      i = 174;
    } else {
      i = sensor.inceptor.ch[1];
    }

    // SignalConversion generated from: '<S2>/Bus Creator' incorporates:
    //   Constant: '<S3>/Constant1'
    //   Constant: '<S9>/Constant'
    //   Constant: '<S9>/Constant1'
    //   Constant: '<S9>/Constant2'
    //   Constant: '<S9>/Constant3'
    //   DataTypeConversion: '<S3>/Data Type Conversion2'
    //   Inport: '<Root>/Sensor Data'
    //   MATLAB Function: '<S9>/remap_with_deadband'
    //   Saturate: '<S3>/Saturation2'
    remap_with_deadband(static_cast<real32_T>(i), 174.0F, 1810.0F, -1.0F, 1.0F,
                        0.1F, &rtb_cmd[2]);
    rtb_cmd[3] = sensor.inceptor.ch[3];

    // Saturate: '<S3>/Saturation3' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion2'
    //   Inport: '<Root>/Sensor Data'
    if (sensor.inceptor.ch[3] > 1810) {
      i = 1810;
    } else if (sensor.inceptor.ch[3] < 174) {
      i = 174;
    } else {
      i = sensor.inceptor.ch[3];
    }

    // SignalConversion generated from: '<S2>/Bus Creator' incorporates:
    //   Constant: '<S11>/Constant'
    //   Constant: '<S11>/Constant1'
    //   Constant: '<S11>/Constant2'
    //   Constant: '<S11>/Constant3'
    //   Constant: '<S3>/Constant2'
    //   MATLAB Function: '<S11>/remap_with_deadband'
    //   Saturate: '<S3>/Saturation3'
    remap_with_deadband(static_cast<real32_T>(i), 174.0F, 1810.0F, -1.0F, 1.0F,
                        0.1F, &rtb_cmd[3]);
    rtb_cmd[0] = rtb_norm_out;
    rtb_cmd[4] = rtb_norm_out_m;
    rtb_cmd[5] = 0.0F;
    rtb_cmd[6] = 0.0F;
    rtb_cmd[7] = 0.0F;
    rtb_cmd[8] = 0.0F;
    rtb_cmd[9] = 0.0F;
    rtb_cmd[10] = 0.0F;
    rtb_cmd[11] = 0.0F;
    rtb_cmd[12] = 0.0F;
    rtb_cmd[13] = 0.0F;
    rtb_cmd[14] = 0.0F;
    rtb_cmd[15] = 0.0F;

    // RelationalOperator: '<S19>/Compare' incorporates:
    //   Constant: '<S19>/Constant'
    rtb_Compare = (rtb_norm_out_m > 0.5F);

    // Switch: '<S1>/emergency_switch' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion'
    if (static_cast<real_T>(rtb_Compare) > 0.5) {
      rtb_norm_out_m = rtb_norm_out;
    } else {
      rtb_norm_out_m = 0.0F;
    }

    // MATLAB Function: '<S1>/remap' incorporates:
    //   Constant: '<S1>/Constant2'
    //   Switch: '<S1>/emergency_switch'
    for (i = 0; i < 8; i++) {
      rtb_raw_out[i] = rtb_norm_out_m * 1000.0F / 100.0F + 1000.0F;
    }

    // End of MATLAB Function: '<S1>/remap'

    // Outport: '<Root>/VMS Data' incorporates:
    //   BusCreator: '<S2>/Bus Creator'
    //   DataTypeConversion: '<S2>/Cast1'
    //   DataTypeConversion: '<S2>/Cast2'
    //   SignalConversion generated from: '<S2>/Bus Creator'
    //
    ctrl->motors_enabled = rtb_Compare;
    ctrl->waypoint_reached = false;
    ctrl->mode = 0;
    ctrl->throttle_cmd_prcnt = rtb_norm_out;
    std::memset(&ctrl->aux[0], 0, 24U * sizeof(real32_T));
    ctrl->sbus.ch17 = false;
    ctrl->sbus.ch18 = false;
    for (i = 0; i < 16; i++) {
      // DataTypeConversion: '<S2>/Cast1'
      rtb_norm_out = rtb_cmd[i];
      ctrl->sbus.cnt[i] = static_cast<int16_T>(std::floor(rtb_norm_out));
      ctrl->sbus.cmd[i] = rtb_norm_out;
    }

    for (i = 0; i < 8; i++) {
      // DataTypeConversion: '<S2>/Cast2'
      rtb_norm_out = rtb_raw_out[i];
      ctrl->pwm.cnt[i] = static_cast<int16_T>(std::floor(rtb_norm_out));
      ctrl->pwm.cmd[i] = rtb_norm_out;
      ctrl->analog.val[i] = 0.0F;
    }

    ctrl->battery.voltage_v = 0.0F;
    ctrl->battery.current_ma = 0.0F;
    ctrl->battery.consumed_mah = 0.0F;
    ctrl->battery.remaining_prcnt = 0.0F;
    ctrl->battery.remaining_time_s = 0.0F;

    // End of Outport: '<Root>/VMS Data'

    // Saturate: '<S3>/Saturation4' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion1'
    //   Inport: '<Root>/Sensor Data'
    if (sensor.inceptor.ch[6] > 1810) {
      i = 1810;
    } else if (sensor.inceptor.ch[6] < 174) {
      i = 174;
    } else {
      i = sensor.inceptor.ch[6];
    }

    // MATLAB Function: '<S6>/remap' incorporates:
    //   Constant: '<S6>/Constant'
    //   Constant: '<S6>/Constant1'
    //   Constant: '<S6>/Constant2'
    //   Constant: '<S6>/Constant3'
    //   Saturate: '<S3>/Saturation4'
    remap(static_cast<real32_T>(i), 172.0F, 1811.0F, -1.0F, 1.0F, &rtb_norm_out);
  }

  // Model initialize function
  void Autocode::initialize()
  {
    // (no initialization code required)
  }

  // Constructor
  Autocode::Autocode()
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
