/*=================================================================*/
/*                     Spectral Measurements                       */
/*-----------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2003-2011.                */
/*                  All Rights Reserved.                           */
/*-----------------------------------------------------------------*/
/*                                                                 */
/* Title:       smt.h                                              */
/* Purpose:     Header file for Spectral Measurements              */
/*   The online help and function panels for each function contain */
/*   additional documentation.                                     */
/*=================================================================*/
#ifndef _SMT_H
#define _SMT_H

#ifndef __VISATYPE_HEADER__
#define ViSession unsigned long
#endif

#ifndef __SMT_DEPRECATED_DEFINES__
#include "niSMT_Deprecated_Defines.h"
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

#ifndef _WIN64
	#pragma pack(push)
	#pragma pack(1)
#endif

//units
#define NISMT_VAL_UNITS_VOLTS 0
#define NISMT_VAL_UNITS_VOLTS_SQUARED 1
#define NISMT_VAL_UNITS_WATTS 2
#define NISMT_VAL_UNITS_DBM 3
#define NISMT_VAL_UNITS_DBW 4
#define NISMT_VAL_UNITS_DBV 5
#define NISMT_VAL_UNITS_DBMV 6
#define NISMT_VAL_UNITS_DBUV 7

//averagingType
#define NISMT_VAL_AVERAGING_TYPE_NO_AVERAGING 0
#define NISMT_VAL_AVERAGING_TYPE_VECTOR_AVERAGING 1
#define NISMT_VAL_AVERAGING_TYPE_RMS_AVERAGING 2
#define NISMT_VAL_AVERAGING_TYPE_PEAK_HOLD_AVERAGING 3

//weightingType
#define NISMT_VAL_WEIGHTING_TYPE_LINEAR 0
#define NISMT_VAL_WEIGHTING_TYPE_EXPONENTIAL 1
	
//linearWeightingMode
#define NISMT_VAL_LINEAR_WEIGHTING_MODE_ONE_SHOT 0
#define NISMT_VAL_LINEAR_WEIGHTING_MODE_AUTO_RESTART_ONE_SHOT 1
#define NISMT_VAL_LINEAR_WEIGHTING_MODE_MOVING_AVERAGE 2
#define NISMT_VAL_LINEAR_WEIGHTING_MODE_CONTINUOUS 3

//calibrationUnits 
#define NISMT_VAL_CALIBRATION_UNITS_VOLTS 0 
#define NISMT_VAL_CALIBRATION_UNITS_WATTS 1 
#define NISMT_VAL_CALIBRATION_UNITS_DBM 2 
#define NISMT_VAL_CALIBRATION_UNITS_DBW 3 
#define NISMT_VAL_CALIBRATION_UNITS_DBV 4 
#define NISMT_VAL_CALIBRATION_UNITS_DBMV 5 
#define NISMT_VAL_CALIBRATION_UNITS_DBUV 6 

//calibration Data type
#define NISMT_VAL_CALIBRATION_DATA_TYPE_POLYNOMIAL 0
#define NISMT_VAL_CALIBRATION_DATA_TYPE_LUT 1

//inputSignalType
#define NISMT_VAL_INPUT_SIGNAL_TYPE_REAL 0
#define NISMT_VAL_INPUT_SIGNAL_TYPE_COMPLEX_MODULATED 1
#define NISMT_VAL_INPUT_SIGNAL_TYPE_COMPLEX_MODULATED_INTERLEAVED 2

//window
#define NISMT_VAL_WINDOW_TYPE_UNIFORM 0
#define NISMT_VAL_WINDOW_TYPE_HANNING 1
#define NISMT_VAL_WINDOW_TYPE_HAMMING 2
#define NISMT_VAL_WINDOW_TYPE_BLACKMAN_HARRIS 3
#define NISMT_VAL_WINDOW_TYPE_EXACT_BLACKMAN 4
#define NISMT_VAL_WINDOW_TYPE_BLACKMAN 5
#define NISMT_VAL_WINDOW_TYPE_FLAT_TOP 6
#define NISMT_VAL_WINDOW_TYPE_FOUR_TERM_B_HARRIS 7
#define NISMT_VAL_WINDOW_TYPE_SEVEN_TERM_B_HARRIS 8
#define NISMT_VAL_WINDOW_TYPE_LOW_SIDELOBE 9

//searchCriteria
#define NISMT_VAL_SEARCH_CRITERIA_MULTIPLE_PEAKS 0
#define NISMT_VAL_SEARCH_CRITERIA_SINGLE_MAX_PEAKS 1
#define NISMT_VAL_SEARCH_CRITERIA_MULTIPLE_PEAKS_INCLUDE_EDGES 2

