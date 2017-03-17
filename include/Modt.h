/*============================================================================*/
/*                        Analog Modulation Measurements                      */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2005-2009.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       Modt.h                                                        */
/* Purpose:     Header file for Analog Modulation Measurements                */
/*   The online help and function panels for each function contain            */
/*   additional documentation.                                                */
/*============================================================================*/

#ifndef __AMODT_HEADER
#define __AMODT_HEADER

#ifndef __VISATYPE_HEADER__
#define ViSession unsigned long
#endif

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#include <cvidef.h>
#else
#define CVIFUNC __stdcall
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push)
#pragma pack(1)

#define MODTMAXERRORSTRINGSIZE                     1024

/* AM SSB */
#define MODT_LOWER_SIDEBAND						0
#define MODT_UPPER_SIDEBAND						1

/* Hilbert Filter Design Type */
#define MODT_WINDOWED_HILBERT_TRANSFORMER		0
#define MODT_EQUIRIPPLE_HILBERT_TRANSFORMER		1

/* IQ components */
#define MODT_IQ_COMPONENT_I						0
#define MODT_IQ_COMPONENT_Q						1
#define MODT_IQ_COMPONENT_MAGNITUDE				2
#define MODT_IQ_COMPONENT_PHASE					3


/*============================================================================*/
/* ERROR CODES                                                                */
/*============================================================================*/

#define ModtNoErr                                  0
#define ModtUninitializedReceiverInfoErr           -20551
#define ModtInvalidTaskIDErr                       -20552
#define ModtInvalidniScopeHandleErr                -20553
#define ModtUnsupportedReceiverErr                 -20554
#define ModtReceiverMismatchErr                    -20555
#define ModtNullVariantinViRefErr                  -20556
#define ModtPBInconsistentSampleRateErr            -20559

#define ModtDLLLoadErr                             -20561
#define ModtFindFunctioninDLLErr                   -20562
#define ModtSessionDestroyErr                      -20563
#define ModtSessionCreateErr                       -20564
#define ModtInvalidAttribRequestErr                -20565

#define ModtInternalErr                            -20567
#define ModtErrorLoadingDynamicCallForReceiverErr  -20568
#define ModtSampleRateLTNyquistFreqErr             -20569
#define ModtRequestedFilterNotUsefulErr            -20570
#define ModtInvalidModulationIndexErr              -20571
#define ModtInvalidPilotToneFrequencyErr           -20572
#define ModtHilbertFilterLengthLTOneErr            -20573
#define ModtFilterTapsLengthLTEightyFiveErr        -20574
#define ModtInvalidCutOffParametersErr             -20575
#define ModtInvalidRelationsAmongCutOffParamsErr   -20576
#define ModtInvalidPilotSearchParameterErr         -20577
#define ModtInvalidDtErr                           -20578
#define ModtInvalidPassbandBandwidthErr            -20579

#define ModtNullArgumentToFunctionErr              -20581
#define ModtNegativeLengthErr					   -20582
#define ModtCreateMutexErr                         -20583
#define ModtInvalidSessionHandleErr                -20584


