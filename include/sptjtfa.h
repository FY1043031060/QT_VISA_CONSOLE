#ifndef _SPTJTFA_H
#define _SPTJTFA_H

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#ifdef _WIN32		
	#define DSPAPI __stdcall
    #define DSPENTRY __stdcall
#else 
	#define DSPAPI
    #define DSPENTRY
#endif


#ifdef __cplusplus
extern "C" {
#endif

#pragma pack (push,1)

typedef enum{
    SptZeroPadding,
    SptSymmetric,
    SptPeriodic,
    SptSpline,
    SptUserDefined,
    SptFirstDerivative,
    SptSecondDerivative,
} SptExtension;

typedef struct {
	double *win;
	int	w_len;
	int dM;
	int N;
} SptWindowInfo;

typedef struct{
    long zoomFactor;
	long minFreq;
	long numOfBins;
} SptFreqInfo;

typedef struct{
	double alpha; 
	double t0; 
	double omega; 
	double beta;
} SptADTParam;

typedef enum{
	SptChirplet, 
	SptGaussian,
} SptADTMode;

#pragma pack (pop)          

long DSPAPI SptRealSTFT(double x[ ], long len, SptWindowInfo *winInfo, 
                        SptExtension extension, double initialCondition[ ],
                        double finalCondition[ ], ComplexNum *CxCoefficient);
long DSPAPI SptCxSTFT(ComplexNum CxData[ ], long len, SptWindowInfo *winInfo, 
                      SptExtension extension, ComplexNum initialCondition[ ], 
                      ComplexNum finalCondition[ ], 
                      ComplexNum *CxCoefficient);
long DSPAPI SptRealDGT(double x[ ], long len, SptWindowInfo *winInfo, 
                       ComplexNum *CxCoefficient);
long DSPAPI SptCxDGT(ComplexNum CxData[ ], long len, SptWindowInfo *winInfo, 
                     ComplexNum *CxCoefficient);
long DSPAPI SptRealSTFTSpectrogram(double x[ ], long len, SptWindowInfo *winInfo,
                                   SptExtension extension, 
                                   double initialCondition[ ], 
                                   double finalCondition[ ], 
                                   double *spectrogram);
long DSPAPI SptCxSTFTSpectrogram(ComplexNum CxData[ ], long len, 
                                 SptWindowInfo *winInfo, SptExtension extension,
                                 ComplexNum initialCondition[ ],
                                 ComplexNum finalCondition[ ],
                                 double *spectrogram);
long DSPAPI SptRealGaborExpansion(ComplexNum *CxCoefficient, long rows, 
                                  long cols, long signalLength, 
                                  SptWindowInfo *winInfo, double waveform[ ]);
long DSPAPI SptCxGaborExpansion(ComplexNum *CxCoefficient, long rows, 
                                long cols, long signalLength, 
                                SptWindowInfo *winInfo,
                                ComplexNum CxWaveform[ ]);
long DSPAPI SptRealFastGaborSpectrogram(double x[ ], long len, 
                                        long timeInterval, long order, 
                                        SptWindowInfo *winInfo, 
                                        SptFreqInfo *freqInfo, 
                                        SptExtension extension, 
                                        double initialCondition[ ], 
                                        double finalCondition[ ], 
                                        double *gaborSpectrogram);
long DSPAPI SptCxFastGaborSpectrogram(ComplexNum CxData[ ], long len, 
                                      long timeInterval, long order, 
                                      SptWindowInfo *winInfo, 
                                      SptFreqInfo *freqInfo, 
                                      SptExtension extension, 
                                      ComplexNum initialCondition[ ], 
                                      ComplexNum finalCondition[ ], 
                                      double *gaborSpectrogram);
long DSPAPI Spt2DDiscreteGaborTransform(double *x, long rows, long cols, 
                                        SptWindowInfo *info1, 
                                        SptWindowInfo *info2, 
                                        ComplexNum *CxOutput);
long DSPAPI Spt2DDiscreteGaborExpansion(ComplexNum *CxData, long size0, 
                                          long size1, long size2, long size3,
                                          long rows, long cols,
                                          SptWindowInfo *info1, 
                                          SptWindowInfo *info2,
                                          double * output);
long DSPAPI SptRealWignerVilleDistribution(double x[ ], long len, 
                                           long numOfFreqBins, 
                                           long timeInterval, 
                                           long analyticalSignal, 
                                           double * result);
long DSPAPI SptCxWignerVilleDistribution(ComplexNum CxData[ ], long len, 
                                         long numOfFreqBins, long timeInterval,
                                         double *result);
long DSPAPI SptRealChoiWilliamsDistribution(double x[ ], long len, 
                                            long numOfFreqBins, 
                                            long timeInterval, double alpha, 
                                            long analyticalSignal,
                                            double *result);
long DSPAPI SptCxChoiWilliamsDistribution(ComplexNum CxData[ ], long len, 
                                          long numOfFreqBins, long timeInterval,
                                          double alpha, double *result);
long DSPAPI SptRealConeShapedDistribution(double x[ ], long len, 
                                          long numOfFreqBins, 
                                          long timeInterval, double alpha, 
                                          long analyticalSignal,
                                          double *result);
long DSPAPI SptCxConeShapedDistribution(ComplexNum CxData[ ], long len, 
                                        long numOfFreqBins, long timeInterval,
                                        double alpha, double *result);
long DSPAPI SptFastDualFunction(SptWindowInfo *winInfo, long equal, 
                                double gamma[ ]);
long DSPAPI SptMeanInstFreq(double *spectra, long rows, long cols, 
                            double freq[ ], double power[ ], double *IF);
long DSPAPI SptRealCohen(double x[ ], long len, double *kernel, long rows, 
                         long cols, long timeInterval, long analyticalSignal,
                         double *result);
long DSPAPI SptCxCohen(ComplexNum CxData[ ], long len, double *kernel, 
                       long rows, long cols, long timeInterval,
                       double *result);
long DSPAPI SptRealEasyGaborSpectrogram(double x[ ], long len, 
                                        long gaborWindowLen, double var, 
                                        long timeInterval, long order, 
                                        double *gaborSpectrogram);
long DSPAPI SptCxEasyGaborSpectrogram(ComplexNum CxData[ ], long len, 
                                      long gaborWindowLen, double var, 
                                      long timeInterval, long order, 
                                      double *gaborSpectrogram);
long DSPAPI SptOptimalGaussianDual(long gaussianWindowLen, double var, 
                                   long oversampling, long equal, 
                                   SptWindowInfo *dualFunctionInfo, 
                                   SptWindowInfo *synthesisWindowInfo);
                                   
/*------------------------------
 	new functions for SPT7.0
 -------------------------------*/                                   
long DSPAPI SptRealReassignedSTFTSp(double x[], long len, 
									SptWindowInfo *winInfo, SptExtension extension, 
							 		double initialCondition[], 
							 		double finalCondition[], 
							 		double *spectrogram);
long DSPAPI SptCxReassignedSTFTSp(ComplexNum CxData[], long len, 
								  SptWindowInfo *winInfo, SptExtension extension, 
								  ComplexNum initialCondition[], 
								  ComplexNum finalCondition[], 
								  double *spectrogram);
long DSPAPI SptRealAdaptiveTransform(double x[], long len, SptADTMode mode, 
									 SptExtension extension, long initWindowLen,
									 long numOfTerms, double *residue, 
									 ComplexNum *Ap, SptADTParam *estimatedTerm, 
									 long *actualNumOfTerm);
long DSPAPI SptCxAdaptiveTransform(ComplexNum CxData[], long len, 
								   SptADTMode mode, SptExtension extension, 
								   long initWindowLen, long numOfTerms,	
								   double *residue, ComplexNum *Ap, 
								   SptADTParam  *estimatedTerm, 
								   long *actualNumOfTerm);
long DSPAPI SptRealAdaptiveExpansion(ComplexNum Ap[], SptADTParam estimatedTerm[],
                                     long numOfTerms, long signalLen, 
                                     double waveform[]);
long DSPAPI SptCxAdaptiveExpansion(ComplexNum Ap[], SptADTParam estimatedTerm[], 
								   long numOfTerms, long signalLen, 
								   ComplexNum CxWaveform[]);
long DSPAPI SptRealAdaptiveSpectrogram(double x[], long len, SptADTMode mode, 
									   SptExtension extension, 
									   long initWindowLen, long numOfTerms,
									   long timeInterval, long numOfFreqBins, 
									   SptFreqInfo *freqInfo,
									   double *spectrogram);
long DSPAPI SptCxAdaptiveSpectrogram(ComplexNum CxData[], long len, 
									 SptADTMode mode, SptExtension extension, 
									 long initWindowLen, long numOfTerms,
									 long timeInterval, long numOfFreqBins, 
									 SptFreqInfo *freqInfo,
									 double *spectrogram);
long DSPAPI SptRealFastGaborSpectrogramEx(double x[], long len, 
											long order, SptWindowInfo *winInfo, 
											long timeInterval, 
											long numOfFreqBins,
											SptFreqInfo *freqInfo, 
											SptExtension extension, 
											double initialCondition[], 
											double finalCondition[], 
											double *gaborSpectrogram);
long DSPAPI SptCxFastGaborSpectrogramEx(ComplexNum CxData[], long len, 
										long order, 
										SptWindowInfo *winInfo, 
										long timeInterval, long numOfFreqBins,
										SptFreqInfo *freqInfo, 
										SptExtension extension, 
										ComplexNum initialCondition[], 
										ComplexNum finalCondition[], 
										double *gaborSpectrogram);
long DSPAPI SptFastMeanInstFreq(double x[], long len, long order, 
								SptWindowInfo *winInfo, long timeInterval, 
								SptExtension extension,
								double initialCondition[],
								double finalCondition[], double IF[]);
long DSPAPI SptGetOptimalDualWinLen(long winLen, double var, long oversampling, 
									long *actualWinLen);
long DSPAPI SptGetEasyGaborSpDimSize(long signalLen, long type, 
										long gaborWindowLen, double var, 
										long timeInterval, long *rows, 
										long *cols);


#ifdef __cplusplus
}
#endif

#endif
