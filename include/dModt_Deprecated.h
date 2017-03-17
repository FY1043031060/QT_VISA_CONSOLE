#ifndef __DMODT_DEPRECATED_H__
#define __DMODT_DEPRECATED_H__

#include "Modt.h"
#include "dModt_Demodulation.h"

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

/* ModtGeneratePulseShapingFilterCoefficients
	Calculates filter coefficients for pulse shaping filters applied by the digital modulation
	functions and demodulation functions. The calculated filter coefficients are used during
	modulation to reduce the bandwidth of the transmitted signal, and during demodulation to reduce
	intersymbol interference. The pulse shaping filter can be used either in transmission or for
	demodulation of PSK-, FSK-, MSK-, and QAM-modulated signals.
Inputs:
    digitalModulationType
        - Modulation type specifies the type of modulation or demodulation for which to generate
        filter coefficients. Valid values are:
            MODT_FSK
            MODT_PSK
            MODT_QAM
            MODT_MSK
    filterType
        - Specifies the class of filter to generate. The selection here must correspond with the
        modulation type input parameter setting. Valid values are:
            MODT_NO_FILTER
            MODT_RAISED_COSINE_FILTER
            MODT_ROOT_RAISED_COSINE_FILTER
            MODT_GAUSSIAN_FILTER
    pulseShapingSamplesPerSymbol
        - Specifies the number of desired samples per symbol for the pulse shaping filter. If the
        pulse shaping filter is used for demodulation, this parameter value must match the samples
        per symbol input to the demodulation function. This must be an even number >2.
        If the pulse shaping filter coefficients are used by the same de/modulation function,
        the pulseShapingSamplesPerSymbol and matchedSamplesPerSymbol input values must be identical.
        	Default Value: 16
    filterParameter
        - Specifies either alpha (rolloff for raised cosine and square root raised cosine filters),
        or BT (the product of the -3dB bandwidth and the symbol period for a Gaussian filter). This
        input is ignored when the filterType parameter is set to MODT_NO_FILTER.
        	Default Value: 0.5
    filterLength
		- Specifies the desired length of the pulse shaping filter, measured in symbols. The length
		of the matched filter can vary according to filterType and digitalModulationType settings.
		Valid values are >1.
			Default Value: 8
    numPulseShapingFilterCoefficients
		- Specifies the number of coefficients for the pulse shaping filter used in modulation.
Outputs:
    pulseShapingFilterCoefficients[]
		- Outputs an ordered array of filter coefficients corresponding to the desired filter
		response for the pulse shaping filter used in modulation. The number of coefficients depends
		on the pulse shaping filter characteristics specified in the filterType input.
*/

	int CVIFUNC ModtGeneratePulseShapingFilterCoefficients ( unsigned short modulationType,
		unsigned short filterType,
		int pulseShapingSamplesPerSymbol,
		double filterParameter,
		int filterLength,
		int numPulseShapingFilterCoefficients,
		double pulseShapingFilterCoefficients[]);

/* ModtGenerateMatchedFilterCoefficients
	Calculates filter coefficients for matched filters applied by the demodulation functions.
	The calculated filter coefficients are used during demodulation to reduce intersymbol
	interference. The matched filter is only used for demodulation.
Inputs:
    digitalModulationType
        - Specifies the type of modulation or demodulation for which to generate filter
        coefficients. Valid values are:
            MODT_FSK
            MODT_PSK
            MODT_QAM
            MODT_MSK
    filterType
        - Specifies the class of filter to generate. The selection here must correspond with the
        modulation type input parameter setting. Valid values are:
            MODT_NO_FILTER
            MODT_RAISED_COSINE_FILTER
            MODT_ROOT_RAISED_COSINE_FILTER
            MODT_GAUSSIAN_FILTER
    matchedSamplesPerSymbol
        - Specifies the number of desired samples per symbol for the demodulation matched filter.
        This parameter value must match the samples per symbol element input to the digital
        demodulation function. Specify an even number >2.If the matched filter coefficients are
        used by the same demodulation function, the pulseShapingSamplesPerSymbol and
        matchedSamplesPerSymbol input values must be identical.
			Default Value: 16
    filterParameter
		- Specifies either alpha (rolloff for raised cosine and square root raised cosine filters),
		or BT (the product of the -3dB bandwidth and the symbol period for a Gaussian filter).
		This input is ignored when the filterType parameter is set to MODT_NO_FILTER.
			Default Value: 0.5
    filterLength
		- Specifies the desired length of the pulse shaping filter, measured in symbols. The
		length of the matched filter can vary according to filter type and modulation type.
		Valid values are >1.
			Default Value: 8
    numMatchedFilterCoefficients
		- Specifies the number of elements in the matchedFilterCoefficients array.

Outputs:
    matchedFilterCoefficients[]
		- Outputs an ordered array of filter coefficients corresponding to the desired filter
		response for the matched filter used in demodulation. The number of coefficients depends on
		the pulse shaping filter characteristics specified in the pulse shaping filter type input.*/

	int CVIFUNC ModtGenerateMatchedFilterCoefficients ( unsigned short modulationType,
		unsigned short filterType,
		int matchedSamplesPerSymbol,
		double filterParameter,
		int filterLength,
		int numMatchedFilterCoefficients,
		double matchedFilterCoefficients[]);

/* ModtGeneratePRBS
	Generates a pseudo-random bit sequence (PRBS) to be modulated. This function generates bit
	sequences based upon a PN sequence. The pattern is repeated until the specified totalNumberOfBits
	is generated.

	Inputs:
	handle
	- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
	handle is used to store state information, which can be used in iterative calls, in calling
	other functions, or recovering state information through other functions. Use the
	ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
	destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
	state information.
	seed
	- Specifies the initial state of the PN generator shift register. If no seed is specified,
	a default seed is used.
	Default Seed: 0xD6BF7DF2
	pnSequenceOrder
	- Specifies the order of the PN bit sequence to be generated. Valid values are between 5 and
	31.
	Default Value: 9
	totalNumberOfBits
	- Specifies the total number of output bits. The generator truncates and/or repeats the bit
	sequence as necessary to output this number of bits in the output bit stream.
	Default Value: 128
	reset
	- Specifies whether to continue generating bits using the previous iteration states. reset must
	be set to TRUE (1) when initializing the PN generator with a new PN seed in. When reset is set
	to FALSE (0), the PN sequence generator picks up where it left off on the previous iteration.
	Default Value: TRUE (1)

	Outputs:
	bitStream[]
	- Outputs the sequence of generated data bits. The length of this array must be equal to the
	totalNumberOfBits input value.
	*/

	int CVIFUNC ModtGeneratePRBS (
		ModtHandle handle,
		int seed,
		int pnSequenceOrder,
		int totalNumberOfBits,
		int reset,
		unsigned char bitStream[]);

