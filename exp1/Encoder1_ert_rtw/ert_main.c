/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Encoder1'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Sep 18 16:12:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder1.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  currentTime = (extmodeSimulationTime_T) Encoder1_M->Timing.taskTime0;
  Encoder1_step();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(0, currentTime);

#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
}

extern void rtIOStreamResync();
volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.001;
  float systemClock = 0;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(Encoder1_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  Encoder1_initialize();
  noInterrupts();
  interrupts();

  /* External Mode initialization */
  errorCode = extmodeInit(Encoder1_M->extModeInfo, &rtmGetTFinal(Encoder1_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(Encoder1_M, true);
    }
  }

  noInterrupts();
  configureArduinoARMTimer();
  runModel = !extmodeSimulationComplete() && !extmodeStopRequested() &&
    !rtmGetStopRequested(Encoder1_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  XcpStatus lastXcpState = xcpStatusGet();
  interrupts();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(!extmodeSimulationComplete() && !extmodeStopRequested() &&
                      !rtmGetStopRequested(Encoder1_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disable_rt_OneStep();
    if (lastXcpState==XCP_CONNECTED && xcpStatusGet()==XCP_DISCONNECTED)
      rtIOStreamResync();
    lastXcpState = xcpStatusGet();
    MW_Arduino_Loop();
  }

  /* Terminate model */
  Encoder1_terminate();

  /* External Mode reset */
  extmodeReset();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
