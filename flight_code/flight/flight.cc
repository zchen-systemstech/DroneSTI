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

#include "flight/hardware_defs.h"
#include "flight/global_defs.h"
#include "flight/config.h"
#include "flight/msg.h"
#include "flight/sys.h"
#include "flight/sensors.h"
#include "flight/effectors.h"
#include "flight/nav.h"
#include "flight/vms.h"
#include "flight/datalog.h"
#include "flight/telem.h"

/* Aircraft data */
AircraftData data;
/* Timer for sending effector commands */
IntervalTimer effector_timer;
// (No file-scope SBUS timer - polling is done in main loop)

/* ISR to send effector commands */
void send_effectors() {
  /* Stop the effector timer */
  effector_timer.end();
  #if defined(__FMU_R_V1__)
  /* Pulse the BFS bus */
  digitalWriteFast(BFS_INT1, LOW);
  digitalWriteFast(BFS_INT2, HIGH);
  #endif
  /* Send effector commands */
  EffectorsWrite();
}

/* ISR to gather sensor data and run VMS */
void run() {
  /* ISR: gather sensor data and run VMS. Bench SBUS printing has been
   * removed from the ISR to keep ISR execution short. SBUS debug prints
   * are performed from the main loop.
   */
  /* Start the effector timer */
  effector_timer.begin(send_effectors, EFFECTOR_DELAY_US);
  #if defined(__FMU_R_V1__)
  /* Pulse the BFS bus */
  digitalWriteFast(BFS_INT1, HIGH);
  digitalWriteFast(BFS_INT2, LOW);
  #endif
  /* System data */
  SysRead(&data.sys);
  /* Sensor data */
  SensorsRead(&data.sensor);
  /* Nav filter */
  //NavRun(data.sensor, &data.nav);
  /* VMS */
  VmsRun(data.sys, data.sensor, data.nav, data.telem, &data.vms);
  /* Command effectors */
  EffectorsCmd(data.vms);
  /* Write effectors immediately (instead of relying on timer callback) */
  //EffectorsWrite();
  /* Datalog */
  DatalogAdd(data);
  /* Telemetry */
  //TelemUpdate(data, &data.telem);
  /* Frame duration */
  SysFrameEnd();
}

int main() {
  /* Init the message bus */
  MsgBegin();
  /* Init system */
  SysInit();
  /* Init sensors */
  SensorsInit(config.sensor);
  /* Init nav */
  NavInit(config.nav);
  /* Init effectors */
  EffectorsInit();
  /* Init VMS */
  VmsInit();
  /* Init telemetry */
  TelemInit(config, &data.telem);
  /* Init datalog */
  DatalogInit();
  /* Attach data ready interrupt to run sensor processing, VMS, and effector
   * commands at the frame rate. This is the normal production behavior.
   */
  attachInterrupt(IMU_DRDY, run, RISING);

  /* Optional: millis-based diagnostic polling for VMS output monitoring */
  uint32_t last_print_ms = millis();
  MSG_BUS.println("Entering main loop - IMU ISR enabled");
  while (1) {
    /* Flush datalog */
    DatalogFlush();
    
    /* Optional: Print VMS outputs at 5 Hz for monitoring (doesn't affect flight) */
    uint32_t now = millis();
    if ((now - last_print_ms) >= 200) {
      last_print_ms = now;
      MSG_BUS.print("VMS: motor=");
      MSG_BUS.print(data.vms.motors_enabled ? 1 : 0);
      MSG_BUS.print(" SBUS:");
      for (int i = 0; i < 8; ++i) {
        if (i) MSG_BUS.print(' ');
        MSG_BUS.print(data.vms.sbus.cnt[i]);
      }
      MSG_BUS.print(" PWM:");
      for (int i = 0; i < NUM_PWM_PINS; ++i) {
        MSG_BUS.print(' ');
        MSG_BUS.print(data.vms.pwm.cnt[i]);
      }
      MSG_BUS.println();
    }
  }
}

