#ifndef __DMODT_UTILITY_H_
#define __DMODT_UTILITY_H_

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

/* Digital Modulation Types */
#define MODT_FSK	0
#define MODT_PSK    1
#define MODT_QAM    2
#define MODT_MSK    3
#define MODT_PAM    4
#define MODT_ASK    5
#define MODT_CPM    6

/* Filter Types */
#define MODT_NO_FILTER                  0
#define MODT_RAISED_COSINE_FILTER       1
#define MODT_ROOT_RAISED_COSINE_FILTER  2
#define MODT_GAUSSIAN_FILTER            3

/* PSK Types */
#ifndef __MODT_PSK_TYPE
#define __MODT_PSK_TYPE
#define MODT_NORMAL_PSK_TYPE	0
#define MODT_SHIFTED_PSK_TYPE	1
#define MODT_OFFSET_PSK_TYPE	2
#endif

/* Packed Bit Orders */
#define MODT_MSB_FIRST_PACKED_BIT_ORDER		0
#define MODT_LSB_FIRST_PACKED_BIT_ORDER		1

/* Integer Formats */
#define MODT_UNSIGNED_INTEGER_FORMAT	0
#define MODT_SIGNED_INTEGER_FORMAT		1

	int CVIFUNC ModtGenerateBits_Fibonacci_PNOrder ( ModtHandle handle,
		int totalBits,
		int PNSequenceOrder,
		int seedIn,
		int reset,
		unsigned char outputBitStream[],
		int *seedOut);

	int CVIFUNC ModtGenerateBits_Fibonacci_PrimitivePolynomial ( ModtHandle handle,
		int totalBits,
		const unsigned char primitivePolynomial[],
		int numPrimitivePolynomialElements,
		int seedIn,
		int reset,
		unsigned char outputBitStream[],
		int *seedOut);

	int CVIFUNC ModtGenerateBits_Galois_PNOrder ( ModtHandle handle,
		int totalBits,
		int PNSequenceOrder,
		int seedIn,
		int reset,
		unsigned char outputBitStream[],
		int *seedOut);

	int CVIFUNC ModtGenerateBits_Galois_PrimitivePolynomial ( ModtHandle handle,
		int totalBits,
		const unsigned char primitivePolynomial[],
		int numPrimitivePolynomialElements,
		int seedIn,
		int reset,
		unsigned char outputBitStream[],
		int *seedOut);

	int CVIFUNC ModtGenerateBits_UserDefined ( ModtHandle handle,
		int totalBits,
		const unsigned char userBaseBitPattern[],
		int numUserBaseBitPatternElements,
		int reset,
		unsigned char outputBitStream[]);	

	int CVIFUNC ModtMapBitsToASKSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int reset,
		int symbolsArraySize,
		niComplexNum symbols[],
		int *actualNumSymbols);

	int CVIFUNC ModtMapBitsToCPMSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const double *symbolMap,
		int numSymbolMapRows,
		int numSymbolMapColumns,
		int reset,
		int symbolsArraySize,
		double symbols[],
		int *actualNumSymbols);

	int CVIFUNC ModtMapBitsToFSKSymbolsEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const double symbolMap[],
		int numSymbolMapElements,
		int reset,
		int symbolsArraySize,
		double symbols[],
		int *actualNumSymbols);

	int CVIFUNC ModtMapBitsToMSKSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int enableDifferentialEncoding,
		int reset,
		int symbolsArraySize,
		double symbols[]);

	int CVIFUNC ModtMapBitsToPAMSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int reset,
		int symbolsArraySize,
		niComplexNum symbols[],
		int *actualNumSymbols);

	int CVIFUNC ModtMapBitsToPSKSymbolsEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		int reset,
		int symbolsArraySize,
		niComplexNum symbols[],
		int *actualNumSymbols);

	int CVIFUNC ModtMapBitsToQAMSymbolsEx ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int reset,
		int symbolsArraySize,
		niComplexNum symbols[],
		int *actualNumSymbols);

	int CVIFUNC ModtPackBits ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int bitsPerInteger,
		int packedBitOrder,
		int integerFormat,
		int reset,
		int outputIntegersArraySize,
		int outputIntegers[],
		int *actualNumOutputIntegers);

	int CVIFUNC ModtUnPackBits ( const int inputIntegers[],
		int numInputIntegers,
		int bitsPerInteger,
		int packedBitOrder,
		int integerFormat,
		int numOutputBitStreamElements,
		unsigned char outputBitStream[]);

	int CVIFUNC ModtGenerateFilterCoefficients ( int modulationType,
		int filterType,
		int pulseShapingSamplesPerSymbol,
		int matchedSamplesPerSymbol,
		double filterParameter,
		int filterLength,
		int pulseShapingFilterCoefficientsArraySize, 
		double pulseShapingFilterCoefficients[], 
		int *actualNumPulseShapingFilterCoefficients, 
		int matchedFilterCoefficientsArraySize, 
		double matchedFilterCoefficients[], 
		int *actualNumMatchedFilterCoefficients);
	
	int CVIFUNC ModtGenerateASKSymbolMap ( int M_ASK,
		niComplexNum symbolMap[]);

	int CVIFUNC ModtGenerateFSKSymbolMap ( double frequencyDeviation,
		int M_FSK,
		double symbolMap[]);
	
	int CVIFUNC ModtGeneratePSKSymbolMap ( int M_PSK,
		niComplexNum symbolMap[]);

	int CVIFUNC ModtGenerateQAMSymbolMap ( int M_QAM,
		niComplexNum symbolMap[]);

	int CVIFUNC ModtGeneratePAMSymbolMap ( int M_PAM,
		niComplexNum symbolMap[]);

	int CVIFUNC ModtGenerateCPMSymbolMap ( int M_CPM,
		const int modulationIndexNumeratorArray[], 
		const int modulationIndexDenominatorArray[],
		int numModulationIndexElements,
		double symbolRate,
		double *symbolMap);
		

	int CVIFUNC ModtCalculateWorstCaseScalingFactor_ASK ( int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		double *waveformScalingFactor);

	int CVIFUNC ModtCalculateWorstCaseScalingFactor_PAM ( int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		double *waveformScalingFactor);

	int CVIFUNC ModtCalculateWorstCaseScalingFactor_PSK ( int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		double *waveformScalingFactor);

	int CVIFUNC ModtCalculateWorstCaseScalingFactor_QAM ( int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		double *waveformScalingFactor);

	int CVIFUNC ModtCalculatePowerAdjustmentAndPAPR ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		double waveformScalingFactor,
		int reset,
		double *fullScaleAdjustment,
		double *PAPR);

#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__DMODT_UTILITY_H_