#define ModtInvalidTotalNumberOfBitsErr            -21801
#define ModtPNSequenceOutOfRangeErr                -21802
#define ModtUserBitPatternEmptyErr                 -21803
#define ModtInputBitStreamEmptyErr                 -21804
#define ModtSpreadingCodeEmptyErr                  -21805
#define ModtInputChipStreamEmptyErr                -21806
#define ModtChipLengthLTSpreadingCodeErr           -21807
#define ModtSyncSearchDepthLTOneErr                -21808
#define ModtSyncConfThresOutOfRangeErr             -21809
#define ModtSyncSearchMTInfoBitsLengthErr          -21810
#define ModtSyncNotFoundErr                        -21811
#define ModtInvalidUserBitPatternErr               -21812
#define ModtInvalidInputBitStreamErr               -21813
#define ModtInvalidSpreadingCodeErr                -21814
#define ModtInvalidInputChipStreamErr              -21815
#define ModtSamplesPerSymbolLTOneErr               -21816
#define ModtSymbolRateLTZeroErr                    -21817
#define ModtIDCOffsetOutOfRangeErr                 -21818
#define ModtQDCOffsetOutOfRangeErr                 -21819
#define ModtIQGainImbalanceOutOfRangeErr           -21820
#define ModtQuadratureSkewOutOfRangeErr            -21821
#define ModtSamplesPerSymbolOddErr                 -21822
#define ModtFilterCoeffEmptyErr                    -21823
#define ModtInvalidNumberOfSymbolsErr              -21824
#define ModtSymbolValuesNotUniqueErr               -21825
#define ModtSymbolsOutOfRangeErr                   -21826
#define ModtIncompatibleModTypeAndFilterErr        -21827
#define ModtFilteringSymbolsErr                    -21828
#define ModtInvalidSymbolNumbersErr                -21829
#define ModtQAMSymbolMapNotSquareErr               -21830
#define ModtFilterLengthLTOneErr                   -21831
#define ModtFilterParamOutOfRangeErr               -21832
#define ModtBitsPerSymbolLTOneErr                  -21833
#define ModtWidthLT2SymbolsErr                     -21834
#define ModtWidthIsNegativeErr                     -21835
#define ModtDtLTZeroErr                            -21836
#define ModtWaveformDataEmptyErr                   -21837
#define ModtSymbolValuesOutOfRangeErr              -21838
#define ModtSyncLocationUncerZeroErr               -21839
#define ModtSyncIndentZeroErr                      -21840
#define ModtUnequalMaskLengthsErr                  -21841
#define ModtUpperMaskEmptyErr                      -21842
#define ModtIdealPowerCurveEmptyErr                -21843
#define ModtLowerMaskEmptyErr                      -21844
#define ModtInvalidFSKSymbolValuesErr              -21845
#define ModtInputWaveLengthLTMaskLengthErr         -21846
#define ModtBERSyncThresOutOfRangeErr              -21847
#define ModtFadingProfileArrayEmptyErr             -21849
#define ModtSampleRateLTZeroErr                    -21850
#define ModtSamplePhaseOffsetZeroErr               -21851
#define ModtResamplingErrorErr                     -21852
#define ModtToneFreqLTZeroErr                      -21853
#define ModtListOfToneEmptyErr                     -21854
#define ModtInvalidQuadOneAndTwoErr                -21855
#define ModtInvalidQuadOneAndFourErr               -21856
#define ModtInvalidSymbolQuadOneAndFourErr         -21857
#define ModtCannotLocateSyncSequenceErr            -21858
#define ModtInvalidOffsetPSKFormatErr              -21859
#define ModtInvalidConfidenceParameterErr          -21860
#define ModtDtChangedErr                           -21861
#define ModtEyeAndTrellisLengthLTZeroErr           -21862
#define ModtOldAndNewSampRatesOutOfRangeErr        -21863
#define ModtInvalidInputSeedErr                    -21864
#define ModtInputSymbolArrayEmptyErr               -21865
#define ModtInputSyncNumberArrayEmptyErr           -21866
#define ModtNumSyncBitsNotLTThirtyTwoErr           -21867
#define ModtInvaildInverseFExponentErr             -21868
#define ModtInvalidOffsetFrequencyErr              -21869
#define ModtInvalidDecimationFactorOrOffsetErr     -21870
#define ModtInvalidBlockCodeCombinationErr         -21871
#define ModtInvalidRSCodeCombinationErr            -21872
#define ModtInvalidGeneratorMatrixInputErr         -21873
#define ModtInvalidLengthCombinationErr            -21874
#define ModtInvalidTracebackDepthErr               -21875
#define ModtEquilizerParamCombinationErr           -21876
#define ModtInvalidEqualizerCoefficientsErr        -21877
#define ModtInvalidValuesErr                       -21878
#define ModtInvalidDopplerSpeedAndSampFreqErr      -21879
#define ModtSymbolMapNotOnStraightLineErr          -21881
#define ModtInvalidReferencePatternErr             -21882
#define ModtReferencePatternLengthLTTwoErr         -21883
#define ModtInvalidDeviationErr                    -21884
#define ModtCarrierPhaseCorrectionLTOneErr         -21885
#define ModtInvalidSymbolMapErr                    -21886
#define ModtInvalidCombinationErr                  -21887
#define ModtInvalidMErr                            -21888
#define ModtGaloisFieldOrderNotSupportedErr        -21889
#define ModtInvalidBCHCodeWordLengthErr            -21890
#define ModtInvalidMeasurementErr                  -21891
#define ModtInvalidFilterCoeffLenErr               -21892
#define ModtInadequateNumberOfSymbolsErr           -21893
#define ModtInadequateComplexDataLenErr            -21894
#define ModtInadequateBitStreamLenErr              -21895
#define ModtInadequateChipStreamLenErr             -21896


