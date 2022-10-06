/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave.c
 *
 * Code generated for Simulink model 'PWM_sinewave'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct  6 17:17:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM_sinewave.h"
#include "rtwtypes.h"
#include "PWM_sinewave_private.h"
#include "PWM_sinewave_types.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_PWM_sinewave_T PWM_sinewave_B;

/* Block states (default storage) */
DW_PWM_sinewave_T PWM_sinewave_DW;

/* Real-time model */
static RT_MODEL_PWM_sinewave_T PWM_sinewave_M_;
RT_MODEL_PWM_sinewave_T *const PWM_sinewave_M = &PWM_sinewave_M_;

/* Callback for Hardware Interrupt Block: '<S2>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <S2>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(PWM_sinewave_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

    /* Output and update for function-call system: '<S2>/Triggered Subsystem' */
    {
      boolean_T b_value;
      PWM_sinewave_M->Timing.clockTick2 = PWM_sinewave_M->Timing.clockTick0;

      /* MATLABSystem: '<S3>/Digital Input' */
      if (PWM_sinewave_DW.obj.SampleTime !=
          PWM_sinewave_P.DigitalInput_SampleTime) {
        PWM_sinewave_DW.obj.SampleTime = PWM_sinewave_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S3>/Sum' incorporates:
       *  Constant: '<S3>/Constant'
       *  Delay: '<S3>/Delay'
       *  Gain: '<S3>/Gain'
       *  MATLABSystem: '<S3>/Digital Input'
       *  Sum: '<S3>/Add'
       */
      PWM_sinewave_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)
        PWM_sinewave_P.Gain_Gain_d : 0) * 0.015625 -
        PWM_sinewave_P.Constant_Value;
      PWM_sinewave_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */
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
void PWM_sinewave_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T lastTime;
    real_T rtb_Derivative;
    real_T u0_tmp;
    real_T *lastU;
    uint8_T tmp;

    /* Sin: '<Root>/Sine Wave' incorporates:
     *  Step: '<S1>/Step'
     */
    u0_tmp = PWM_sinewave_M->Timing.t[0];
    PWM_sinewave_B.Saturation = sin(PWM_sinewave_P.SineWave_Freq * u0_tmp +
      PWM_sinewave_P.SineWave_Phase) * PWM_sinewave_P.SineWave_Amp +
      PWM_sinewave_P.SineWave_Bias;

    /* Saturate: '<Root>/Saturation' */
    if (PWM_sinewave_B.Saturation > PWM_sinewave_P.Saturation_UpperSat) {
      /* Sin: '<Root>/Sine Wave' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      PWM_sinewave_B.Saturation = PWM_sinewave_P.Saturation_UpperSat;
    } else if (PWM_sinewave_B.Saturation < PWM_sinewave_P.Saturation_LowerSat) {
      /* Sin: '<Root>/Sine Wave' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      PWM_sinewave_B.Saturation = PWM_sinewave_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Signum: '<S1>/Sign' */
    if (rtIsNaN(PWM_sinewave_B.Saturation)) {
      rtb_Derivative = PWM_sinewave_B.Saturation;
    } else if (PWM_sinewave_B.Saturation < 0.0) {
      rtb_Derivative = -1.0;
    } else {
      rtb_Derivative = (PWM_sinewave_B.Saturation > 0.0);
    }

    /* End of Signum: '<S1>/Sign' */

    /* MATLABSystem: '<S1>/Digital Output1' incorporates:
     *  Bias: '<S1>/Bias'
     *  Gain: '<S1>/Gain'
     *  Gain: '<S1>/Gain2'
     */
    rtb_Derivative = rt_roundd_snf((PWM_sinewave_P.Gain_Gain * rtb_Derivative +
      PWM_sinewave_P.Bias_Bias) * PWM_sinewave_P.Gain2_Gain);
    if (rtb_Derivative < 256.0) {
      if (rtb_Derivative >= 0.0) {
        tmp = (uint8_T)rtb_Derivative;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(49, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output1' */

    /* MATLABSystem: '<S1>/PWM' */
    obj = &PWM_sinewave_DW.obj_p;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);

    /* Abs: '<S1>/Abs' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtb_Derivative = fabs(PWM_sinewave_P.Gain1_Gain * PWM_sinewave_B.Saturation);

    /* MATLABSystem: '<S1>/PWM' */
    if (!(rtb_Derivative <= 255.0)) {
      rtb_Derivative = 255.0;
    }

    MW_PWM_SetDutyCycle(PWM_sinewave_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Derivative);

    /* Gain: '<S2>/Gain3' */
    PWM_sinewave_B.Gain3 = PWM_sinewave_P.Gain3_Gain *
      PWM_sinewave_DW.Delay_DSTATE;

    /* Derivative: '<S2>/Derivative' */
    rtb_Derivative = PWM_sinewave_M->Timing.t[0];
    if ((PWM_sinewave_DW.TimeStampA >= rtb_Derivative) &&
        (PWM_sinewave_DW.TimeStampB >= rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = PWM_sinewave_DW.TimeStampA;
      lastU = &PWM_sinewave_DW.LastUAtTimeA;
      if (PWM_sinewave_DW.TimeStampA < PWM_sinewave_DW.TimeStampB) {
        if (PWM_sinewave_DW.TimeStampB < rtb_Derivative) {
          lastTime = PWM_sinewave_DW.TimeStampB;
          lastU = &PWM_sinewave_DW.LastUAtTimeB;
        }
      } else if (PWM_sinewave_DW.TimeStampA >= rtb_Derivative) {
        lastTime = PWM_sinewave_DW.TimeStampB;
        lastU = &PWM_sinewave_DW.LastUAtTimeB;
      }

      rtb_Derivative = (PWM_sinewave_B.Gain3 - *lastU) / (rtb_Derivative -
        lastTime);
    }

    /* End of Derivative: '<S2>/Derivative' */

    /* Gain: '<Root>/Gain' */
    PWM_sinewave_B.Gain = PWM_sinewave_P.Gain_Gain_j * rtb_Derivative;

    /* Step: '<S1>/Step' */
    if (u0_tmp < PWM_sinewave_P.Step_Time) {
      rtb_Derivative = PWM_sinewave_P.Step_Y0;
    } else {
      rtb_Derivative = PWM_sinewave_P.Step_YFinal;
    }

    /* MATLABSystem: '<S1>/Digital Output' */
    rtb_Derivative = rt_roundd_snf(rtb_Derivative);
    if (rtb_Derivative < 256.0) {
      if (rtb_Derivative >= 0.0) {
        tmp = (uint8_T)rtb_Derivative;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(48, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<S2>/Derivative' */
    if (PWM_sinewave_DW.TimeStampA == (rtInf)) {
      PWM_sinewave_DW.TimeStampA = PWM_sinewave_M->Timing.t[0];
      lastU = &PWM_sinewave_DW.LastUAtTimeA;
    } else if (PWM_sinewave_DW.TimeStampB == (rtInf)) {
      PWM_sinewave_DW.TimeStampB = PWM_sinewave_M->Timing.t[0];
      lastU = &PWM_sinewave_DW.LastUAtTimeB;
    } else if (PWM_sinewave_DW.TimeStampA < PWM_sinewave_DW.TimeStampB) {
      PWM_sinewave_DW.TimeStampA = PWM_sinewave_M->Timing.t[0];
      lastU = &PWM_sinewave_DW.LastUAtTimeA;
    } else {
      PWM_sinewave_DW.TimeStampB = PWM_sinewave_M->Timing.t[0];
      lastU = &PWM_sinewave_DW.LastUAtTimeB;
    }

    *lastU = PWM_sinewave_B.Gain3;

    /* End of Update for Derivative: '<S2>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      PWM_sinewave_M->Timing.t[0];

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((PWM_sinewave_M->Timing.clockTick1) * 0.001);

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
  PWM_sinewave_M->Timing.t[0] =
    ((time_T)(++PWM_sinewave_M->Timing.clockTick0)) *
    PWM_sinewave_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PWM_sinewave_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void PWM_sinewave_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PWM_sinewave_M->solverInfo,
                          &PWM_sinewave_M->Timing.simTimeStep);
    rtsiSetTPtr(&PWM_sinewave_M->solverInfo, &rtmGetTPtr(PWM_sinewave_M));
    rtsiSetStepSizePtr(&PWM_sinewave_M->solverInfo,
                       &PWM_sinewave_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&PWM_sinewave_M->solverInfo, (&rtmGetErrorStatus
      (PWM_sinewave_M)));
    rtsiSetRTModelPtr(&PWM_sinewave_M->solverInfo, PWM_sinewave_M);
  }

  rtsiSetSimTimeStep(&PWM_sinewave_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&PWM_sinewave_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(PWM_sinewave_M, &PWM_sinewave_M->Timing.tArray[0]);
  rtmSetTFinal(PWM_sinewave_M, -1);
  PWM_sinewave_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  PWM_sinewave_M->Sizes.checksums[0] = (2638338826U);
  PWM_sinewave_M->Sizes.checksums[1] = (3819854365U);
  PWM_sinewave_M->Sizes.checksums[2] = (2892088977U);
  PWM_sinewave_M->Sizes.checksums[3] = (2605192153U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    PWM_sinewave_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &PWM_sinewave_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &PWM_sinewave_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PWM_sinewave_M->extModeInfo,
      &PWM_sinewave_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PWM_sinewave_M->extModeInfo,
                        PWM_sinewave_M->Sizes.checksums);
    rteiSetTPtr(PWM_sinewave_M->extModeInfo, rtmGetTPtr(PWM_sinewave_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    PWM_sinewave_DW.TimeStampA = (rtInf);
    PWM_sinewave_DW.TimeStampB = (rtInf);

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' incorporates:
     *  SubSystem: '<S2>/Triggered Subsystem'
     */

    /* System initialize for function-call system: '<S2>/Triggered Subsystem' */
    PWM_sinewave_M->Timing.clockTick2 = PWM_sinewave_M->Timing.clockTick0;

    /* Start for MATLABSystem: '<S3>/Digital Input' */
    PWM_sinewave_DW.obj.matlabCodegenIsDeleted = false;
    PWM_sinewave_DW.obj.SampleTime = PWM_sinewave_P.DigitalInput_SampleTime;
    PWM_sinewave_DW.obj.isInitialized = 1;
    digitalIOSetup(51, 0);
    PWM_sinewave_DW.obj.isSetupComplete = true;

    /* SystemInitialize for Outport: '<S3>/Out1' incorporates:
     *  Delay: '<S3>/Delay'
     *  Sum: '<S3>/Sum'
     */
    PWM_sinewave_DW.Delay_DSTATE = PWM_sinewave_P.Out1_Y0;
    ;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    PWM_sinewave_DW.obj_j.matlabCodegenIsDeleted = true;
    PWM_sinewave_DW.obj_j.isInitialized = 0;
    PWM_sinewave_DW.obj_j.matlabCodegenIsDeleted = false;
    PWM_sinewave_DW.obj_j.isSetupComplete = false;
    PWM_sinewave_DW.obj_j.isInitialized = 1;
    digitalIOSetup(49, 1);
    PWM_sinewave_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    PWM_sinewave_DW.obj_p.matlabCodegenIsDeleted = true;
    PWM_sinewave_DW.obj_p.isInitialized = 0;
    PWM_sinewave_DW.obj_p.matlabCodegenIsDeleted = false;
    obj = &PWM_sinewave_DW.obj_p;
    PWM_sinewave_DW.obj_p.isSetupComplete = false;
    PWM_sinewave_DW.obj_p.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    PWM_sinewave_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    PWM_sinewave_DW.obj_h.matlabCodegenIsDeleted = true;
    PWM_sinewave_DW.obj_h.isInitialized = 0;
    PWM_sinewave_DW.obj_h.matlabCodegenIsDeleted = false;
    PWM_sinewave_DW.obj_h.isSetupComplete = false;
    PWM_sinewave_DW.obj_h.isInitialized = 1;
    digitalIOSetup(48, 1);
    PWM_sinewave_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void PWM_sinewave_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!PWM_sinewave_DW.obj_j.matlabCodegenIsDeleted) {
    PWM_sinewave_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &PWM_sinewave_DW.obj_p;
  if (!PWM_sinewave_DW.obj_p.matlabCodegenIsDeleted) {
    PWM_sinewave_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PWM_sinewave_DW.obj_p.isInitialized == 1) &&
        PWM_sinewave_DW.obj_p.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle(PWM_sinewave_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close(PWM_sinewave_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

  /* Terminate for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' incorporates:
   *  SubSystem: '<S2>/Triggered Subsystem'
   */
  /* Termination for function-call system: '<S2>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S3>/Digital Input' */
  if (!PWM_sinewave_DW.obj.matlabCodegenIsDeleted) {
    PWM_sinewave_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!PWM_sinewave_DW.obj_h.matlabCodegenIsDeleted) {
    PWM_sinewave_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
