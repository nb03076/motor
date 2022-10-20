/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_position_control_P.h
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

#ifndef RTW_HEADER_Motor_position_control_P_h_
#define RTW_HEADER_Motor_position_control_P_h_
#ifndef Motor_position_control_P_COMMON_INCLUDES_
#define Motor_position_control_P_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                           /* Motor_position_control_P_COMMON_INCLUDES_ */

#include "Motor_position_control_P_types.h"
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
  real_T Output;                       /* '<S2>/Output' */
  real_T Gain3;                        /* '<S4>/Gain3' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Derivative;                   /* '<S4>/Derivative' */
} B_Motor_position_control_P_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S9>/Digital Input' */
  codertarget_arduinobase_blo_o_T obj_d;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_blo_o_T obj_f;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<S1>/PWM' */
  real_T Delay_DSTATE;                 /* '<S9>/Delay' */
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S4>/Derivative' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S4>/Triggered Subsystem' */
} DW_Motor_position_control_P_T;

/* Parameters (default storage) */
struct P_Motor_position_control_P_T_ {
  real_T Ramp_InitialOutput;           /* Mask Parameter: Ramp_InitialOutput
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T StairGenerator_RepeatPattern;
                                 /* Mask Parameter: StairGenerator_RepeatPattern
                                  * Referenced by: '<S5>/Constant'
                                  */
  real_T StairGenerator_TimeInput[7];/* Mask Parameter: StairGenerator_TimeInput
                                      * Referenced by: '<S5>/Time'
                                      */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S2>/Step'
                                        */
  boolean_T DetectFallNonpositive_vinit;
                                  /* Mask Parameter: DetectFallNonpositive_vinit
                                   * Referenced by: '<S7>/Delay Input1'
                                   */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S9>/Digital Input'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S9>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: TimeInput( end )
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360/1024
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4/455
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Bias_Bias;                    /* Expression: 1
                                        * Referenced by: '<S1>/Bias'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0_l;                    /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  int8_T Index_Y0;                     /* Computed Parameter: Index_Y0
                                        * Referenced by: '<S6>/Index'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S9>/Gain'
                                        */
  uint8_T Constant_Value_e;            /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S8>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Motor_position_contro_T {
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
extern P_Motor_position_control_P_T Motor_position_control_P_P;

/* Block signals (default storage) */
extern B_Motor_position_control_P_T Motor_position_control_P_B;

/* Block states (default storage) */
extern DW_Motor_position_control_P_T Motor_position_control_P_DW;

/* Model entry point functions */
extern void Motor_position_control_P_initialize(void);
extern void Motor_position_control_P_step(void);
extern void Motor_position_control_P_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Motor_position_contr_T *const Motor_position_control_P_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion1' : Unused code path elimination
 * Block '<S5>/Output' : Unused code path elimination
 * Block '<S5>/Selector' : Unused code path elimination
 * Block '<S6>/Constant1' : Unused code path elimination
 * Block '<S6>/Constant2' : Unused code path elimination
 * Block '<S6>/Constant3' : Unused code path elimination
 * Block '<S6>/Sum' : Unused code path elimination
 * Block '<S6>/Switch' : Unused code path elimination
 * Block '<S6>/Switch1' : Unused code path elimination
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
 * '<Root>' : 'Motor_position_control_P'
 * '<S1>'   : 'Motor_position_control_P/Motor'
 * '<S2>'   : 'Motor_position_control_P/Ramp'
 * '<S3>'   : 'Motor_position_control_P/Stair Generator'
 * '<S4>'   : 'Motor_position_control_P/encoder'
 * '<S5>'   : 'Motor_position_control_P/Stair Generator/Discrete'
 * '<S6>'   : 'Motor_position_control_P/Stair Generator/Discrete/While Iterator Subsystem'
 * '<S7>'   : 'Motor_position_control_P/Stair Generator/Discrete/While Iterator Subsystem/Detect Fall Nonpositive'
 * '<S8>'   : 'Motor_position_control_P/Stair Generator/Discrete/While Iterator Subsystem/Detect Fall Nonpositive/Nonpositive'
 * '<S9>'   : 'Motor_position_control_P/encoder/Triggered Subsystem'
 */
#endif                              /* RTW_HEADER_Motor_position_control_P_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
