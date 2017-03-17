/*=================================================================*/
/*                     Spectral Measurements                       */
/*-----------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2003-2011.                */
/*                  All Rights Reserved.                           */
/*-----------------------------------------------------------------*/
/*                                                                 */
/* Title:       niSMTDeprecated.h                                  */
/* Purpose:     Deprecated Header file for Spectral Measurements   */
/*=================================================================*/

#ifndef _SMT_DEPRECATED_DEFINES_H
#define _SMT_DEPRECATED_DEFINES_H

//units
#define V 0
#define V2 1
#define W 2
#define dBm 3
#define dBw 4
#define dBV 5
#define dBmV 6
#define dBuV 7

//averagingType
#define NO_AVERAGING 0
#define VECTOR_AVERAGING 1
#define RMS_AVERAGING 2
#define PEAK_HOLD_AVERAGING 3

//weightingType
#define LINEAR 0
#define EXPONENTIAL 1
	
//linearWeightingMode
#define ONE_SHOT 0
#define AUTO_RESTART_ONE_SHOT 1
#define MOVING_AVERAGE 2
#define CONTINUOUS 3

//calibrationUnits 
#define CALIBRATIONUNITS_Volts 0 
#define CALIBRATIONUNITS_Watts 1 
#define CALIBRATIONUNITS_dBm 2 
#define CALIBRATIONUNITS_dBW 3 
#define CALIBRATIONUNITS_dBV 4 
#define CALIBRATIONUNITS_dBmV 5 
#define CALIBRATIONUNITS_dBuV 6 

//type
#define POLYNOMIAL 0
#define LUT 1

//inputSignalType
#define REAL 0
#define COMPLEX_MODULATED 1
#define COMPLEX_MODULATED_INTERLEAVED 2

//window
#define UNIFORM 0
#define HANNING 1
#define HAMMING 2
#define BLACKMAN_HARRIS 3
#define EXACT_BLACKMAN 4
#define BLACKMAN 5
#define FLAT_TOP 6
#define FOUR_TERM_B_HARRIS 7
#define SEVEN_TERM_B_HARRIS 8
#define LOW_SIDELOBE 9

//searchCriteria
#define MULTIPLE_PEAKS 0
#define SINGLE_MAX_PEAKS 1
#define MULTIPLE_PEAKS_INCLUDE_EDGES 2

//peakScaling
#define RMS_SCALING 0
#define PK_SCALING 1

//spectrum type
#define FFT_SPECTRUM_COMPLEX 0
#define AMPLITUDE 1
#define POWER_SPECTRUM 2
#define CROSS_SPECTRUM_COMPLEX 3
#define FREQUENCY_RESPONSE_COMPLEX 4

//linear/dB
#define LINEAR 0
#define DB 1

#endif