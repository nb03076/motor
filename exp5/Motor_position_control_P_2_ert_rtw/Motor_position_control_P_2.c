/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_position_control_P_2.c
 *
 * Code generated for Simulink model 'Motor_position_control_P_2'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 20 16:31:33 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_position_control_P_2.h"
#include "rtwtypes.h"
#include "Motor_position_control_P_2_private.h"
#include "Motor_position_control_P_2_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_Motor_position_control_P_2_T Motor_position_control_P_2_B;

/* Block states (default storage) */
DW_Motor_position_control_P_2_T Motor_position_control_P_2_DW;

/* Real-time model */
static RT_MODEL_Motor_position_contr_T Motor_position_control_P_2_M_;
RT_MODEL_Motor_position_contr_T *const Motor_position_control_P_2_M =
  &Motor_position_control_P_2_M_;

/* Callback for Hardware Interrupt Block: '<S3>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <S3>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Motor_position_control_P_2_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

    /* Output and update for function-call system: '<S3>/Triggered Subsystem' */
    {
      boolean_T b_value;
      Motor_position_control_P_2_M->Timing.clockTick2 =
        Motor_position_control_P_2_M->Timing.clockTick0;

      /* MATLABSystem: '<S8>/Digital Input' */
      if (Motor_position_control_P_2_DW.obj.SampleTime !=
          Motor_position_control_P_2_P.DigitalInput_SampleTime) {
        Motor_position_control_P_2_DW.obj.SampleTime =
          Motor_position_control_P_2_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S8>/Sum' incorporates:
       *  Constant: '<S8>/Constant'
       *  Delay: '<S8>/Delay'
       *  Gain: '<S8>/Gain'
       *  MATLABSystem: '<S8>/Digital Input'
       *  Sum: '<S8>/Add'
       */
      Motor_position_control_P_2_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)
        Motor_position_control_P_2_P.Gain_Gain : 0) * 0.015625 -
        Motor_position_control_P_2_P.Constant_Value;
      Motor_position_control_P_2_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */
  }
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
void Motor_position_control_P_2_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T lastTime;
    real_T rtb_MathFunction;
    real_T *lastU;
    int32_T i;
    int8_T rtb_DataTypeConversion[7];
    int8_T rtb_Switch;
    int8_T s5_iter;
    uint8_T tmp;
    boolean_T DelayInput1_DSTATE;
    boolean_T rtb_FixPtRelationalOperator;

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     */
    if (Motor_position_control_P_2_P.StairGenerator_RepeatPattern >
        Motor_position_control_P_2_P.Switch_Threshold) {
      rtb_MathFunction = Motor_position_control_P_2_P.Constant2_Value;
    } else {
      rtb_MathFunction = Motor_position_control_P_2_P.Constant1_Value;
    }

    /* End of Switch: '<S4>/Switch' */

    /* Math: '<S4>/Math Function' incorporates:
     *  DigitalClock: '<S4>/Digital Clock'
     */
    rtb_MathFunction = rt_modd_snf
      (((Motor_position_control_P_2_M->Timing.clockTick1) * 0.001),
       rtb_MathFunction);

    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Time'
     *  RelationalOperator: '<S4>/Relational Operator'
     */
    for (i = 0; i < 7; i++) {
      rtb_DataTypeConversion[i] = (int8_T)(rtb_MathFunction >=
        Motor_position_control_P_2_P.StairGenerator_TimeInput[i]);
    }

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* Outputs for Iterator SubSystem: '<S4>/While Iterator Subsystem' incorporates:
     *  WhileIterator: '<S5>/While Iterator'
     */
    s5_iter = 1;

    /* InitializeConditions for UnitDelay: '<S6>/Delay Input1'
     *
     * Block description for '<S6>/Delay Input1':
     *
     *  Store in Global RAM
     */
    DelayInput1_DSTATE =
      Motor_position_control_P_2_P.DetectFallNonpositive_vinit;
    do {
      rtb_FixPtRelationalOperator = DelayInput1_DSTATE;
      DelayInput1_DSTATE = (rtb_DataTypeConversion[s5_iter - 1] <=
                            Motor_position_control_P_2_P.Constant_Value_j);
      rtb_FixPtRelationalOperator = ((int32_T)DelayInput1_DSTATE > (int32_T)
        rtb_FixPtRelationalOperator);
      if (rtb_FixPtRelationalOperator) {
        rtb_Switch = (int8_T)(s5_iter -
                              Motor_position_control_P_2_P.Constant2_Value_k);
      } else if (rtb_MathFunction >=
                 Motor_position_control_P_2_P.Switch1_Threshold) {
        rtb_Switch = Motor_position_control_P_2_P.Constant1_Value_k;
      } else {
        rtb_Switch = Motor_position_control_P_2_P.Constant3_Value;
      }

      s5_iter++;
    } while ((!rtb_FixPtRelationalOperator) && (s5_iter <= 7));

    /* End of Outputs for SubSystem: '<S4>/While Iterator Subsystem' */

    /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
     *  Constant: '<S4>/Output'
     *  Selector: '<S4>/Selector'
     */
    Motor_position_control_P_2_B.DataTypeConversion1 =
      Motor_position_control_P_2_P.Output_Value[rtb_Switch];

    /* Gain: '<S3>/Gain3' */
    Motor_position_control_P_2_B.Gain3 = Motor_position_control_P_2_P.Gain3_Gain
      * Motor_position_control_P_2_DW.Delay_DSTATE;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Sum: '<Root>/Add'
     */
    Motor_position_control_P_2_B.Saturation =
      (Motor_position_control_P_2_B.DataTypeConversion1 -
       Motor_position_control_P_2_B.Gain3) *
      Motor_position_control_P_2_P.Gain2_Gain;

    /* Saturate: '<Root>/Saturation' */
    if (Motor_position_control_P_2_B.Saturation >
        Motor_position_control_P_2_P.Saturation_UpperSat) {
      /* Gain: '<Root>/Gain2' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      Motor_position_control_P_2_B.Saturation =
        Motor_position_control_P_2_P.Saturation_UpperSat;
    } else if (Motor_position_control_P_2_B.Saturation <
               Motor_position_control_P_2_P.Saturation_LowerSat) {
      /* Gain: '<Root>/Gain2' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      Motor_position_control_P_2_B.Saturation =
        Motor_position_control_P_2_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Signum: '<S1>/Sign' */
    if (rtIsNaN(Motor_position_control_P_2_B.Saturation)) {
      rtb_MathFunction = Motor_position_control_P_2_B.Saturation;
    } else if (Motor_position_control_P_2_B.Saturation < 0.0) {
      rtb_MathFunction = -1.0;
    } else {
      rtb_MathFunction = (Motor_position_control_P_2_B.Saturation > 0.0);
    }

    /* End of Signum: '<S1>/Sign' */

    /* MATLABSystem: '<S1>/Digital Output1' incorporates:
     *  Bias: '<S1>/Bias'
     *  Gain: '<S1>/Gain2'
     */
    rtb_MathFunction = rt_roundd_snf((rtb_MathFunction +
      Motor_position_control_P_2_P.Bias_Bias) *
      Motor_position_control_P_2_P.Gain2_Gain_e);
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
    obj = &Motor_position_control_P_2_DW.obj_d;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);

    /* Abs: '<S1>/Abs' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    rtb_MathFunction = fabs(Motor_position_control_P_2_P.Gain1_Gain *
      Motor_position_control_P_2_B.Saturation);

    /* MATLABSystem: '<S1>/PWM' */
    if (!(rtb_MathFunction <= 255.0)) {
      rtb_MathFunction = 255.0;
    }

    MW_PWM_SetDutyCycle
      (Motor_position_control_P_2_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
       rtb_MathFunction);

    /* Derivative: '<S3>/Derivative' */
    rtb_MathFunction = Motor_position_control_P_2_M->Timing.t[0];
    if ((Motor_position_control_P_2_DW.TimeStampA >= rtb_MathFunction) &&
        (Motor_position_control_P_2_DW.TimeStampB >= rtb_MathFunction)) {
      /* Derivative: '<S3>/Derivative' */
      Motor_position_control_P_2_B.Derivative = 0.0;
    } else {
      lastTime = Motor_position_control_P_2_DW.TimeStampA;
      lastU = &Motor_position_control_P_2_DW.LastUAtTimeA;
      if (Motor_position_control_P_2_DW.TimeStampA <
          Motor_position_control_P_2_DW.TimeStampB) {
        if (Motor_position_control_P_2_DW.TimeStampB < rtb_MathFunction) {
          lastTime = Motor_position_control_P_2_DW.TimeStampB;
          lastU = &Motor_position_control_P_2_DW.LastUAtTimeB;
        }
      } else if (Motor_position_control_P_2_DW.TimeStampA >= rtb_MathFunction) {
        lastTime = Motor_position_control_P_2_DW.TimeStampB;
        lastU = &Motor_position_control_P_2_DW.LastUAtTimeB;
      }

      /* Derivative: '<S3>/Derivative' */
      Motor_position_control_P_2_B.Derivative =
        (Motor_position_control_P_2_B.Gain3 - *lastU) / (rtb_MathFunction -
        lastTime);
    }

    /* End of Derivative: '<S3>/Derivative' */
    /* Step: '<S1>/Step' */
    if (Motor_position_control_P_2_M->Timing.t[0] <
        Motor_position_control_P_2_P.Step_Time) {
      rtb_MathFunction = Motor_position_control_P_2_P.Step_Y0;
    } else {
      rtb_MathFunction = Motor_position_control_P_2_P.Step_YFinal;
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

  {
    real_T *lastU;

    /* Update for Derivative: '<S3>/Derivative' */
    if (Motor_position_control_P_2_DW.TimeStampA == (rtInf)) {
      Motor_position_control_P_2_DW.TimeStampA =
        Motor_position_control_P_2_M->Timing.t[0];
      lastU = &Motor_position_control_P_2_DW.LastUAtTimeA;
    } else if (Motor_position_control_P_2_DW.TimeStampB == (rtInf)) {
      Motor_position_control_P_2_DW.TimeStampB =
        Motor_position_control_P_2_M->Timing.t[0];
      lastU = &Motor_position_control_P_2_DW.LastUAtTimeB;
    } else if (Motor_position_control_P_2_DW.TimeStampA <
               Motor_position_control_P_2_DW.TimeStampB) {
      Motor_position_control_P_2_DW.TimeStampA =
        Motor_position_control_P_2_M->Timing.t[0];
      lastU = &Motor_position_control_P_2_DW.LastUAtTimeA;
    } else {
      Motor_position_control_P_2_DW.TimeStampB =
        Motor_position_control_P_2_M->Timing.t[0];
      lastU = &Motor_position_control_P_2_DW.LastUAtTimeB;
    }

    *lastU = Motor_position_control_P_2_B.Gain3;

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Motor_position_control_P_2_M->Timing.t[0];

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
      ((Motor_position_control_P_2_M->Timing.clockTick1) * 0.001);

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
  Motor_position_control_P_2_M->Timing.t[0] =
    ((time_T)(++Motor_position_control_P_2_M->Timing.clockTick0)) *
    Motor_position_control_P_2_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Motor_position_control_P_2_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Motor_position_control_P_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Motor_position_control_P_2_M->solverInfo,
                          &Motor_position_control_P_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Motor_position_control_P_2_M->solverInfo, &rtmGetTPtr
                (Motor_position_control_P_2_M));
    rtsiSetStepSizePtr(&Motor_position_control_P_2_M->solverInfo,
                       &Motor_position_control_P_2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Motor_position_control_P_2_M->solverInfo,
                          (&rtmGetErrorStatus(Motor_position_control_P_2_M)));
    rtsiSetRTModelPtr(&Motor_position_control_P_2_M->solverInfo,
                      Motor_position_control_P_2_M);
  }

  rtsiSetSimTimeStep(&Motor_position_control_P_2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Motor_position_control_P_2_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Motor_position_control_P_2_M,
             &Motor_position_control_P_2_M->Timing.tArray[0]);
  rtmSetTFinal(Motor_position_control_P_2_M, -1);
  Motor_position_control_P_2_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Motor_position_control_P_2_M->Sizes.checksums[0] = (241416132U);
  Motor_position_control_P_2_M->Sizes.checksums[1] = (867658104U);
  Motor_position_control_P_2_M->Sizes.checksums[2] = (2928985892U);
  Motor_position_control_P_2_M->Sizes.checksums[3] = (2192631929U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    Motor_position_control_P_2_M->extModeInfo = (&rt_ExtModeInfo);
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
      &Motor_position_control_P_2_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Motor_position_control_P_2_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Motor_position_control_P_2_M->extModeInfo,
      &Motor_position_control_P_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Motor_position_control_P_2_M->extModeInfo,
                        Motor_position_control_P_2_M->Sizes.checksums);
    rteiSetTPtr(Motor_position_control_P_2_M->extModeInfo, rtmGetTPtr
                (Motor_position_control_P_2_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Derivative: '<S3>/Derivative' */
    Motor_position_control_P_2_DW.TimeStampA = (rtInf);
    Motor_position_control_P_2_DW.TimeStampB = (rtInf);

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' incorporates:
     *  SubSystem: '<S3>/Triggered Subsystem'
     */

    /* System initialize for function-call system: '<S3>/Triggered Subsystem' */
    Motor_position_control_P_2_M->Timing.clockTick2 =
      Motor_position_control_P_2_M->Timing.clockTick0;

    /* Start for MATLABSystem: '<S8>/Digital Input' */
    Motor_position_control_P_2_DW.obj.matlabCodegenIsDeleted = false;
    Motor_position_control_P_2_DW.obj.SampleTime =
      Motor_position_control_P_2_P.DigitalInput_SampleTime;
    Motor_position_control_P_2_DW.obj.isInitialized = 1;
    digitalIOSetup(51, 0);
    Motor_position_control_P_2_DW.obj.isSetupComplete = true;

    /* SystemInitialize for Outport: '<S8>/Out1' incorporates:
     *  Delay: '<S8>/Delay'
     *  Sum: '<S8>/Sum'
     */
    Motor_position_control_P_2_DW.Delay_DSTATE =
      Motor_position_control_P_2_P.Out1_Y0;
    ;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    Motor_position_control_P_2_DW.obj_p.matlabCodegenIsDeleted = true;
    Motor_position_control_P_2_DW.obj_p.isInitialized = 0;
    Motor_position_control_P_2_DW.obj_p.matlabCodegenIsDeleted = false;
    Motor_position_control_P_2_DW.obj_p.isSetupComplete = false;
    Motor_position_control_P_2_DW.obj_p.isInitialized = 1;
    digitalIOSetup(49, 1);
    Motor_position_control_P_2_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    Motor_position_control_P_2_DW.obj_d.matlabCodegenIsDeleted = true;
    Motor_position_control_P_2_DW.obj_d.isInitialized = 0;
    Motor_position_control_P_2_DW.obj_d.matlabCodegenIsDeleted = false;
    obj = &Motor_position_control_P_2_DW.obj_d;
    Motor_position_control_P_2_DW.obj_d.isSetupComplete = false;
    Motor_position_control_P_2_DW.obj_d.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    Motor_position_control_P_2_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    Motor_position_control_P_2_DW.obj_o.matlabCodegenIsDeleted = true;
    Motor_position_control_P_2_DW.obj_o.isInitialized = 0;
    Motor_position_control_P_2_DW.obj_o.matlabCodegenIsDeleted = false;
    Motor_position_control_P_2_DW.obj_o.isSetupComplete = false;
    Motor_position_control_P_2_DW.obj_o.isInitialized = 1;
    digitalIOSetup(48, 1);
    Motor_position_control_P_2_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void Motor_position_control_P_2_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

  /* Terminate for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' incorporates:
   *  SubSystem: '<S3>/Triggered Subsystem'
   */
  /* Termination for function-call system: '<S3>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S8>/Digital Input' */
  if (!Motor_position_control_P_2_DW.obj.matlabCodegenIsDeleted) {
    Motor_position_control_P_2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S3>/External Interrupt' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!Motor_position_control_P_2_DW.obj_p.matlabCodegenIsDeleted) {
    Motor_position_control_P_2_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &Motor_position_control_P_2_DW.obj_d;
  if (!Motor_position_control_P_2_DW.obj_d.matlabCodegenIsDeleted) {
    Motor_position_control_P_2_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Motor_position_control_P_2_DW.obj_d.isInitialized == 1) &&
        Motor_position_control_P_2_DW.obj_d.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle
        (Motor_position_control_P_2_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close
        (Motor_position_control_P_2_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!Motor_position_control_P_2_DW.obj_o.matlabCodegenIsDeleted) {
    Motor_position_control_P_2_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
