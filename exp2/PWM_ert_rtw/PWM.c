/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM.c
 *
 * Code generated for Simulink model 'PWM'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep 22 17:05:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM.h"
#include "rtwtypes.h"
#include "PWM_private.h"
#include "PWM_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Block signals (default storage) */
B_PWM_T PWM_B;

/* Block states (default storage) */
DW_PWM_T PWM_DW;

/* Real-time model */
static RT_MODEL_PWM_T PWM_M_;
RT_MODEL_PWM_T *const PWM_M = &PWM_M_;

/* Callback for Hardware Interrupt Block: '<S3>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <S3>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(PWM_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

    /* Output and update for function-call system: '<S3>/Triggered Subsystem' */
    {
      boolean_T b_value;
      PWM_M->Timing.clockTick2 = PWM_M->Timing.clockTick0;

      /* MATLABSystem: '<S4>/Digital Input' */
      if (PWM_DW.obj.SampleTime != PWM_P.DigitalInput_SampleTime) {
        PWM_DW.obj.SampleTime = PWM_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S4>/Sum' incorporates:
       *  Constant: '<S4>/Constant'
       *  Delay: '<S4>/Delay'
       *  Gain: '<S4>/Gain'
       *  MATLABSystem: '<S4>/Digital Input'
       *  Sum: '<S4>/Add'
       */
      PWM_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)PWM_P.Gain_Gain_d : 0) *
        0.015625 - PWM_P.Constant_Value;
      PWM_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */
  }
}

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
void PWM_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T Saturation_tmp;
    real_T lastTime;
    real_T u0;
    real_T *lastU;
    uint8_T tmp;

    /* Clock: '<S2>/Clock' incorporates:
     *  Derivative: '<S3>/Derivative'
     */
    Saturation_tmp = PWM_M->Timing.t[0];

    /* Step: '<S2>/Step' incorporates:
     *  Step: '<S1>/Step'
     */
    lastTime = PWM_M->Timing.t[0];
    if (lastTime < PWM_P.Ramp_start) {
      u0 = PWM_P.Step_Y0;
    } else {
      u0 = PWM_P.Ramp_slope;
    }

    /* End of Step: '<S2>/Step' */

    /* Sum: '<S2>/Output' incorporates:
     *  Clock: '<S2>/Clock'
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Product: '<S2>/Product'
     *  Sum: '<S2>/Sum'
     */
    PWM_B.Saturation = (Saturation_tmp - PWM_P.Ramp_start) * u0 +
      PWM_P.Ramp_InitialOutput;

    /* Saturate: '<Root>/Saturation' */
    if (PWM_B.Saturation > PWM_P.Saturation_UpperSat) {
      /* Sum: '<S2>/Output' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      PWM_B.Saturation = PWM_P.Saturation_UpperSat;
    } else if (PWM_B.Saturation < PWM_P.Saturation_LowerSat) {
      /* Sum: '<S2>/Output' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      PWM_B.Saturation = PWM_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Signum: '<S1>/Sign' */
    if (rtIsNaN(PWM_B.Saturation)) {
      u0 = PWM_B.Saturation;
    } else if (PWM_B.Saturation < 0.0) {
      u0 = -1.0;
    } else {
      u0 = (PWM_B.Saturation > 0.0);
    }

    /* End of Signum: '<S1>/Sign' */

    /* MATLABSystem: '<S1>/Digital Output1' incorporates:
     *  Bias: '<S1>/Bias'
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain2'
     */
    u0 = rt_roundd_snf((PWM_P.Gain_Gain * u0 + PWM_P.Bias_Bias) *
                       PWM_P.Gain2_Gain);
    if (u0 < 256.0) {
      if (u0 >= 0.0) {
        tmp = (uint8_T)u0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(49, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output1' */

    /* MATLABSystem: '<S1>/PWM' */
    obj = &PWM_DW.obj_p;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);

    /* Abs: '<S1>/Abs' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    u0 = fabs(PWM_P.Gain1_Gain * PWM_B.Saturation);

    /* MATLABSystem: '<S1>/PWM' */
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    MW_PWM_SetDutyCycle(PWM_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, u0);

    /* Step: '<S1>/Step' */
    if (lastTime < PWM_P.Step_Time) {
      lastTime = PWM_P.Step_Y0_p;
    } else {
      lastTime = PWM_P.Step_YFinal;
    }

    /* MATLABSystem: '<S1>/Digital Output' */
    lastTime = rt_roundd_snf(lastTime);
    if (lastTime < 256.0) {
      if (lastTime >= 0.0) {
        tmp = (uint8_T)lastTime;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(48, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output' */
    /* Gain: '<S3>/Gain3' */
    PWM_B.Gain3 = PWM_P.Gain3_Gain * PWM_DW.Delay_DSTATE;

    /* Derivative: '<S3>/Derivative' */
    if ((PWM_DW.TimeStampA >= Saturation_tmp) && (PWM_DW.TimeStampB >=
         Saturation_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      PWM_B.Derivative = 0.0;
    } else {
      lastTime = PWM_DW.TimeStampA;
      lastU = &PWM_DW.LastUAtTimeA;
      if (PWM_DW.TimeStampA < PWM_DW.TimeStampB) {
        if (PWM_DW.TimeStampB < Saturation_tmp) {
          lastTime = PWM_DW.TimeStampB;
          lastU = &PWM_DW.LastUAtTimeB;
        }
      } else if (PWM_DW.TimeStampA >= Saturation_tmp) {
        lastTime = PWM_DW.TimeStampB;
        lastU = &PWM_DW.LastUAtTimeB;
      }

      /* Derivative: '<S3>/Derivative' */
      PWM_B.Derivative = (PWM_B.Gain3 - *lastU) / (Saturation_tmp - lastTime);
    }
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<S3>/Derivative' */
    if (PWM_DW.TimeStampA == (rtInf)) {
      PWM_DW.TimeStampA = PWM_M->Timing.t[0];
      lastU = &PWM_DW.LastUAtTimeA;
    } else if (PWM_DW.TimeStampB == (rtInf)) {
      PWM_DW.TimeStampB = PWM_M->Timing.t[0];
      lastU = &PWM_DW.LastUAtTimeB;
    } else if (PWM_DW.TimeStampA < PWM_DW.TimeStampB) {
      PWM_DW.TimeStampA = PWM_M->Timing.t[0];
      lastU = &PWM_DW.LastUAtTimeA;
    } else {
      PWM_DW.TimeStampB = PWM_M->Timing.t[0];
      lastU = &PWM_DW.LastUAtTimeB;
    }

    *lastU = PWM_B.Gain3;

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      PWM_M->Timing.t[0];

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
      ((PWM_M->Timing.clockTick1) * 0.005);

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
  PWM_M->Timing.t[0] =
    ((time_T)(++PWM_M->Timing.clockTick0)) * PWM_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PWM_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void PWM_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PWM_M->solverInfo, &PWM_M->Timing.simTimeStep);
    rtsiSetTPtr(&PWM_M->solverInfo, &rtmGetTPtr(PWM_M));
    rtsiSetStepSizePtr(&PWM_M->solverInfo, &PWM_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&PWM_M->solverInfo, (&rtmGetErrorStatus(PWM_M)));
    rtsiSetRTModelPtr(&PWM_M->solverInfo, PWM_M);
  }

  rtsiSetSimTimeStep(&PWM_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&PWM_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(PWM_M, &PWM_M->Timing.tArray[0]);
  rtmSetTFinal(PWM_M, -1);
  PWM_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  PWM_M->Sizes.checksums[0] = (3558517471U);
  PWM_M->Sizes.checksums[1] = (3909326794U);
  PWM_M->Sizes.checksums[2] = (430700370U);
  PWM_M->Sizes.checksums[3] = (576154250U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    PWM_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&PWM_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&PWM_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PWM_M->extModeInfo,
      &PWM_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PWM_M->extModeInfo, PWM_M->Sizes.checksums);
    rteiSetTPtr(PWM_M->extModeInfo, rtmGetTPtr(PWM_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Derivative: '<S3>/Derivative' */
    PWM_DW.TimeStampA = (rtInf);
    PWM_DW.TimeStampB = (rtInf);

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' incorporates:
     *  SubSystem: '<S3>/Triggered Subsystem'
     */

    /* System initialize for function-call system: '<S3>/Triggered Subsystem' */
    PWM_M->Timing.clockTick2 = PWM_M->Timing.clockTick0;

    /* Start for MATLABSystem: '<S4>/Digital Input' */
    PWM_DW.obj.matlabCodegenIsDeleted = false;
    PWM_DW.obj.SampleTime = PWM_P.DigitalInput_SampleTime;
    PWM_DW.obj.isInitialized = 1;
    digitalIOSetup(51, 0);
    PWM_DW.obj.isSetupComplete = true;

    /* SystemInitialize for Outport: '<S4>/Out1' incorporates:
     *  Delay: '<S4>/Delay'
     *  Sum: '<S4>/Sum'
     */
    PWM_DW.Delay_DSTATE = PWM_P.Out1_Y0;
    ;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    PWM_DW.obj_j.matlabCodegenIsDeleted = true;
    PWM_DW.obj_j.isInitialized = 0;
    PWM_DW.obj_j.matlabCodegenIsDeleted = false;
    PWM_DW.obj_j.isSetupComplete = false;
    PWM_DW.obj_j.isInitialized = 1;
    digitalIOSetup(49, 1);
    PWM_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    PWM_DW.obj_p.matlabCodegenIsDeleted = true;
    PWM_DW.obj_p.isInitialized = 0;
    PWM_DW.obj_p.matlabCodegenIsDeleted = false;
    obj = &PWM_DW.obj_p;
    PWM_DW.obj_p.isSetupComplete = false;
    PWM_DW.obj_p.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    PWM_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    PWM_DW.obj_h.matlabCodegenIsDeleted = true;
    PWM_DW.obj_h.isInitialized = 0;
    PWM_DW.obj_h.matlabCodegenIsDeleted = false;
    PWM_DW.obj_h.isSetupComplete = false;
    PWM_DW.obj_h.isInitialized = 1;
    digitalIOSetup(48, 1);
    PWM_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void PWM_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!PWM_DW.obj_j.matlabCodegenIsDeleted) {
    PWM_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &PWM_DW.obj_p;
  if (!PWM_DW.obj_p.matlabCodegenIsDeleted) {
    PWM_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PWM_DW.obj_p.isInitialized == 1) && PWM_DW.obj_p.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle(PWM_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close(PWM_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!PWM_DW.obj_h.matlabCodegenIsDeleted) {
    PWM_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

  /* Terminate for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' incorporates:
   *  SubSystem: '<S3>/Triggered Subsystem'
   */
  /* Termination for function-call system: '<S3>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S4>/Digital Input' */
  if (!PWM_DW.obj.matlabCodegenIsDeleted) {
    PWM_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
