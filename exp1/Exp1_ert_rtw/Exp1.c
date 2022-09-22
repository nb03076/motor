/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Exp1.c
 *
 * Code generated for Simulink model 'Exp1'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep 15 15:46:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Exp1.h"
#include "rtwtypes.h"
#include "Exp1_private.h"
#include <math.h>

/* Block states (default storage) */
DW_Exp1_T Exp1_DW;

/* Real-time model */
static RT_MODEL_Exp1_T Exp1_M_;
RT_MODEL_Exp1_T *const Exp1_M = &Exp1_M_;
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
void Exp1_step(void)
{
  real_T rtb_PulseGenerator;
  real_T tmp;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Exp1_DW.clockTickCounter < Exp1_P.PulseGenerator_Duty) &&
    (Exp1_DW.clockTickCounter >= 0) ? Exp1_P.PulseGenerator_Amp : 0.0;
  if (Exp1_DW.clockTickCounter >= Exp1_P.PulseGenerator_Period - 1.0) {
    Exp1_DW.clockTickCounter = 0;
  } else {
    Exp1_DW.clockTickCounter++;
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
  Exp1_M->Timing.taskTime0 =
    ((time_T)(++Exp1_M->Timing.clockTick0)) * Exp1_M->Timing.stepSize0;
}

/* Model initialize function */
void Exp1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Exp1_M, -1);
  Exp1_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  Exp1_M->Sizes.checksums[0] = (3275326408U);
  Exp1_M->Sizes.checksums[1] = (3422806016U);
  Exp1_M->Sizes.checksums[2] = (4241494076U);
  Exp1_M->Sizes.checksums[3] = (2845158796U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Exp1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Exp1_M->extModeInfo,
      &Exp1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Exp1_M->extModeInfo, Exp1_M->Sizes.checksums);
    rteiSetTPtr(Exp1_M->extModeInfo, rtmGetTPtr(Exp1_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  Exp1_DW.obj_p.matlabCodegenIsDeleted = false;
  Exp1_DW.obj_p.isInitialized = 1;
  digitalIOSetup(44, 1);
  Exp1_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  Exp1_DW.obj.matlabCodegenIsDeleted = false;
  Exp1_DW.obj.isInitialized = 1;
  digitalIOSetup(45, 1);
  Exp1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Exp1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Exp1_DW.obj_p.matlabCodegenIsDeleted) {
    Exp1_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!Exp1_DW.obj.matlabCodegenIsDeleted) {
    Exp1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
