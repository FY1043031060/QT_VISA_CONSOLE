#ifndef __DEMODULATION_H__
#define __DEMODULATION_H__

#include "Modt.h"

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

/* PSK Types */
#ifndef __MODT_PSK_TYPE
#define __MODT_PSK_TYPE
#define MODT_NORMAL_PSK_TYPE	0
#define MODT_SHIFTED_PSK_TYPE	1
#define MODT_OFFSET_PSK_TYPE	2
#endif

/* Symbol Phase Continuity */
#ifndef __MODT_SYMBOL_PHASE_CONTINUITY
#define __MODT_SYMBOL_PHASE_CONTINUITY
#define MODT_CONTINUOUS_SYMBOL_PHASE		0
#define MODT_DISCONTINUOUS_SYMBOL_PHASE		1
#endif

	/* Specifies parameter values describing the synchronization sequence and the range of bits over which
	to search for the sequence.*/
	typedef struct {
		/* Specifies the expected location of the first symbol of the sync sequence. This value is an
		index to the input complex waveform. A value of -1 searches the entire input complex waveform and
		ignores the sync location uncertainty (symbols) parameter.*/
		int expectedSyncLocation;
		/* Specifies the mapped symbol pattern used to synchronize the bit stream. To prevent false
		synchronization, select this pattern such that there is a low probability of accidental
		correlation to non-synchronization parts of the data stream. You can use the relevent
		ModtMapBitsTo...Symbols()(... represents the modulation/demodulation type like FSK, PSK, etc)
		function to generate the syncSequence. If this parameter is NULL, the signal is still demodulated,
		but there is a phase ambiguity in the recovered symbols.*/
		niComplexNum *syncSequence;
		/* Number of elements in the syncSequence.*/
		int syncSequenceLength;
		/* Specifies the number of symbols before or after the expected sync location to where the first
		symbol of the sync sequence may be located. This parameter is ignored if the expected sync
		location parameter is set to -1.*/
		int syncLocationUncertainity;
		/* Specifies the distance that the sync sequence is indented into the information block, that is,
		the number of symbols preceding the sync sequence that are demodulated. For example, a value of
		10 indicates that the output bit stream will consist of 10 data symbols, followed by the sync
		sequence, followed by the remaining data symbols.*/
		int syncIndent;
	} SynchronizationParameters;


	/* Contains the results of measurements performed by the FSK demodulator.*/
	typedef struct {
		/* The measured carrier frequency offset in Hz. It is removed from the output recovered complex
		waveform.*/
		double frequencyOffset;
		/* The measured carrier frequency drift in Hz. It is not removed from the output recovered
		complex waveform.*/
		double frequencyDrift;
		/* The measured FSK deviation error in Hz.*/
		double deviationError;
		/* The measured FSK error in Hz. This is an average of the average rms deviation error for each
		FSK state.*/
		double FSKError;
		/* The index value of the symbol within the input complex waveform where the peak correlation to
		the sync sequence was found. If no sync sequence is specified in the synchronization parameters
		input cluster, this parameter outputs the offset from the start of the input complex waveform to
		the first complete symbol.*/
		double syncFoundIndex;
	} FSKMeasurements;

	/* Contains the results of measurements performed by the PSK demodulator.*/
	typedef struct {
		/* The measured carrier frequency offset in Hz. It is removed from the output recovered complex
		waveform.*/
		double frequencyOffset;
		/* The measured carrier frequency drift in Hz. It is not removed from the output recovered
		complex waveform.*/
		double frequencyDrift;
		/* The measured phase offset in degrees. It is removed from the recovered complex waveform.*/
		double phaseOffset;
		/* The symbol index within the input complex waveform where the peak correlation to the sync
		sequence was found. If no sync sequence is specified in the synchronization parameters input
		cluster, this parameter outputs the offset from the start of the input complex waveform to the
		first complete symbol.*/
		double syncFoundIndex;
	} PSKMeasurements;

	typedef PSKMeasurements ASKMeasurements;

	typedef PSKMeasurements PAMMeasurements;


	/* Contains the results of measurements performed by the QAM demodulator.*/
	typedef struct {
		/* The measured carrier frequency offset in Hz. It is removed from the output recovered complex
		waveform.*/
		double frequencyOffset;
		/* The measured carrier frequency drift in Hz. It is not removed from the output recovered
		complex waveform.*/
		double frequencyDrift;
		/* The measured phase offset in degrees. It is removed from the recovered complex waveform.*/
		double phaseOffset;
		/* The symbol index within the input complex waveform where the peak correlation to the sync
		sequence was found. If no sync sequence is specified in the synchronization parameters input
		cluster, this parameter outputs the offset from the start of the input complex waveform to the
		first complete symbol.*/
		double syncFoundIndex;
	} QAMMeasurements;

	/* Contains the results of measurements performed by the MSK demodulator.*/
	typedef struct {
		/* The measured carrier frequency offset in Hz. It is removed from the output recovered complex
		waveform.*/
		double frequencyOffset;
		/* The measured carrier frequency drift in Hz. It is not removed from the output recovered
		complex waveform.*/
		double frequencyDrift;
		/* The symbol index within the input complex waveform where the peak correlation of the sync
		sequence was found. If no sync sequence is specified in the synchronization parameters input
		cluster, this parameter outputs the offset from the start of the input complex waveform to the
		first complete symbol.*/
		double syncFoundIndex;
	} MSKMeasurements;
	
	typedef MSKMeasurements CPMMeasurements;
	
	/* Contains the results of Impairment measurements.*/
	typedef struct {
		/* The DC offset of the I waveform, expressed as a percentage of the largest I or Q value in the
		symbol map.*/
		double IDCOffset;
		/* The DC offset of the Q waveform, expressed as a percentage of the largest I or Q value in the
		symbol map.*/
		double QDCOffset;
		/* The offset in dB of the constellation origin from its ideal location.*/
		double originOffset;
		/* The measured ratio of I gain to Q gain in dB.*/
		double iqGainImbalance;
		/* The measured modulation error ratio in dB.*/
		double modulationErrorRatio;
		/* The measured quadrature skew of the complex waveform in degrees.*/
		double quadratureSkew;
	} QuadratureImpairments;

	typedef struct {
		/* The DC offset of the I waveform, expressed as a percentage of the largest I or Q value in the
		symbol map.*/
		double IDCOffset;
		/* The DC offset of the Q waveform, expressed as a percentage of the largest I or Q value in the
		symbol map.*/
		double QDCOffset;
		/* The offset in dB of the constellation origin from its ideal location.*/
		double originOffset;
		/* The measured modulation error ratio in dB.*/
		double modulationErrorRatio;
	} PAMQuadratureImpairments;

	typedef PAMQuadratureImpairments ASKQuadratureImpairments;

	int CVIFUNC ModtCalculatePostTriggerBER_FibonacciPNSequence ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int PNSequenceOrder,
		double BERTriggerThreshold,
		double confidenceLevel,
		int reset,
		double *BER,
		double *accumulatedBER,
		int *triggerFound,
		unsigned int *triggerFoundIndex);

	int CVIFUNC ModtCalculatePostTriggerBER_GaloisPNSequence ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int PNSequenceOrder,
		double BERTriggerThreshold,
		double confidenceLevel,
		int reset,
		double *BER,
		double *accumulatedBER,
		int *triggerFound,
		unsigned int *triggerFoundIndex);

	int CVIFUNC ModtCalculatePostTriggerBER_UserPattern ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const unsigned char referenceBitPattern[],
		int numReferenceBitPatternElements,
		double BERTriggerThreshold,
		double confidenceLevel,
		int reset,
		double *BER,
		double *accumulatedBER,
		int *triggerFound,
		unsigned int *triggerFoundIndex);

	int CVIFUNC ModtMeasureBurstTiming ( ModtHandle handle,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int startIndex,
		int width,
		const double upperMask[],
		const double lowerMask[],
		const double idealPowerCurve[],
		int maskLength,
		int *testPassed,
		int *firstErrorSampleIndex,
		int *correlatedBurstIndex,
		double *amplitudeDroop,
		double *crestFactor);

	int CVIFUNC ModtMeasureRho ( ModtHandle handle,
		const niComplexNum receivedWaveform[],
		const niComplexNum idealWaveform[],
		int numWaveformSamples,
		double *rho);

	int CVIFUNC ModtMeasureASKQuadratureImpairments ( ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		int numRecoveredWaveformElements,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int startIndex,
		int width,
		int reset,
		int *numIndividualSymbolElements,
		ASKQuadratureImpairments *impairments);

	int CVIFUNC ModtMeasureCPMQuadratureImpairments ( ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		const niComplexNum detectedWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		int startIndex,
		int width,
		int *numMagnitudeErrorEVMIndividualSymbolElements,
		int *numPhaseErrorIndividualSymbolElements,
		QuadratureImpairments *impairments);

	int CVIFUNC ModtMeasureMSKQuadratureImpairments (  ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		const niComplexNum detectedWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		int startIndex,
		int width,
		int *numMagnitudeErrorEVMIndividualSymbolElements,
		int *numPhaseErrorIndividualSymbolElements,
		QuadratureImpairments *impairments);

	int CVIFUNC ModtMeasurePAMQuadratureImpairments ( ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		int numRecoveredWaveformElements,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int startIndex,
		int width,
		int reset,
		int *numIndividualSymbolElements,
		PAMQuadratureImpairments *impairments);


	int CVIFUNC ModtMeasurePSKQuadratureImpairments ( ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		int numRecoveredWaveformElements,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		int startIndex,
		int width,
		int reset,
		int *numIndividualSymbolElements,
		QuadratureImpairments *impairments);

	int CVIFUNC ModtMeasureQAMQuadratureImpairments ( ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		int numRecoveredWaveformElements,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int startIndex,
		int width,
		int reset,
		int *numIndividualSymbolElements,
		QuadratureImpairments *impairments);

	int CVIFUNC ModtASKDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		ASKMeasurements *measurements);

	int CVIFUNC ModtCPMDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		double *symbolMap,
		int numSymbolMapRows,
		int numSymbolMapColumns,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		CPMMeasurements *measurements);

	int CVIFUNC ModtFSKDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const double symbolMap[],
		int numSymbolMapElements,
		int symbolPhaseContinuity,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		FSKMeasurements *measurements);

	int CVIFUNC ModtMSKDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int enableDifferentialEncoding,
		int samplesPerSymbol,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		MSKMeasurements *measurements);

	int CVIFUNC ModtPAMDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		PAMMeasurements *measurements);

	int CVIFUNC ModtPSKDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		PSKMeasurements *measurements);

	int CVIFUNC ModtQAMDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		QAMMeasurements *measurements);


	int CVIFUNC ModtGetCPMDetectedComplexWaveform (ModtHandle  handle,
		double *t0,
		double *dt,
		int numDetectedWaveformElements,
		niComplexNum detectedWaveform[]);

	int CVIFUNC ModtGetMSKDetectedComplexWaveform (ModtHandle  handle,
		double *t0,
		double *dt,
		int numDetectedWaveformElements,
		niComplexNum detectedWaveform[]);

	int CVIFUNC ModtGetRecoveredComplexWaveform (ModtHandle  handle,
		double *t0,
		double *dt,
		int numRecoveredWaveformElements,
		niComplexNum recoveredWaveform[]);

	int CVIFUNC ModtGetRecoveredBitStream (ModtHandle handle,
		int numRecoveredBitStreamElements,
		unsigned char recoveredBitStream[]);

	int CVIFUNC ModtGetPhaseError (ModtHandle handle,
		int numIndividualSymbolValues,
		double individualSymbolValues[],
		double *rmsValue,
		double *peakValue,
		int* peakSymbolIndex);

	int CVIFUNC ModtGetMagnitudeError(ModtHandle handle,
		int numIndividualSymbolValues,
		double individualSymbolValues[],
		double *rmsValue,
		double *peakValue,
		int *peakSymbolIndex);

	int CVIFUNC ModtGetEVMMeasurements (ModtHandle handle,
		int numIndividualSymbolValues,
		double individualSymbolValues[],
		double *rmsValue,
		double *peakValue,
		int* peakSymbolIndex);

#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__DEMODULATION_H__