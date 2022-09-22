/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: led_contorl.c
 *
 * Code generated for Simulink model 'led_contorl'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep 15 17:04:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "led_contorl.h"
#include "rtwtypes.h"
#include "led_contorl_private.h"
#include <math.h>

/* Block states (default storage) */
DW_led_contorl_T led_contorl_DW;

/* Real-time model */
static RT_MODEL_led_contorl_T led_contorl_M_;
RT_MODEL_led_contorl_T *const led_contorl_M = &led_contorl_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void led_contorl_step(void)
{
  real_T rtb_PulseGenerator;
  real_T tmp;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (led_contorl_DW.clockTickCounter <
                        led_contorl_P.PulseGenerator_Duty) &&
    (led_contorl_DW.clockTickCounter >= 0) ? led_contorl_P.PulseGenerator_Amp :
    0.0;
  if (led_contorl_DW.clockTickCounter >= led_contorl_P.PulseGenerator_Period -
      1.0) {
    led_contorl_DW.clockTickCounter = 0;
  } else {
    led_contorl_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp = rt_roundd_snf(rtb_PulseGenerator);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(44, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<Root>/NOT'
   */
  writeDigitalPin(45, (uint8_T)!(rtb_PulseGenerator != 0.0));

  {                                    /* Sample time: [0.005s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  led_contorl_M->Timing.taskTime0 =
    ((time_T)(++led_contorl_M->Timing.clockTick0)) *
    led_contorl_M->Timing.stepSize0;
}

/* Model initialize function */
void led_contorl_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(led_contorl_M, -1);
  led_contorl_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  led_contorl_M->Sizes.checksums[0] = (2099898932U);
  led_contorl_M->Sizes.checksums[1] = (1076317859U);
  led_contorl_M->Sizes.checksums[2] = (3430411287U);
  led_contorl_M->Sizes.checksums[3] = (3103083348U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    led_contorl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(led_contorl_M->extModeInfo,
      &led_contorl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(led_contorl_M->extModeInfo,
                        led_contorl_M->Sizes.checksums);
    rteiSetTPtr(led_contorl_M->extModeInfo, rtmGetTPtr(led_contorl_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  led_contorl_DW.obj_p.matlabCodegenIsDeleted = false;
  led_contorl_DW.obj_p.isInitialized = 1;
  digitalIOSetup(44, 1);
  led_contorl_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  led_contorl_DW.obj.matlabCodegenIsDeleted = false;
  led_contorl_DW.obj.isInitialized = 1;
  digitalIOSetup(45, 1);
  led_contorl_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void led_contorl_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!led_contorl_DW.obj_p.matlabCodegenIsDeleted) {
    led_contorl_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!led_contorl_DW.obj.matlabCodegenIsDeleted) {
    led_contorl_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
