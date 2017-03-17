#ifndef __MODULATION_H__
#define __MODULATION_H__

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

	int CVIFUNC ModtASKModulate ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		niComplexNum symbolsOut[],
		int *actualNumSymbolsOut);

	int CVIFUNC ModtCPMModulate ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		double *symbolMap,
		int numSymbolMapRows,
		int numSymbolMapColumns,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		double symbolsOut[],
		int *actualNumSymbolsOut);

	int CVIFUNC ModtFSKModulateEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const double symbolMap[],
		int numSymbolMapElements,
		int symbolPhaseContinuity,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		double symbolsOut[],
		int *actualNumSymbolsOut);

	int CVIFUNC ModtMSKModulateEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		int enableDifferentialEncoding,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		double symbolsOut[],
		int *actualNumSymbolsOut);

	int CVIFUNC ModtPAMModulate ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		niComplexNum symbolsOut[],
		int *actualNumSymbolsOut);

	int CVIFUNC ModtPSKModulateEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		niComplexNum symbolsOut[],
		int *actualNumSymbolsOut);

	int CVIFUNC ModtQAMModulateEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int flushBuffers,
		double *t0,
		double *dt,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int symbolsOutArraySize,
		niComplexNum symbolsOut[],
		int *actualNumSymbolsOut);


#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__MODULATION_H__