#ifndef __DMODT_CHANNEL_CODING_H__
#define __DMODT_CHANNEL_CODING_H__

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

/* Convolutional Code Rates */
#define MODT_CONVOLUTIONAL_CODE_RATE_k1_n2		0
#define MODT_CONVOLUTIONAL_CODE_RATE_k1_n3		1
#define MODT_CONVOLUTIONAL_CODE_RATE_k1_n4		2
#define MODT_CONVOLUTIONAL_CODE_RATE_k2_n3		3
#define MODT_CONVOLUTIONAL_CODE_RATE_k3_n4		4


/* BCH Coding Parameters*/
#define MODT_BCH_CODE_TYPE_n7_k4_t1			"7,4,1"
#define MODT_BCH_CODE_TYPE_n15_k11_t1		"15,11,1"
#define MODT_BCH_CODE_TYPE_n15_k7_t2		"15,7,2"
#define MODT_BCH_CODE_TYPE_n15_k5_t3		"15,5,3"
#define MODT_BCH_CODE_TYPE_n31_k26_t1		"31,26,1"
#define MODT_BCH_CODE_TYPE_n31_k21_t2		"31,21,2"
#define MODT_BCH_CODE_TYPE_n31_k16_t3		"31,16,3"
#define MODT_BCH_CODE_TYPE_n31_k11_t5		"31,11,5"
#define MODT_BCH_CODE_TYPE_n31_k6_t7		"31,6,7"
#define MODT_BCH_CODE_TYPE_n63_k57_t1		"63,57,1"
#define MODT_BCH_CODE_TYPE_n63_k51_t2		"63,51,2"
#define MODT_BCH_CODE_TYPE_n63_k45_t3		"63,45,3"
#define MODT_BCH_CODE_TYPE_n63_k39_t4		"63,39,4"
#define MODT_BCH_CODE_TYPE_n63_k36_t5		"63,36,5"
#define MODT_BCH_CODE_TYPE_n63_k30_t6		"63,30,6"
#define MODT_BCH_CODE_TYPE_n63_k24_t7		"63,24,7"
#define MODT_BCH_CODE_TYPE_n63_k18_t10		"63,18,10"
#define MODT_BCH_CODE_TYPE_n63_k16_t11		"63,16,11"
#define MODT_BCH_CODE_TYPE_n63_k10_t13		"63,10,13"
#define MODT_BCH_CODE_TYPE_n63_k7_t15		"63,7,15"
#define MODT_BCH_CODE_TYPE_n127_k120_t1		"127,120,1"
#define MODT_BCH_CODE_TYPE_n127_k113_t2		"127,113,2"
#define MODT_BCH_CODE_TYPE_n127_k106_t3		"127,106,3"
#define MODT_BCH_CODE_TYPE_n127_k99_t4		"127,99,4"
#define MODT_BCH_CODE_TYPE_n127_k92_t5		"127,92,5"
#define MODT_BCH_CODE_TYPE_n127_k85_t6		"127,85,6"
#define MODT_BCH_CODE_TYPE_n127_k78_t7		"127,78,7"
#define MODT_BCH_CODE_TYPE_n127_k71_t9		"127,71,9"
#define MODT_BCH_CODE_TYPE_n127_k64_t10		"127,64,10"
#define MODT_BCH_CODE_TYPE_n127_k57_t11		"127,57,11"
#define MODT_BCH_CODE_TYPE_n127_k50_t13		"127,50,13"
#define MODT_BCH_CODE_TYPE_n127_k43_t14		"127,43,14"
#define MODT_BCH_CODE_TYPE_n127_k36_t15		"127,36,15"
#define MODT_BCH_CODE_TYPE_n127_k29_t21		"127,29,21"
#define MODT_BCH_CODE_TYPE_n127_k22_t23		"127,22,23"
#define MODT_BCH_CODE_TYPE_n127_k15_t27		"127,15,27"
#define MODT_BCH_CODE_TYPE_n127_k8_t31		"127,8,31"
#define MODT_BCH_CODE_TYPE_n255_k247_t1		"255,247,1"
#define MODT_BCH_CODE_TYPE_n255_k239_t2		"255,239,2"
#define MODT_BCH_CODE_TYPE_n255_k231_t3		"255,231,3"
#define MODT_BCH_CODE_TYPE_n255_k223_t4		"255,223,4"
#define MODT_BCH_CODE_TYPE_n255_k215_t5		"255,215,5"
#define MODT_BCH_CODE_TYPE_n255_k207_t6		"255,207,6"
#define MODT_BCH_CODE_TYPE_n255_k199_t7		"255,199,7"
#define MODT_BCH_CODE_TYPE_n255_k191_t8		"255,191,8"
#define MODT_BCH_CODE_TYPE_n255_k187_t9		"255,187,9"
#define MODT_BCH_CODE_TYPE_n255_k179_t10	"255,179,10"
#define MODT_BCH_CODE_TYPE_n255_k171_t11	"255,171,11"
#define MODT_BCH_CODE_TYPE_n255_k163_t12	"255,163,12"
#define MODT_BCH_CODE_TYPE_n255_k155_t13	"255,155,13"
#define MODT_BCH_CODE_TYPE_n255_k147_t14	"255,147,14"
#define MODT_BCH_CODE_TYPE_n255_k139_t15	"255,139,15"
#define MODT_BCH_CODE_TYPE_n255_k131_t18	"255,131,18"
#define MODT_BCH_CODE_TYPE_n255_k123_t19	"255,123,19"
#define MODT_BCH_CODE_TYPE_n255_k115_t21	"255,115,21"
#define MODT_BCH_CODE_TYPE_n255_k107_t22	"255,107,22"
#define MODT_BCH_CODE_TYPE_n255_k99_t23		"255,99,23"
#define MODT_BCH_CODE_TYPE_n255_k91_t25		"255,91,25"
#define MODT_BCH_CODE_TYPE_n255_k87_t26		"255,87,26"
#define MODT_BCH_CODE_TYPE_n255_k79_t27		"255,79,27"
#define MODT_BCH_CODE_TYPE_n255_k71_t29		"255,71,29"
#define MODT_BCH_CODE_TYPE_n255_k63_t30		"255,63,30"
#define MODT_BCH_CODE_TYPE_n255_k55_t31		"255,55,31"
#define MODT_BCH_CODE_TYPE_n255_k47_t42		"255,47,42"
#define MODT_BCH_CODE_TYPE_n255_k45_t43		"255,45,43"
#define MODT_BCH_CODE_TYPE_n255_k37_t45		"255,37,45"
#define MODT_BCH_CODE_TYPE_n255_k29_t47		"255,29,47"
#define MODT_BCH_CODE_TYPE_n255_k21_t55		"255,21,55"
#define MODT_BCH_CODE_TYPE_n255_k13_t59		"255,13,59"
#define MODT_BCH_CODE_TYPE_n255_k9_t63		"255,9,63"
#define MODT_BCH_CODE_TYPE_n511_k502_t1		"511,502,1"
#define MODT_BCH_CODE_TYPE_n511_k493_t2		"511,493,2"
#define MODT_BCH_CODE_TYPE_n511_k484_t3		"511,484,3"
#define MODT_BCH_CODE_TYPE_n511_k475_t4		"511,475,4"
#define MODT_BCH_CODE_TYPE_n511_k466_t5		"511,466,5"
#define MODT_BCH_CODE_TYPE_n511_k457_t6		"511,457,6"
#define MODT_BCH_CODE_TYPE_n511_k448_t7		"511,448,7"
#define MODT_BCH_CODE_TYPE_n511_k439_t8		"511,439,8"
#define MODT_BCH_CODE_TYPE_n511_k430_t9		"511,430,9"
#define MODT_BCH_CODE_TYPE_n511_k421_t10	"511,421,10"
#define MODT_BCH_CODE_TYPE_n511_k412_t11	"511,412,11"
#define MODT_BCH_CODE_TYPE_n511_k403_t12	"511,403,12"
#define MODT_BCH_CODE_TYPE_n511_k394_t13	"511,394,13"
#define MODT_BCH_CODE_TYPE_n511_k385_t14	"511,385,14"
#define MODT_BCH_CODE_TYPE_n511_k376_t15	"511,376,15"
#define MODT_BCH_CODE_TYPE_n511_k367_t16	"511,367,16"
#define MODT_BCH_CODE_TYPE_n511_k358_t18	"511,358,18"
#define MODT_BCH_CODE_TYPE_n511_k349_t19	"511,349,19"
#define MODT_BCH_CODE_TYPE_n511_k340_t20	"511,340,20"
#define MODT_BCH_CODE_TYPE_n511_k331_t21	"511,331,21"
#define MODT_BCH_CODE_TYPE_n511_k322_t22	"511,322,22"
#define MODT_BCH_CODE_TYPE_n511_k313_t23	"511,313,23"
#define MODT_BCH_CODE_TYPE_n511_k304_t25	"511,304,25"
#define MODT_BCH_CODE_TYPE_n511_k295_t26	"511,295,26"
#define MODT_BCH_CODE_TYPE_n511_k286_t27	"511,286,27"
#define MODT_BCH_CODE_TYPE_n511_k277_t28	"511,277,28"
#define MODT_BCH_CODE_TYPE_n511_k268_t29	"511,268,29"
#define MODT_BCH_CODE_TYPE_n511_k259_t30	"511,259,30"
#define MODT_BCH_CODE_TYPE_n511_k250_t31	"511,250,31"
#define MODT_BCH_CODE_TYPE_n511_k241_t36	"511,241,36"
#define MODT_BCH_CODE_TYPE_n511_k238_t37	"511,238,37"
#define MODT_BCH_CODE_TYPE_n511_k229_t38	"511,229,38"
#define MODT_BCH_CODE_TYPE_n511_k220_t39	"511,220,39"
#define MODT_BCH_CODE_TYPE_n511_k211_t41	"511,211,41"
#define MODT_BCH_CODE_TYPE_n511_k202_t42	"511,202,42"
#define MODT_BCH_CODE_TYPE_n511_k193_t43	"511,193,43"
#define MODT_BCH_CODE_TYPE_n511_k184_t45	"511,184,45"
#define MODT_BCH_CODE_TYPE_n511_k175_t46	"511,175,46"
#define MODT_BCH_CODE_TYPE_n511_k166_t47	"511,166,47"
#define MODT_BCH_CODE_TYPE_n511_k157_t51	"511,157,51"
#define MODT_BCH_CODE_TYPE_n511_k148_t53	"511,148,53"
#define MODT_BCH_CODE_TYPE_n511_k139_t54	"511,139,54"
#define MODT_BCH_CODE_TYPE_n511_k130_t55	"511,130,55"
#define MODT_BCH_CODE_TYPE_n511_k121_t58	"511,121,58"
#define MODT_BCH_CODE_TYPE_n511_k112_t59	"511,112,59"
#define MODT_BCH_CODE_TYPE_n511_k103_t61	"511,103,61"
#define MODT_BCH_CODE_TYPE_n511_k94_t62		"511,94,62"
#define MODT_BCH_CODE_TYPE_n511_k85_t63		"511,85,63"
#define MODT_BCH_CODE_TYPE_n511_k76_t85		"511,76,85"
#define MODT_BCH_CODE_TYPE_n511_k67_t87		"511,67,87"
#define MODT_BCH_CODE_TYPE_n511_k58_t91		"511,58,91"
#define MODT_BCH_CODE_TYPE_n511_k49_t93		"511,49,93"
#define MODT_BCH_CODE_TYPE_n511_k40_t95		"511,40,95"
#define MODT_BCH_CODE_TYPE_n511_k31_t109	"511,31,109"
#define MODT_BCH_CODE_TYPE_n511_k28_t111	"511,28,111"
#define MODT_BCH_CODE_TYPE_n511_k19_t119	"511,19,119"
#define MODT_BCH_CODE_TYPE_n511_k10_t121	"511,10,121"

