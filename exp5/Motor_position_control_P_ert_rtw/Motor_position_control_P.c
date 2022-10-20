/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_position_control_P.c
 *
 * Code generated for Simulink model 'Motor_position_control_P'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 20 16:35:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_position_control_P.h"
#include "rtwtypes.h"
#include "Motor_position_control_P_private.h"
#include "Motor_position_control_P_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Block signals (default storage) */
B_Motor_position_control_P_T Motor_position_control_P_B;

/* Block states (default storage) */
DW_Motor_position_control_P_T Motor_position_control_P_DW;

/* Real-time model */
static RT_MODEL_Motor_position_contr_T Motor_position_control_P_M_;
RT_MODEL_Motor_position_contr_T *const Motor_position_control_P_M =
  &Motor_position_control_P_M_;

/* Callback for Hardware Interrupt Block: '<S4>/External Interrupt' */
void MW_ISR_50(void)
{
  /* Call the system: <S4>/Triggered Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Motor_position_control_P_DW.TriggeredSubsystem_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

    /* Output and update for function-call system: '<S4>/Triggered Subsystem' */
    {
      boolean_T b_value;
      Motor_position_control_P_M->Timing.clockTick2 =
        Motor_position_control_P_M->Timing.clockTick0;

      /* MATLABSystem: '<S9>/Digital Input' */
      if (Motor_position_control_P_DW.obj.SampleTime !=
          Motor_position_control_P_P.DigitalInput_SampleTime) {
        Motor_position_control_P_DW.obj.SampleTime =
          Motor_position_control_P_P.DigitalInput_SampleTime;
      }

      b_value = readDigitalPin(51);

      /* Sum: '<S9>/Sum' incorporates:
       *  Constant: '<S9>/Constant'
       *  Delay: '<S9>/Delay'
       *  Gain: '<S9>/Gain'
       *  MATLABSystem: '<S9>/Digital Input'
       *  Sum: '<S9>/Add'
       */
      Motor_position_control_P_DW.Delay_DSTATE += (real_T)(b_value ? (int32_T)
        Motor_position_control_P_P.Gain_Gain : 0) * 0.015625 -
        Motor_position_control_P_P.Constant_Value;
      Motor_position_control_P_DW.TriggeredSubsystem_SubsysRanBC = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */
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
void Motor_position_control_P_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T Output_tmp;
    real_T tmp_0;
    real_T u0;
    real_T *lastU;
    uint8_T tmp;

    /* Clock: '<S2>/Clock' incorporates:
     *  Derivative: '<S4>/Derivative'
     */
    Output_tmp = Motor_position_control_P_M->Timing.t[0];

    /* Step: '<S2>/Step' incorporates:
     *  Step: '<S1>/Step'
     */
    tmp_0 = Motor_position_control_P_M->Timing.t[0];
    if (tmp_0 < Motor_position_control_P_P.Ramp_start) {
      u0 = Motor_position_control_P_P.Step_Y0;
    } else {
      u0 = Motor_position_control_P_P.Ramp_slope;
    }

    /* End of Step: '<S2>/Step' */

    /* Sum: '<S2>/Output' incorporates:
     *  Clock: '<S2>/Clock'
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Product: '<S2>/Product'
     *  Sum: '<S2>/Sum'
     */
    Motor_position_control_P_B.Output = (Output_tmp -
      Motor_position_control_P_P.Ramp_start) * u0 +
      Motor_position_control_P_P.Ramp_InitialOutput;

    /* Gain: '<S4>/Gain3' */
    Motor_position_control_P_B.Gain3 = Motor_position_control_P_P.Gain3_Gain *
      Motor_position_control_P_DW.Delay_DSTATE;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Sum: '<Root>/Add'
     */
    Motor_position_control_P_B.Saturation = (Motor_position_control_P_B.Output -
      Motor_position_control_P_B.Gain3) * Motor_position_control_P_P.Gain2_Gain;

    /* Saturate: '<Root>/Saturation' */
    if (Motor_position_control_P_B.Saturation >
        Motor_position_control_P_P.Saturation_UpperSat) {
      /* Gain: '<Root>/Gain2' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      Motor_position_control_P_B.Saturation =
        Motor_position_control_P_P.Saturation_UpperSat;
    } else if (Motor_position_control_P_B.Saturation <
               Motor_position_control_P_P.Saturation_LowerSat) {
      /* Gain: '<Root>/Gain2' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      Motor_position_control_P_B.Saturation =
        Motor_position_control_P_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Signum: '<S1>/Sign' */
    if (rtIsNaN(Motor_position_control_P_B.Saturation)) {
      u0 = Motor_position_control_P_B.Saturation;
    } else if (Motor_position_control_P_B.Saturation < 0.0) {
      u0 = -1.0;
    } else {
      u0 = (Motor_position_control_P_B.Saturation > 0.0);
    }

    /* End of Signum: '<S1>/Sign' */

    /* MATLABSystem: '<S1>/Digital Output1' incorporates:
     *  Bias: '<S1>/Bias'
     *  Gain: '<S1>/Gain2'
     */
    u0 = rt_roundd_snf((u0 + Motor_position_control_P_P.Bias_Bias) *
                       Motor_position_control_P_P.Gain2_Gain_c);
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
    obj = &Motor_position_control_P_DW.obj_l;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);

    /* Abs: '<S1>/Abs' incorporates:
     *  Gain: '<S1>/Gain1'
     */
    u0 = fabs(Motor_position_control_P_P.Gain1_Gain *
              Motor_position_control_P_B.Saturation);

    /* MATLABSystem: '<S1>/PWM' */
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (Motor_position_control_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, u0);

    /* Derivative: '<S4>/Derivative' */
    if ((Motor_position_control_P_DW.TimeStampA >= Output_tmp) &&
        (Motor_position_control_P_DW.TimeStampB >= Output_tmp)) {
      /* Derivative: '<S4>/Derivative' */
      Motor_position_control_P_B.Derivative = 0.0;
    } else {
      u0 = Motor_position_control_P_DW.TimeStampA;
      lastU = &Motor_position_control_P_DW.LastUAtTimeA;
      if (Motor_position_control_P_DW.TimeStampA <
          Motor_position_control_P_DW.TimeStampB) {
        if (Motor_position_control_P_DW.TimeStampB < Output_tmp) {
          u0 = Motor_position_control_P_DW.TimeStampB;
          lastU = &Motor_position_control_P_DW.LastUAtTimeB;
        }
      } else if (Motor_position_control_P_DW.TimeStampA >= Output_tmp) {
        u0 = Motor_position_control_P_DW.TimeStampB;
        lastU = &Motor_position_control_P_DW.LastUAtTimeB;
      }

      /* Derivative: '<S4>/Derivative' */
      Motor_position_control_P_B.Derivative = (Motor_position_control_P_B.Gain3
        - *lastU) / (Output_tmp - u0);
    }

    /* Step: '<S1>/Step' */
    if (tmp_0 < Motor_position_control_P_P.Step_Time) {
      tmp_0 = Motor_position_control_P_P.Step_Y0_l;
    } else {
      tmp_0 = Motor_position_control_P_P.Step_YFinal;
    }

    /* MATLABSystem: '<S1>/Digital Output' */
    tmp_0 = rt_roundd_snf(tmp_0);
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint8_T)tmp_0;
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

    /* Update for Derivative: '<S4>/Derivative' */
    if (Motor_position_control_P_DW.TimeStampA == (rtInf)) {
      Motor_position_control_P_DW.TimeStampA =
        Motor_position_control_P_M->Timing.t[0];
      lastU = &Motor_position_control_P_DW.LastUAtTimeA;
    } else if (Motor_position_control_P_DW.TimeStampB == (rtInf)) {
      Motor_position_control_P_DW.TimeStampB =
        Motor_position_control_P_M->Timing.t[0];
      lastU = &Motor_position_control_P_DW.LastUAtTimeB;
    } else if (Motor_position_control_P_DW.TimeStampA <
               Motor_position_control_P_DW.TimeStampB) {
      Motor_position_control_P_DW.TimeStampA =
        Motor_position_control_P_M->Timing.t[0];
      lastU = &Motor_position_control_P_DW.LastUAtTimeA;
    } else {
      Motor_position_control_P_DW.TimeStampB =
        Motor_position_control_P_M->Timing.t[0];
      lastU = &Motor_position_control_P_DW.LastUAtTimeB;
    }

    *lastU = Motor_position_control_P_B.Gain3;

    /* End of Update for Derivative: '<S4>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Motor_position_control_P_M->Timing.t[0];

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
      ((Motor_position_control_P_M->Timing.clockTick1) * 0.001);

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
  Motor_position_control_P_M->Timing.t[0] =
    ((time_T)(++Motor_position_control_P_M->Timing.clockTick0)) *
    Motor_position_control_P_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Motor_position_control_P_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Motor_position_control_P_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Motor_position_control_P_M->solverInfo,
                          &Motor_position_control_P_M->Timing.simTimeStep);
    rtsiSetTPtr(&Motor_position_control_P_M->solverInfo, &rtmGetTPtr
                (Motor_position_control_P_M));
    rtsiSetStepSizePtr(&Motor_position_control_P_M->solverInfo,
                       &Motor_position_control_P_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Motor_position_control_P_M->solverInfo,
                          (&rtmGetErrorStatus(Motor_position_control_P_M)));
    rtsiSetRTModelPtr(&Motor_position_control_P_M->solverInfo,
                      Motor_position_control_P_M);
  }

  rtsiSetSimTimeStep(&Motor_position_control_P_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Motor_position_control_P_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Motor_position_control_P_M,
             &Motor_position_control_P_M->Timing.tArray[0]);
  rtmSetTFinal(Motor_position_control_P_M, -1);
  Motor_position_control_P_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Motor_position_control_P_M->Sizes.checksums[0] = (2141886949U);
  Motor_position_control_P_M->Sizes.checksums[1] = (4041651856U);
  Motor_position_control_P_M->Sizes.checksums[2] = (2794994270U);
  Motor_position_control_P_M->Sizes.checksums[3] = (1080778458U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Motor_position_control_P_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &Motor_position_control_P_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Motor_position_control_P_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Motor_position_control_P_M->extModeInfo,
      &Motor_position_control_P_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Motor_position_control_P_M->extModeInfo,
                        Motor_position_control_P_M->Sizes.checksums);
    rteiSetTPtr(Motor_position_control_P_M->extModeInfo, rtmGetTPtr
                (Motor_position_control_P_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Derivative: '<S4>/Derivative' */
    Motor_position_control_P_DW.TimeStampA = (rtInf);
    Motor_position_control_P_DW.TimeStampB = (rtInf);

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' incorporates:
     *  SubSystem: '<S4>/Triggered Subsystem'
     */

    /* System initialize for function-call system: '<S4>/Triggered Subsystem' */
    Motor_position_control_P_M->Timing.clockTick2 =
      Motor_position_control_P_M->Timing.clockTick0;

    /* Start for MATLABSystem: '<S9>/Digital Input' */
    Motor_position_control_P_DW.obj.matlabCodegenIsDeleted = false;
    Motor_position_control_P_DW.obj.SampleTime =
      Motor_position_control_P_P.DigitalInput_SampleTime;
    Motor_position_control_P_DW.obj.isInitialized = 1;
    digitalIOSetup(51, 0);
    Motor_position_control_P_DW.obj.isSetupComplete = true;

    /* SystemInitialize for Outport: '<S9>/Out1' incorporates:
     *  Delay: '<S9>/Delay'
     *  Sum: '<S9>/Sum'
     */
    Motor_position_control_P_DW.Delay_DSTATE =
      Motor_position_control_P_P.Out1_Y0;
    ;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(50), &MW_ISR_50, RISING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    Motor_position_control_P_DW.obj_d.matlabCodegenIsDeleted = true;
    Motor_position_control_P_DW.obj_d.isInitialized = 0;
    Motor_position_control_P_DW.obj_d.matlabCodegenIsDeleted = false;
    Motor_position_control_P_DW.obj_d.isSetupComplete = false;
    Motor_position_control_P_DW.obj_d.isInitialized = 1;
    digitalIOSetup(49, 1);
    Motor_position_control_P_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    Motor_position_control_P_DW.obj_l.matlabCodegenIsDeleted = true;
    Motor_position_control_P_DW.obj_l.isInitialized = 0;
    Motor_position_control_P_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &Motor_position_control_P_DW.obj_l;
    Motor_position_control_P_DW.obj_l.isSetupComplete = false;
    Motor_position_control_P_DW.obj_l.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(2U, 0.0, 0.0);
    Motor_position_control_P_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    Motor_position_control_P_DW.obj_f.matlabCodegenIsDeleted = true;
    Motor_position_control_P_DW.obj_f.isInitialized = 0;
    Motor_position_control_P_DW.obj_f.matlabCodegenIsDeleted = false;
    Motor_position_control_P_DW.obj_f.isSetupComplete = false;
    Motor_position_control_P_DW.obj_f.isInitialized = 1;
    digitalIOSetup(48, 1);
    Motor_position_control_P_DW.obj_f.isSetupComplete = true;
  }
}

/* Model terminate function */
void Motor_position_control_P_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

  /* Terminate for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' incorporates:
   *  SubSystem: '<S4>/Triggered Subsystem'
   */
  /* Termination for function-call system: '<S4>/Triggered Subsystem' */

  /* Terminate for MATLABSystem: '<S9>/Digital Input' */
  if (!Motor_position_control_P_DW.obj.matlabCodegenIsDeleted) {
    Motor_position_control_P_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Input' */
  ;

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!Motor_position_control_P_DW.obj_d.matlabCodegenIsDeleted) {
    Motor_position_control_P_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &Motor_position_control_P_DW.obj_l;
  if (!Motor_position_control_P_DW.obj_l.matlabCodegenIsDeleted) {
    Motor_position_control_P_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Motor_position_control_P_DW.obj_l.isInitialized == 1) &&
        Motor_position_control_P_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_SetDutyCycle
        (Motor_position_control_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(2U);
      MW_PWM_Close(Motor_position_control_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!Motor_position_control_P_DW.obj_f.matlabCodegenIsDeleted) {
    Motor_position_control_P_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
