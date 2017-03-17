#ifndef __DMODT_IMPAIRMENTS_H__
#define __DMODT_IMPAIRMENTS_H__

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

	/* Specifies the frequency and amplitude of tones.*/
	typedef struct {
		/* Specifies the frequency of the tone in Hz.*/
		double toneFrequency;
		/* Specifies tone amplitude in dB relative to the specified reference power in the function
		ModtAddMultiTone().*/
		double toneRelativePower;
	} ToneParameters;

	int CVIFUNC ModtAddAWGNEx ( ModtHandle handle,
		const niComplexNum inputData[],
		int numInputDataElements,
		int samplesPerSymbol,
		int bitsPerSymbol,
		double desiredEbN0,
		int seedIn,
		int reset,
		niComplexNum outputData[],
		int *seedOut);

	int CVIFUNC ModtAddMultiTone ( ModtHandle handle,
		double dt,
		const niComplexNum inputData[],
		int numInputDataElements,
		const ToneParameters multiToneInfo[],
		int numTones,
		double referencePower,
		int reset,
		niComplexNum outputData[]);

	int CVIFUNC ModtAddPhaseNoise ( ModtHandle handle,
		double t0,
		double dt,
		const niComplexNum inputWaveform[],
		int numInputWaveformSamples,
		double offsetFrequency,
		double noiseDensity,
		double inverseFrequencyExponent,
		int seedIn,
		int reset,
		niComplexNum outputWaveform[],
		int *seedOut);

	int CVIFUNC ModtApplyFlatFadingProfile ( ModtHandle handle,
		const niComplexNum inputData[],
		int numInputDataElements,
		const niComplexNum fadingProfileData[],
		int numFadingProfileDataSamples,
		int reset,
		niComplexNum outputData[]);

	int CVIFUNC ModtApplySelectiveFadingProfile ( ModtHandle handle,
		const niComplexNum inputData[],
		int numInputDataElements,
		const niComplexNum *fadingProfile,
		int numFadingProfileRows,
		int numFadingProfileColumns,
		const double *powerDelayProfile,
		int numPowerDelayProfileRows,
		int numPowerDelayProfileColumns,
		int reset,
		niComplexNum outputData[]);

	int CVIFUNC ModtApplyIQImpairments ( ModtHandle handle,
		double dt,
		const niComplexNum inputData[],
		int numInputDataElements,
		double offsetIDC,
		double offsetQDC,
		double gainImbalanceIQ,
		double quadratureSkew,
		double frequencyOffset,
		int reset,
		niComplexNum impairedComplexData[]);

	int CVIFUNC ModtGenerateRayleighFlatFadingProfile_Gans ( ModtHandle handle,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum fadingProfile[],
		int *seedOut);

	int CVIFUNC ModtGenerateRayleighFlatFadingProfile_Jakes ( ModtHandle handle,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum fadingProfile[],
		int *seedOut);

	int CVIFUNC ModtGenerateRicianFlatFadingProfile_Gans ( ModtHandle handle,
		double ricianParameter,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum fadingProfile[],
		int *seedOut);

	int CVIFUNC ModtGenerateRicianFlatFadingProfile_Jakes ( ModtHandle handle,
		double ricianParameter,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum fadingProfile[],
		int *seedOut);

	int CVIFUNC ModtGenerateRayleighSelectiveFadingProfile_Gans ( ModtHandle handle,
		int numberOfPaths,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum *fadingProfile,
		int *seedOut);

	int CVIFUNC ModtGenerateRayleighSelectiveFadingProfile_Jakes ( ModtHandle handle,
		int numberOfPaths,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum *fadingProfile,
		int *seedOut);

	int CVIFUNC ModtGenerateRicianSelectiveFadingProfile_Gans ( ModtHandle handle,
		int numberOfPaths,
		double ricianParameter,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum *fadingProfile,
		int *seedOut);

	int CVIFUNC ModtGenerateRicianSelectiveFadingProfile_Jakes ( ModtHandle handle,
		int numberOfPaths,
		double ricianParameter,
		int profileLength,
		double samplingFrequency,
		double dopplerSpread,
		int seedIn,
		double fadingVariance,
		int reset,
		niComplexNum *fadingProfile,
		int *seedOut);

#pragma pack(pop)

#ifdef __cplusplus
} // extern "C"
#endif

#endif //__DMODT_IMPAIRMENTS_H__