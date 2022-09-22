/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_Angle.c
 *
 * Code generated for Simulink model 'Encoder_Angle'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Sep 18 16:05:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder_Angle.h"
#include "Encoder_Angle_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Encoder_Angle_T Encoder_Angle_B;

/* Block states (default storage) */
DW_Encoder_Angle_T Encoder_Angle_DW;

/* Real-time model */
static RT_MODEL_Encoder_Angle_T Encoder_Angle_M_;
RT_MODEL_Encoder_Angle_T *const Encoder_Angle_M = &Encoder_Angle_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <Root>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Encoder_Angle_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Triggered Subsystem' */
    {
      boolean_T b_value;
      Encoder_Angle_M->Timing.clockTick2 = Encoder_Angle_M->Timing.clockTick0;

      /* MATLABSystem: '<S1>/Digital Input' */
      if (Encoder_Angle_DW.obj.SampleTime !=
          Encoder_Angle_P.DigitalInput_SampleTime) {
        Encoder_Angle_DW.obj.SampleTime =
          Encoder_Angle_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S1>/Sum' incorporates:
       *  Constant: '<S1>/Constant'
       *  Delay: '<S1>/Delay'
       *  Gain: '<S1>/Gain'
       *  MATLABSystem: '<S1>/Digital Input'
       *  Sum: '<S1>/Add'
       */
      Encoder_Angle_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)
        Encoder_Angle_P.Gain_Gain_a : 0) * 0.015625 -
        Encoder_Angle_P.Constant_Value;
      Encoder_Angle_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/* Model step function */
void Encoder_Angle_step(void)
{
  {
    real_T lastTime;
    real_T tmp;
    real_T *lastU;

    /* Gain: '<Root>/Gain' */
    Encoder_Angle_B.Gain = Encoder_Angle_P.Gain_Gain *
      Encoder_Angle_DW.Delay_DSTATE;

    /* Derivative: '<Root>/Derivative' */
    tmp = Encoder_Angle_M->Timing.t[0];
    if ((Encoder_Angle_DW.TimeStampA >= tmp) && (Encoder_Angle_DW.TimeStampB >=
         tmp)) {
      /* Derivative: '<Root>/Derivative' */
      Encoder_Angle_B.Derivative = 0.0;
    } else {
      lastTime = Encoder_Angle_DW.TimeStampA;
      lastU = &Encoder_Angle_DW.LastUAtTimeA;
      if (Encoder_Angle_DW.TimeStampA < Encoder_Angle_DW.TimeStampB) {
        if (Encoder_Angle_DW.TimeStampB < tmp) {
          lastTime = Encoder_Angle_DW.TimeStampB;
          lastU = &Encoder_Angle_DW.LastUAtTimeB;
        }
      } else if (Encoder_Angle_DW.TimeStampA >= tmp) {
        lastTime = Encoder_Angle_DW.TimeStampB;
        lastU = &Encoder_Angle_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative' */
      Encoder_Angle_B.Derivative = (Encoder_Angle_B.Gain - *lastU) / (tmp -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (Encoder_Angle_DW.TimeStampA == (rtInf)) {
      Encoder_Angle_DW.TimeStampA = Encoder_Angle_M->Timing.t[0];
      lastU = &Encoder_Angle_DW.LastUAtTimeA;
    } else if (Encoder_Angle_DW.TimeStampB == (rtInf)) {
      Encoder_Angle_DW.TimeStampB = Encoder_Angle_M->Timing.t[0];
      lastU = &Encoder_Angle_DW.LastUAtTimeB;
    } else if (Encoder_Angle_DW.TimeStampA < Encoder_Angle_DW.TimeStampB) {
      Encoder_Angle_DW.TimeStampA = Encoder_Angle_M->Timing.t[0];
      lastU = &Encoder_Angle_DW.LastUAtTimeA;
    } else {
      Encoder_Angle_DW.TimeStampB = Encoder_Angle_M->Timing.t[0];
      lastU = &Encoder_Angle_DW.LastUAtTimeB;
    }

    *lastU = Encoder_Angle_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Encoder_Angle_M->Timing.t[0];

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
      ((Encoder_Angle_M->Timing.clockTick1) * 0.005);

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
  Encoder_Angle_M->Timing.t[0] =
    ((time_T)(++Encoder_Angle_M->Timing.clockTick0)) *
    Encoder_Angle_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Encoder_Angle_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Encoder_Angle_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Encoder_Angle_M->solverInfo,
                          &Encoder_Angle_M->Timing.simTimeStep);
    rtsiSetTPtr(&Encoder_Angle_M->solverInfo, &rtmGetTPtr(Encoder_Angle_M));
    rtsiSetStepSizePtr(&Encoder_Angle_M->solverInfo,
                       &Encoder_Angle_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Encoder_Angle_M->solverInfo, (&rtmGetErrorStatus
      (Encoder_Angle_M)));
    rtsiSetRTModelPtr(&Encoder_Angle_M->solverInfo, Encoder_Angle_M);
  }

  rtsiSetSimTimeStep(&Encoder_Angle_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Encoder_Angle_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Encoder_Angle_M, &Encoder_Angle_M->Timing.tArray[0]);
  rtmSetTFinal(Encoder_Angle_M, -1);
  Encoder_Angle_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  Encoder_Angle_M->Sizes.checksums[0] = (1925016841U);
  Encoder_Angle_M->Sizes.checksums[1] = (1302800828U);
  Encoder_Angle_M->Sizes.checksums[2] = (153788069U);
  Encoder_Angle_M->Sizes.checksums[3] = (1913080852U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Encoder_Angle_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Encoder_Angle_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Encoder_Angle_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Encoder_Angle_M->extModeInfo,
      &Encoder_Angle_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_Angle_M->extModeInfo,
                        Encoder_Angle_M->Sizes.checksums);
    rteiSetTPtr(Encoder_Angle_M->extModeInfo, rtmGetTPtr(Encoder_Angle_M));
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Encoder_Angle_DW.TimeStampA = (rtInf);
  Encoder_Angle_DW.TimeStampB = (rtInf);

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Triggered Subsystem' */
  Encoder_Angle_M->Timing.clockTick2 = Encoder_Angle_M->Timing.clockTick0;

  /* Start for MATLABSystem: '<S1>/Digital Input' */
  Encoder_Angle_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_Angle_DW.obj.SampleTime = Encoder_Angle_P.DigitalInput_SampleTime;
  Encoder_Angle_DW.obj.isInitialized = 1;
  digitalIOSetup(51, 0);
  Encoder_Angle_DW.obj.isSetupComplete = true;

  /* SystemInitialize for Outport: '<S1>/Out1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Sum: '<S1>/Sum'
   */
  Encoder_Angle_DW.Delay_DSTATE = Encoder_Angle_P.Out1_Y0;
  ;

  /* Attach callback function */
  /* Changes made wrt g2141701, this change was needed to make the
   * architecture simpler for adding new boards.
   */
  attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/* Model terminate function */
void Encoder_Angle_terminate(void)
{
  /* Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem'
   */

  /* Termination for function-call system: '<Root>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  if (!Encoder_Angle_DW.obj.matlabCodegenIsDeleted) {
    Encoder_Angle_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
