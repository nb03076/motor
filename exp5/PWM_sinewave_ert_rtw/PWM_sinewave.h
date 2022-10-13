/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave.h
 *
 * Code generated for Simulink model 'PWM_sinewave'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 13 15:58:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PWM_sinewave_h_
#define RTW_HEADER_PWM_sinewave_h_
#ifndef PWM_sinewave_COMMON_INCLUDES_
#define PWM_sinewave_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* PWM_sinewave_COMMON_INCLUDES_ */

#include "PWM_sinewave_types.h"
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
  real_T DataTypeConversion1;          /* '<S4>/Data Type Conversion1' */
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T Derivative;                   /* '<S3>/Derivative' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Gain1;                        /* '<Root>/Gain1' */
} B_PWM_sinewave_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S8>/Digital Input' */
  codertarget_arduinobase_blo_p_T obj_j;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_blo_p_T obj_h;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_p;/* '<S1>/PWM' */
  real_T Delay_DSTATE;                 /* '<S8>/Delay' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S3>/Triggered Subsystem' */
} DW_PWM_sinewave_T;

/* Parameters (default storage) */
struct P_PWM_sinewave_T_ {
  real_T StairGenerator_RepeatPattern;
                                 /* Mask Parameter: StairGenerator_RepeatPattern
                                  * Referenced by: '<S4>/Constant'
                                  */
  real_T StairGenerator_TimeInput[10];
                                     /* Mask Parameter: StairGenerator_TimeInput
                                      * Referenced by: '<S4>/Time'
                                      */
  boolean_T DetectFallNonpositive_vinit;
                                  /* Mask Parameter: DetectFallNonpositive_vinit
                                   * Referenced by: '<S6>/Delay Input1'
                                   */
  real_T Switch1_Threshold;            /* Expression: max( TimeInput )
                                        * Referenced by: '<S5>/Switch1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S8>/Digital Input'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S8>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay'
                                        */
  real_T Output_Value[11];             /* Expression: [ 0, AmplitudeInput ]
                                        * Referenced by: '<S4>/Output'
                                        */
  real_T Constant2_Value;              /* Expression: TimeInput( end )
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360/1024
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 7/455
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
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
  real_T Gain1_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  int8_T Constant2_Value_j;            /* Computed Parameter: Constant2_Value_j
                                        * Referenced by: '<S5>/Constant2'
                                        */
  int8_T Constant1_Value_c;            /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S5>/Constant1'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S5>/Constant3'
                                        */
  int8_T Index_Y0;                     /* Computed Parameter: Index_Y0
                                        * Referenced by: '<S5>/Index'
                                        */
  uint8_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S8>/Gain'
                                        */
  uint8_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S7>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PWM_sinewave_T {
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
extern P_PWM_sinewave_T PWM_sinewave_P;

/* Block signals (default storage) */
extern B_PWM_sinewave_T PWM_sinewave_B;

/* Block states (default storage) */
extern DW_PWM_sinewave_T PWM_sinewave_DW;

/* Model entry point functions */
extern void PWM_sinewave_initialize(void);
extern void PWM_sinewave_step(void);
extern void PWM_sinewave_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PWM_sinewave_T *const PWM_sinewave_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'PWM_sinewave'
 * '<S1>'   : 'PWM_sinewave/Motor'
 * '<S2>'   : 'PWM_sinewave/Stair Generator'
 * '<S3>'   : 'PWM_sinewave/encoder'
 * '<S4>'   : 'PWM_sinewave/Stair Generator/Discrete'
 * '<S5>'   : 'PWM_sinewave/Stair Generator/Discrete/While Iterator Subsystem'
 * '<S6>'   : 'PWM_sinewave/Stair Generator/Discrete/While Iterator Subsystem/Detect Fall Nonpositive'
 * '<S7>'   : 'PWM_sinewave/Stair Generator/Discrete/While Iterator Subsystem/Detect Fall Nonpositive/Nonpositive'
 * '<S8>'   : 'PWM_sinewave/encoder/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_PWM_sinewave_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