/* ModtGenerateCustomBitPattern
	Generates a bit sequence using a user-defined base bit pattern. The selected pattern is repeated
	until the specified totalNumberOfBits is generated.

	Inputs:
	handle
	- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
	handle is used to store state information, which can be used in iterative calls, in calling
	other functions, or recovering state information through other functions. Use the
	ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
	destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
	state information.
	userBaseBitPattern[]
	- Specifies a user-defined base pattern of bits.
	numUserBaseBitPatternBits
	- Specifies the number of bits in the userBaseBitPattern array.
	totalNumberOfBits
	- Specifies the total number of output bits. The generator truncates and/or repeats the bit
	sequence as necessary to output this number of bits in the output bitStream.
	Default Value: 128
	reset
	- Specifies whether to continue generating bits using the previous iteration states. reset must
	be set to TRUE (1) when initializing the PN generator with a new PN seed in. When reset is set
	to FALSE (0), the PN sequence generator picks up where it left off on the previous iteration.
	Default Value: TRUE (1)

	Outputs:
	bitStream[]
	- Outputs the sequence of generated data bits. The length of this array must be equal to the
	totalNumberOfBits input value.
	*/

	int CVIFUNC ModtGenerateCustomBitPattern (
		ModtHandle handle,
		const unsigned char userBaseBitPattern[],
		int numUserBaseBitPatternBits,
		int totalNumberOfBits,
		int reset,
		unsigned char bitStream[]);

/* ModtCalculateBERAfterTrigger
	Calculates the average bit error rate (BER) against a PN sequence. The sequence must be the same
	as the PN sequence generated by the ModtGeneratePRBS function with matching PN order. On first
	call, or whenever you pass 1 (TRUE) to reset, the function steps through each set of N+1 bits in
	the inputBitStream sequence to generate a seed for the PN bit sequence. Subsequent input bits are
	compared to this PN bit sequence. When the BER on the subsequent input bits is below the specified
	BERTriggerThreshold with the specified confidence, the function begins reporting the BER. BER
	calculation begins on the bit following the set of N+1 bits in which the trigger is found. All
	subsequent iterations of the function use a continuation of the same PN sequence until you pass
	1 (TRUE) to the reset parameter.
	The function is "triggered" in that it only reports BER on bits after a match is found. Hence you
	do not need to synchronize your transmitter with the unit under test (UUT)- the test can begin
	before transmission begins. The triggerFound indicator outputs whether the BER measurement has
	started. When 0 (FALSE) is passed to reset, the triggerFoundIndex indicator outputs the starting
	bit for the block of data in which the trigger initially occurred (this is not necessarily the
	current block).

	Inputs:
	handle
	- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
	handle is used to store state information, which can be used in iterative calls, in calling
	other functions, or recovering state information through other functions. Use the
	ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
	destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
	state information.
	inputBitStream[]
	- Specifies the bit sequence over which BER is calculated. This bit stream should include
	only data bits of the PN sequence. It should not include sync bits or guard bits. At least
	64 bits are required for BER measurement.
	numInputBitStreamElements
	- Specifies the number of elements in the inputBitStream array.
	pnSequenceOrder
	- Specifies the order of the transmitted PN bit sequence. This input must match the PN
	sequence order of the bits transmitted to the device under test. Valid values are between 5
	and 31.
	Default Value: 9
	BERTriggerThreshold
	- Specifies the BER threshold that must be exceeded for the triggerFound decision. This value
	determines when the BER measurement begins; bits before this value and seed bits are not
	included in the BER measurement. Valid values are between 0.0 and 1.0.
	Default Value: 0.1
	Note: The number of bits examined for the pretrigger BER used for comparison to the
	BERTriggerThreshold is determined by the specified confidence and BERTriggerThreshold values.
	The following images show the range of required input lengths for a confidence input in the
	range [0.5,0.99] and a BERTriggerThreshold input in the range [0.1,0.5].
	confidence
	- Specifies the level of confidence that the true BER of the bits after sync is below the
	specified BERTriggerThreshold required to report a trigger. Values between 0.0 and 1.0
	represent proportional confidence, ie an input of 0.95 (default) specifies 95% confidence.
	Default Value: 0.95 (95% confidence)
	Tip: Specify a value of -1 to set the minimum number of bits required for a trigger to the
	length of the specified reference bit pattern. This option is useful when the inputBitStream
	is very short.
	Note  The specified confidence can only be reached after processing a minimum number of bits
	in the inputBitStream. As such, this input indirectly specifies the minimum inputBitStream
	length in which a trigger can occur. Specify a confidence value of -1 to allow triggering on
	inputBitStream lengths equal to 3x(PN sequence order).
	reset
	- Specifies whether the function continues bit error rate calculations from a previous
	iteration. Set reset to 1 (TRUE) to reset the trigger and the accumulatedBER measurement. A
	reset setting of 0 (FALSE) maintains the previous synchronization and does not clear the
	existing accumulatedBER value.
	Default Value: 1 (TRUE)

	Outputs:
	triggerFound
	- Returns whether or not the function found PN sequence synchronization exceeding the specified
	BERTriggerThreshold. Pass NULL if you do not need this information.
	triggerFoundIndex
	- Outputs the index value of the first bit where the bit pattern matched the specified trigger.
	This index value indicates the number of bits since the last reset that are not part of the BER
	calculation. Pass NULL if you do not need this information.
	BER
	- Outputs the measured bit error rate as a fraction of the total number of detected bits. The
	determination of BER includes only bits in the current iteration, and only bits after the sync
	location. Pass NULL if you do not need this information.
	accumulatedBER
	- Outputs the bit error rate accumulated over successive instances of this function since the
	last reset. When reset is 0 (FALSE), this value includes all bits since the last sync found.
	Pass NULL if you do not need this information.
	*/

	int CVIFUNC ModtCalculateBERAfterTrigger (
		ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int pnSequenceOrder,
		double BERTriggerThreshold,
		double confidence,
		int reset,
		int *triggerFound,
		int *triggerFoundIndex,
		double *BER,
		double *accumulatedBER);

/* ModtAddAWGN
    This function generates zero-mean complex additive white Gaussian noise (AWGN) and adds it to
    the complex baseband modulated waveform, returning a signal-plus-noise waveform having a
    user-specified Eb/No.
	Eb represents the energy per bit, while No represents the noise variance.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
        handle is used to store state information, which can be used in iterative calls, in calling
        other functions, or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle
        to destroy the handle created. Pass NULL for a one-shot call to the function, if you do not
        need state information.
    inputData[]
        - Specifies the complex-valued signal-only baseband modulated waveform. The real and
        imaginary parts of this complex data array correspond to the in-phase (I) and quadrature-phase
        (Q) data, respectively.
    numInputDataSamples
        - Specifies the length of the input complex waveform (ie, the number of elements in the
        inputData array).
    samplesPerSymbol
        - Specifies the number of samples per symbol in the inputData array.
			Default Value: 16
    bitsPerSymbol
        - Specifies the number of bits per symbol in the modulation format underlying the input
        complex waveform. For example, the number of bits per symbol in quadrature-phase shift keying
        (QPSK) is 2.
			Default Value: 1
    desiredEbNo
        - Specifies the desired Eb/No of the output complex waveform in dB.
			Default Value: 10.00 dB
    seedIn
        - Specifies (when reset is set to TRUE) how the noise sample generator is reseeded. When this
        parameter value is >0, the AWGN generator is reseeded using the seed you specify. Set this
        value to -1 to reseed the AWGN generator with a random seed.
			Default Value: 0xFFFFFFFF (-1)
		Note This parameter is disregarded when reset is set to 0 (FALSE).
    reset
        - Specifies whether the function continues applying AWGN using the previous iteration states.
        reset must be set to 1 (TRUE) whenever you want to reseed the AWGN generator. The AWGN generator
        maintains its previous state when reset is set to 0 (FALSE).
			Default Value: 1 (TRUE)

Outputs:
    outputData[]
        - Outputs the signal-plus-noise complex baseband waveform data. This array contains the number
        of elements specified in the numInputDataSamples input.
*/

	int CVIFUNC ModtAddAWGN ( ModtHandle handle,
		const niComplexNum inputData[],
		int numInputDataElements,
		int samplesPerSymbol,
		int bitsPerSymbol,
		double desiredEbN0,
		int seedIn,
		int reset,
		niComplexNum outputData[]);

