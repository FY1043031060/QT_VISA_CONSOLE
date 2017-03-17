#ifndef _SPT_H		  
#define _SPT_H		    
		   
#include "analysis.h"
#include "sptjtfa.h"
#include "sptsrse.h"
#include "sptwfbd.h"

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

char * DSPAPI SptGetErrorString(long error);

#ifdef __cplusplus
}
#endif

#define JTFADataSizeErr	       -20601		/*The input arrays do not contain the correct number of data values for JTFA analysis.*/
#define JTFAdMErr		       -20602		/*The time increment must be greater than zero. In Gabor related functions, it also should be power of two.*/
#define JTFANErr		       -20603		/*The number of frequency bins must be power of two.*/
#define JTFAWinLenErr	       -20604		/*The window length must be greater than zero. In Gabor Transform, it also should be multiple of N and dM.*/
#define GaborOversamplErr      -20605		/*The oversampling rate of Gabor transform must be greater or equal to one.*/
#define JTFATIErr		       -20606		/*The time interval must be power of two. In WVD and Adaptive Spectrogram, it is only required to be greater than zero.*/
#define JTFAFreqBinErr	       -20607		/*The number of frequency bins must be greater than zero.*/
#define JTFAFreqRangeErr       -20608		/*The frequency range is invalid.*/
#define GaborSpOrderErr	       -20609		/*The order of the Gabor spectrogram must be greater or equal to zero.*/
#define GaborSpInterpErr       -20610		/*The interpolate factor of the Gabor spectrogram must be greater than zero.*/
#define KernelDimErr	       -20611		/*The dimension of kernel must be power of two.*/
#define AdptTermErr		       -20612		/*The number of term for adaptive  chirplet transform must be greater than zero.*/
#define GaussVarErr		       -20613		/*The variance of gaussian windows must be greater than zero.*/

#define SRSASamplErr	       -20631		/*The input arrays do not contain the correct number of data values for super resolution spectrum  analysis.*/
#define SRSAOrderErr	       -20632		/*The order for AR model must be greater than zero and  not greater than two thirds  the number of samples.*/
#define SRSARootsErr	       -20633		/*The number of roots of polynomial must be greater than zero.*/
#define SRSAFreqBinsErr	       -20634		/*The number of frequency bins in spectrum computing must greater than two.*/
#define NumOfCxSinErr	       -20635		/*The number of complex sinusoids must be greater than zero and not greater than two thirds the number of samples.*/
#define OrderGENumOfSinErr     -20636		/*The AR order must be greater than  or equal to the number of complex sinusoids.*/
#define SampleFreqErr		   -20637		/*The sampling frequency should be greater than zero.*/

#define WaveTypeErr		       -20661		/*The selection of wavelet type is invalid.*/
#define WaveSamplErr	       -20662		/*The input arrays do not contain the correct number of data values for wavelet analysis.*/
#define WaveScaleErr	       -20663		/*The scale of wavelet decomposition must be greater than or equal to zero.*/
#define WaveShiftErr	       -20664		/*The indexes of decimation or interpolation must be greater than zero.*/
#define WaveDecimatErr	       -20665		/*The decimation factor must be greater or equal to two.*/
#define WaveInterpErr	       -20666		/*The interpolation factor must be greater or equal to two.*/
#define WaveRefineErr	       -20667		/*The refinement level for computing mother wavelet must be greater than zero.*/
#define FilterLenErr	       -20668		/*The length of analysis filter or synthesis filter must be great than zero.*/
#define ExtenLenErr		       -20669		/*The size of the initial or final condition array must be greater than zero.*/
#define InvalidPathErr	       -20670		/*The path for arbitrary path decompositon or reconstruction is invalid.*/
#define InvalidNodeErr	   	   -20671		/*The node for wavelet packet process is invalid.*/
#define IsTNodeErr		       -20672		/*The node must not be a terminal node for wavelet packet process.*/
#define NotTNodeErr		       -20673		/*The node must be a terminal node for wavelet packet process.*/
#define NotFullTreeErr	       -20674		/*The wavelet packet tree structure is not a full tree.*/
#define WFBFileOpenErr	       -20675		/*Cannot open data file for wavelet filter bank.*/
#define WFBFileFormatErr       -20676		/*The format of data file for wavelet filter bank is invalid.*/

#define RefOutOfMemErr	       -20691		/*The reference number can not be allocted.*/
#define RefAlreadyExistErr     -20692		/*The reference number being added to the internal table already exists.*/
#define RefInvalidErr	       -20693		/*The reference number is invalid.*/
#define RefDataTypeErr	       -20694		/*The operation does not support the data type stored in the reference number.*/
#define RefIndexOutOfRangeErr  -20695		/*The index of 2D array stored in the reference number is out of range.*/
#define InvalidSessionErr	   -20696		/*The session is an invalid session.*/
#define InvalidHandleErr	   -20697		/*The handle is an invalid handle.*/

#define kFailedToLoadDLLError  -20105		/*The DLL does not load.*/
#define kCouldNotFindFunction  -20106 		/*Missing one or more functions.*/
#define kCouldNotCreateMutex   -20107		/*The mutex cannot be created.*/
#define NoErr				   0			/*No error. The function call was successful.*/


#endif

