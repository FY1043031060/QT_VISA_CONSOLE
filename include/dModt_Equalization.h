#ifndef __EQUALIZATION_H__
#define __EQUALIZATION_H__

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

	typedef struct {
		int tapsPerSymbol;
		double deltaTraining;
		double deltaSteadyState;
	} FeedforwardEqualizerParameters;
	
	int CVIFUNC ModtASKFeedforwardEqualizerLMS_SpecifyCoefficients ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const niComplexNum equalizerCoefficientsIn[],
		int numEqualizerCoefficients,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtASKFeedforwardEqualizerLMS_SpecifyLength ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int equalizerLength,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtPAMFeedforwardEqualizerLMS_SpecifyCoefficients ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const niComplexNum equalizerCoefficientsIn[],
		int numEqualizerCoefficients,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtPAMFeedforwardEqualizerLMS_SpecifyLength ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int equalizerLength,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtPSKFeedforwardEqualizerLMS_SpecifyCoefficients ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		const niComplexNum equalizerCoefficientsIn[],
		int numEqualizerCoefficients,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtPSKFeedforwardEqualizerLMS_SpecifyLength ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		int equalizerLength,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtQAMFeedforwardEqualizerLMS_SpecifyCoefficients ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const niComplexNum equalizerCoefficientsIn[],
		int numEqualizerCoefficients,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtQAMFeedforwardEqualizerLMS_SpecifyLength ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int equalizerLength,
		const unsigned char trainingBits[],
		int numTrainingBits,
		const FeedforwardEqualizerParameters *eqParameters,
		int reset,
		niComplexNum equalizerCoefficientsOut[],
		int *numOutputWaveformElements,
		int *numOutputBitStreamElements,
		int *numEqErrorElements);

	int CVIFUNC ModtGetEqualizerOutputWaveform(ModtHandle handle,
		double *t0,
		double *dt,
		int numOutputWaveformElements,
		niComplexNum outputWaveform[]);

	int CVIFUNC ModtGetEqualizerOutputBitStream(ModtHandle handle,
		int numOutputBitStreamElements,
		unsigned char outputBitStream[]);

	int CVIFUNC ModtGetEqualizerError(ModtHandle handle,
		int numEqErrorElements,
		double eqError[]);

#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__EQUALIZATION_H__