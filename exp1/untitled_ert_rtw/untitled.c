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
 * C/C++ source code generated on : Thu Sep 15 16:40:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <Root>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(untitled_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Triggered Subsystem' */
    {
      boolean_T b_value;
      untitled_M->Timing.clockTick2 = untitled_M->Timing.clockTick0;

      /* MATLABSystem: '<S1>/Digital Input' */
      if (untitled_DW.obj.SampleTime != untitled_P.DigitalInput_SampleTime) {
        untitled_DW.obj.SampleTime = untitled_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S1>/Sum' incorporates:
       *  Constant: '<S1>/Constant'
       *  Delay: '<S1>/Delay'
       *  Gain: '<S1>/Gain'
       *  MATLABSystem: '<S1>/Digital Input'
       *  Sum: '<S1>/Add'
       */
      untitled_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)
        untitled_P.Gain_Gain_a : 0) * 0.015625 - untitled_P.Constant_Value;
      untitled_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/* Model step function */
void untitled_step(void)
{
  {
    real_T lastTime;
    real_T tmp;
    real_T *lastU;

    /* Gain: '<Root>/Gain' */
    untitled_B.Gain = untitled_P.Gain_Gain * untitled_DW.Delay_DSTATE;

    /* Derivative: '<Root>/Derivative' */
    tmp = untitled_M->Timing.t[0];
    if ((untitled_DW.TimeStampA >= tmp) && (untitled_DW.TimeStampB >= tmp)) {
      /* Derivative: '<Root>/Derivative' */
      untitled_B.Derivative = 0.0;
    } else {
      lastTime = untitled_DW.TimeStampA;
      lastU = &untitled_DW.LastUAtTimeA;
      if (untitled_DW.TimeStampA < untitled_DW.TimeStampB) {
        if (untitled_DW.TimeStampB < tmp) {
          lastTime = untitled_DW.TimeStampB;
          lastU = &untitled_DW.LastUAtTimeB;
        }
      } else if (untitled_DW.TimeStampA >= tmp) {
        lastTime = untitled_DW.TimeStampB;
        lastU = &untitled_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative' */
      untitled_B.Derivative = (untitled_B.Gain - *lastU) / (tmp - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (untitled_DW.TimeStampA == (rtInf)) {
      untitled_DW.TimeStampA = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeA;
    } else if (untitled_DW.TimeStampB == (rtInf)) {
      untitled_DW.TimeStampB = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeB;
    } else if (untitled_DW.TimeStampA < untitled_DW.TimeStampB) {
      untitled_DW.TimeStampA = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeA;
    } else {
      untitled_DW.TimeStampB = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeB;
    }

    *lastU = untitled_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

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
  untitled_M->Sizes.checksums[0] = (2841065108U);
  untitled_M->Sizes.checksums[1] = (1289396072U);
  untitled_M->Sizes.checksums[2] = (2850110866U);
  untitled_M->Sizes.checksums[3] = (1763401494U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&untitled_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&untitled_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  untitled_DW.TimeStampA = (rtInf);
  untitled_DW.TimeStampB = (rtInf);

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Triggered Subsystem' */
  untitled_M->Timing.clockTick2 = untitled_M->Timing.clockTick0;

  /* Start for MATLABSystem: '<S1>/Digital Input' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.DigitalInput_SampleTime;
  untitled_DW.obj.isInitialized = 1;
  digitalIOSetup(51, 0);
  untitled_DW.obj.isSetupComplete = true;

  /* SystemInitialize for Outport: '<S1>/Out1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Sum: '<S1>/Sum'
   */
  untitled_DW.Delay_DSTATE = untitled_P.Out1_Y0;
  ;

  /* Attach callback function */
  /* Changes made wrt g2141701, this change was needed to make the
   * architecture simpler for adding new boards.
   */
  attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem'
   */

  /* Termination for function-call system: '<Root>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
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
