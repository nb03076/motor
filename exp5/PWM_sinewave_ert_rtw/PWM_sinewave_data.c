/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave_data.c
 *
 * Code generated for Simulink model 'PWM_sinewave'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 16 13:14:02 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM_sinewave.h"

/* Block parameters (default storage) */
P_PWM_sinewave_T PWM_sinewave_P = {
  /* Mask Parameter: StairGenerator_RepeatPattern
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Mask Parameter: StairGenerator_TimeInput
   * Referenced by: '<S4>/Time'
   */
  { 0.0, 3.0, 6.0, 9.0, 12.0, 15.0, 18.0, 21.0, 24.0, 27.0 },

  /* Mask Parameter: DetectFallNonpositive_vinit
   * Referenced by: '<S6>/Delay Input1'
   */
  false,

  /* Expression: max( TimeInput )
   * Referenced by: '<S5>/Switch1'
   */
  27.0,

  /* Expression: -1
   * Referenced by: '<S8>/Digital Input'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S8>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S8>/Delay'
   */
  0.0,

  /* Expression: [ 0, AmplitudeInput ]
   * Referenced by: '<S4>/Output'
   */
  { 0.0, 0.0, 2000.0, -3000.0, 4000.0, 5000.0, -3000.0, 5000.0, 2000.0, -4000.0,
    0.0 },

  /* Expression: TimeInput( end )
   * Referenced by: '<S4>/Constant2'
   */
  27.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 360/1024
   * Referenced by: '<S3>/Gain3'
   */
  0.3515625,

  /* Expression: 7/455
   * Referenced by: '<Root>/Gain'
   */
  0.015384615384615385,

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

  /* Computed Parameter: Constant2_Value_j
   * Referenced by: '<S5>/Constant2'
   */
  1,

  /* Computed Parameter: Constant1_Value_c
   * Referenced by: '<S5>/Constant1'
   */
  10,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S5>/Constant3'
   */
  0,

  /* Computed Parameter: Index_Y0
   * Referenced by: '<S5>/Index'
   */
  0,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S8>/Gain'
   */
  128U,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S7>/Constant'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
