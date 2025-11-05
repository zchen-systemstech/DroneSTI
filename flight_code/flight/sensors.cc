/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "flight/sensors.h"
#include "flight/global_defs.h"
#include "flight/config.h"
#include "flight/msg.h"
#include "flight/analog.h"
#if defined(__FMU_R_V2__)
#include "flight/battery.h"
#endif

namespace {
/* Whether pitot static is installed */
bool pitot_static_installed_;
/* Sensors */
bfs::SbusRx inceptor;
bfs::Mpu9250 imu;
bfs::Ublox gnss;
bfs::Bme280 fmu_static_pres;
bfs::Ams5915 pitot_static_pres;
bfs::Ams5915 pitot_diff_pres;
}  // namespace

void SensorsInit(const SensorConfig &cfg) {
  pitot_static_installed_ = cfg.pitot_static_installed;
  MsgInfo("Intializing sensors...");
  /* Initialize IMU */
  if (!imu.Init(cfg.imu)) {
    MsgError("Unable to initialize IMU.");
  }
  /* Initialize GNSS */
  /* Initialize GNSS
   * For FMU Mini and FMU R V2 tutorial scopes GNSS init is intentionally
   * disabled so other peripherals (like SBUS) can be tested without the
   * firmware blocking on GNSS initialization failures. Match the tutorial
   * behavior: only call Init for FMU_R_V1 builds.
   */
#if defined(__FMU_R_V1__)
  if (!gnss.Init(cfg.gnss)) {
    MsgError("Unable to initialize GNSS.");
  }
#else
  /* GNSS init disabled for this build to allow testing other peripherals. */
#endif
  /* Initialize pressure transducers */
  /* Initialize pressure transducers
   * Disabled for SBUS testing: some boards may not have the pressure
   * transducers installed or wired during bench testing. Initializing
   * them here can produce a fatal MsgError which prevents SBUS tests.
   * Skip initialization so SBUS and other peripherals can be tested.
   */
#if 0
  if (pitot_static_installed_) {
    if (!pitot_static_pres.Init(cfg.static_pres)) {
      MsgError("Unable to initialize static pressure sensor.");
    }
    if (!pitot_diff_pres.Init(cfg.diff_pres)) {
      MsgError("Unable to initialize differential pressure sensor.");
    }
  } else {
    if (!fmu_static_pres.Init(cfg.static_pres)) {
      MsgError("Unable to initialize static pressure sensor.");
    }
  }
#else
  MsgInfo("Skipping pressure transducer initialization for SBUS testing.\n");
#endif
  MsgInfo("done.\n");
  /* Initialize inceptors */
  MsgInfo("Initializing inceptors...");
  while (!inceptor.Init(&SBUS_UART)) {}
  MsgInfo("done.\n");
}
void SensorsRead(SensorData * const data) {
  if (!data) {return;}
  /* Read inceptors */
  data->inceptor.new_data = inceptor.Read();
  if (data->inceptor.new_data) {
    data->inceptor.ch = inceptor.ch();
    data->inceptor.ch17 = inceptor.ch17();
    data->inceptor.ch18 = inceptor.ch18();
    data->inceptor.lost_frame = inceptor.lost_frame();
    data->inceptor.failsafe = inceptor.failsafe();
    /* Debug: print SBUS channel values when DEBUG is enabled so user can
     * verify RC inputs on the serial monitor. */
    if (DEBUG) {
      MSG_BUS.print("SBUS:");
      for (int i = 0; i < static_cast<int>(bfs::SbusRx::NUM_CH); i++) {
        MSG_BUS.print(' ');
        MSG_BUS.print(data->inceptor.ch[i]);
      }
      MSG_BUS.print(" ch17:");
      MSG_BUS.print(data->inceptor.ch17 ? 1 : 0);
      MSG_BUS.print(" ch18:");
      MSG_BUS.print(data->inceptor.ch18 ? 1 : 0);
      MSG_BUS.print(" lost:");
      MSG_BUS.print(data->inceptor.lost_frame ? 1 : 0);
      MSG_BUS.print(" failsafe:");
      MSG_BUS.println(data->inceptor.failsafe ? 1 : 0);
    }
  }
  /* Read IMU */
  // if (!imu.Read(&data->imu)) {
  //   MsgWarning("Unable to read IMU data.\n");
  // }
  /* Read GNSS */
  //gnss.Read(&data->gnss);
  /* Set whether pitot static is installed */
  // data->pitot_static_installed = pitot_static_installed_;
  /* Read pressure transducers */
  // if (pitot_static_installed_) {
  //   if (!pitot_static_pres.Read(&data->static_pres)) {
  //     MsgWarning("Unable to read pitot static pressure data.\n");
  //   }
  //   if (!pitot_diff_pres.Read(&data->diff_pres)) {
  //     MsgWarning("Unable to read pitot diff pressure data.\n");
  //   }
  // } else {
  //   if (!fmu_static_pres.Read(&data->static_pres)) {
  //     MsgWarning("Unable to read FMU static pressure data.\n");
  //   }
  // }
  /* Read analog channels */
  // AnalogRead(&data->adc);
  /* Read battery voltage / current */
  #if defined(__FMU_R_V2__)
  // BatteryRead(&data->power_module);
  #endif
}

void SbusPollDebug() {
  /* Immediate SBUS print: parse any available bytes and print current
   * channel values. Timing is handled externally (timer/flag in main).
   */
  (void)inceptor.Read();
  auto ch = inceptor.ch();
  MSG_BUS.print("SBUS:");
  for (int i = 0; i < static_cast<int>(bfs::SbusRx::NUM_CH); i++) {
    MSG_BUS.print(' ');
    MSG_BUS.print(ch[i]);
  }
  MSG_BUS.print(" ch17:");
  MSG_BUS.print(inceptor.ch17() ? 1 : 0);
  MSG_BUS.print(" ch18:");
  MSG_BUS.print(inceptor.ch18() ? 1 : 0);
  MSG_BUS.print(" lost:");
  MSG_BUS.print(inceptor.lost_frame() ? 1 : 0);
  MSG_BUS.print(" failsafe:");
  MSG_BUS.println(inceptor.failsafe() ? 1 : 0);
}