//peakScaling
#define NISMT_VAL_PEAK_SCALING_RMS_SCALING 0
#define NISMT_VAL_PEAK_SCALING_PK_SCALING 1

//spectrum type
#define NISMT_VAL_SPECTRUM_TYPE_FFT_SPECTRUM_COMPLEX 0
#define NISMT_VAL_SPECTRUM_TYPE_AMPLITUDE 1
#define NISMT_VAL_SPECTRUM_TYPE_POWER_SPECTRUM 2
#define NISMT_VAL_SPECTRUM_TYPE_CROSS_SPECTRUM_COMPLEX 3
#define NISMT_VAL_SPECTRUM_TYPE_FREQUENCY_RESPONSE_COMPLEX 4

//Filter Type
#define NISMT_VAL_FILTER_TYPE_NONE 0
#define NISMT_VAL_FILTER_TYPE_RAISED_COSINE  1
#define NISMT_VAL_FILTER_TYPE_ROOT_RAISED_COSINE 2
#define NISMT_VAL_FILTER_TYPE_GAUSSIAN 3

//Spectrum scale linear/dB
#define NISMT_VAL_SPECTRUM_SCALE_LINEAR 0
#define NISMT_VAL_SPECTRUM_SCALE_DB 1

/*-----------------------------------------------------------------*/
/* Error Codes                                                     */
/*-----------------------------------------------------------------*/
#define SmtNoErr                            0
#define SmtZoomGTZeroErr                -20501
#define SmtFFTSizeGTZeroErr             -20502
#define SmtInternalBufferOverflowErr    -20503
#define SmtSamplingFreqGTZeroErr        -20504
#define SmtFFTBinRBWErr                 -20505
#define SmtSpectrumTypeErr              -20506
#define SmtAveragingTypeErr             -20507
#define SmtInvalidSessionErr            -20508
#define SmtDLLLoadErr                   -20509
#define SmtFindFunctionErr              -20510
#define SmtCreateMutexErr               -20511
#define SmtRBWTimeSpanDefaultErr        -20512
#define SMTBandSpecErr                  -20513
#define SMTHWNotSupportedErr			-20514
#define SMTValNotSupportedErr			-20515
#define SMTParameterOutOfRangeErr		-20516
#define SMTHardwareNotSupportedErr		-20517

#define SmtMinErr                       -20501
#define SmtMaxErr                       -20517
	/*-----------------------------------------------------------------*/
	/* Warning Codes                                                   */
	/*-----------------------------------------------------------------*/
#define SmtFunctionNotSupported         20501

	/*-----------------------------------------------------------------*/
	/* Maximum string length returned by SmtGetErrorString             */
	/*-----------------------------------------------------------------*/
#define SmtMaxErrorStringSize           1024


	/*-----------------------------------------------------------------*/
	/* Typedefs                                                        */
	/*-----------------------------------------------------------------*/
#ifndef __SmtHandle__
	#define __SmtHandle__
	typedef int SmtHandle;
#endif

#ifndef __SmtSpectrumSettings__
#define __SmtSpectrumSettings__
	typedef struct {
		double centerFrequency;
		double span;
		double resolutionBandwidth;
		unsigned short window;
		int spectralLines;
	} SmtSpectrumSettings;
#endif

#ifndef __SmtZoomSettings__
#define __SmtZoomSettings__
	typedef struct {
		double centerFrequency;
		double zoom;
		unsigned short window;
		int windowSize;
		int FFTSize;
		double overlap;
		double frequencyShift;
		unsigned short dataFormat;
		double trim;
	} SmtZoomSettings;
#endif

#ifndef __SmtSpectrumInfo__
#define __SmtSpectrumInfo__
	typedef struct {
		unsigned short spectrumType;
		unsigned short linearDB;
		unsigned short window;
		int windowSize;
		int FFTSize;
	} SmtSpectrumInfo;
#endif

#ifndef __SmtBandSpecification__
#define __SmtBandSpecification__
	typedef struct {
		double centerFrequency;
		double bandwidth;
	} SmtBandSpecification;
#endif

#ifndef __SmtAdjacentBandSpecification__
#define __SmtAdjacentBandSpecification__
	typedef struct {
		double offset;
		double bandwidth;
	} SmtAdjacentBandSpecification;
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
#elif defined(COMPATIBLE_SMT_COMPLEX)
#pragma message ("Due to the order of the #include lines in your source file, SmtComplexNum might not be compatible with NiComplexNumber used by other NI libraries.  Please change the inclusion order so that smt.h is the first header file included")
#endif 


