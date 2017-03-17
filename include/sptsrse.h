#ifndef _SPTSRSE_H
#define _SPTSRSE_H

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

typedef struct {
    double lowBoundFreq;
    double freqInc;
    double * powerSpectrum;
} SptPowerSpectrumPlot;


#pragma pack (pop)

long DSPAPI SptRealCovariance (double x[ ], long len, long numOfComplexSin,
                           double coefficient[ ], ComplexNum CxRoots[ ],
                           double * noiseEst);
long DSPAPI SptRealCovPowerSpectrum(double x[ ], long len, long numOfComplexSin,
                                long numOfBins, double sampleFreq, 
                                SptPowerSpectrumPlot * powerSpectrumPlot, 
                                double * noiseEst);
long DSPAPI SptRealPrincipalComAutogressive(double x[ ], long len, long order,
                                        long numOfComplexSin, 
                                        double coefficient[],
                                        ComplexNum CxRoots[ ]);
long DSPAPI SptRealPCARPowerSpectrum(double x[ ], long len, long order, 
                                 long numOfComplexSin, long numOfBins,
                                 double sampleFreq, long positiveOnly, 
                                 double amplitude[ ], double phase[ ], 
                                 double frequency[ ], double * noiseEst, 
                                 SptPowerSpectrumPlot * powerSpectrumPlot, 
                                 long * outputSize);
long DSPAPI SptRealProny(double x[ ], long len, long numOfComplexSin, 
                     double sampleFreq, long positiveOnly, double amplitude[ ],
                     double phase[ ], double dampFactor[ ], 
                     double frequency[ ], long * outputSize);
long DSPAPI SptRealMatrixPencil(double x[ ], long len, long order, 
                            long numOfComplexSin, double sampleFreq, 
                            long positiveOnly, double amplitude[ ], 
                            double phase[ ], double dampFactor[ ], 
                            double frequency[ ], double * noiseEst,
                            long * outputSize);
long DSPAPI SptRealMinDescriptLen(double x[ ], long len, long largest, 
                              long * optimalAROrder);
long DSPAPI SptCxCovariance (ComplexNum CxData[ ], long len, 
                             long numOfComplexSin, 
                             ComplexNum CxCoefficient[ ], 
                             ComplexNum CxRoots[ ], double * noiseEst);
long DSPAPI SptCxCovPowerSpectrum(ComplexNum CxData[ ], long len, 
                                  long numOfComplexSin, long numOfBins,
                                  double sampleFreq, 
                                  SptPowerSpectrumPlot * powerSpectrumPlot,
                                  double * noiseEst);
long DSPAPI SptCxPrincipalComAutogressive(ComplexNum CxData[ ], long len, 
                                          long order, long numOfComplexSin,
                                          ComplexNum CxCoefficient[], 
                                          ComplexNum CxRoots[ ]);
long DSPAPI SptCxPCARPowerSpectrum(ComplexNum CxData[ ], long len, long order, 
                                   long numOfComplexSin, long numOfBins, 
                                   double sampleFreq, double amplitude[ ], 
                                   double phase[ ], double frequency[ ], 
                                   double * noiseEst, 
                                   SptPowerSpectrumPlot * powerSpectrumPlot, 
                                   long * outputSize);
long DSPAPI SptCxProny(ComplexNum CxData[ ], long len, long numOfComplexSin, 
                       double sampleFreq, double amplitude[ ], double phase[ ], 
                       double dampFactor[ ], double frequency[ ], 
                       long * outputSize);
long DSPAPI SptCxMatrixPencil(ComplexNum CxData[ ], long len, long order, 
                              long numOfComplexSin, double sampleFreq, 
                              double amplitude[ ], double phase[ ], 
                              double dampFactor[ ], double frequency[ ],
                              double * noiseEst, long * outputSize);
long DSPAPI SptCxMinDescriptLen(ComplexNum CxData[ ], long len, long largest,
                                long * optimalAROrder);
#ifdef __cplusplus
}
#endif

#endif
