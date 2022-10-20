/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_position_control_P_data.c
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

/* Block parameters (default storage) */
P_Motor_position_control_P_T Motor_position_control_P_P = {
  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Mask Parameter: StairGenerator_RepeatPattern
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Mask Parameter: StairGenerator_TimeInput
   * Referenced by: '<S5>/Time'
   */
  { 0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0 },

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S2>/Step'
   */
  3000.0,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S2>/Constant'
   *   '<S2>/Step'
   */
  3.0,

  /* Mask Parameter: DetectFallNonpositive_vinit
   * Referenced by: '<S7>/Delay Input1'
   */
  false,

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

  /* Expression: 0
   * Referenced by: '<S5>/Constant1'
   */
  0.0,

  /* Expression: TimeInput( end )
   * Referenced by: '<S5>/Constant2'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S5>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Expression: 360/1024
   * Referenced by: '<S4>/Gain3'
   */
  0.3515625,

  /* Expression: 4/455
   * Referenced by: '<Root>/Gain2'
   */
  0.0087912087912087912,

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

  /* Computed Parameter: Index_Y0
   * Referenced by: '<S6>/Index'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S9>/Gain'
   */
  128U,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S8>/Constant'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