/* ModtApplyFadingProfile
		Applies a user-defined profile to fade the complex baseband modulated waveform. If the
		fadingProfileData array is shorter than the inputData array, the function repeats the fading profile
		until the entire inputData array is covered. If the fadingProfileData array is longer than the
		inputData array, the function begins applying the fading profile at the index point where it left
		off during the previous iteration (when reset is set to 0 - FALSE). The t0 and dt values of the
		outputComplexData are identical to those of the inputData.

	Inputs:
		handle
			- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
			handle is used to store state information, which can be used in iterative calls, in calling
			other functions, or recovering state information through other functions. Use the
			ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
			destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
			state information.
		inputData[]
			- Specifies the complex-valued signal-only baseband modulated waveform. The real and
			imaginary parts of this complex data array correspond to the in-phase (I) and quadrature-phase
			(Q) data, respectively.
		numInputDataSamples
			- Specifies the length of the input complex waveform (ie, the number of elements in the
			inputData array).
		fadingProfile[]
			- Specifies the sample-by-sample profile to be applied to the input complex waveform. At each
			call, the function begins applying this fading profile from the index point where it left off
			on the previous iteration unless reset is set to 1 (TRUE).
		numFadingProfileSamples
			- Specifies the number of elements in the fadingProfileData array.
		reset
			- Specifies whether the function begins applying the fading profile at the index point where
			it left off on the last iteration. Set reset to 1 (TRUE) if you want to begin applying the
			fading profile at index point 0.
				Default Value: 1 (TRUE)

	Outputs:
		outputData[]
			- Outputs the complex-valued signal-only baseband modulated waveform after applying the fading
			profile. The real and imaginary parts of this complex data array correspond to the in-phase (I)
			and quadrature-phase (Q) data, respectively. This array contains the number of elements
			specified in the numInputDataSamples input.
	*/

	int CVIFUNC ModtApplyFadingProfile (
		ModtHandle handle,
		const niComplexNum inputData[],
		int numInputDataSamples,
		const niComplexNum fadingProfileData[],
		int numFadingProfileDataSamples,
		int reset,
		niComplexNum outputData[]);


/* ModtFractionalResample
	Inputs a complex-valued waveform and resamples and/or realigns it based on the input parameters
	that you specify. To re-align the input waveform in time, input a non-zero value to the
	initialSampleOffset parameter. Positive (negative values are invalid) initialSampleOffset values
	push the output complex waveform forward or backwards in time, respectively, relative to the
	input complex waveform.
	To resample a waveform, enter a desiredSampleRate that differs from the existing sample rate of
	the input complex waveform. To realign a waveform without changing its sample rate, input a
	value to the desiredSampleRate parameter equal to the existing sample rate. To resample a waveform
	without changing the relative timing offset between the input and output complex waveforms, enter
	a value of 0 to the initialSampleOffset parameter.

	Inputs:
	handle
	- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
	handle is used to store state information, which can be used in iterative calls, in calling
	other functions, or recovering state information through other functions. Use the
	ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
	destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
	state information.
	t0
	- Specifies the trigger(start) time, in seconds, of the acquired inputData array.
	dt
	- Specifies time interval between data points in the acquired inputData array in seconds.
	inputData[]
	- Specifies the complex-valued signal-only baseband modulated waveform. The real and imaginary
	parts of this complex data array correspond to the in-phase (I) and quadrature-phase (Q) data,
	respectively.
	numInputDataSamples
	- Specifies the number of samples in the inputData array.
	initialSampleOffset
	- Specifies the initial sample offset in seconds. This positive value specifies the location
	in time of the first output point relative to the first input point.
	Default Value: 0.0
	desiredSampleRate
	- Specifies the desired sample rate of the output complex waveform data, in units Hz. This
	value can be an integer or a non-integer multiple of the inputData sample rate.
	Default Value: 1.0 Hz
	reset
	- Controls whether the function continues resampling using the previous iteration states.
	reset must be set to TRUE (1) whenever you desire to restart fractional resampling.
	Default Value: TRUE (1)
	numResampledComplexDataSamples
	- Specifies the size of the resampled waveform data array being passed in. The minimum size of
	the array is calculated as:
	resampleFactor 		= newSampleRate / oldSampleRate;
	integerFactor 		= resampleFactor >= 1.0 ? floor (resampleFactor) : 1;
	fractionalFactor 	= resampleFactor / (double) integerFactor;
	numResampledDataLength = ceil (inputDataLength * fractionalFactor) * integerFactor;

	Outputs:
	resampledComplexData[]
	- Outputs the resampled complex baseband waveform data. the resampled complex-valued signal-only
	waveform. The real and imaginary parts of this complex data array correspond to the in-phase (I)
	and quadrature-phase (Q) data, respectively.
	actualNumResampledComplexDataSamples
	- Outputs the actual number of samples in the resampledComplexData array.
	*/

	int CVIFUNC ModtFractionalResample (
		ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputData[],
		int numInputDataSamples,
		double initialSampleOffset,
		double desiredSampleRate,
		int reset,
		int numResampledComplexDataSamples,
		niComplexNum resampledComplexData[],
		int *actualNumResampledComplexDataSamples);

/* ModtMapBitsToOffsetPSKSymbols
    Maps the inputBitStream to corresponding offsetPSKSymbols. Offset is currently only supported
    for M=4.

Inputs:
    handle
		- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
		handle is used to store state information, which can be used in iterative calls, in calling
		other functions, or recovering state information through other functions. Use the
		ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle
		to destroy the handle created. Pass NULL for a one-shot call to the function, if you do not
		need state information.
	inputBitStream[]
        - The bits to be converted to symbols.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolMap[]
        - An ordered array mapping each boolean symbol to its coordinates in the IQ complex plane.
        Use ModtGeneratePSKSymbolMap() function to generate an OffsetPSK symbol map.
    numSymbolMapElements
        - The size of the symbolMap array. This should be equal to 2^N where, N is the number of
        bits per symbol.
    enableDifferentialPSK
        - Enables or disables differential PSK. The symbols can be represented as the transitions
        between constellation points or as the constellation points themselves. Differential
        operation is used to implement PSK formats such as DQPSK and pi/4-DQPSK. Pass 1 to enable or
        0 to disable differential PSK.
    reset
        - Reset controls whether the function continues mapping using the previous iteration states.
        Reset must be 1 whenever you desire to restart mapping.
    numOffsetPSKSymbols
        - Represents the size of the offsetPSKSymbols array being passed in.

Outputs:
    offsetPSKSymbols[]
        - Contains the symbols that represent the numbers passed in. The size of the array is equal
        to numOffsetPSKSymbols which must be at least equal to:
            ceil(numInputBitStreamElements/log_base_2(numSymbolMapElements))
*/

	int CVIFUNC ModtMapBitsToOffsetPSKSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int reset,
		int numSymbols,
		niComplexNum symbols[]);

