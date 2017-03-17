#ifndef _SPTWFBD_H
#define _SPTWFBD_H

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
    double *lowPass;
	long lowLen;
	double *highPass;
    long highLen;
} SptFilter;

typedef enum{
    SptMexicanHat,
	SptMeyr,
	SptMorlet,
	SptFromAnalysis,
} SptWaveletType;

typedef struct{
    double * Y;
	long sizeY;
	double * X;
	long sizeX;
}SptWaveletPlot;

typedef enum{
	TIMEDOMAIN,
    FREQDOMAIN,
} SptDomain;

typedef enum{
	SptRigrSure,
	SptHeurSure,
    SptSqTwoLog,
	SptMinimax,
} SptThresholdRule;

typedef enum{
    SptOne,
	SptSln,
	SptMln,
} SptScale;

typedef enum{
  SptShannon,
  SptThreshold,
  SptSure,
  SptNorm,
  SptEnergy,
} SptEntropy;

#pragma pack (pop)


long DSPAPI SptInterpolationFilter(double x[ ], long len, 
                                   double filterCoef[ ], long lenFilterCoef,
                                   long interpfactor, long shift,
                                   double output[]);
long DSPAPI SptDecimationFilter(double x[ ], long len, double coef[ ], 
                                long lenCoef, SptExtension extension, 
                                double initialCondition[ ], 
                                double finalCondition[ ], 
                                long decFact, 
                                long shift, double output[ ]);
long DSPAPI SptMotherWavScaling(SptFilter * filter, long refine, 
                                double scaleFunc[ ], long * scaleFuncSize,
                                double motherWav[ ], long * waveSize, 
                                double * dt);
long DSPAPI SptAnalysisFilterBank(double x[ ], long len, 
                                  SptFilter * analysisFilter,
                                  SptExtension extension, 
                                  double initialCondition[ ], 
                                  double finalCondition[ ],
                                  long shift, double lowPass[ ], 
                                  double highPass[ ]);
long DSPAPI SptSynthesisFilterBank(double lowPass[ ], double highPass[ ], 
                                   long len, SptFilter * synthesisFilter, 
                                   long shift, double output[ ]);
long DSPAPI SptDiscreteWaveletTransform(double x[ ], long len, 
                                        SptFilter * filter, 
                                        SptExtension extension, 
                                        double initialCondition[ ], 
                                        double finalCondition[ ], 
                                        long scales, long shift, 
                                        double dwt[ ], long * outputSize, 
                                        long lengths[ ]);
long DSPAPI SptInvDiscreteWaveletTransform(double dwt [ ], long dwtLen, 
                                           long lengths[ ], long lengthLen, 
                                           SptFilter * filter, long shift,
                                           double x[ ]);
long DSPAPI SptArbitraryPath(double x[ ], long len, char *path, long pathLen,
                             SptFilter *filter, SptExtension extension, 
                             double initialCondition[ ], 
                             double finalCondition[ ], 
                             long shift, double waveletTransform[ ]);
long DSPAPI SptAnalysisFilterBank2D(double * x, long rows, long cols, 
                                    SptFilter * analysisFilter, 
                                    SptExtension extension, long shift, 
                                    double * lowLow, double * lowHigh, 
                                    double * highLow, double * highHigh);
long DSPAPI SptSynthesisFilterBank2D(double * lowLow, double * lowHigh, 
                                     double * highLow, double * highHigh, 
                                     long rows, long cols, 
                                     SptFilter * synthesisFilter, 
                                     long rowsOutput, long colsOutput, 
                                     long shift, double * output);
long DSPAPI SptDeNoise1D(double x[ ], long len, long scales, 
                         SptThresholdRule thresholdRule, long hardThreshold, 
                         SptScale rescaling, SptExtension extension, 
                         SptFilter * analysisFilter, 
                         SptFilter * synthesisFilter, long shift, 
                         double deNoised[ ]);
long DSPAPI SptConWaveletTransform(double x[ ], long len, SptWaveletType type,
                                   SptFilter * filter, long scales, 
                                   double * conWaveletTransform,
                                   SptWaveletPlot * plot);
long DSPAPI SptDetrend(double x[ ], long len, double trendLevel,
                       SptExtension extension, double initialCondition[ ], 
                       double finalCondition[ ], SptFilter * analysisFilter, 
                       SptFilter * synthesisFilter, long shift, 
                       double detrend[ ], double trend[ ]);
void * DSPAPI SptAllocCoeffWFBD(void);
long DSPAPI SptReadCoeffWFBD(char coeffPath[], SptFilter * analysisFilter,
                             SptFilter * synthesisFilter);
long DSPAPI SptFreeCoeffWFBD(void * fptr);
long DSPAPI SptTruncatedAnalysisFilterBank(double x[ ], long len, 
                                           SptFilter * analysisFilter, 
                                           SptExtension extension,
                                           double initialCondition[ ], 
                                           double finalCondition[ ], 
                                           long shift, double lowPass[ ], 
                                           double highPass[ ]);
/*------------------------------
 	new functions for SPT7.0
 -------------------------------*/   
long DSPAPI SptConWaveletTransformEx(double x[ ], long len, SptWaveletType type,
                                     SptFilter * filter, long scales, 
                                     long timeStep, double * conWaveletTransform);
long DSPAPI SptArbPathDecomposition(double x[], long len, char *path, 
									long pathLen, SptFilter *analysisFilter, 
									SptExtension extension, double pathCoeff[], 
									long *pathCoeffLen,
									double residualCoeffs[], 
									long *residualCoeffsLen, 
									long residualSizes[]);
long DSPAPI SptArbPathReconstruction(double pathCoeff[], long pathCoeffLen,
									 double residualCoeffs[],
									 long residualCoeffsLen,
									 long residualSizes[],
									 long residualSizesLen, char *path, 
									 long pathLen, SptFilter *synthesisFilter,
									 double waveform[]);
long DSPAPI SptWPCreateHandle(long* WPHandle);									
long DSPAPI SptWPDisposeHandle(long WPHandle);
long DSPAPI SptWPDecomposition1D(long WPHandle, double x[],	long len, 
								 long scales, SptExtension extension, 
								 SptEntropy entropyType, double refValue,
								 SptFilter *analysisFilter, 
								 SptFilter *synthesisFilter);
long DSPAPI SptWPReconstruction1D(long WPHandle, double waveform[]);
long DSPAPI SptWPReadTerminalNode(long WPHandle, char *node, long nodeLen,
						  			double *coefficient);
long DSPAPI SptWPWriteTerminalNode(long WPHandle, double coefficient[], long length, 
									char *node, long nodeLen);
long DSPAPI SptWPSplit1D(long WPHandle, char *node, long nodeLen);
long DSPAPI SptWPJoin1D(long WPHandle, char *node, long nodeLen);
long DSPAPI SptWPReadEntropy(long WPHandle, char *node, long nodeLen,
							 double *entropy);
long DSPAPI SptWPReadTreeStr(long WPHandle, long treeStr[]);
long DSPAPI SptWPGetTerminalNodeLen(long WPHandle, char *node, long nodeLen, 
							long *coeffLen);
long DSPAPI SptWPGetTreeStrLen(long WPHandle, long *treeStrLen);
long DSPAPI SptWPOptimalNode(long WPHandle, long method, 
							char *optimalNode, long *nodeLen);
long DSPAPI SptWPIndexToNode(long index, char *node, long *nodeLen);


#ifdef __cplusplus
}
#endif


#endif