/*============================================================================*/
/* WARNING CODES                                                              */
/*============================================================================*/

#define ModtRFAttenValCoercedWrn                    20557
#define ModtFMDevInconsistentSampleRateWrn          20558
#define ModtModulationIndexGTOneWrn                 20571
#define ModtInsufficientErrorStringLengthWrn        20562

#define ModtInadequateBitsForBERWrn                 21848
#define ModtInsufficientProfileLengthWrn            21880


/*============================================================================*/
/* TYPE DEFINITIONS                                                           */
/*============================================================================*/

#ifndef __ModtHandle__
#define __ModtHandle__
typedef int ModtHandle;
#endif

/* complex numbers */
#if !defined(_New_NIComplexNumber_struct)
#define _New_NIComplexNumber_struct
#pragma pack(push, 8)
struct New_NIComplexNumber_struct {
   union {
              double re;   /* deprecated;  use 'real' field instead */
              double real;
  };
   union {
              double im;   /* deprecated;  use 'imaginary' field instead */
              double imaginary;
  };
};
#pragma pack(pop)
#endif


#if !defined(_NIComplexNumber)
typedef struct New_NIComplexNumber_struct  NIComplexNumber;
#define _NIComplexNumber
#elif defined(COMPATIBLE_AMT_COMPLEX)
#pragma message ("Due to the order of the #include lines in your source file, niComplexNum might not be compatible with NiComplexNumber used by other NI libraries.  Please change the inclusion order so that modt.h is the first header file included")
#endif

#if defined(COMPATIBLE_AMT_COMPLEX) 
typedef struct New_NIComplexNumber_struct niComplexNum;
#else 
typedef NIComplexNumber niComplexNum; 
#endif

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif

#include "Modt_Deprecated.h" /* Deprecated functions Declaration */