/* ModtMapBitsToFSKSymbols
    Maps the inputBitStream to corresponding FSKSymbols.

Inputs:
    handle
		- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
		handle is used to store state information, which can be used in iterative calls, in calling
		other functions, or recovering state information through other functions. Use the
		ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
		destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
		state information.
	inputBitStream[]
        - Specifies the incoming bit stream to be mapped to FSKsymbols.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolMap[]
		- Outputs an ordered array mapping each boolean symbol to its desired coordinates in the
		complex plane. Use the ModtGenerateFSKSymbolMap function to generate the symbol map.
	numSymbolMapElements
		- Specifies the number of elements in the symbolMap array. This should be equal to 2N where,
		N is the number of bits per symbol.
	reset
		- Specifies whether the function continues mapping using the previous iteration states. reset
		must be 1 whenever you desire to restart mapping
			Default Value: 1 (TRUE)
    numFskSymbols
		- Specifies the number of elements in the FSKSymbols array. The size must be at least equal
		to:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))

Outputs:
    fskSymbols[]
		- Returns an array of FSK symbols with a one-to-one mapping to the inputBitStream based on
		the specified symbolMap. The size of the array is equal to the value of numFSKSymbols, which
		must be at least equal to:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))
*/

	int CVIFUNC ModtMapBitsToFSKSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const double symbolMap[],
		int numSymbolMapElements,
		int reset,
		int numSymbols,
		double symbols[]);

/* ModtMapBitsToPSKSymbols
    Maps the inputBitStream to corresponding PSKSymbols.

Inputs:
    handle
		- The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
		handle is used to store state information, which can be used in iterative calls, in calling
		other functions, or recovering state information through other functions. Use the
		ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
		destroy the handle created. Pass NULL for a one-shot call to the function, if you do not
		need state information.
	inputBitStream[]
        - Specifies the incoming bit stream to be mapped to PSKSymbols.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolMap[]
		- Outputs an ordered array mapping each boolean symbol to its desired coordinates in the IQ
		complex plane. Use the ModtGeneratePSKSymbolMap function to generate the symbol map.
	numSymbolMapElements
        - Specifies the number of elements in the symbolMap array. This should be equal to 2N where,
        N is the number of bits per symbol.
    enableDifferentialPSK
		- Enables or disables differential PSK. The symbols can be represented as the transitions
		between constellation points or as the constellation points themselves. Differential operation
		is used to implement PSK formats such as DQPSK and  pi/4-DQPSK. Pass 1 to enable or 0 to
		disable differential PSK.
			Default Value: 0 (DISABLE)
    enableShiftedPSK
		- Specifies whether shifted PSK is enabled. For shifted PSK, the constellation is rated by
		DQPSK( pi/n) each symbol. This shift is half the phase angle between adjacent states, which
		is pi/(2n), where n is the number of bits per symbol. Pass 1 to enable or 0 to disable
		shifted PSK.
			Default Value: 0 (DISABLE)
    reset
        - Specifies whether the function continues mapping using the previous iteration states. reset
        must be 1 (TRUE) whenever you desire to restart mapping.
        	Default Value: 1 (TRUE)
    numPskSymbols
        - Specifies the number of elements in the PSKSymbols array. The size must be at least equal to:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))


Outputs:
    pskSymbols[]
		- Returns an array of PSK symbols with a one-to-one mapping to the inputBitStream based on
		the specified symbolMap. The size of the array is equal to the value of numPSKSymbols, which
		must be at least equal to:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))
*/

	int CVIFUNC ModtMapBitsToPSKSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int PSKType,
		int reset,
		int numSymbols,
		niComplexNum symbols[]);

/* ModtMapBitsToQAMSymbols
    Maps the inputBitStream to corresponding QAMSymbols.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel.
        The handle is used to store state information, which can be used in iterative calls,
        in calling other functions, or recovering state information through other functions.
        Use the ModtCreateSessionHandle function to create a handle, and use the
        ModtDestroySessionHandle to destroy the handle created. Pass NULL for a one-shot call to
        the function, if you do not need state information.
    inputBitStream[]
        - Specifies the incoming bit stream to be mapped to QAMSymbols.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolMap[]
        - Outputs an ordered array mapping each boolean symbol to its desired coordinates in the
        IQ complex plane. Use the ModtGenerateQAMSymbolMap function to generate the symbol map.
    numSymbolMapElements
        - Specifies the number of elements in the symbolMap array. This should be equal to 2N
        where, N is the number of bits per symbol.
    reset
        - Specifies whether the function continues mapping using the previous iteration states.
        reset must be 1 (TRUE) whenever you desire to restart mapping.
			Default Value: 1 (TRUE)
    numQamSymbols
        - Specifies the the number of elements in the QAMSymbols array. The size of the array must
        be at least equal to:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))


Outputs:
    qamSymbols[]
        - Returns an array of QAM symbols with a one-to-one mapping to the inputBitStream based
        on the specified symbolMap. The size of the array is equal to the numQAMSymbols input value,
        which must be at least equal to:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))
*/

	int CVIFUNC ModtMapBitsToQAMSymbols ( ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int reset,
		int numSymbols,
		niComplexNum symbols[]);

/* Demodulation Functions*/

