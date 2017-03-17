#ifndef __DMODT_INTERLEAVING_H__
#define __DMODT_INTERLEAVING_H__

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

	int CVIFUNC ModtBlockInterleaveMatrix ( ModtHandle handle,
		const int inputData[],
		int numInputDataElements,
		int numberOfRows,
		int numberOfColumns,
		int reset,
		int outputDataArraySize,
		int outputData[],
		int *actualNumOutputDataElements);

	int CVIFUNC ModtConvolutionalInterleaver_Generic ( ModtHandle handle,
		const int inputData[],
		int numInputDataElements,
		const int interleaverDelays[],
		int numInterleaverDelays,
		const int *initialState,
		int numInitialStateRows,
		int numInitialStateColumns,
		int reset,
		int outputData[]);

	int CVIFUNC ModtConvolutionalInterleaver_Standard ( ModtHandle handle,
		const int inputData[],
		int numInputDataElements,
		int numberOfBranches,
		int unitDelay,
		const int *initialState,
		int numInitialStateRows,
		int numInitialStateColumns,
		int reset,
		int outputData[]);

	int CVIFUNC ModtPermute ( ModtHandle handle,
		const int inputData[],
		int numInputDataElements,
		const int permutationArray[],
		int numPermutationArrayElements,
		int reset,
		int outputDataArraySize,
		int outputData[],
		int *actualNumOutputDataElements);

#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__DMODT_INTERLEAVING_H__