#if defined(COMPATIBLE_SMT_COMPLEX) 
	typedef struct New_NIComplexNumber_struct SmtComplexNum;
#else 
	typedef NIComplexNumber SmtComplexNum; 
#endif


	/*-----------------------------------------------------------------*/
	/* Function Declarations                                           */
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------*/
	/* Toplevel Functions                                              */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtCreateHandle (SmtHandle *handle);

	int CVIFUNC SmtDestroyHandle (SmtHandle handle);

	int CVIFUNC SmtGetErrorString (int errorCode,
		unsigned char errorString[],
		int errorStringSize);

	/*-----------------------------------------------------------------*/
	/* Hardware independent configuration                              */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtConfigContZoomFFT (double samplingFrequency,
		unsigned short inputSignalType, 
		double frequencyShift, 
		double centerFrequency, 
		double span, 
		double resolutionBandWidth, 
		unsigned short window, 
		int spectralLines, 
		double overlap, 
		int *maxBlockSize, 
		SmtSpectrumSettings *actualSpectrumSettings, 
		SmtZoomSettings *zoomSettings);

	int CVIFUNC SmtConfigZoomFFT (double samplingFrequency, 
		unsigned short inputSignalType, 
		double frequencyShift, 
		double centerFrequency, 
		double span, 
		double resolutionBandWidth, 
		unsigned short window, 
		int spectralLines, 
		int *acquisitionSize, 
		SmtSpectrumSettings *actualSpectrumSettings, 
		SmtZoomSettings *zoomSettings);

	/*-----------------------------------------------------------------*/
	/* Zoom FFT Spectrum                                               */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtContZoomFFT (SmtHandle handle, 
		double t0, 
		double dt, 
		double inputData[], 
		int inputDataSize, 
		SmtZoomSettings *zoomSettings, 
		int reset, 
		short *spectrumReady, 
		double *f0, 
		double *df, 
		SmtComplexNum spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo);

	int CVIFUNC SmtContZoomFFTEx (SmtHandle handle, 
		double t0, 
		double dt, 
		double inputData[], 
		int inputDataSize, 
		SmtZoomSettings *zoomSettings, 
		int reset, 
		short *spectrumReady, 
		double *f0, 
		double *df, 
		SmtComplexNum spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo,
		double *t0Out,
		double *dtOut,
		SmtComplexNum filteredTimeData[],
		int filteredTimeDataSize);

	int CVIFUNC SmtZoomFFT (double t0, 
		double dt, 
		double inputData[], 
		int inputDataSize, 
		SmtZoomSettings *zoomSettings, 
		double *f0, 
		double *df, 
		SmtComplexNum spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo);

	/*-----------------------------------------------------------------*/
	/* Spectrum Averaging                                              */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtAveragedFFTSpectrum (SmtHandle handle, 
		double f0, 
		double df, 
		SmtComplexNum spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		unsigned short averagingType, 
		unsigned short weightingType, 
		double averagingSize, 
		unsigned short linearWeightingMode, 
		int restartAveraging, 
		SmtComplexNum averagedFFTSpectrum[], 
		double *averagesSofar,
		short *dataReady);

	int CVIFUNC SmtAveragedPowerSpectrum (SmtHandle handle, 
		double f0, 
		double df, 
		SmtComplexNum spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		unsigned short averagingType, 
		unsigned short weightingType, 
		double averagingSize, 
		unsigned short linearWeightingMode, 
		int restartAveraging, 
		double averagedPowerSpectrum[], 
		double *averagesSofar,
		short *dataReady);

	int CVIFUNC SmtAveragedCrossSpectrum (SmtHandle handle, 
		double f0, 
		double df, 
		SmtComplexNum spectrumX[], 
		SmtComplexNum spectrumY[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		unsigned short averagingType, 
		unsigned short weightingType, 
		double averagingSize, 
		unsigned short linearWeightingMode, 
		int restartAveraging, 
		SmtComplexNum averagedCrossSpectrum[], 
		double *averagesSofar,
		short *dataReady);

	int CVIFUNC SmtAveragedFrequencyResponse (SmtHandle handle, 
		double f0, 
		double df, 
		SmtComplexNum spectrumX[], 
		SmtComplexNum spectrumY[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		unsigned short averagingType, 
		unsigned short weightingType, 
		double averagingSize, 
		unsigned short linearWeightingMode, 
		int restartAveraging,
		SmtComplexNum averagedFrequencyResponse[], 
		double *averagesSofar,
		short *dataReady);

	/*-----------------------------------------------------------------*/
	/* Spectrum Measurements                                           */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtPowerInBand (double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		SmtBandSpecification *bandSpecification, 
		unsigned short units, 
		double impedanceOhm, 
		double *powerInBand);

	int CVIFUNC SmtAdjacentChannelPower (double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		SmtBandSpecification *bandSpecification, 
		double spacing, 
		unsigned short units, 
		double impedanceOhm, 
		double *powerInChannel, 
		double *powerInUpperChannel, 
		double *powerInLowerChannel);

	int CVIFUNC SmtAdjacentChannelPowerEx(double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		SmtBandSpecification *centerChannelSpecification, 
		SmtAdjacentBandSpecification adjacentChannelSpecifications[], 
		int numberOfAdjacentChannels,
		unsigned short units, 
		double impedanceOhm, 
		double *powerInCentralChannel, 
		double powerInAdjacentChannels[]);

	int CVIFUNC SmtOccupiedBandWidth (double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		double percentPower, 
		double *occupiedBW, 
		double *freqLow, 
		double *freqHigh);

	int CVIFUNC SmtSpectrumUnitConversion (double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		unsigned short units,
		unsigned short peakScaling,
		int psdOnOff,
		double impedanceOhm,
		double unitConvertedSpectrum[], 
		unsigned char *label, 
		int labelSize);

	int CVIFUNC SmtSpectrumPeakSearch (double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectrumInfo, 
		unsigned short searchCriteria, 
		double threshold, 
		int *numPeaks, 
		double peaks[], 
		double frequency[], 
		int peaksSize);

	int CVIFUNC SmtSpectrumPeakSearchMaxNPeaks(double f0, 
		double df,	
		double spectrum[], 
		int spectrumSize, 
		SmtSpectrumInfo *spectralInfo, 
		int expectedNumberPeaks, 
		double Value[], 
		double Frequency[], 
		int *actualNumPeaks);

int CVIFUNC SmtFilterSpectrum (SmtHandle handle, 
		double f0, 
		double df, 
		double spectrumIn[],  
		int spectrumSize, 
		SmtSpectrumInfo *spectralInfoIn, 
		SmtBandSpecification centerChannelSpecification, 
		SmtAdjacentBandSpecification adjacentChannelSpecifications[], 
		int numberOfAdjacentChannels, 
		int filterType[], 
		int filterTypeSize,
		double filterParameter[], 
		int filterParameterSize, 
		double filterBandwidth[],
		int filterBandwidthSize,
		int reset,
		double filteredSpectrum[]);

	/*-----------------------------------------------------------------*/
	/* NI PXI-562x Specific			                                   */
	/* Calls to these routines require that NI-Scope be installed      */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtConfigSpectrumForNiScope (ViSession scopeHandle,
		double minSampleRate,
		double centerFrequency, 
		double span,
		double resolutionBandWidth,
		unsigned short window,
		int spectralLines,
		int *acquisitionSize,
		SmtSpectrumSettings *actualSpectrumSettings,
		SmtZoomSettings *zoomSettings);

	int CVIFUNC SmtConfigContZoomFFTForNiScope (ViSession scopeHandle,
		double minSampleRate,
		double centerFrequency,
		double span,
		double resolutionBandwidth,
		unsigned short window,
		int spectralLines,
		double overlap,
		int *maxBlockSize,
		SmtSpectrumSettings *actualSpectrumSettings,
		SmtZoomSettings *zoomSettings,
		int *initialAcquisitionSize);

	int CVIFUNC SmtCalculateCorrection  (ViSession scopeHandle, 
		SmtSpectrumSettings *actualSpectrumSettings, 
		double correctionFactors[], 
		int correctionFactorsSize);

	int CVIFUNC SmtApplyCorrection (double f0, 
		double df, 
		double spectrum[], 
		int spectrumSize, 
		double correctionFactors[], 
		SmtSpectrumInfo *spectrumInfo, 
		double correctedSpectrum[]);

	int CVIFUNC SmtCalculateUserCorrection (double f1, 
		double f2, 
		double calibrationData[], 
		int calibrationDataSize, 
		unsigned short calibrationUnits, 
		unsigned short type, 
		SmtSpectrumSettings *actualSpectrumSettings, 
		double correctionFactors[], 
		int correctionFactorsSize);

#ifndef _WIN64
	/*-----------------------------------------------------------------*/
	/* NI PXI-5660 Specific				                               */
	/* Calls to these functions require installed versions of NI-Scope */
	/* and NI-Tuner.                                                   */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtConfigureSpectrumForRFSA (ViSession scopeHandle,
		int tunerTaskID,
		double minSampleRate,
		double centerFrequency,
		double span,
		double resolutionBandwidth,
		unsigned short window,
		int spectralLines,
		int referenceLevel,
		int mixerLevel,
		int *acquisitionSize,
		SmtSpectrumSettings *actualSpectrumSettings,
		SmtZoomSettings *zoomSettings);

	int CVIFUNC SmtConfigureContZoomFFTForRFSA (ViSession scopeHandle,
		int tunerTaskID,
		double minSampleRate,
		double centerFrequency,
		double span,
		double resolutionBandwidth,
		unsigned short window,
		int spectralLines,
		double overlap,
		int referenceLevel,
		int mixerLevel,
		int *maxBlockSize,
		SmtSpectrumSettings *actualSpectrumSettings,
		SmtZoomSettings *zoomSettings,
		int *initialAcquisitionSize);

	int CVIFUNC SmtCalculateCorrectionForRFSA (ViSession scopeHandle,
		int tunerDevice,
		SmtSpectrumSettings *actualSpectrumSettings,
		double correctionFactors[],
		int correctionFactorsSize);

	int CVIFUNC SmtApplyCorrectionFFTSpectrum (double f0, 
		double df, 
		SmtComplexNum spectrum[], 
		int spectrumSize, 
		double correctionFactors[], 
		SmtSpectrumInfo *spectrumInfo, 
		SmtComplexNum correctedSpectrum[]);
#endif
	/*-----------------------------------------------------------------*/
	/* Deprecated  Functions / Definitions                             */
	/*-----------------------------------------------------------------*/
	/* The functions,  definitions in this section should not be used  */
	/* for future development                                          */
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------*/
	/* handleErrSMT : Deprecated , for equivalent functionality use    */
	/* the errChk and nullChk macros from the CVI standard library     */
	/* Programmer's Toolbox                                            */
	/*-----------------------------------------------------------------*/

#define handleErrSMT(fCall) {               \
	errorSMT = (fCall);                 \
	if (errorSMT < 0) goto ErrorSMT;    \
	}

#ifndef _WIN64	
	/*-----------------------------------------------------------------*/
	/* SmtConfigSpectrumForRFSA and SmtConfigContZoomFFTForRFSA have   */
	/* been Deprecated and replaced by SmtConfigureSpectrumForRFSA and */
	/* SmtConfigureContZoomFFTForRFSA, respectively. The older         */
	/* functions call the NI-Tuner initialize function internally.     */ 
	/* With the newer functions, NI-Tuner initialize must be           */
	/* called before invoking either function.                         */
	/*-----------------------------------------------------------------*/
	/*-----------------------------------------------------------------*/
	/* SmtConfigSpectrumForRFSA replaced by                            */
	/* SmtConfigureSpectrumForRFSA                                     */
	/*-----------------------------------------------------------------*/
	int CVIFUNC SmtConfigSpectrumForRFSA (ViSession scopeHandle,
		int tunerDevice,
		double minSampleRate,
		double centerFrequency,
		double span,
		double resolutionBandwidth,
		unsigned short window,
		int spectralLines,
		int referenceLevel,
		unsigned short referenceConfiguration,
		int *acquisitionSize,
		SmtSpectrumSettings *actualSpectrumSettings,
		SmtZoomSettings *zoomSettings);

	/* SmtConfigContZoomFFTForRFSA replaced by                         */
	/* SmtConfigureContZoomFFTForRFSA                                  */
	int CVIFUNC SmtConfigContZoomFFTForRFSA (ViSession scopeHandle,
		int tunerDevice,
		double minSampleRate,
		double centerFrequency,
		double span,
		double resolutionBandwidth,
		unsigned short window,
		int spectralLines,
		double overlap,
		int referenceLevel,
		unsigned short referenceConfiguration,
		int *maxBlockSize,
		SmtSpectrumSettings *actualSpectrumSettings,
		SmtZoomSettings *zoomSettings,
		int *initialAcquisitionSize);
#endif
	/*-----------------------------------------------------------------*/
	/* End: Deprecated  Functions / Definitions                        */
	/*-----------------------------------------------------------------*/

#ifndef __VISATYPE_HEADER__
#undef ViSession
#endif

#ifndef _WIN64
#pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif /* ndef _SMT_H */