/* ModtMeasureOffsetPSKQuadratureImpairments
    This function measures and reports offset PSK quadrature impairments over a single user-
    specified window. The measurements are calculated on a symbol-by-symbol basis at the symbol
    timing. This function must be called once for each measurement window.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel.
        The handle is used to store state information, which can be used in iterative calls, in
        calling other functions, or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle
        to destroy the handle created. Use this handle to recover magnitude error, phase error,
        and EVM error.
    recoveredComplexData[]
        - Specifies the time-aligned and oversampled complex waveform data after matched filtering,
        frequency offset correction, and phase offset correction. Input the recoveredComplexData
        output array of the ModtPSKDemodulate function to this input.
    numRecoveredComplexDataSamples
        - Specifies the number of elements in the recoveredComplexData array.
    inputBitStream[]
        - Specifies the demodulated bit stream from the recoveredBitStream output of the
        ModtPSKDemodulate function.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the
        symbol rate to determine the sample rate.
			Default Value: 16
    symbolMap[]
        - Specifies an ordered array mapping each boolean symbol to its coordinates in the IQ complex
        plane. Use the ModtGeneratePSKSymbolMap function to generate the PSK symbol map.
    numSymbolMapElements
        - Specifies the number of elements in the symbolMap array.
    enableDifferentialPSK
        - Specifies how the modulation represents symbols. Pass ENABLE (1) to represent the symbols
        as the transitions between constellation points. Pass DISABLE (0) to represent the symbols
        as the constellation points themselves. Differential operation is used to implement PSK
        formats such as DQPSK and  /4-DQPSK.
			Default Value: DISABLE (0)
    startIndex
        - Specifies the index of the first symbol for the measurement of impairments. This parameter,
        together with the width parameter, specifies the window over which impairments are measured.
			Default Value: 0
    width
        - Specifies the number of symbols over which to measure impairments. A value of -1 (default)
        measures impairments over all symbols. Positive values must be two or greater. This parameter,
        with the startIndex parameter, specifies the window over which impairments are measured.
			Default Value: -1 (all)
    reset
        - Specifies how the function handles bits from partial symbols in the input bit stream. When
        reset is set to TRUE, bits making up incomplete symbols are discarded. When reset is set to
        FALSE, the function saves the leftover bits and starts with them on the next iteration.
			Default Value: TRUE

Outputs:
    numIndividualSymbolValues
        - Outputs the number of elements in the array used to obtain the magnitude error, phase error,
        or EVM (Error Vector Magnitude) using the ModtGetMagnitudeError, ModtGetPhaseError, and
        functions. Pass NULL if you do not need this information.
    quadratureImpairments
        - Outputs the measured DC offset of the I and Q waveforms as a percentage of the largest I or
        Q value in the symbol map of the recoveredComplexData array. This array also contains IQ gain
        imbalance, modulation error ratio and quadrature skew. Pass NULL if you do not need this
        information.
*/

	int CVIFUNC ModtMeasureOffsetPSKQuadratureImpairments ( ModtHandle handle,
		const niComplexNum recoveredWaveform[],
		int numRecoveredWaveformElements,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int startIndex,
		int width,
		int reset,
		int *numIndividualSymbolElements,
		QuadratureImpairments *impairments);

/* ModtOffsetPSKDemodulate
    This function demodulates a offset PSK-modulated complex baseband waveform and returns the time-
    aligned oversampled complex waveform, the demodulated bit stream, and measurement results obtained
    during demodulation. This function attempts to remove carrier and phase offset by locking to the
    carrier signal.
	Note: Offset mode is only supported for 4-PSK (OQPSK), and use of the offset mode requires some
	form of band-limiting filtration. Raised cosine and root raised cosine are the only valid filter
	types for OQPSK demodulation. Demodulator locking performance degrades with alpha values <0.3 in
	the raised cosine or root raised cosine filter design.
	Note: This function assumes that the input data sample rate is an integer multiple of the symbol
	rate. The integer multiple must match the value of the samplesPerSymbol input value.
	The recoveredComplexWaveform output contains the time-aligned and oversampled complex waveform
	data after frequency offset correction and phase offset correction. The frequency offset and phase
	offset corrections are scalar values applied to the entire block. To obtain the
	recoveredComplexWaveform, use the ModtGetRecoveredComplexWaveform function with these
	numRecoveredComplexDataSamples and ModtHandle parameters. Call the ModtGetRecoveredBitStream
	function with the same ModtHandle passed to this function to obtain the recoveredBitStream array.


Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
        handle is used to store state information, which can be used in iterative calls, in calling
        other functions or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle and the ModtDestroySessionHandle function
        to destroy the handle. Use this handle to recover the ComplexData and BitStream outputs.
    t0
        - Specifies the trigger (start) time of the signal data in seconds.
    dt
        - Specifies the time interval in seconds between data points in the signal data.
    inputData[]
        - Specifies the offset PSK-modulated complex baseband waveform data. The real and imaginary
        parts of this complex data array correspond to the in-phase (I) and quadrature-phase (Q) data,
        respectively.
    numInputDataSamples
        - Specifies the length of the input complex waveform (ie, the number of elements in the
        inputData array).
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the
        symbol rate to determine the sample rate.
			Default Value: 16
    symbolMap[]
        - Specifies an ordered array mapping each boolean symbol to its desired deviation frequency.
        Use the ModtGeneratePSKSymbolMap function to generate the PSK symbol map.
    numSymbolMapElements
        - Specifies the number of elements in the symbolMap array.
    enableDifferentialPSK
        - Specifies how the modulation represents symbols. Pass ENABLE (1) to represent the symbols
        as the transitions between constellation points. Pass DISABLE (0) to represent the symbols
        as the constellation points themselves. Differential operation is used to implement PSK
        formats such as DQPSK and  /4-DQPSK.
			Default Value: DISABLE (0)
    syncParameters
        - Specifies parameter values describing the synchronization sequence and the range of bits
        over which to search for this sequence. Use the ModtMapBitsToPSKSymbols function to generate
        this value. The synchronization parameters are ignored if this value is NULL.
    matchedFilterCoefficients[]
        - Specifies an ordered array containing the desired matched filter coefficients. Use the
        ModtGenerateMatchedFilterCoefficients function to generate this array. Ensure that the
        matchedSamplesPerSymbol input value of the ModtGenerateMatchedFilterCoefficients function is
        equal to the samplesPerSymbol input value of this function.
		Note: When reset? is set to TRUE, there is a transient response of half the filter length at
		the start of the demodulated signal, and the returned output data is shortened by approximately
		half the filter length. When reset? is set to FALSE, the function uses data from the previous
		iteration to eliminate the transient.
		Tip: When reset? is set to TRUE, the number of trailing symbols that are carried over to the
		next iteration during demodulation is upper bounded by [L/2 + P/2 + 4(13 + K)]/K, where L is
		the matched filter length in taps, P is the pulse shaping filter length in taps, and K is the
		number of samples per symbol. For typical values of L = 57, P = 25, and K = 4, this value equals
		27.25 symbols. Therefore when reset? is set to TRUE, a total of 1028 FSK symbols must be input
		to the demodulator to obtain at least 1000 symbols at the output. This formula does not account
		for truncation due to any specified synchronization parameters.
    numMatchedFilterCoefficients
        - Specifies the number of elements in the matchedFilterCoefficients array.
    pulseShapingFilterCoefficients[]
        - Specifies an ordered array containing the coefficients for the desired pulse shaping filter.
        Use the ModtGeneratePulseShapingFilterCoefficients function to generate this array. Ensure that
        the matchedSamplesPerSymbol input value of the ModtGeneratePulseShapingFilterCoefficients
        function is equal to the samplesPerSymbol input value of this function.
		Note: When reset is set to TRUE, there is a transient response of half the filter length at the
		start of the modulated signal, and the returned output data is shortened by approximately half
		the filter length. When reset is set to FALSE, the function uses data from the previous
		iteration to eliminate the transient.
    numPulseShapingFilterCoefficients
        - Size of the pulseShapingFilterCoefficients array.
    reset
        - Specifies whether to continue demodulation using the previous iteration states. reset must be
        1 (TRUE) whenever you want to restart the demodulator. The function resets on the first call
        and when reset is set to 1 (TRUE). Set reset to 0 (FALSE) if the input complex waveform data is
        contiguous with the input complex waveform data from the previous iteration of this function.
			Default Value: 1 (TRUE)

Outputs:
    numRecoveredComplexDataSamples
        - Specifies the actual number of elements in the recoveredComplexData array. Call the
        ModtGetRecoveredComplexWaveform function with the same ModtHandle passed to this function to
        obtain the recoveredComplexData array. Pass NULL if you do not need this information.
    numRecoveredBitStreamElements
        - Specifies the actual number of elements in the recoveredBitStream array. Call the
        ModtGetRecoveredBitStream function with the same ModtHandle passed to this function to obtain
        the recoveredBitStream array. Pass NULL if you do not need this information.
    pskMeasurements
        - Outputs the results of measurements performed by the PSK demodulator. Pass NULL if you do
        not need this information.
*/

	int CVIFUNC ModtOffsetPSKDemodulate ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformElements,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		const SynchronizationParameters *syncParameters,
		const double matchedFilterCoefficients[],
		int numMatchedFilterCoefficients,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int *numRecoveredWaveformElements,
		int *numRecoveredBitStreamElements,
		PSKMeasurements *measurements);
		
	
