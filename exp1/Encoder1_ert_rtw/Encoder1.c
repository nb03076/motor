/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder1.c
 *
 * Code generated for Simulink model 'Encoder1'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Sep 18 16:12:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder1.h"
#include "Encoder1_private.h"

/* Block signals (default storage) */
B_Encoder1_T Encoder1_B;

/* Block states (default storage) */
DW_Encoder1_T Encoder1_DW;

/* Real-time model */
static RT_MODEL_Encoder1_T Encoder1_M_;
RT_MODEL_Encoder1_T *const Encoder1_M = &Encoder1_M_;

/* Model step function */
void Encoder1_step(void)
{
  /* MATLABSystem: '<Root>/Digital Input' */
  if (Encoder1_DW.obj_p.SampleTime != Encoder1_P.DigitalInput_SampleTime) {
    Encoder1_DW.obj_p.SampleTime = Encoder1_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  Encoder1_B.DigitalInput = readDigitalPin(50);

  /* MATLABSystem: '<Root>/Digital Input1' */
  if (Encoder1_DW.obj.SampleTime != Encoder1_P.DigitalInput1_SampleTime) {
    Encoder1_DW.obj.SampleTime = Encoder1_P.DigitalInput1_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input1' */
  Encoder1_B.DigitalInput1 = readDigitalPin(51);

  /* SignalConversion generated from: '<Root>/Mux' */
  Encoder1_B.TmpSignalConversionAtTAQSigLogg[0] = Encoder1_B.DigitalInput;
  Encoder1_B.TmpSignalConversionAtTAQSigLogg[1] = Encoder1_B.DigitalInput1;

  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder1_M->Timing.taskTime0 =
    ((time_T)(++Encoder1_M->Timing.clockTick0)) * Encoder1_M->Timing.stepSize0;
}

/* Model initialize function */
void Encoder1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Encoder1_M, -1);
  Encoder1_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Encoder1_M->Sizes.checksums[0] = (3594538908U);
  Encoder1_M->Sizes.checksums[1] = (3918509962U);
  Encoder1_M->Sizes.checksums[2] = (1002952377U);
  Encoder1_M->Sizes.checksums[3] = (2264766694U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Encoder1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder1_M->extModeInfo,
      &Encoder1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder1_M->extModeInfo, Encoder1_M->Sizes.checksums);
    rteiSetTPtr(Encoder1_M->extModeInfo, rtmGetTPtr(Encoder1_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  Encoder1_DW.obj_p.matlabCodegenIsDeleted = false;
  Encoder1_DW.obj_p.SampleTime = Encoder1_P.DigitalInput_SampleTime;
  Encoder1_DW.obj_p.isInitialized = 1;
  digitalIOSetup(50, 0);
  Encoder1_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  Encoder1_DW.obj.matlabCodegenIsDeleted = false;
  Encoder1_DW.obj.SampleTime = Encoder1_P.DigitalInput1_SampleTime;
  Encoder1_DW.obj.isInitialized = 1;
  digitalIOSetup(51, 0);
  Encoder1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Encoder1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!Encoder1_DW.obj_p.matlabCodegenIsDeleted) {
    Encoder1_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Input1' */
  if (!Encoder1_DW.obj.matlabCodegenIsDeleted) {
    Encoder1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
