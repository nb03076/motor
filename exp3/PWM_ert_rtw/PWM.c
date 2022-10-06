/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM.c
 *
 * Code generated for Simulink model 'PWM'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep 30 17:20:51 2022
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

/* Continuous states */
X_PWM_T PWM_X;

/* Block states (default storage) */
DW_PWM_T PWM_DW;

/* Real-time model */
static RT_MODEL_PWM_T PWM_M_;
RT_MODEL_PWM_T *const PWM_M = &PWM_M_;

/* Callback for Hardware Interrupt Block: '<S2>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <S2>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(PWM_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

    /* Output and update for function-call system: '<S2>/Triggered Subsystem' */
    {
      boolean_T b_value;
      PWM_M->Timing.clockTick2 = PWM_M->Timing.clockTick0;

      /* MATLABSystem: '<S3>/Digital Input' */
      if (PWM_DW.obj.SampleTime != PWM_P.DigitalInput_SampleTime) {
        PWM_DW.obj.SampleTime = PWM_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S3>/Sum' incorporates:
       *  Constant: '<S3>/Constant'
       *  Delay: '<S3>/Delay'
       *  Gain: '<S3>/Gain'
       *  MATLABSystem: '<S3>/Digital Input'
       *  Sum: '<S3>/Add'
       */
      PWM_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)PWM_P.Gain_Gain_d : 0) *
        0.015625 - PWM_P.Constant_Value;
      PWM_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PWM_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PWM_step();
  PWM_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PWM_step();
  PWM_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
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
  if (rtmIsMajorTimeStep(PWM_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&PWM_M->solverInfo,((PWM_M->Timing.clockTick0+1)*
      PWM_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PWM_M)) {
    PWM_M->Timing.t[0] = rtsiGetT(&PWM_M->solverInfo);
  }

  {
    codertarget_arduinobase_inter_T *obj;
    real_T lastTime;
    real_T rtb_Gain1;
    real_T *lastU;
    uint8_T tmp;
    if (rtmIsMajorTimeStep(PWM_M)) {
      /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
      rtb_Gain1 = (PWM_DW.clockTickCounter < PWM_P.PulseGenerator_Duty) &&
        (PWM_DW.clockTickCounter >= 0) ? PWM_P.PulseGenerator_Amp : 0.0;
      if (PWM_DW.clockTickCounter >= PWM_P.PulseGenerator_Period - 1.0) {
        PWM_DW.clockTickCounter = 0;
      } else {
        PWM_DW.clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

      /* Bias: '<Root>/Bias' */
      PWM_B.Saturation = rtb_Gain1 + PWM_P.Bias_Bias;

      /* Saturate: '<Root>/Saturation' */
      if (PWM_B.Saturation > PWM_P.Saturation_UpperSat) {
        /* Bias: '<Root>/Bias' incorporates:
         *  Saturate: '<Root>/Saturation'
         */
        PWM_B.Saturation = PWM_P.Saturation_UpperSat;
      } else if (PWM_B.Saturation < PWM_P.Saturation_LowerSat) {
        /* Bias: '<Root>/Bias' incorporates:
         *  Saturate: '<Root>/Saturation'
         */
        PWM_B.Saturation = PWM_P.Saturation_LowerSat;
      }

      /* End of Saturate: '<Root>/Saturation' */

      /* Signum: '<S1>/Sign' */
      if (rtIsNaN(PWM_B.Saturation)) {
        rtb_Gain1 = PWM_B.Saturation;
      } else if (PWM_B.Saturation < 0.0) {
        rtb_Gain1 = -1.0;
      } else {
        rtb_Gain1 = (PWM_B.Saturation > 0.0);
      }

      /* End of Signum: '<S1>/Sign' */

      /* MATLABSystem: '<S1>/Digital Output1' incorporates:
       *  Bias: '<S1>/Bias'
       *  Gain: '<S1>/Gain'
       *  Gain: '<S1>/Gain2'
       */
      rtb_Gain1 = rt_roundd_snf((PWM_P.Gain_Gain * rtb_Gain1 + PWM_P.Bias_Bias_f)
        * PWM_P.Gain2_Gain);
      if (rtb_Gain1 < 256.0) {
        if (rtb_Gain1 >= 0.0) {
          tmp = (uint8_T)rtb_Gain1;
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
      rtb_Gain1 = fabs(PWM_P.Gain1_Gain * PWM_B.Saturation);

      /* MATLABSystem: '<S1>/PWM' */
      if (!(rtb_Gain1 <= 255.0)) {
        rtb_Gain1 = 255.0;
      }

      MW_PWM_SetDutyCycle(PWM_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, rtb_Gain1);
    }

    /* Step: '<S1>/Step' */
    if (PWM_M->Timing.t[0] < PWM_P.Step_Time) {
      rtb_Gain1 = PWM_P.Step_Y0;
    } else {
      rtb_Gain1 = PWM_P.Step_YFinal;
    }

    /* End of Step: '<S1>/Step' */

    /* MATLABSystem: '<S1>/Digital Output' */
    rtb_Gain1 = rt_roundd_snf(rtb_Gain1);
    if (rtb_Gain1 < 256.0) {
      if (rtb_Gain1 >= 0.0) {
        tmp = (uint8_T)rtb_Gain1;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(48, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output' */
    if (rtmIsMajorTimeStep(PWM_M)) {
      /* Gain: '<S2>/Gain3' */
      PWM_B.Gain3 = PWM_P.Gain3_Gain * PWM_DW.Delay_DSTATE;
    }

    /* Derivative: '<S2>/Derivative' */
    rtb_Gain1 = PWM_M->Timing.t[0];
    if ((PWM_DW.TimeStampA >= rtb_Gain1) && (PWM_DW.TimeStampB >= rtb_Gain1)) {
      /* Derivative: '<S2>/Derivative' */
      PWM_B.Derivative = 0.0;
    } else {
      lastTime = PWM_DW.TimeStampA;
      lastU = &PWM_DW.LastUAtTimeA;
      if (PWM_DW.TimeStampA < PWM_DW.TimeStampB) {
        if (PWM_DW.TimeStampB < rtb_Gain1) {
          lastTime = PWM_DW.TimeStampB;
          lastU = &PWM_DW.LastUAtTimeB;
        }
      } else if (PWM_DW.TimeStampA >= rtb_Gain1) {
        lastTime = PWM_DW.TimeStampB;
        lastU = &PWM_DW.LastUAtTimeB;
      }

      /* Derivative: '<S2>/Derivative' */
      PWM_B.Derivative = (PWM_B.Gain3 - *lastU) / (rtb_Gain1 - lastTime);
    }

    /* End of Derivative: '<S2>/Derivative' */
    if (rtmIsMajorTimeStep(PWM_M)) {
    }

    /* TransferFcn: '<Root>/Transfer Fcn' */
    PWM_B.TransferFcn = 0.0;
    PWM_B.TransferFcn += PWM_P.TransferFcn_C * PWM_X.TransferFcn_CSTATE;
    if (rtmIsMajorTimeStep(PWM_M)) {
    }
  }

  if (rtmIsMajorTimeStep(PWM_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S2>/Derivative' */
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

    /* End of Update for Derivative: '<S2>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
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

    if (rtmIsMajorTimeStep(PWM_M)) {   /* Sample time: [0.005s, 0.0s] */
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
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PWM_M)) {
    rt_ertODEUpdateContinuousStates(&PWM_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++PWM_M->Timing.clockTick0;
    PWM_M->Timing.t[0] = rtsiGetSolverStopTime(&PWM_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PWM_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PWM_derivatives(void)
{
  XDot_PWM_T *_rtXdot;
  _rtXdot = ((XDot_PWM_T *) PWM_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = PWM_P.TransferFcn_A * PWM_X.TransferFcn_CSTATE;
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
    rtsiSetdXPtr(&PWM_M->solverInfo, &PWM_M->derivs);
    rtsiSetContStatesPtr(&PWM_M->solverInfo, (real_T **) &PWM_M->contStates);
    rtsiSetNumContStatesPtr(&PWM_M->solverInfo, &PWM_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PWM_M->solverInfo,
      &PWM_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PWM_M->solverInfo,
      &PWM_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PWM_M->solverInfo,
      &PWM_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PWM_M->solverInfo, (&rtmGetErrorStatus(PWM_M)));
    rtsiSetRTModelPtr(&PWM_M->solverInfo, PWM_M);
  }

  rtsiSetSimTimeStep(&PWM_M->solverInfo, MAJOR_TIME_STEP);
  PWM_M->intgData.y = PWM_M->odeY;
  PWM_M->intgData.f[0] = PWM_M->odeF[0];
  PWM_M->intgData.f[1] = PWM_M->odeF[1];
  PWM_M->intgData.f[2] = PWM_M->odeF[2];
  PWM_M->contStates = ((X_PWM_T *) &PWM_X);
  rtsiSetSolverData(&PWM_M->solverInfo, (void *)&PWM_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&PWM_M->solverInfo, false);
  rtsiSetSolverName(&PWM_M->solverInfo,"ode3");
  rtmSetTPtr(PWM_M, &PWM_M->Timing.tArray[0]);
  rtmSetTFinal(PWM_M, -1);
  PWM_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  PWM_M->Sizes.checksums[0] = (3074696099U);
  PWM_M->Sizes.checksums[1] = (3230185716U);
  PWM_M->Sizes.checksums[2] = (3452806129U);
  PWM_M->Sizes.checksums[3] = (810846939U);

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

    /* InitializeConditions for Derivative: '<S2>/Derivative' */
    PWM_DW.TimeStampA = (rtInf);
    PWM_DW.TimeStampB = (rtInf);

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    PWM_X.TransferFcn_CSTATE = 0.0;

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' incorporates:
     *  SubSystem: '<S2>/Triggered Subsystem'
     */

    /* System initialize for function-call system: '<S2>/Triggered Subsystem' */
    PWM_M->Timing.clockTick2 = PWM_M->Timing.clockTick0;

    /* Start for MATLABSystem: '<S3>/Digital Input' */
    PWM_DW.obj.matlabCodegenIsDeleted = false;
    PWM_DW.obj.SampleTime = PWM_P.DigitalInput_SampleTime;
    PWM_DW.obj.isInitialized = 1;
    digitalIOSetup(51, 0);
    PWM_DW.obj.isSetupComplete = true;

    /* SystemInitialize for Outport: '<S3>/Out1' incorporates:
     *  Delay: '<S3>/Delay'
     *  Sum: '<S3>/Sum'
     */
    PWM_DW.Delay_DSTATE = PWM_P.Out1_Y0;
    ;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

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
  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */

  /* Terminate for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' incorporates:
   *  SubSystem: '<S2>/Triggered Subsystem'
   */
  /* Termination for function-call system: '<S2>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S3>/Digital Input' */
  if (!PWM_DW.obj.matlabCodegenIsDeleted) {
    PWM_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S2>/External Interrupt' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