/* Modulation Functions*/

/* ModtFSKModulate
    Inputs a sequence of data bits, performs FSK modulation, and returns the modulated complex baseband
    waveform in the output FSKModulatedData parameter. The numSymbolMapElements parameter dictates the
    M in M-ary modulation schemes.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
        handle is used to store state information, which can be used in iterative calls, in calling
        other functions, or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
        destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
        state information.
    inputBitStream[]
        - Specifies the sequence of information bits to be modulated.
		Note: For FSK systems with more than 1 bit per symbol, such as 4-FSK, the symbols are
		converted to bits in least significant bit (LSB) first order. For example, if the detected
		symbols are 2,1,... the output bits are 0,1,1,0...
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolRate
        - Specifies the desired symbol rate in units of Hz.
			Default Value: 1.00 Hz
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the symbol
        rate to determine the sample rate.
		For error-free operation, the samples per symbol should be an even number. Applying Carson's
		rule for FSK modulation, the 98% FSK bandwidth is given by:
			0.5 × (1 + r) × symbol rate + peak frequency deviation,
			where 0 < r = 1 is the filter parameter.
		To satisfy Nyquist criterion, a good guideline is given by
			samples per symbol = 2 × ceil(1.5 × bandwidth/symbol rate)
		to obtain 3× oversampling.
		Default Value: 16
    symbolMap[]
        - Specifies an ordered array mapping each boolean symbol to its desired deviation frequency.
        The number of FSK levels in the array must be 2N where N is the number of bits per symbol. Use
		the ModtGenerateFSKSymbolMap function to generate the FSK symbol map.
    numSymbolMapElements
        - Specifies the number of elements in the symbolMap array. The number of FSK levels in the array
        must be 2N, where N is the number of bits per symbol.
    symbolPhaseContinuity
        - Specifies whether or not the phase transitions between symbols are continuous (0) or
        discontinuous (1). Setting this parameter to discontinuous specifies discontinuous phase FSK
        (DPFSK). With DPFSK, modulation consists of selecting the appropriate sinusoid based on the
        input data. Thus when switching from one symbol to the next, there is a discontinuity in the
        FSK signal phase. In order to emulate a hardware-based DPFSK source, the function maintains
        the phase of each independent sinusoid versus time. In this way the DPFSK modulator acts in
        the same fashion as a hardware-based (ie, multiple switched tone generator) FSK modulator.
			Default Value: CONTINUOUS (0)
    pulseShapingfilterCoefficients[]
        - Specifies an ordered array containing the coefficients for the desired pulse shaping filter.
        Use the ModtGeneratePulseShapingFilterCoefficients function to generate the coefficients. When
        generating the filter coefficients, ensure that the value of the pulseShapingSamplesPerSymbol
        input of the ModtGeneratePulseShapingFilterCoefficients function is equal to the value of the
        samplesPerSymbol input to this function.
		Note: When reset is set to TRUE, there is a transient response of half the filter length at the
		start of the modulated signal, and the returned output data is shortened by approximately half
		the filter length. When reset is set to FALSE, the function uses data from the previous iteration
		to eliminate the transient.
    numPulseShapingFilterCoefficients
        - Specifies the number of elements in the pulseShapingFilterCoefficients array.
    reset
        - Specifies whether the function continues modulation using the previous iteration states. The
        function resets on the first call and when reset is set to TRUE. reset must be set to TRUE
        whenever you want to restart the modulator.
			Default Value: TRUE (1)
    numFskModulateDataSamples
        - Specifies the requested number of elements in the FSKModulatedData array.
    numSymbolsOut
        - Specifies the number of elements in the symbolsOut array.

Outputs:
    fskModulatedData[]
        - Outputs the FSK-modulated complex-valued signal-only waveform data. The real and imaginary
        parts of this complex data array correspond to the in-phase (I) and quadrature-phase (Q) data,
        respectively. The upper bound of the size for this array is calculated as:
			samplesPerSymbol × ceil(numInputBitStreamElements/(log2(numSymbolMapElements)))
		The size of the array must be >= the upper bound above.
    actualNumFskModulatedDataSamples
        - Specifies the actual number of elements in the returned FSKModulatedData array.
    symbolsOut[]
        - Outputs the array of mapped symbols, before pulse shaping is applied. The real portion
        corresponds to the carrier frequency offset of the mapped symbol, and the imaginary portion
        is zero. The length of this array is calculated as:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))
		If you do not need this information pass NULL to symbolsOut and pass 0 to the numSymbolsOut input.
*/
	int CVIFUNC ModtFSKModulate (
		ModtHandle  handle,
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
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int numSymbolsOut,
		double symbolsOut[]);