/* Golay CodeTypes */
#define MODT_GOLAY_CODE_TYPE_n23_k12_t3		0
#define MODT_GOLAY_CODE_TYPE_n24_k12_t3		1

/*RS Symbol Mapping */
#define MODT_RS_SYMBOL_MAPPING_POLYNOMIAL	0
#define MODT_RS_SYMBOL_MAPPING_EXPONENT		1

/*RS Message Poly order*/
#define MODT_RS_MESSAGE_POLY_ORDER_ASCENDING_POWERS_OF_X 		0
#define MODT_RS_MESSAGE_POLY_ORDER_DESCENDING_POWERS_OF_X 		1

/*RS Shortening Zeros location*/
#define MODT_RS_SHORTENING_ZERO_LOCATION_PRIOR_MESSAGE    0
#define MODT_RS_SHORTENING_ZERO_LOCATION_POST_MESSAGE     1

/*RS Parity Poly order*/
#define MODT_RS_PARITY_POLY_ORDER_ASCENDING_POWERS_OF_X 		0
#define MODT_RS_PARITY_POLY_ORDER_DESCENDING_POWERS_OF_X 		1

/*RS Parity  Position*/
#define MODT_RS_PARITY_POSITION_BEGINNING	0
#define MODT_RS_PARITY_POSITION_END			1

