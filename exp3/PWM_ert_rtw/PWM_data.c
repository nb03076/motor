/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_data.c
 *
 * Code generated for Simulink model 'PWM'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep 30 17:20:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM.h"

/* Block parameters (default storage) */
P_PWM_T PWM_P = {
  /* Expression: -1
   * Referenced by: '<S3>/Digital Input'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S3>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<Root>/Pulse Generator'
   */
  24.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  400.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  200.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: -12
   * Referenced by: '<Root>/Bias'
   */
  -12.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation'
   */
  -12.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain'
   */
  -1.0,

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

  /* Expression: 5
   * Referenced by: '<S1>/Step'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 360/1024
   * Referenced by: '<S2>/Gain3'
   */
  0.3515625,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -200.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  200.0,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S3>/Gain'
   */
  128U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
