//
// File: rtmodel.h
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
#ifndef rtmodel_h_
#define rtmodel_h_
#include "sig_kadet.h"
#define MODEL_CLASSNAME                bfs::Autocode
#define MODEL_STEPNAME                 Run
#define MODEL_STEP_FCN_CONTROL_USED    1

//
//  ROOT_IO_FORMAT: 0 (Individual arguments)
//  ROOT_IO_FORMAT: 1 (Structure reference)
//  ROOT_IO_FORMAT: 2 (Part of model data structure)

#define ROOT_IO_FORMAT                 1

// Macros generated for backwards compatibility
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((void) 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((void*) 0)
#endif
#endif                                 // rtmodel_h_

//
// File trailer for generated code.
//
// [EOF]
//
