/*============================================================================*/
/*                        Analog Modulation Measurements                      */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2005-2009.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       Modt_Deprecated.h                                             */
/* Purpose:     Header file for Deprecated Analog Modulation functions.       */
/*   The online help for each function contain                                */
/*   additional documentation.                                                */
/*============================================================================*/

#ifndef __AMODT_DEPRECATED_H
#define __AMODT_DEPRECATED_H

/*
ModtGetComplexIQComponent:
    Inputs
        iqData[]                Pre-allocated array of samples to process
        numIQDataElements       Length (elements) of the IQData input buffer and requestedData output buffer
        componentToExtract      0: I, 1: Q, 2: Magnitude, 3: Phase
    Outputs
        requestedComponent      Extracted signal component, input an empty array with length equal to IQDataNumElements
*/

int CVIFUNC ModtGetComplexIQComponent ( niComplexNum iqData[],
	int numIQDataElements,
	int componentToExtract,
	double requestedComponent[]);

/*
ModtDownconvertPassband         
    Software (hardware independent) signal downconversion.
    Decimates, downconverts, and optionally filters a signal.
            
    Inputs:
        handle                  call ModtCreateSessionHandle to create
        t0                   
        dt
        inputWaveform[]             Pre-allocated array of samples to downconvert
        numInputWaveformElements    Length (samples) of pre-allocated inputData array    
        carrierFrequency   
        passbandBandwidth    
        initialPhase         
        reset                   1: reset filter, 0: continue with last design
        enableFilter            1: enable downconversion filter, 0: disable filter (output is unfiltered)
    Outputs:
        downconvertedWaveformT0
        downconvertedWaveformDt
        downconvertedWaveform[]         Pre-allocated array that will contain downconverted signal
                                    input a buffer with a minimum length of inputDataNumElements
        filterRipple                Ripple in the designed filter 
        filterLength                with enableFilter input set to true, this outputs the number of coefficients
                                    in the designed FIR filter that is being applied to the downconvertedData
                                    output. If the enableFilter input set to false, this output will be zero
*/
int CVIFUNC ModtDownconvertPassband ( ModtHandle handle,
	double t0,
	double dt,
	double inputWaveform[],
	int numInputWaveformElements,
	double carrierFrequency,
	double passbandBandwidth,
	double initialPhase,
	int reset,
	int enableFilter,
	double *downconvertedWaveformT0,
	double *downconvertedWaveformDt,
	niComplexNum downconvertedWaveform[],
	double *filterRipple,
	int *filterLength);

/*
ModtUpconvertBaseband
    Software (hardware independent) signal upconversion.
        
    Inputs:
        handle                  call ModtCreateSessionHandle to create
        t0                   
        dt
        inputWaveform[]             Pre-allocated array of samples to upconvert
        numInputWaveformElements    Length (samples) of pre-allocated inputData array
        intialPhase
        reset
        carrierFrequency
    Outputs:
        upconvertedWaveformT0
        upconvertedWaveformDt
        upconvertedWaveform[]       Pre-allocated array that will contain the upconverted signal
                                    input a buffer with a minimum length of inputDataNumElements 
*/
int CVIFUNC ModtUpconvertBaseband ( ModtHandle handle,
	double t0,
	double dt,
	niComplexNum inputWaveform[],
	int numInputWaveformElements,
	double initialPhase,
	int reset,
	double carrierFrequency,
	double *upconvertedWaveformT0,
	double *upconvertedWaveformDt,
	double upconvertedWaveform[]);

/* 
ModtAMModulate 
    Inputs:
        handle                  call ModtCreateSessionHandle to create
        inputData[]             Pre-allocated array of samples to modulate
        numInputDataElements    Length (samples) of pre-allocated inputData array
        modulationIndex  
    Outputs:
        modulatedWaveform[]       Pre-allocated array that will contain AM Modulated signal
                                    input a buffer with a minimum length of inputDataNumElements
*/ 
int CVIFUNC ModtAMModulate ( ModtHandle handle,
	double t0,
	double dt, 
	double inputData[], 
	int numInputDataElements,
	double modulationIndex, 
	niComplexNum modulatedWaveform[]);

/*
ModtFMModulate
    Inputs:
        handle                  call ModtCreateSessionHandle to create
        inputData[]             Pre-allocated array of samples to modulate 
        numInputDataElements    Length (samples) of pre-allocated inputData array
        FMDeviation         
        reset                   1: reset 0: continue
    Outputs:
        modulatedWaveformT0
        modulatedWaveformDt
        modulatedWaveform[]:      Pre-allocated array that will contain FM modulated signal
                                    input a buffer with a minimum length of inputDataNumElements
*/  
int CVIFUNC ModtFMModulate ( ModtHandle handle, 
    double t0, 
    double dt,
    double inputData[],
    int numInputDataElements,
    double FMDeviation,
    int reset,
    double *modulatedWaveformT0, 
    double *modulatedWaveformDt, 
    niComplexNum modulatedWaveform[]);

/*
ModtAMDemodulate
    Inputs:
        handle                  call ModtCreateSessionHandle to create
        inputWaveform[]             Pre-allocated array of samples to demodulate
        numInputWaveformElements    Length (samples) of pre-allocated inputData array
        modulationIndex
    Outputs:
        demodulatedWaveform[]     Pre-allocated array that will contain AM demodulated signal
                                    input a buffer with a minimum length of inputDataNumElements
        carrierAmplitude
*/

int CVIFUNC ModtAMDemodulate (ModtHandle handle,
	double t0, 
	double dt, 
	niComplexNum inputWaveform[], 
	int numInputWaveformElements,
	double modulationIndex,
	double demodulatedWaveform[], 
	double *carrierAmplitude);

/*
ModtFMDemodulate
    Inputs:
        handle                  call ModtCreateSessionHandle to create
        t0
        dt
        inputWaveform[]             Pre-allocated array of samples to demodulate
        numInputWaveformElements    Length (samples) of pre-allocated inputData array
        carrierCorrection       0: OFF, 1: ON
        FMDeviation
        reset
    Outputs:
        demodulatedWaveformT0
        demodulatedWaveformDt
        demodulatedWaveform[]     Pre-allocated array that will contain FM modulated signal
                                    input a buffer with a minimum length of inputDataNumElements
        carrierOffset                   
*/                           
int CVIFUNC ModtFMDemodulate (  ModtHandle handle,
	double t0, 
    double dt, 
    niComplexNum inputWaveform[],
    int numInputWaveformElements,
    int carrierCorrection,
    double FMDeviation,
    int reset,
    double *demodulatedWaveformT0, 
    double *demodulatedWaveformDt, 
    double demodulatedWaveform[],
    double *carrierOffset);

/*
ModtPMDemodulate
    Inputs:
        t0
        dt
        inputWaveform[]             Pre-allocated array of samples to demodulate
        numInputWaveformElements    Length (samples) of pre-allocated inputData array
        phaseDeviation
        carrierCorrection       0: OFF, 1: ON  
    Outputs:                    
        demodulatedWaveform[]            Pre-allocated array that will contain PM demodulated signal
                                    input a buffer with a minimum length of inputDataNumElements
    
*/                           
int CVIFUNC ModtPMDemodulate (  ModtHandle handle, 
	double t0, 
    double dt, 
    niComplexNum inputWaveform[],
    int numInputWaveformElements,
    double phaseDeviation,
    int carrierCorrection,
    double demodulatedWaveform[], 
    double *carrierOffset);


#endif /* ndef __AMODT_DEPRECATED_H */