/* ModtMSKModulate
	Inputs a sequence of data bits, performs MSK modulation, and returns the modulated complex
	baseband waveform in the MSKModulatedData output parameter.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel.
        The handle is used to store state information, which can be used in iterative calls,
        in calling other functions, or recovering state information through other functions.
        Use the ModtCreateSessionHandle function to create a handle, and use the
        ModtDestroySessionHandle to destroy the handle created. Pass NULL for a one-shot call
        to the function, if you do not need state information.
    inputBitStream[]
        - Specifies the sequence of information bits to be modulated.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolRate
        - Specifies the desired symbol rate in units of Hz.
			Default Value: 1.00
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the
        symbol rate to determine the sample rate.
			Default Value: 16
    enableDifferentialEncoding
        - Specifies whether to enable (1) or disable (2) differential encoding of the bit stream.
			Default Value: 1 (ENABLE)
    pulseShapingfilterCoefficients[]
        - Specifies an ordered array containing the coefficients for the desired pulse shaping
        filter. Use the ModtGeneratePulseShapingFilterCoefficients function to generate the
        coefficients. When generating the filter coefficients, ensure that the value of the
        pulseShapingSamplesPerSymbol input of the ModtGeneratePulseShapingFilterCoefficients
        function is equal to the value of the samplesPerSymbol input to this function.
		Note: When reset is set to TRUE, there is a transient response of half the filter length
		at the start of the modulated signal, and the returned output data is shortened by
		approximately half the filter length. When reset is set to FALSE, the function uses data
		from the previous iteration to eliminate the transient.
    numPulseShapingFilterCoefficients
        - Specifies the number of elements in the pulseShapingFilterCoefficients array.
    reset
        - Specifies whether the function continues modulation using the previous iteration states.
        The function resets on the first call and when reset is set to 1 (TRUE). reset must be set
        to 1 (TRUE) whenever you want to restart the modulator.
			Default Value: 1 (TRUE)
    numMskModulateDataSamples
        - Specifies the requested number of elements in the MSKModulatedData output array.
    numSymbolsOut
        - Specifies the number of elements in the symbolsOut array.

Outputs:
    mskModulatedData[]
        - Specifies the requested length of the MSKModulatedData output array. The real and
        imaginary parts of this complex data array correspond to the in-phase (I) and quadrature-phase
        (Q) data, respectively. The upper bound of the size for this array is calculated as:
			samplesPerSymbol × numInputBitStreamElements
		The size of the array must be ? the upper bound calculated above.
    actualNumMskModulatedDataSamples
        - Specifies the actual number of elements in the returned MSKModulatedData output array.
    symbolsOut[]
        - Outputs the array of mapped symbols, before pulse shaping is applied. The real portion
        corresponds to the carrier frequency offset of the mapped symbol, and the imaginary portion
        is zero. The length of this array is equal to the of numInputBitStreamElements input value.
        If you do not need this information pass NULL to symbolsOut and pass 0 to the numSymbolsOut
        input.
*/

	int CVIFUNC ModtMSKModulate (
		ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		int enableDifferentialEncoding,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int numSymbolsOut,
		double symbolsOut[]);

/* ModtPSKModulate
	Inputs a sequence of data bits, performs PSK modulation, and returns the modulated complex
	baseband waveform in the output PSKModulatedData parameter. The numSymbolMapElements parameter
	dictates the M in M-ary modulation schemes.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
        handle is used to store state information, which can be used in iterative calls, in calling
        other functions, or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle
        to destroy the handle created. Pass NULL for a one-shot call to the function, if you do not
        need state information.
    inputBitStream[]
        - Specifies the sequence of information bits to be modulated.
		Note: For PSK systems with more than 1 bit per symbol, such as 4-PSK, the symbols are
		converted to bits in least significant bit (LSB) first order. For example, if the detected
		symbols are 2,1,... the output bits are 0,1,1,0...
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolRate
        - Specifies the desired symbol rate in units of Hz.
			Default Value: 1.00
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the
        symbol rate to determine the sample rate.
			Default Value: 16
    symbolMap[]
        - Specifies an ordered array mapping each boolean symbol to its desired deviation frequency.
        Use the ModtGeneratePSKSymbolMap function to generate the PSK symbol map.
    numSymbolMapElements
        - Specifies the number of symbols in the symbolMap array. The number of PSK levels in the
        array must be 2N where N is the number of bits per symbol.
    enableDifferentialPSK
        - Specifies how the modulation represents symbols. Pass ENABLE (1) to represent the symbols
        as the transitions between constellation points. Pass DISABLE (0) to represent the symbols
        as the constellation points themselves. Differential operation is used to implement PSK
        formats such as DQPSK and  pi/4-DQPSK.
			Default Value: DISABLE (0)
    enableShiftedPSK
        - Specifies whether shifted PSK modulation is used. In shifted PSK, the constellation is
        rated by DQPSK( /M) each symbol. This shift is half the phase angle between adjacent states,
        which is pi/(2n), where n is the number of bits per symbol. Pass 1 (SHIFTED) or 0 (NORMAL)
        to control differential PSK.
			Default Value: 0 (NORMAL)
    pulseShapingfilterCoefficients[]
        - Specifies an ordered array containing the coefficients for the desired pulse shaping filter.
        Use the ModtGeneratePulseShapingFilterCoefficients function to generate the coefficients. When
        generating the filter coefficients, ensure that the value of the pulseShapingSamplesPerSymbol
        input of the ModtGeneratePulseShapingFilterCoefficients function is equal to the value of the
        samplesPerSymbol input to this function.
		Note: When reset is set to TRUE, there is a transient response of half the filter length at
		the start of the modulated signal, and the returned output data is shortened by approximately
		half the filter length. When reset is set to FALSE, the function uses data from the previous
		iteration to eliminate the transient.
    numPulseShapingFilterCoefficients
        - Specifies the number of elements in the pulseShapingFilterCoefficients array.
    reset
        - Specifies whether the function continues modulation using the previous iteration states.
        The function resets on the first call and when reset is set to 1 (TRUE). reset must be set to
        1 (TRUE) whenever you want to restart the modulator.
			Default Value: 1 (TRUE)
    numPskModulateDataSamples
        - Specifies the requested number of elements in the PSKModulatedData output array.
    numSymbolsOut
        - Specifies the number of elements in the symbolsOut array.

Outputs:
    pskModulatedData[]
        - Outputs the PSK-modulated complex baseband waveform data. The real and imaginary parts of
        this complex data array correspond to the in-phase (I) and quadrature-phase (Q) data,
        respectively. The upper bound of the size for this array is calculated as:
		samplesPerSymbol * ceil(numInputBitStreamElements/(log2(numSymbolMapElements)))
		The size of the array must be >= the upper bound above.
    actualNumPskModulatedDataSamples
        - Specifies the actual number of elements in the returned PSKModulatedData output array.
    symbolsOut[]
        - Outputs the array of mapped symbols, before pulse shaping is applied. The real portion
        corresponds to the carrier frequency offset of the mapped symbol, and the imaginary portion
        is zero. The length of this array is calculated as:
			ceil(numInputBitStreamElements/log2(numSymbolMapElements))
		If you do not need this information pass NULL to symbolsOut and pass 0 to the
		numSymbolMapElements input.
*/

	int CVIFUNC ModtPSKModulate (
		ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		int enableShiftedPSK,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int numSymbolsOut,
		niComplexNum symbolsOut[]);