/*============================================================================*/
/* FUNCTIONS                                                                  */
/*============================================================================*/

	int CVIFUNC ModtCreateSessionHandle (ModtHandle *pHandle);

	int CVIFUNC ModtDestroySessionHandle (ModtHandle handle);

	int CVIFUNC ModtInitReceiverInfoForNIScope (ModtHandle handle,
		ViSession niScopeHandle);

	int CVIFUNC ModtInitReceiverInfoForRFSA (ModtHandle handle,
		int tunerTaskID, 
		ViSession niScopeHandle);

	int CVIFUNC ModtConfigDownconversionSettings (ModtHandle handle,
		double minIQSampleRate,
		double carrierFrequency,
		double bandwidth,
		double timeDuration,
		double *niScopeSampleRate,
		int *numNIScopeSamples,
		int *numIQDataElements);

	int CVIFUNC ModtGetRFSAReferenceLevel (ModtHandle handle,
		int *referenceLevel);

	int CVIFUNC ModtSetRFSAReferenceLevel (ModtHandle handle, 
		int referenceLevel);

	int CVIFUNC ModtGetRFSARFAttenuation (ModtHandle handle,
		int *rfAttenuation);

	int CVIFUNC ModtSetRFSARFAttenuation (ModtHandle handle,
		int rfAttenuation);


	int CVIFUNC ModtGetReceiverDataFormat (ModtHandle handle,
		int *receiverDataFormat);

	int CVIFUNC ModtGetReceiverAutoSuppressSWIQ (ModtHandle handle,
		int *receiverAutoSuppressSWIQ);

	int CVIFUNC ModtSetReceiverAutoSuppressSWIQ (ModtHandle handle,
		int receiverAutosuppressSWIQ);

	int CVIFUNC ModtGetCarrierFrequency (ModtHandle handle,
		double *carrierFrequency);

	int CVIFUNC ModtGetReceiverBW (ModtHandle handle,
		double *receiverBandwidth);

	int CVIFUNC ModtConvertIFToIQ (ModtHandle handle,
		double relativeInitialX,
		double xIncrement,
		double inputWaveform[],
		int numInputWaveformElements,
		void *inputWaveformInfo, /* cast from struct niScope_wfmInfo */
		double phaseAdjust,
		double *iqDataT0,
		double *iqDataDt,
		niComplexNum iqData[]);

	int CVIFUNC ModtGetComplexIQComponentEx (ModtHandle handle,
		niComplexNum iqData[],
		int numIQDataElements,
		int componentToExtract,
		int reset,
		double requestedComponent[]);
	                                          
	int CVIFUNC ModtniComplexNumToReImArrays (niComplexNum iqData[],
		int numIQDataElements,
		double realData[],
		double imaginaryData[]);

	int CVIFUNC ModtFractionalResampleEx ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double initialSampleOffset,
		double desiredSampleRate,
		int reset,
		int flushBuffers,
		double *resampledWaveformT0,
		double *resampledWaveformDt,
		int resampledWaveformArraySize,
		niComplexNum resampledWaveform[],
		int *actualNumResampledWaveformElements);
	    
	int CVIFUNC ModtGetErrorString (int errorCode,
		char errorMessage[],
		int errorMessageLength);

	int CVIFUNC ModtDownconvertPassband_RealInput (ModtHandle handle,
		double t0,
		double dt,
		double inputWaveform[],
		int numInputWaveformElements,
		double carrierFrequency,
		double passbandBandwidth,
		double initialPhase,
		int reset,
		int enableFilter,
		double *downconvertedWaveformT0,
		double *downconvertedWaveformDt,
		niComplexNum downconvertedWaveform[],
		double *filterRipple,
		int *filterLength);

	int CVIFUNC ModtDownconvertPassband_ComplexInput (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double carrierFrequency,
		double passbandBandwidth,
		double initialPhase,
		int reset,
		int enableFilter,
		double *downconvertedWaveformT0,
		double *downconvertedWaveformDt,
		niComplexNum downconvertedWaveform[],
		double *filterRipple,
		int *filterLength);

	int CVIFUNC ModtUpconvertBaseband_RealOutput (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double initialPhase,
		int reset,
		double carrierFrequency,
		double *upconvertedWaveformT0,
		double *upconvertedWaveformDt,
		double upconvertedWaveform[]);

	int CVIFUNC ModtUpconvertBaseband_ComplexOutput (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double initialPhase,
		int reset,
		double carrierFrequency,
		double *upconvertedWaveformT0,
		double *upconvertedWaveformDt,
		niComplexNum upconvertedWaveform[]);

	int CVIFUNC ModtAMModulate_DSB (ModtHandle handle,
		double t0,
		double dt,
		double inputData[],
		int numInputDataElements,
		double modulationIndex,
		double peakMessageAmplitude,
		int suppressCarrier,
		double *modulatedWaveformT0,
		double *modulatedWaveformDt,
		niComplexNum modulatedWaveform[]);

	int CVIFUNC ModtAMModulate_SSB (ModtHandle handle,
		double t0,
		double dt,
		double inputData[],
		int numInputDataElements,
		double modulationIndex,
		double pilotToneFrequency,
		double pilotToneAmplitude,
		int numHilbertFilterTaps,
		int hilbertFilterDesignType,
		int sideBand,
		double peakMessageAmplitude,
		int suppressCarrier,
		int reset,
		double *modulatedWaveformT0,
		double *modulatedWaveformDt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements);

	int CVIFUNC ModtAMModulate_VSB (ModtHandle handle,
		double t0,
		double dt,
		double inputData[],
		int numInputDataElements,
		double modulationIndex,
		double pilotToneFrequency,
		double pilotToneAmplitude,
		int numFilterTaps,
		double filterLowerPassband,
		double filterUpperPassband,
		double filterLowerStopband,
		double filterUpperStopband,
		double peakMessageAmplitude,
		int suppressCarrier,
		int reset,
		double *modulatedWaveformT0,
		double *modulatedWaveformDt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements);

	int CVIFUNC ModtFMModulateEx (ModtHandle handle,
		double t0,
		double dt,
		double inputData[],
		int numInputDataElements,
		double FMDeviation,
		int reset,
		double *modulatedWaveformT0,
		double *modulatedWaveformDt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements);

	int CVIFUNC ModtPMModulate (ModtHandle handle, 
		double t0,
		double dt,
		double inputData[],
		int numInputDataElements,
		double phaseDeviation,
		niComplexNum modulatedWaveform[]);

	int CVIFUNC ModtAMDemodulate_DSB (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double modulationIndex,
		int suppressedCarrier,
		double *demodulatedWaveformT0,
		double *demodulatedWaveformDt,
		double demodulatedWaveform[],
		double *carrierAmplitude);

	int CVIFUNC ModtAMDemodulate_SSB (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double modulationIndex,
		int numTaps,
		double approximateFrequency,
		double searchCriterion,
		double costasLoopParameterAlpha,
		double costasLoopParameterBeta,
		int suppressedCarrier,
		int reset,
		double *demodulatedWaveformT0,
		double *demodulatedWaveformDt,
		int demodulatedWaveformArraySize,
		double demodulatedWaveform[],
		int *actualNumDemodulatedWaveformElements,
		double *extractedPilotTone,
		double *frequencyOffset);

	int CVIFUNC ModtAMDemodulate_VSB (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double modulationIndex,
		int numTaps,
		double approximateFrequency,
		double searchCriterion,
		double costasLoopParameterAlpha,
		double costasLoopParameterBeta,
		int suppressedCarrier,
		int reset,
		double *demodulatedWaveformT0,
		double *demodulatedWaveformDt,
		int demodulatedWaveformArraySize,
		double demodulatedWaveform[],
		int *actualNumDemodulatedWaveformElements,
		double *extractedPilotTone,
		double *frequencyOffset);

	int CVIFUNC ModtFMDemodulateEx (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int carrierCorrection,
		double FMDeviation,
		int removeTransientWhenReset,
		int reset,
		double *demodulatedWaveformT0,
		double *demodulatedWaveformDt,
		int demodulatedWaveformArraySize,
		double demodulatedWaveform[],
		int *actualNumDemodulatedWaveformElements,
		double *carrierOffset);

	int CVIFUNC ModtPMDemodulateEx (ModtHandle handle,
		double t0,
		double dt,
		niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double phaseDeviation,
		int carrierCorrection,
		int reset,
		double *demodulatedWaveformT0,
		double *demodulatedWaveformDt,
		int demodulatedWaveformArraySize,
		double demodulatedWaveform[],
		int *actualNumDemodulatedWaveformElements,
		double *carrierOffset);

	int CVIFUNC ModtGetScalarAttributeI32(ModtHandle handle, 
		char *channelString,
		int attributeID, 
		int *value);

	int CVIFUNC ModtSetScalarAttributeI32(ModtHandle handle, 
		char *channelString,
		int attributeID, 
		int value);

	int CVIFUNC ModtSetVectorAttributeI8(ModtHandle handle,
		char *channelString,
		int attributeID, 
		char *array, 
		int arraySizeInSamples);

	int CVIFUNC ModtGetVectorAttributeI8(ModtHandle handle, 
		char *channelString,
		int attributeId, 
		int arraySizeInSamples, 
		char *array, 
		int *actualArraySizeInSamples);

#ifndef __VISATYPE_HEADER__
#undef ViSession
#endif

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* ndef __AMODT_HEADER */
