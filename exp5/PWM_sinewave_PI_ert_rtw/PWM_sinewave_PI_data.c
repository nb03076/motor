/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave_PI_data.c
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

#include "PWM_sinewave_PI.h"

/* Block parameters (default storage) */
P_PWM_sinewave_PI_T PWM_sinewave_PI_P = {
  /* Mask Parameter: StairGenerator_RepeatPattern
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Mask Parameter: StairGenerator_TimeInput
   * Referenced by: '<S5>/Time'
   */
  { 0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0 },

  /* Mask Parameter: DetectFallNonpositive_vinit
   * Referenced by: '<S7>/Delay Input1'
   */
  false,

  /* Expression: max( TimeInput )
   * Referenced by: '<S6>/Switch1'
   */
  30.0,

  /* Expression: -1
   * Referenced by: '<S9>/Digital Input'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S9>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S9>/Delay'
   */
  0.0,

  /* Expression: [ 0, AmplitudeInput ]
   * Referenced by: '<S5>/Output'
   */
  { 0.0, 0.0, 90.0, 180.0, 270.0, 360.0, 180.0, 0.0 },

  /* Expression: TimeInput( end )
   * Referenced by: '<S5>/Constant2'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch'
   */
  0.0,

  /* Expression: 360/1024
   * Referenced by: '<S4>/Gain3'
   */
  0.3515625,

  /* Expression: 0.04149
   * Referenced by: '<Root>/Gain2'
   */
  0.04149,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation'
   */
  -12.0,

  /* Expression: 1
   * Referenced by: '<S1>/Bias'
   */
  1.0,

  /* Expression: 1/2
   * Referenced by: '<S1>/Gain2'
   */
  0.5,

  /* Expression: 255/12
   * Referenced by: '<S1>/Gain1'
   */
  21.25,

  /* Expression: 2
   * Referenced by: '<S1>/Step'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -149.01960784313727,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  149.01960784313727,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  -158.8235294117647,

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  158.8235294117647,

  /* Computed Parameter: Constant2_Value_k
   * Referenced by: '<S6>/Constant2'
   */
  1,

  /* Computed Parameter: Constant1_Value_k
   * Referenced by: '<S6>/Constant1'
   */
  7,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S6>/Constant3'
   */
  0,

  /* Computed Parameter: Index_Y0
   * Referenced by: '<S6>/Index'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S9>/Gain'
   */
  128U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S8>/Constant'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