/* ModtOffsetPSKModulate
	Inputs a sequence of data bits, performs offset PSK modulation, and returns the modulated complex
	baseband waveform in the output offsetPSKModulatedData parameter. For offset PSK, the ideal symbol
	timing for Q is offset by 1/2 of a symbol period from the ideal symbol timing for I. Offset is
	currently only supported for M=4.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel. The
        handle is used to store state information, which can be used in iterative calls, in calling
        other functions, or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle to
        destroy the handle created. Pass NULL for a one-shot call to the function, if you do not need
        state information.
    inputBitStream[]
        - Specifies the sequence of information bits to be modulated.
		Note: For PSK systems with more than 1 bit per symbol, such as 4-PSK, the symbols are
		converted to bits in least significant bit (LSB) first order. For example, if the detected
		symbols are 2,1,... the output bits are 0,1,1,0...
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolRate
        - Specifies the desired symbol rate in units of Hz.
			Default Value: 1.00
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the symbol
        rate to determine the sample rate.
			Default Value: 16
    symbolMap[]
        - Specifies an ordered array mapping each boolean symbol to its desired deviation frequency.
        Use ModtGeneratePSKSymbolMap function to generate the PSK symbol map.
    numSymbolMapElements
        - Specifies the number of symbols in the symbolMap array. The number of PSK levels in the
        array must be 2N where N is the number of bits per symbol.
    enableDifferentialPSK
        - Specifies how the modulation represents symbols. Pass ENABLE (1) to represent the symbols
        as the transitions between constellation points. Pass DISABLE (0) to represent the symbols as
        the constellation points themselves. Differential operation is used to implement PSK formats
        such as DQPSK and  pi/4-DQPSK.
			Default Value: DISABLE (0)
    pulseShapingfilterCoefficients[]
        - Specifies an ordered array containing the coefficients for the desired pulse shaping filter.
        Use the ModtGeneratePulseShapingFilterCoefficients function to generate the coefficients. When
        generating the filter coefficients, ensure that the value of the pulseShapingSamplesPerSymbol
        input of the ModtGeneratePulseShapingFilterCoefficients function is equal to the value of the
        samplesPerSymbol input to this function.
		Note: When reset is set to TRUE, there is a transient response of half the filter length at
		the start of the modulated signal, and the returned output data is shortened by approximately
		half the filter length. When reset is set to FALSE, the function uses data from the previous
		iteration to eliminate the transient.
    numPulseShapingFilterCoefficients
        - Specifies the number of elements in the pulseShapingFilterCoefficients array.
    reset
        - Specifies whether the function continues modulation using the previous iteration states.
        The function resets on the first call and when reset is set to 1 (TRUE). reset must be set to
        1 (TRUE) whenever you want to restart the modulator.
			Default Value: 1 (TRUE)
    numOffsetPSKModulateDataSamples
        - Specifies the requested number of elements in the offsetPSKModulatedData output array.
    numSymbolsOut
        - Specifies the number of elements in the symbolsOut array.

Outputs:
    offsetPSKModulatedData[]
        - Outputs the offset PSK-modulated complex baseband waveform data. The real and imaginary parts
        of this complex data array correspond to the in-phase (I) and quadrature-phase (Q) data,
        respectively. The upper bound of the size for this array is calculated as:
			samplesPerSymbol * ceil(numInputBitStreamElements/(log2(numSymbolMapElements)))
		The size of the array must be >= the upper bound above.
    actualNumOffsetPSKModulatedDataSamples
        - Specifies the actual number of elements in the returned offsetPSKModulatedData output array.
    symbolsOut[]
        - Outputs the array of mapped symbols, before pulse shaping is applied. The real portion
        corresponds to the carrier frequency offset of the mapped symbol, and the imaginary portion is
        zero. The length of this array is calculated as:
			ceil(numInputBitStreamElements/log<sub2(numSymbolMapElements))
		If you do not need this information pass NULL to symbolsOut and pass 0 to the numSymbolsOut input.
*/

	int CVIFUNC ModtOffsetPSKModulate (
		ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		int enableDifferentialPSK,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int numSymbolsOut,
		niComplexNum symbolsOut[]);

/* ModtQAMModulate
    Inputs a sequence of data bits, performs QAM modulation, and returns the modulated complex
    baseband waveform in the output QAMModulatedData parameter. The numSymbolMapElements parameter
    dictates the M in M-ary modulation schemes.

Inputs:
    handle
        - The handle you obtained from ModtCreateSessionHandle that identifies a data channel.
        The handle is used to store state information, which can be used in iterative calls, in
        calling other functions, or recovering state information through other functions. Use the
        ModtCreateSessionHandle function to create a handle, and use the ModtDestroySessionHandle
        to destroy the handle created. Pass NULL for a one-shot call to the function, if you do not
        need state information.
    inputBitStream[]
        - Specifies the sequence of information bits to be modulated.
    numInputBitStreamElements
        - Specifies the number of elements in the inputBitStream array.
    symbolRate
        - Specifies the desired symbol rate in units of Hz.
			Default Value: 1.00
    samplesPerSymbol
        - Specifies the number of samples dedicated to each symbol. Multiply this value by the
        symbol rate to determine the sample rate.
			Default Value: 16
    symbolMap[]
        - Specifies an ordered array mapping each boolean symbol to its desired deviation frequency.
        Use the ModtGenerateQAMSymbolMap function to generate the QAM symbol map.
    numSymbolMapElements
        - Specifies the number of symbols in the symbolMap array. The number of QAM levels in the
        array must be 2n where n is the number of bits per symbol.
    pulseShapingfilterCoefficients[]
        - Specifies an ordered array containing the coefficients for the desired pulse shaping filter.
        Use the ModtGeneratePulseShapingFilterCoefficients function to generate the coefficients.
        When generating the filter coefficients, ensure that the value of the pulseShapingSamplesPerSymbol
        input of the ModtGeneratePulseShapingFilterCoefficients function is equal to the value of the
        samplesPerSymbol input to this function.
		Note: When reset is set to TRUE, there is a transient response of half the filter length at the
		start of the modulated signal, and the returned output data is shortened by approximately half
		the filter length. When reset is set to FALSE, the function uses data from the previous iteration
		to eliminate the transient.
    numPulseShapingFilterCoefficients
        - Specifies the number of elements in the pulseShapingFilterCoefficients array.
    reset
        - Specifies whether the function continues modulation using the previous iteration states. The
        function resets on the first call and when reset is set to 1 (TRUE). reset must be set to 1 (TRUE)
        whenever you want to restart the modulator.
			Default Value: 1 (TRUE)
    numQamModulateDataSamples
        - Specifies the requested number of elements in the QAMModulatedData output array.
    numSymbolsOut
        - Specifies the number of elements in the symbolsOut array.

Outputs:
    qamModulatedData[]
        - Outputs the QAM-modulated complex baseband waveform data. The real and imaginary parts of
        this complex data array correspond to the in-phase (I) and quadrature-phase (Q) data, respectively.
        The upper bound of the size for this array is calculated as:
		ceil(numInputBitStreamElements/(log2(numSymbolMapElements)))
		The size of the array must be >= the upper bound above.
    actualNumQamModulatedDataSamples
        - Specifies the actual number of elements in the returned QAMModulatedData output array.
    symbolsOut[]
        - Outputs the array of mapped symbols, before pulse shaping is applied. The real portion
        corresponds to the carrier frequency offset of the mapped symbol, and the imaginary portion
        is zero. The length of this array is calculated as:
		ceil(numInputBitStreamElements/log2(numSymbolMapElements))
		If you do not need this information pass NULL to symbolsOut and pass 0 to this input.
*/

	int CVIFUNC ModtQAMModulate (
		ModtHandle handle,
		const unsigned char inputBitStream[],
		int numInputBitStreamElements,
		double symbolRate,
		int samplesPerSymbol,
		const niComplexNum symbolMap[],
		int numSymbolMapElements,
		const double pulseShapingFilterCoefficients[],
		int numPulseShapingFilterCoefficients,
		int reset,
		int modulatedWaveformArraySize,
		niComplexNum modulatedWaveform[],
		int *actualNumModulatedWaveformElements,
		int numSymbolsOut,
		niComplexNum symbolsOut[]);

#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__DMODT_DEPRECATED_H__