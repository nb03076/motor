/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM.h
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

#ifndef RTW_HEADER_PWM_h_
#define RTW_HEADER_PWM_h_
#ifndef PWM_COMMON_INCLUDES_
#define PWM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* PWM_COMMON_INCLUDES_ */

#include "PWM_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T Derivative;                   /* '<S3>/Derivative' */
} B_PWM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S4>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_j;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_blo_e_T obj_h;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_p;/* '<S1>/PWM' */
  real_T Delay_DSTATE;                 /* '<S4>/Delay' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S3>/Triggered Subsystem' */
} DW_PWM_T;

/* Parameters (default storage) */
struct P_PWM_T_ {
  real_T Ramp_InitialOutput;           /* Mask Parameter: Ramp_InitialOutput
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S2>/Step'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S4>/Digital Input'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Bias_Bias;                    /* Expression: 1
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Step_Time;                    /* Expression: 5
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0_p;                    /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360/1024
                                        * Referenced by: '<S3>/Gain3'
                                        */
  uint8_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S4>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PWM_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PWM_T PWM_P;

/* Block signals (default storage) */
extern B_PWM_T PWM_B;

/* Block states (default storage) */
extern DW_PWM_T PWM_DW;

/* Model entry point functions */
extern void PWM_initialize(void);
extern void PWM_step(void);
extern void PWM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PWM_T *const PWM_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Step' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PWM'
 * '<S1>'   : 'PWM/Motor'
 * '<S2>'   : 'PWM/Ramp'
 * '<S3>'   : 'PWM/encoder'
 * '<S4>'   : 'PWM/encoder/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_PWM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
