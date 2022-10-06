/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dcmotor_transfer_func.c
 *
 * Code generated for Simulink model 'dcmotor_transfer_func'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep 30 17:17:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dcmotor_transfer_func.h"
#include "rtwtypes.h"
#include "dcmotor_transfer_func_private.h"

/* Block signals (default storage) */
B_dcmotor_transfer_func_T dcmotor_transfer_func_B;

/* Continuous states */
X_dcmotor_transfer_func_T dcmotor_transfer_func_X;

/* Block states (default storage) */
DW_dcmotor_transfer_func_T dcmotor_transfer_func_DW;

/* Real-time model */
static RT_MODEL_dcmotor_transfer_fun_T dcmotor_transfer_func_M_;
RT_MODEL_dcmotor_transfer_fun_T *const dcmotor_transfer_func_M =
  &dcmotor_transfer_func_M_;

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
  dcmotor_transfer_func_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  dcmotor_transfer_func_step();
  dcmotor_transfer_func_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  dcmotor_transfer_func_step();
  dcmotor_transfer_func_derivatives();

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

/* Model step function */
void dcmotor_transfer_func_step(void)
{
  real_T rtb_PulseGenerator;
  if (rtmIsMajorTimeStep(dcmotor_transfer_func_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&dcmotor_transfer_func_M->solverInfo,
                          ((dcmotor_transfer_func_M->Timing.clockTick0+1)*
      dcmotor_transfer_func_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(dcmotor_transfer_func_M)) {
    dcmotor_transfer_func_M->Timing.t[0] = rtsiGetT
      (&dcmotor_transfer_func_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  dcmotor_transfer_func_B.TransferFcn = 0.0;
  dcmotor_transfer_func_B.TransferFcn += dcmotor_transfer_func_P.TransferFcn_C *
    dcmotor_transfer_func_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(dcmotor_transfer_func_M)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    rtb_PulseGenerator = (dcmotor_transfer_func_DW.clockTickCounter <
                          dcmotor_transfer_func_P.PulseGenerator_Duty) &&
      (dcmotor_transfer_func_DW.clockTickCounter >= 0) ?
      dcmotor_transfer_func_P.PulseGenerator_Amp : 0.0;
    if (dcmotor_transfer_func_DW.clockTickCounter >=
        dcmotor_transfer_func_P.PulseGenerator_Period - 1.0) {
      dcmotor_transfer_func_DW.clockTickCounter = 0;
    } else {
      dcmotor_transfer_func_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Bias: '<Root>/Bias' */
    dcmotor_transfer_func_B.Bias = rtb_PulseGenerator +
      dcmotor_transfer_func_P.Bias_Bias;
  }

  if (rtmIsMajorTimeStep(dcmotor_transfer_func_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        dcmotor_transfer_func_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(dcmotor_transfer_func_M)) {/* Sample time: [0.005s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((dcmotor_transfer_func_M->Timing.clockTick1) * 0.005);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(dcmotor_transfer_func_M)) {
    rt_ertODEUpdateContinuousStates(&dcmotor_transfer_func_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++dcmotor_transfer_func_M->Timing.clockTick0;
    dcmotor_transfer_func_M->Timing.t[0] = rtsiGetSolverStopTime
      (&dcmotor_transfer_func_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      dcmotor_transfer_func_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void dcmotor_transfer_func_derivatives(void)
{
  XDot_dcmotor_transfer_func_T *_rtXdot;
  _rtXdot = ((XDot_dcmotor_transfer_func_T *) dcmotor_transfer_func_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = dcmotor_transfer_func_P.TransferFcn_A *
    dcmotor_transfer_func_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += dcmotor_transfer_func_B.Bias;
}

/* Model initialize function */
void dcmotor_transfer_func_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dcmotor_transfer_func_M->solverInfo,
                          &dcmotor_transfer_func_M->Timing.simTimeStep);
    rtsiSetTPtr(&dcmotor_transfer_func_M->solverInfo, &rtmGetTPtr
                (dcmotor_transfer_func_M));
    rtsiSetStepSizePtr(&dcmotor_transfer_func_M->solverInfo,
                       &dcmotor_transfer_func_M->Timing.stepSize0);
    rtsiSetdXPtr(&dcmotor_transfer_func_M->solverInfo,
                 &dcmotor_transfer_func_M->derivs);
    rtsiSetContStatesPtr(&dcmotor_transfer_func_M->solverInfo, (real_T **)
                         &dcmotor_transfer_func_M->contStates);
    rtsiSetNumContStatesPtr(&dcmotor_transfer_func_M->solverInfo,
      &dcmotor_transfer_func_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&dcmotor_transfer_func_M->solverInfo,
      &dcmotor_transfer_func_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&dcmotor_transfer_func_M->solverInfo,
      &dcmotor_transfer_func_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&dcmotor_transfer_func_M->solverInfo,
      &dcmotor_transfer_func_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&dcmotor_transfer_func_M->solverInfo,
                          (&rtmGetErrorStatus(dcmotor_transfer_func_M)));
    rtsiSetRTModelPtr(&dcmotor_transfer_func_M->solverInfo,
                      dcmotor_transfer_func_M);
  }

  rtsiSetSimTimeStep(&dcmotor_transfer_func_M->solverInfo, MAJOR_TIME_STEP);
  dcmotor_transfer_func_M->intgData.y = dcmotor_transfer_func_M->odeY;
  dcmotor_transfer_func_M->intgData.f[0] = dcmotor_transfer_func_M->odeF[0];
  dcmotor_transfer_func_M->intgData.f[1] = dcmotor_transfer_func_M->odeF[1];
  dcmotor_transfer_func_M->intgData.f[2] = dcmotor_transfer_func_M->odeF[2];
  dcmotor_transfer_func_M->contStates = ((X_dcmotor_transfer_func_T *)
    &dcmotor_transfer_func_X);
  rtsiSetSolverData(&dcmotor_transfer_func_M->solverInfo, (void *)
                    &dcmotor_transfer_func_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&dcmotor_transfer_func_M->solverInfo,
    false);
  rtsiSetSolverName(&dcmotor_transfer_func_M->solverInfo,"ode3");
  rtmSetTPtr(dcmotor_transfer_func_M, &dcmotor_transfer_func_M->Timing.tArray[0]);
  rtmSetTFinal(dcmotor_transfer_func_M, -1);
  dcmotor_transfer_func_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  dcmotor_transfer_func_M->Sizes.checksums[0] = (459587812U);
  dcmotor_transfer_func_M->Sizes.checksums[1] = (4219087551U);
  dcmotor_transfer_func_M->Sizes.checksums[2] = (3215710073U);
  dcmotor_transfer_func_M->Sizes.checksums[3] = (1304360736U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    dcmotor_transfer_func_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(dcmotor_transfer_func_M->extModeInfo,
      &dcmotor_transfer_func_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(dcmotor_transfer_func_M->extModeInfo,
                        dcmotor_transfer_func_M->Sizes.checksums);
    rteiSetTPtr(dcmotor_transfer_func_M->extModeInfo, rtmGetTPtr
                (dcmotor_transfer_func_M));
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  dcmotor_transfer_func_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void dcmotor_transfer_func_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
