/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep 22 16:40:18 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "untitled_private.h"
#include <math.h>
#include "untitled_types.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
void untitled_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Gain1;
  real_T tmp;
  real_T tmp_1;
  uint8_T tmp_0;

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step'
   */
  tmp_1 = untitled_M->Timing.t[0];
  if (tmp_1 < untitled_P.Step1_Time) {
    rtb_Gain1 = untitled_P.Step1_Y0;
  } else {
    rtb_Gain1 = untitled_P.Step1_YFinal;
  }

  /* End of Step: '<Root>/Step1' */

  /* Signum: '<Root>/Sign' */
  if (rtIsNaN(rtb_Gain1)) {
    tmp = rtb_Gain1;
  } else if (rtb_Gain1 < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (rtb_Gain1 > 0.0);
  }

  /* End of Signum: '<Root>/Sign' */

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Bias: '<Root>/Bias'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain2'
   */
  tmp = rt_roundd_snf((untitled_P.Gain_Gain * tmp + untitled_P.Bias_Bias) *
                      untitled_P.Gain2_Gain);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(49, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/PWM' */
  obj = &untitled_DW.obj_i;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);

  /* Abs: '<Root>/Abs' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  rtb_Gain1 = fabs(untitled_P.Gain1_Gain * rtb_Gain1);

  /* MATLABSystem: '<Root>/PWM' */
  if (!(rtb_Gain1 <= 255.0)) {
    rtb_Gain1 = 255.0;
  }

  MW_PWM_SetDutyCycle(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, rtb_Gain1);

  /* Step: '<Root>/Step' */
  if (tmp_1 < untitled_P.Step_Time) {
    tmp_1 = untitled_P.Step_Y0;
  } else {
    tmp_1 = untitled_P.Step_YFinal;
  }

  /* MATLABSystem: '<Root>/Digital Output' */
  tmp_1 = rt_roundd_snf(tmp_1);
  if (tmp_1 < 256.0) {
    if (tmp_1 >= 0.0) {
      tmp_0 = (uint8_T)tmp_1;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(48, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      untitled_M->Timing.t[0];

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.005s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((untitled_M->Timing.clockTick1) * 0.005);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.t[0] =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1982934845U);
  untitled_M->Sizes.checksums[1] = (2902143787U);
  untitled_M->Sizes.checksums[2] = (789564370U);
  untitled_M->Sizes.checksums[3] = (1396742322U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    untitled_DW.obj.matlabCodegenIsDeleted = false;
    untitled_DW.obj.isInitialized = 1;
    digitalIOSetup(49, 1);
    untitled_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    untitled_DW.obj_i.isInitialized = 0;
    untitled_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &untitled_DW.obj_i;
    untitled_DW.obj_i.isSetupComplete = false;
    untitled_DW.obj_i.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    untitled_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    untitled_DW.obj_h.matlabCodegenIsDeleted = false;
    untitled_DW.obj_h.isInitialized = 1;
    digitalIOSetup(48, 1);
    untitled_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &untitled_DW.obj_i;
  if (!untitled_DW.obj_i.matlabCodegenIsDeleted) {
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_i.isInitialized == 1) &&
        untitled_DW.obj_i.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close(untitled_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
