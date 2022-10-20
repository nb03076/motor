/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave_PI_with_TF.c
 *
 * Code generated for Simulink model 'PWM_sinewave_PI_with_TF'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 17 22:04:39 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM_sinewave_PI_with_TF.h"
#include "rtwtypes.h"
#include "PWM_sinewave_PI_with_TF_private.h"
#include "PWM_sinewave_PI_with_TF_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_PWM_sinewave_PI_with_TF_T PWM_sinewave_PI_with_TF_B;

/* Continuous states */
X_PWM_sinewave_PI_with_TF_T PWM_sinewave_PI_with_TF_X;

/* Block states (default storage) */
DW_PWM_sinewave_PI_with_TF_T PWM_sinewave_PI_with_TF_DW;

/* Real-time model */
static RT_MODEL_PWM_sinewave_PI_with_T PWM_sinewave_PI_with_TF_M_;
RT_MODEL_PWM_sinewave_PI_with_T *const PWM_sinewave_PI_with_TF_M =
  &PWM_sinewave_PI_with_TF_M_;

/* Callback for Hardware Interrupt Block: '<S4>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <S4>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(PWM_sinewave_PI_with_TF_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

    /* Output and update for function-call system: '<S4>/Triggered Subsystem' */
    {
      boolean_T b_value;
      PWM_sinewave_PI_with_TF_M->Timing.clockTick2 =
        PWM_sinewave_PI_with_TF_M->Timing.clockTick0;

      /* MATLABSystem: '<S9>/Digital Input' */
      if (PWM_sinewave_PI_with_TF_DW.obj.SampleTime !=
          PWM_sinewave_PI_with_TF_P.DigitalInput_SampleTime) {
        PWM_sinewave_PI_with_TF_DW.obj.SampleTime =
          PWM_sinewave_PI_with_TF_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S9>/Sum' incorporates:
       *  Constant: '<S9>/Constant'
       *  Delay: '<S9>/Delay'
       *  Gain: '<S9>/Gain'
       *  MATLABSystem: '<S9>/Digital Input'
       *  Sum: '<S9>/Add'
       */
      PWM_sinewave_PI_with_TF_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)
        PWM_sinewave_PI_with_TF_P.Gain_Gain : 0) * 0.015625 -
        PWM_sinewave_PI_with_TF_P.Constant_Value;
      PWM_sinewave_PI_with_TF_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PWM_sinewave_PI_with_TF_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PWM_sinewave_PI_with_TF_step();
  PWM_sinewave_PI_with_TF_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PWM_sinewave_PI_with_TF_step();
  PWM_sinewave_PI_with_TF_derivatives();

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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
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
void PWM_sinewave_PI_with_TF_step(void)
{
  if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&PWM_sinewave_PI_with_TF_M->solverInfo,
                          ((PWM_sinewave_PI_with_TF_M->Timing.clockTick0+1)*
      PWM_sinewave_PI_with_TF_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PWM_sinewave_PI_with_TF_M)) {
    PWM_sinewave_PI_with_TF_M->Timing.t[0] = rtsiGetT
      (&PWM_sinewave_PI_with_TF_M->solverInfo);
  }

  {
    codertarget_arduinobase_inter_T *obj;
    real_T lastTime;
    real_T rtb_MathFunction;
    real_T *lastU;
    int32_T i;
    int8_T rtb_DataTypeConversion[10];
    int8_T rtb_Switch;
    int8_T s6_iter;
    uint8_T tmp;
    boolean_T DelayInput1_DSTATE;
    boolean_T rtb_FixPtRelationalOperator;
    if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/Constant'
       *  Constant: '<S5>/Constant1'
       *  Constant: '<S5>/Constant2'
       */
      if (PWM_sinewave_PI_with_TF_P.StairGenerator_RepeatPattern >
          PWM_sinewave_PI_with_TF_P.Switch_Threshold) {
        rtb_MathFunction = PWM_sinewave_PI_with_TF_P.Constant2_Value;
      } else {
        rtb_MathFunction = PWM_sinewave_PI_with_TF_P.Constant1_Value;
      }

      /* End of Switch: '<S5>/Switch' */

      /* Math: '<S5>/Math Function' incorporates:
       *  DigitalClock: '<S5>/Digital Clock'
       */
      rtb_MathFunction = rt_modd_snf
        (((PWM_sinewave_PI_with_TF_M->Timing.clockTick1) * 0.001),
         rtb_MathFunction);

      /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
       *  Constant: '<S5>/Time'
       *  RelationalOperator: '<S5>/Relational Operator'
       */
      for (i = 0; i < 10; i++) {
        rtb_DataTypeConversion[i] = (int8_T)(rtb_MathFunction >=
          PWM_sinewave_PI_with_TF_P.StairGenerator_TimeInput[i]);
      }

      /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

      /* Outputs for Iterator SubSystem: '<S5>/While Iterator Subsystem' incorporates:
       *  WhileIterator: '<S6>/While Iterator'
       */
      s6_iter = 1;

      /* InitializeConditions for UnitDelay: '<S7>/Delay Input1'
       *
       * Block description for '<S7>/Delay Input1':
       *
       *  Store in Global RAM
       */
      DelayInput1_DSTATE = PWM_sinewave_PI_with_TF_P.DetectFallNonpositive_vinit;
      do {
        rtb_FixPtRelationalOperator = DelayInput1_DSTATE;
        DelayInput1_DSTATE = (rtb_DataTypeConversion[s6_iter - 1] <=
                              PWM_sinewave_PI_with_TF_P.Constant_Value_j);
        rtb_FixPtRelationalOperator = ((int32_T)DelayInput1_DSTATE > (int32_T)
          rtb_FixPtRelationalOperator);
        if (rtb_FixPtRelationalOperator) {
          rtb_Switch = (int8_T)(s6_iter -
                                PWM_sinewave_PI_with_TF_P.Constant2_Value_k);
        } else if (rtb_MathFunction >=
                   PWM_sinewave_PI_with_TF_P.Switch1_Threshold) {
          rtb_Switch = PWM_sinewave_PI_with_TF_P.Constant1_Value_k;
        } else {
          rtb_Switch = PWM_sinewave_PI_with_TF_P.Constant3_Value;
        }

        s6_iter++;
      } while ((!rtb_FixPtRelationalOperator) && (s6_iter <= 10));

      /* End of Outputs for SubSystem: '<S5>/While Iterator Subsystem' */

      /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
       *  Constant: '<S5>/Output'
       *  Selector: '<S5>/Selector'
       */
      PWM_sinewave_PI_with_TF_B.DataTypeConversion1 =
        PWM_sinewave_PI_with_TF_P.Output_Value[rtb_Switch];

      /* Gain: '<S4>/Gain3' */
      PWM_sinewave_PI_with_TF_B.Gain3 = PWM_sinewave_PI_with_TF_P.Gain3_Gain *
        PWM_sinewave_PI_with_TF_DW.Delay_DSTATE;
    }

    /* Derivative: '<S4>/Derivative' */
    rtb_MathFunction = PWM_sinewave_PI_with_TF_M->Timing.t[0];
    if ((PWM_sinewave_PI_with_TF_DW.TimeStampA >= rtb_MathFunction) &&
        (PWM_sinewave_PI_with_TF_DW.TimeStampB >= rtb_MathFunction)) {
      /* Derivative: '<S4>/Derivative' */
      PWM_sinewave_PI_with_TF_B.Derivative = 0.0;
    } else {
      lastTime = PWM_sinewave_PI_with_TF_DW.TimeStampA;
      lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeA;
      if (PWM_sinewave_PI_with_TF_DW.TimeStampA <
          PWM_sinewave_PI_with_TF_DW.TimeStampB) {
        if (PWM_sinewave_PI_with_TF_DW.TimeStampB < rtb_MathFunction) {
          lastTime = PWM_sinewave_PI_with_TF_DW.TimeStampB;
          lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeB;
        }
      } else if (PWM_sinewave_PI_with_TF_DW.TimeStampA >= rtb_MathFunction) {
        lastTime = PWM_sinewave_PI_with_TF_DW.TimeStampB;
        lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeB;
      }

      /* Derivative: '<S4>/Derivative' */
      PWM_sinewave_PI_with_TF_B.Derivative = (PWM_sinewave_PI_with_TF_B.Gain3 - *
        lastU) / (rtb_MathFunction - lastTime);
    }

    /* End of Derivative: '<S4>/Derivative' */
    if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
      /* Memory: '<S3>/Memory' */
      PWM_sinewave_PI_with_TF_B.Memory =
        PWM_sinewave_PI_with_TF_DW.Memory_PreviousInput;
    }

    /* Sum: '<Root>/Add' incorporates:
     *  TransferFcn: '<Root>/Transfer Fcn2'
     */
    rtb_MathFunction = PWM_sinewave_PI_with_TF_P.TransferFcn2_C *
      PWM_sinewave_PI_with_TF_X.TransferFcn2_CSTATE -
      PWM_sinewave_PI_with_TF_B.Derivative;

    /* Sum: '<S3>/Add' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S3>/Gain4'
     */
    PWM_sinewave_PI_with_TF_B.Add = PWM_sinewave_PI_with_TF_P.Gain1_Gain *
      rtb_MathFunction * PWM_sinewave_PI_with_TF_P.Gain4_Gain +
      PWM_sinewave_PI_with_TF_B.Memory;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Gain: '<S3>/Gain2'
     */
    PWM_sinewave_PI_with_TF_B.Saturation = PWM_sinewave_PI_with_TF_P.Gain2_Gain *
      rtb_MathFunction + PWM_sinewave_PI_with_TF_B.Add;

    /* Saturate: '<Root>/Saturation' */
    if (PWM_sinewave_PI_with_TF_B.Saturation >
        PWM_sinewave_PI_with_TF_P.Saturation_UpperSat) {
      /* Sum: '<S3>/Sum1' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      PWM_sinewave_PI_with_TF_B.Saturation =
        PWM_sinewave_PI_with_TF_P.Saturation_UpperSat;
    } else if (PWM_sinewave_PI_with_TF_B.Saturation <
               PWM_sinewave_PI_with_TF_P.Saturation_LowerSat) {
      /* Sum: '<S3>/Sum1' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      PWM_sinewave_PI_with_TF_B.Saturation =
        PWM_sinewave_PI_with_TF_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Signum: '<S1>/Sign' */
    if (rtIsNaN(PWM_sinewave_PI_with_TF_B.Saturation)) {
      rtb_MathFunction = PWM_sinewave_PI_with_TF_B.Saturation;
    } else if (PWM_sinewave_PI_with_TF_B.Saturation < 0.0) {
      rtb_MathFunction = -1.0;
    } else {
      rtb_MathFunction = (PWM_sinewave_PI_with_TF_B.Saturation > 0.0);
    }

    /* End of Signum: '<S1>/Sign' */

    /* MATLABSystem: '<S1>/Digital Output1' incorporates:
     *  Bias: '<S1>/Bias'
     *  Gain: '<S1>/Gain2'
     */
    rtb_MathFunction = rt_roundd_snf((rtb_MathFunction +
      PWM_sinewave_PI_with_TF_P.Bias_Bias) *
      PWM_sinewave_PI_with_TF_P.Gain2_Gain_e);
    if (rtb_MathFunction < 256.0) {
      if (rtb_MathFunction >= 0.0) {
        tmp = (uint8_T)rtb_MathFunction;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(49, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output1' */

    /* MATLABSystem: '<S1>/PWM' */
    obj = &PWM_sinewave_PI_with_TF_DW.obj_d;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);

    /* Abs: '<S1>/Abs' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtb_MathFunction = fabs(PWM_sinewave_PI_with_TF_P.Gain1_Gain_a *
      PWM_sinewave_PI_with_TF_B.Saturation);

    /* MATLABSystem: '<S1>/PWM' */
    if (!(rtb_MathFunction <= 255.0)) {
      rtb_MathFunction = 255.0;
    }

    MW_PWM_SetDutyCycle
      (PWM_sinewave_PI_with_TF_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
       rtb_MathFunction);
    if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
    }

    /* Step: '<S1>/Step' */
    if (PWM_sinewave_PI_with_TF_M->Timing.t[0] <
        PWM_sinewave_PI_with_TF_P.Step_Time) {
      rtb_MathFunction = PWM_sinewave_PI_with_TF_P.Step_Y0;
    } else {
      rtb_MathFunction = PWM_sinewave_PI_with_TF_P.Step_YFinal;
    }

    /* End of Step: '<S1>/Step' */

    /* MATLABSystem: '<S1>/Digital Output' */
    rtb_MathFunction = rt_roundd_snf(rtb_MathFunction);
    if (rtb_MathFunction < 256.0) {
      if (rtb_MathFunction >= 0.0) {
        tmp = (uint8_T)rtb_MathFunction;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(48, tmp);

    /* End of MATLABSystem: '<S1>/Digital Output' */
  }

  if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S4>/Derivative' */
    if (PWM_sinewave_PI_with_TF_DW.TimeStampA == (rtInf)) {
      PWM_sinewave_PI_with_TF_DW.TimeStampA =
        PWM_sinewave_PI_with_TF_M->Timing.t[0];
      lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeA;
    } else if (PWM_sinewave_PI_with_TF_DW.TimeStampB == (rtInf)) {
      PWM_sinewave_PI_with_TF_DW.TimeStampB =
        PWM_sinewave_PI_with_TF_M->Timing.t[0];
      lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeB;
    } else if (PWM_sinewave_PI_with_TF_DW.TimeStampA <
               PWM_sinewave_PI_with_TF_DW.TimeStampB) {
      PWM_sinewave_PI_with_TF_DW.TimeStampA =
        PWM_sinewave_PI_with_TF_M->Timing.t[0];
      lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeA;
    } else {
      PWM_sinewave_PI_with_TF_DW.TimeStampB =
        PWM_sinewave_PI_with_TF_M->Timing.t[0];
      lastU = &PWM_sinewave_PI_with_TF_DW.LastUAtTimeB;
    }

    *lastU = PWM_sinewave_PI_with_TF_B.Gain3;

    /* End of Update for Derivative: '<S4>/Derivative' */
    if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
      /* Update for Memory: '<S3>/Memory' */
      PWM_sinewave_PI_with_TF_DW.Memory_PreviousInput =
        PWM_sinewave_PI_with_TF_B.Add;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        PWM_sinewave_PI_with_TF_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {/* Sample time: [0.001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((PWM_sinewave_PI_with_TF_M->Timing.clockTick1) * 0.001);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PWM_sinewave_PI_with_TF_M)) {
    rt_ertODEUpdateContinuousStates(&PWM_sinewave_PI_with_TF_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++PWM_sinewave_PI_with_TF_M->Timing.clockTick0;
    PWM_sinewave_PI_with_TF_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PWM_sinewave_PI_with_TF_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PWM_sinewave_PI_with_TF_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PWM_sinewave_PI_with_TF_derivatives(void)
{
  XDot_PWM_sinewave_PI_with_TF_T *_rtXdot;
  _rtXdot = ((XDot_PWM_sinewave_PI_with_TF_T *)
             PWM_sinewave_PI_with_TF_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = PWM_sinewave_PI_with_TF_P.TransferFcn2_A *
    PWM_sinewave_PI_with_TF_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += PWM_sinewave_PI_with_TF_B.DataTypeConversion1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = PWM_sinewave_PI_with_TF_P.TransferFcn1_A *
    PWM_sinewave_PI_with_TF_X.TransferFcn1_CSTATE;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = PWM_sinewave_PI_with_TF_P.TransferFcn3_A *
    PWM_sinewave_PI_with_TF_X.TransferFcn3_CSTATE;
}

/* Model initialize function */
void PWM_sinewave_PI_with_TF_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
                          &PWM_sinewave_PI_with_TF_M->Timing.simTimeStep);
    rtsiSetTPtr(&PWM_sinewave_PI_with_TF_M->solverInfo, &rtmGetTPtr
                (PWM_sinewave_PI_with_TF_M));
    rtsiSetStepSizePtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
                       &PWM_sinewave_PI_with_TF_M->Timing.stepSize0);
    rtsiSetdXPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
                 &PWM_sinewave_PI_with_TF_M->derivs);
    rtsiSetContStatesPtr(&PWM_sinewave_PI_with_TF_M->solverInfo, (real_T **)
                         &PWM_sinewave_PI_with_TF_M->contStates);
    rtsiSetNumContStatesPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
      &PWM_sinewave_PI_with_TF_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
      &PWM_sinewave_PI_with_TF_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
      &PWM_sinewave_PI_with_TF_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
      &PWM_sinewave_PI_with_TF_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
                          (&rtmGetErrorStatus(PWM_sinewave_PI_with_TF_M)));
    rtsiSetRTModelPtr(&PWM_sinewave_PI_with_TF_M->solverInfo,
                      PWM_sinewave_PI_with_TF_M);
  }

  rtsiSetSimTimeStep(&PWM_sinewave_PI_with_TF_M->solverInfo, MAJOR_TIME_STEP);
  PWM_sinewave_PI_with_TF_M->intgData.y = PWM_sinewave_PI_with_TF_M->odeY;
  PWM_sinewave_PI_with_TF_M->intgData.f[0] = PWM_sinewave_PI_with_TF_M->odeF[0];
  PWM_sinewave_PI_with_TF_M->intgData.f[1] = PWM_sinewave_PI_with_TF_M->odeF[1];
  PWM_sinewave_PI_with_TF_M->intgData.f[2] = PWM_sinewave_PI_with_TF_M->odeF[2];
  PWM_sinewave_PI_with_TF_M->contStates = ((X_PWM_sinewave_PI_with_TF_T *)
    &PWM_sinewave_PI_with_TF_X);
  rtsiSetSolverData(&PWM_sinewave_PI_with_TF_M->solverInfo, (void *)
                    &PWM_sinewave_PI_with_TF_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&PWM_sinewave_PI_with_TF_M->solverInfo,
    false);
  rtsiSetSolverName(&PWM_sinewave_PI_with_TF_M->solverInfo,"ode3");
  rtmSetTPtr(PWM_sinewave_PI_with_TF_M,
             &PWM_sinewave_PI_with_TF_M->Timing.tArray[0]);
  rtmSetTFinal(PWM_sinewave_PI_with_TF_M, -1);
  PWM_sinewave_PI_with_TF_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  PWM_sinewave_PI_with_TF_M->Sizes.checksums[0] = (1639584044U);
  PWM_sinewave_PI_with_TF_M->Sizes.checksums[1] = (2084059757U);
  PWM_sinewave_PI_with_TF_M->Sizes.checksums[2] = (1680514916U);
  PWM_sinewave_PI_with_TF_M->Sizes.checksums[3] = (1511534878U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    PWM_sinewave_PI_with_TF_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &PWM_sinewave_PI_with_TF_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &PWM_sinewave_PI_with_TF_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PWM_sinewave_PI_with_TF_M->extModeInfo,
      &PWM_sinewave_PI_with_TF_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PWM_sinewave_PI_with_TF_M->extModeInfo,
                        PWM_sinewave_PI_with_TF_M->Sizes.checksums);
    rteiSetTPtr(PWM_sinewave_PI_with_TF_M->extModeInfo, rtmGetTPtr
                (PWM_sinewave_PI_with_TF_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Derivative: '<S4>/Derivative' */
    PWM_sinewave_PI_with_TF_DW.TimeStampA = (rtInf);
    PWM_sinewave_PI_with_TF_DW.TimeStampB = (rtInf);

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
    PWM_sinewave_PI_with_TF_X.TransferFcn2_CSTATE = 0.0;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    PWM_sinewave_PI_with_TF_DW.Memory_PreviousInput =
      PWM_sinewave_PI_with_TF_P.Memory_InitialCondition;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
    PWM_sinewave_PI_with_TF_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
    PWM_sinewave_PI_with_TF_X.TransferFcn3_CSTATE = 0.0;

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' incorporates:
     *  SubSystem: '<S4>/Triggered Subsystem'
     */

    /* System initialize for function-call system: '<S4>/Triggered Subsystem' */
    PWM_sinewave_PI_with_TF_M->Timing.clockTick2 =
      PWM_sinewave_PI_with_TF_M->Timing.clockTick0;

    /* Start for MATLABSystem: '<S9>/Digital Input' */
    PWM_sinewave_PI_with_TF_DW.obj.matlabCodegenIsDeleted = false;
    PWM_sinewave_PI_with_TF_DW.obj.SampleTime =
      PWM_sinewave_PI_with_TF_P.DigitalInput_SampleTime;
    PWM_sinewave_PI_with_TF_DW.obj.isInitialized = 1;
    digitalIOSetup(51, 0);
    PWM_sinewave_PI_with_TF_DW.obj.isSetupComplete = true;

    /* SystemInitialize for Outport: '<S9>/Out1' incorporates:
     *  Delay: '<S9>/Delay'
     *  Sum: '<S9>/Sum'
     */
    PWM_sinewave_PI_with_TF_DW.Delay_DSTATE = PWM_sinewave_PI_with_TF_P.Out1_Y0;
    ;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    PWM_sinewave_PI_with_TF_DW.obj_p.matlabCodegenIsDeleted = true;
    PWM_sinewave_PI_with_TF_DW.obj_p.isInitialized = 0;
    PWM_sinewave_PI_with_TF_DW.obj_p.matlabCodegenIsDeleted = false;
    PWM_sinewave_PI_with_TF_DW.obj_p.isSetupComplete = false;
    PWM_sinewave_PI_with_TF_DW.obj_p.isInitialized = 1;
    digitalIOSetup(49, 1);
    PWM_sinewave_PI_with_TF_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    PWM_sinewave_PI_with_TF_DW.obj_d.matlabCodegenIsDeleted = true;
    PWM_sinewave_PI_with_TF_DW.obj_d.isInitialized = 0;
    PWM_sinewave_PI_with_TF_DW.obj_d.matlabCodegenIsDeleted = false;
    obj = &PWM_sinewave_PI_with_TF_DW.obj_d;
    PWM_sinewave_PI_with_TF_DW.obj_d.isSetupComplete = false;
    PWM_sinewave_PI_with_TF_DW.obj_d.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    PWM_sinewave_PI_with_TF_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    PWM_sinewave_PI_with_TF_DW.obj_o.matlabCodegenIsDeleted = true;
    PWM_sinewave_PI_with_TF_DW.obj_o.isInitialized = 0;
    PWM_sinewave_PI_with_TF_DW.obj_o.matlabCodegenIsDeleted = false;
    PWM_sinewave_PI_with_TF_DW.obj_o.isSetupComplete = false;
    PWM_sinewave_PI_with_TF_DW.obj_o.isInitialized = 1;
    digitalIOSetup(48, 1);
    PWM_sinewave_PI_with_TF_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void PWM_sinewave_PI_with_TF_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

  /* Terminate for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' incorporates:
   *  SubSystem: '<S4>/Triggered Subsystem'
   */
  /* Termination for function-call system: '<S4>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S9>/Digital Input' */
  if (!PWM_sinewave_PI_with_TF_DW.obj.matlabCodegenIsDeleted) {
    PWM_sinewave_PI_with_TF_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!PWM_sinewave_PI_with_TF_DW.obj_p.matlabCodegenIsDeleted) {
    PWM_sinewave_PI_with_TF_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &PWM_sinewave_PI_with_TF_DW.obj_d;
  if (!PWM_sinewave_PI_with_TF_DW.obj_d.matlabCodegenIsDeleted) {
    PWM_sinewave_PI_with_TF_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PWM_sinewave_PI_with_TF_DW.obj_d.isInitialized == 1) &&
        PWM_sinewave_PI_with_TF_DW.obj_d.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle
        (PWM_sinewave_PI_with_TF_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close(PWM_sinewave_PI_with_TF_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!PWM_sinewave_PI_with_TF_DW.obj_o.matlabCodegenIsDeleted) {
    PWM_sinewave_PI_with_TF_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