/*RS Attribute IDs*/
#define MODT_REED_SOLOMON_PRIMITIVE_POLY				0
#define MODT_REED_SOLOMON_SYMBOL_MAPPING				1
#define MODT_REED_SOLOMON_GALOIS_PRIMITIVE_ELEMENT		2
#define MODT_REED_SOLOMON_START_ROOT_EXP_GEN_POLY		3
#define MODT_REED_SOLOMON_MESSAGE_POLY_ORDER			4
#define MODT_REED_SOLOMON_SHORTENING_ZEROS_LOCATION		5
#define MODT_REED_SOLOMON_PARITY_POLY_ORDER				6
#define MODT_REED_SOLOMON_PARITY_POSITION				7

	int CVIFUNC ModtBCHDecoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const char codingParametersNKT[],
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtBCHEncoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const char codingParametersNKT[],
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtViterbiDecoderHardDecision_GeneratorMatrix ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const unsigned int *generatorMatrix,
		int numGeneratorMatrixRows,
		int numGeneratorMatrixColumns,
		int constraintLength,
		unsigned int initialState,
		int tracebackDepth,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtViterbiDecoderHardDecision_Rate ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int codeRate,
		int constraintLength,
		unsigned int initialState,
		int tracebackDepth,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtViterbiDecoderSoftDecision_GeneratorMatrix ( ModtHandle handle,
		const int inputIntegers[],
		int numInputIntegers,
		const unsigned int *generatorMatrix,
		int numGeneratorMatrixRows,
		int numGeneratorMatrixColumns,
		int constraintLength,
		unsigned int initialState,
		int numSoftDecisionBits,
		int tracebackDepth,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtViterbiDecoderSoftDecision_Rate ( ModtHandle handle,
		const int inputIntegers[],
		int numInputIntegers,
		int codeRate,
		int constraintLength,
		unsigned int initialState,
		int numSoftDecisionBits,
		int tracebackDepth,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtViterbiDecoderUnQuantized_GeneratorMatrix ( ModtHandle handle,
		const double inputSymbols[],
		int numInputSymbols,
		const unsigned int *generatorMatrix,
		int numGeneratorMatrixRows,
		int numGeneratorMatrixColumns,
		int constraintLength,
		unsigned int initialState,
		int tracebackDepth,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtViterbiDecoderUnQuantized_Rate ( ModtHandle handle,
		const double inputSymbols[],
		int numInputSymbols,
		int codeRate,
		int constraintLength,
		unsigned int initialState,
		int tracebackDepth,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtConvolutionalEncoder_GeneratorMatrix ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const unsigned int *generatorMatrix,
		int numGeneratorMatrixRows,
		int numGeneratorMatrixColumns,
		int constraintLength,
		unsigned int initialState,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtConvolutionalEncoder_Rate ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int codeRate,
		int constraintLength,
		unsigned int initialState,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements,
		unsigned int *finalState);

	int CVIFUNC ModtDepunctureDataStream ( ModtHandle handle,
		const double inputDataStream[],
		int numInputDataStreamElements,
		const unsigned char *puncturePattern,
		int numPuncturePatternRows,
		int numPuncturePatternColumns,
		double erasureValue,
		int reset,
		int outputDataStreamArraySize,
		double outputDataStream[],
		int *actualNumOutputDataStreamElements);

	int CVIFUNC ModtDespreadSymbols ( ModtHandle handle,
		const unsigned char inputChipStream[],
		int numInputChipStreamBits,
		const unsigned char spreadingCode[],
		int numSpreadingCodeBits,
		int syncSearchDepth,
		double syncConfidenceThreshold,
		int reset,
		int numOutputBitStreamBits,
		unsigned char outputBitStream[],
		int *syncFoundIndex,
		double *syncConfidenceMetric);

	int CVIFUNC ModtGolayDecoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int GolayCodeTypeNKT,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtGolayEncoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int GolayCodeTypeNKT,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtHammingDecoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int hammingOrder,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtHammingEncoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int hammingOrder,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtLDPCDecoder_FloodingSchedule ( ModtHandle handle,
		const unsigned char *parityCheckMatrix,
		int numParityCheckMatrixRows,
		int numParityCheckMatrixColumns,
		const double likelihoodsArray[],
		int numLikelihoodsArrayElements,
		int maximumNumberOfIterations,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtLDPCDecoder_SerialSchedule ( ModtHandle handle,
		const unsigned char *parityCheckMatrix,
		int numParityCheckMatrixRows,
		int numParityCheckMatrixColumns,
		const double likelihoodsArray[],
		int numLikelihoodsArrayElements,
		int maximumNumberOfIterations,
		int reset,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtLDPCEncoder ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const unsigned char *parityCheckMatrixIn,
		int numParityCheckMatrixRows,
		int numParityCheckMatrixColumns,
		int reset,
		unsigned char *parityCheckMatrixOut,
		int outputBitStreamArraySize,
		unsigned char outputBitStream[],
		int *actualNumOutputBitStreamElements);

	int CVIFUNC ModtLDPCGenerateIrregularParityCheckMatrix ( int maximumNumberOfIterations,
		int numberOfColumns,
		int numberOfRows,
		int numberOfOnesInCodeColumn,
		unsigned char *irregularParityCheckMatrix);

	int CVIFUNC ModtLDPCGenerateRegularParityCheckMatrix ( int maximumNumberOfIterations,
		int numberOfColumns,
		int numberOfRows,
		int numberOfOnesInCodeColumn,
		int numberOfOnesInCodeRow,
		unsigned char *regularParityCheckMatrix);

	int CVIFUNC ModtPunctureDataStream ( ModtHandle handle,
		const int inputDataStream[],
		int numInputDataStreamElements,
		const unsigned char *puncturePattern,
		int numPuncturePatternRows,
		int numPuncturePatternColumns,
		int reset,
		int outputDataStreamArraySize,
		int outputDataStream[],
		int *actualNumOutputDataStreamElements);

	int CVIFUNC ModtRSSymbolDecoder_Normal ( ModtHandle handle,
		const int inputSymbols[],
		int numInputSymbols,
		int codeWordLength,
		int dataWordLength,
		int reset,
		int outputSymbolsArraySize,
		int outputSymbols[],
		int *actualNumOutputSymbols);

	int CVIFUNC ModtRSSymbolDecoder_Shortened ( ModtHandle handle,
		const int inputSymbols[],
		int numInputSymbols,
		int codeWordLength,
		int dataWordLength,
		int bitsPerRSSymbol,
		int reset,
		int outputSymbolsArraySize,
		int outputSymbols[],
		int *actualNumOutputSymbols);

	int CVIFUNC ModtRSSymbolEncoder_Normal ( ModtHandle handle,
		const int inputSymbols[],
		int numInputSymbols,
		int codeWordLength,
		int dataWordLength,
		int reset,
		int outputSymbolsArraySize,
		int outputSymbols[],
		int *actualNumOutputSymbols);

	int CVIFUNC ModtRSSymbolEncoder_Shortened ( ModtHandle handle,
		const int inputSymbols[],
		int numInputSymbols,
		int codeWordLength,
		int dataWordLength,
		int bitsPerRSSymbol,
		int reset,
		int outputSymbolsArraySize,
		int outputSymbols[],
		int *actualNumOutputSymbols);

	int CVIFUNC ModtSpreadSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const unsigned char spreadingCode[],
		int numSpreadingCodeBits,
		int numOutputChipStreamChips,
		unsigned char outputChipStream[]);

#pragma pack(pop) 

#ifdef __cplusplus
} // extern "C"
#endif

#endif /*__DMODT_CHANNEL_CODING_H__*/
