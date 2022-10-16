/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave_PI.h
 *
 * Code generated for Simulink model 'PWM_sinewave_PI'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 16 16:48:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PWM_sinewave_PI_h_
#define RTW_HEADER_PWM_sinewave_PI_h_
#ifndef PWM_sinewave_PI_COMMON_INCLUDES_
#define PWM_sinewave_PI_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* PWM_sinewave_PI_COMMON_INCLUDES_ */

#include "PWM_sinewave_PI_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
  real_T DataTypeConversion1;          /* '<S5>/Data Type Conversion1' */
  real_T Gain3;                        /* '<S4>/Gain3' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Derivative;                   /* '<S4>/Derivative' */
} B_PWM_sinewave_PI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S9>/Digital Input' */
  codertarget_arduinobase_blo_m_T obj_p;/* '<S1>/Digital Output1' */
  codertarget_arduinobase_blo_m_T obj_o;/* '<S1>/Digital Output' */
  codertarget_arduinobase_inter_T obj_d;/* '<S1>/PWM' */
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
} DW_PWM_sinewave_PI_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn3_CSTATE;          /* '<Root>/Transfer Fcn3' */
} X_PWM_sinewave_PI_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn3_CSTATE;          /* '<Root>/Transfer Fcn3' */
} XDot_PWM_sinewave_PI_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn3_CSTATE;       /* '<Root>/Transfer Fcn3' */
} XDis_PWM_sinewave_PI_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_PWM_sinewave_PI_T_ {
  real_T StairGenerator_RepeatPattern;
                                 /* Mask Parameter: StairGenerator_RepeatPattern
                                  * Referenced by: '<S5>/Constant'
                                  */
  real_T StairGenerator_TimeInput[7];/* Mask Parameter: StairGenerator_TimeInput
                                      * Referenced by: '<S5>/Time'
                                      */
  boolean_T DetectFallNonpositive_vinit;
                                  /* Mask Parameter: DetectFallNonpositive_vinit
                                   * Referenced by: '<S7>/Delay Input1'
                                   */
  real_T Switch1_Threshold;            /* Expression: max( TimeInput )
                                        * Referenced by: '<S6>/Switch1'
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
  real_T Output_Value[8];              /* Expression: [ 0, AmplitudeInput ]
                                        * Referenced by: '<S5>/Output'
                                        */
  real_T Constant2_Value;              /* Expression: TimeInput( end )
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Gain3_Gain;                   /* Expression: 360/1024
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.04149
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
  real_T Gain2_Gain_e;                 /* Expression: 1/2
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S1>/Gain1'
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
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  int8_T Constant2_Value_k;            /* Computed Parameter: Constant2_Value_k
                                        * Referenced by: '<S6>/Constant2'
                                        */
  int8_T Constant1_Value_k;            /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S6>/Constant1'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S6>/Constant3'
                                        */
  int8_T Index_Y0;                     /* Computed Parameter: Index_Y0
                                        * Referenced by: '<S6>/Index'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S9>/Gain'
                                        */
  uint8_T Constant_Value_j;            /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S8>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PWM_sinewave_PI_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_PWM_sinewave_PI_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
extern P_PWM_sinewave_PI_T PWM_sinewave_PI_P;

/* Block signals (default storage) */
extern B_PWM_sinewave_PI_T PWM_sinewave_PI_B;

/* Continuous states (default storage) */
extern X_PWM_sinewave_PI_T PWM_sinewave_PI_X;

/* Block states (default storage) */
extern DW_PWM_sinewave_PI_T PWM_sinewave_PI_DW;

/* Model entry point functions */
extern void PWM_sinewave_PI_initialize(void);
extern void PWM_sinewave_PI_step(void);
extern void PWM_sinewave_PI_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PWM_sinewave_PI_T *const PWM_sinewave_PI_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Add' : Unused code path elimination
 * Block '<S3>/Gain2' : Unused code path elimination
 * Block '<S3>/Gain3' : Unused code path elimination
 * Block '<S3>/Gain4' : Unused code path elimination
 * Block '<S3>/Memory' : Unused code path elimination
 * Block '<S3>/Sum1' : Unused code path elimination
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
 * '<Root>' : 'PWM_sinewave_PI'
 * '<S1>'   : 'PWM_sinewave_PI/Motor'
 * '<S2>'   : 'PWM_sinewave_PI/Stair Generator'
 * '<S3>'   : 'PWM_sinewave_PI/Subsystem'
 * '<S4>'   : 'PWM_sinewave_PI/encoder'
 * '<S5>'   : 'PWM_sinewave_PI/Stair Generator/Discrete'
 * '<S6>'   : 'PWM_sinewave_PI/Stair Generator/Discrete/While Iterator Subsystem'
 * '<S7>'   : 'PWM_sinewave_PI/Stair Generator/Discrete/While Iterator Subsystem/Detect Fall Nonpositive'
 * '<S8>'   : 'PWM_sinewave_PI/Stair Generator/Discrete/While Iterator Subsystem/Detect Fall Nonpositive/Nonpositive'
 * '<S9>'   : 'PWM_sinewave_PI/encoder/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_PWM_sinewave_PI_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
