/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PWM_sinewave_types.h
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

#ifndef RTW_HEADER_PWM_sinewave_types_h_
#define RTW_HEADER_PWM_sinewave_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */
#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_d_arduinodriver_ArduinoDigita_T
#define typedef_d_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C d_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_d_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_mPMPiw8t0JZKYO8orfnwRG
#define struct_tag_mPMPiw8t0JZKYO8orfnwRG

struct tag_mPMPiw8t0JZKYO8orfnwRG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_mPMPiw8t0JZKYO8orfnwRG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_mPMPiw8t0JZKYO8orfnwRG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

/* Custom Type definition for MATLABSystem: '<S1>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_blo_p_T
#define typedef_codertarget_arduinobase_blo_p_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_blo_p_T;

#endif                             /* typedef_codertarget_arduinobase_blo_p_T */

/* Parameters (default storage) */
typedef struct P_PWM_sinewave_T_ P_PWM_sinewave_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_PWM_sinewave_T RT_MODEL_PWM_sinewave_T;

#endif                                 /* RTW_HEADER_PWM_sinewave_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
