/*============================================================================*/
/*                        L a b W i n d o w s / C V I                         */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 1987-2005.  All Rights Reserved.     */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       pid.h                                                      	  */
/* Purpose:     Include file for the CVI PID Library			              */
/*                                                                            */
/* [01/06/05 Arjun]	                                                          */
/*============================================================================*/

#ifndef __PID_H__
#define __PID_H__

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef _CVI_
	#pragma EnableLibraryRuntimeChecking
	#include <cvirte.h>
#else	
/*============================================================================*/
/* If using some compiler other than CVI, use the following or 				  */
/* equivalent calling conventions, by changing the following macros. 		  */
/* !!! THIS COMMENT NEEDS TO BE REMOVED IN THE RELEASE HEADER FILE. !!!		  */
/*============================================================================*/
//	#define CVIFUNC 	__stdcall
//	#define CVIFUNC_C 	__cdecl
//	#define CVICALLBACK __cdecl
	#include <cvidef.h>	
#endif

/*============================================================================*/
/* Type Definitions															  */
/*============================================================================*/

// Types for handles to Pid, Ramp, and LeadLag objects
typedef struct _pidHandle
{
	long unused;
}*PidHandle;

typedef struct _rampHandle
{
	long unused;
}*PidRampHandle;

typedef struct _leadLagHandle
{
	long unused;
}*PidLeadLagHandle;

typedef struct _setpointProfileHandle
{
	long unused;
}*PidSetpointProfileHandle;


// Type enumerating Pid control Algorithms
typedef enum PidAlgorithmTag {
	pidFastPidAlgorithm			= 0,
	pidPrecisePidAlgorithm		= 1,
	pidAlgorithmMax,
	pidAlgorithmForceTo4Bytes	= 0xffffffff,
} PidAlgorithm;
	
	

// Type enumerating all the Pid Attributes
typedef enum PidAttrTag {
	pidAttrProportionalFactor	= 0,
	pidAttrIntegralTime			= 1,
	pidAttrDerivativeTime		= 2,
	pidAttrBeta					= 3,
	pidAttrControlType			= 4,
	pidAttrDeltaT				= 5,
	pidAttrHoldCurrentOutput	= 6,
	pidAttrInitialOutput		= 7,
	pidAttrLimitOutputRate		= 8,
	pidAttrLinearity			= 9,
	pidAttrManualControlValue	= 10,
	pidAttrOutputMax			= 11,
	pidAttrOutputMin			= 12,
	pidAttrOutputRate			= 13,
	pidAttrReverseActing		= 14,
	pidAttrSetpoint				= 15,
	pidAttrSetpointMax			= 16,
	pidAttrSetpointMin			= 17,
	pidAttrUseInternalTimer		= 18,
	pidAttrUseManualCtrlValue	= 19,
	pidAttrUseProportionalBand	= 20,
	pidAttrUseFilteredPV		= 21,
	pidAttrAlgorithm			= 22,
	pidAttrPVFilterSize			= 23,
	
	pidAttrMax,
	pidAttrForceTo4Bytes		= 0xffffffff,
} PidAttr;

// Type enumerating all the Gain Schedule Attributes
typedef enum PidGainScheduleAttrTag {
	pidGSAttrGainScheduleCriteria 		= 0,
	pidGSAttrUserGainScheduleVariable	= 1,
	pidGSAttrNumGainScheduleItems 		= 2,
	pidGSAttrSelectionMode				= 3,
	pidGSAttrMax,
	pidGSAttrForceTo4Bytes				= 0xffffffff,
} PidGainScheduleAttr;

// Type enumerating all the Autotune Attributes
typedef enum PidAutotuneAttrTag {
	pidAutotuneAttrApplyToActiveParameter	= 0,
	pidAutotuneAttrControlDesign			= 1,
	pidAutotuneAttrControlType				= 2,
	pidAutotuneAttrNoiseLevel				= 3,
	pidAutotuneAttrRelayAmplitude			= 4,
	pidAutotuneAttrOwnerPanelHandle			= 5,
	pidAutotuneAttrMax,
	pidAutotuneAttrForceTo4Bytes			= 0xffffffff,
} PidAutotuneAttr;

// Type enumerating all the LeadLag Attributes
typedef enum LeadLagAttrTag {
	pidLeadLagAttrDeltaT				= 0,
	pidLeadLagAttrGain					= 1,
	pidLeadLagAttrLagTime				= 2,
	pidLeadLagAttrLeadTime				= 3,
	pidLeadLagAttrUseInternalTimer		= 4,
	pidLeadLagAttrOutputMax				= 5,
	pidLeadLagAttrOutputMin				= 6,
	pidLeadLagAttrMax,
	pidLeadLagAttrForceTo4Bytes			= 0xffffffff,
} PidLeadLagAttr;

// Type enumerating all the Ramp Attributes
typedef enum RampAttrTag {
	pidRampAttrDeltaT				= 0,
	pidRampAttrInitialOutput		= 1,
	pidRampAttrRate					= 2,
	pidRampAttrSetpoint				= 3,
	pidRampAttrUseInternalTimer		= 4,
	pidRampAttrMax,
	pidRampAttrForceTo4Bytes		= 0xffffffff,
} PidRampAttr;

// Type enumerating all the Setpoint Profiler Attributes
typedef enum SetpointProfileAttrTag {
	pidSetpointProfileAttrDeltaT				= 0,
	pidSetpointProfileAttrUseInternalTimer		= 1,
	pidSetpointProfileAttrElapsedTime			= 2,
	pidSetpointProfileAttrProfileComplete		= 3,
	pidSetpointProfileAttrMax,
	pidSetpointProfileAttrForceTo4Bytes		= 0xffffffff,
} PidSetpointProfileAttr;

// Type enumerating the kinds of Pid Controllers
typedef enum PidControllerTag {
	pidPID 							= 0,
	pidPI 							= 1,
	pidPD 							= 2,
	pidP 							= 3,
	pidControllerMax,
	pidControllerForceTo4Bytes		= 0xffffffff,
} PidController;

// Type enumerating all the Pid Events
typedef enum PidEventTag {
	pidAutotuneEvent				= 0,
	pidNoiseEstimateEvent			= 1,
	pidRelayCycleEvent				= 2,
	pidEventMax,
	pidEventForceTo4Bytes			= 0xffffffff,
} PidEvent;

// Type enumerating the Autotune Type
typedef enum PidAutotuneTypeTag {
	pidAutotuneClassic				= 0,
	pidAutotuneWizard				= 1,
	pidAutotuneTypeMax,
	pidAutotuneTypeForceTo4Bytes	= 0xffffffff,
} PidAutotuneType;

// Type enumerating the Pid Controller Designs supported by the Autotuning Algorithm
typedef enum PidAutotuneControlDesignTag {
	pidAutotuneNormal 				= 0,
	pidAutotuneFast 				= 1,
	pidAutotuneSlow 				= 2,
	pidAutotuneControlDesignMax,
	pidAutotuneForceTo4Bytes		= 0xffffffff,
} PidAutotuneControlDesign;

// Type enumerating the kinds of Pid Controllers supported by the Autotuning Algorithm
typedef enum PidAutotuneControllerTypeTag {
	pidAutotunePID 						= 0,
	pidAutotunePI 						= 1,
	pidAutotuneP 						= 2,
	pidAutotuneControllerTypeMax,
	pidAutotuneControllerForceTo4Bytes	= 0xffffffff,
} PidAutotuneControllerType;

// Type enumerating the different Gain Schedule criteria supported
typedef enum PidGainScheduleCriteriaTag {
	pidSetpoint 							= 0,
	pidProcessVariable 						= 1,
	pidControllerOutput 					= 2,
	pidGainSchedulingVariable 				= 3,
	pidGainScheduleCriteriaMax,
	pidGainSchedulingCriteriaForceTo4Bytes	= 0xffffffff,
} PidGainScheduleCriteria;

// Type enumerating the Selection Modes for Gain Scheduled controllers
typedef enum PidGainScheduleSelectionModeTag {
	pidManual 						= 0,
	pidAutomatic 					= 1,
	pidSelectionModeMax,
	pidSelectionModeForceTo4Bytes	= 0xffffffff,
} PidGainScheduleSelectionMode;

// Type enumerating error codes returned by the functions
typedef enum PidErrorTag {
	pidErrNoError 							= 0,
	pidErrInvalidHandle						= -1,
	pidErrOutOfMemory						= -2,
	pidErrInvalidArgument					= -3,
	pidErrIllegalFunctionCall				= -4,
	pidErrWizardStartupError				= -5,
	pidErrUnexpectedError					= -6,
	pidErrControllerNotGainScheduled		= -7,
	pidErrControllerNoAutotuning			= -8,
	pidErrNoActiveParameter 				= -9,
	pidErrDeltaTNonPositive 				= -10,
	pidErrIntegralTimeNegative				= -11,
	pidErrDerivativeTimeNegative			= -12,
	pidErrCVIPIDAtUIDllNotFound				= -13,
	pidErrCVIPIDAtUIDllIsCorrupted			= -14,
	pidErrAutotuneWizardNotSupportedOnRT	= -15,
	pidErrCreateMutexError					= -16,
	pidErrInvalidFilterArray				= -17,
	pidErrGainScheduleCannotBeEmpty			= -18,
	pidErrorMax,
	pidErrorForceTo4Bytes					= 0xffffffff,
} PidError;

// Type definition for the Callback function called for Pid Events
typedef int (CVICALLBACK *PidCallbackPtr)(PidHandle handle, PidEvent event,
                                          double , double , 
                                          double , void* callbackData);


/*======================================================================================*/
/* Function Prototypes														     	    */
/*======================================================================================*/

// Returns a string describing the error code passed in
char* CVIFUNC PidGetLibraryErrorString (int error);


// Convert from EGU to Percentage. EGU - Engineering Units
int CVIFUNC PidConvertEGUToPercentage(double maxEGU, double minEGU, double inputEGU, 
									  double *percentSpan);

// Convert from Percentage to EGU. EGU - Engineering Units
int CVIFUNC PidConvertPercentageToEGU(double maxEGU, double minEGU, double inputPercentSpan, 
									  int bCoerce, double *outputEGU);

/*---------------------------------------------------------------------------*/
/* Controller  																 */
/*---------------------------------------------------------------------------*/

// Creates a simple controller [ Non-GainScheduled and No Autotuning ]
int CVIFUNC PidCreate (double kP, double tI, double tD, PidHandle* handle);

// Discards any Pid Controller
int CVIFUNC PidDiscard (PidHandle handle);

// Given the PV computes the controller output
int CVIFUNC PidNextOutput (PidHandle handle, double processVar, double* output);

// Resets the controller to its default state
int CVIFUNC PidReset (PidHandle handle);

// Gets the value of any Pid Controller Attribute
int CVIFUNC PidGetAttribute (PidHandle handle, PidAttr attr, void* value);

// Sets the value of any Pid Controller Attribute
int CVIFUNC_C PidSetAttribute (PidHandle handle, PidAttr attr, ...);

// Gets a process Variable filter
int CVIFUNC PidGetProcessVariableFilter(PidHandle handle, int filterSize, double filter[]);

// Sets a process variable filter
int CVIFUNC PidSetProcessVariableFilter(PidHandle handle, int filterSize, double filter[]);

/*---------------------------------------------------------------------------*/
/* Gain Scheduling  														 */
/*---------------------------------------------------------------------------*/

// Creates a GainScheduled controller. [No Autotuning]
int CVIFUNC PidCreateGainScheduleController (PidGainScheduleCriteria type, long numParams,
								 		 	 double kP[], double tI[], double tD[], 
								 		 	 double gsv[], PidHandle* handle);

// Gets the position of the Active Gain Set
int CVIFUNC PidGetActiveGainSetPosition (PidHandle handle, long* pos);

// Changes the active Gain Set
int CVIFUNC PidChangeActiveGainSet (PidHandle handle, long newSetPos, long* oldSetPos);

// Gets the parameters of the Gain-Schedule Item at index = pos (pos is 1-based)
int CVIFUNC PidGetGainSet (PidHandle handle, long pos, double* kP,
									double* tI, double* tD, double* gsv);

// Sets the parameters of the Gain-Schedule Item at index = pos (pos is 1-based)
int CVIFUNC PidSetGainSet (PidHandle handle, long pos, double kP,
									   double tI, double tD, double gsv);
									   
// Adds a new Gain-Schedule Item to the internal list (adds to the end of the list)
int CVIFUNC PidAddGainSet (PidHandle handle, double kP, double tI, 
									double tD, double gsv);

// Discards the GainSchedule Item at index = pos (the remaining items are shifted accordingly)
int CVIFUNC PidRemoveGainSet (PidHandle handle, long pos);

// Gets the value of any Gain Schedule Attribute
int CVIFUNC PidGetGainScheduleAttribute (PidHandle handle, PidGainScheduleAttr attr, void* value);

// Sets the value of any Gain Schedule Attribute
int CVIFUNC_C PidSetGainScheduleAttribute (PidHandle handle, PidGainScheduleAttr attr, ...);
	
/*---------------------------------------------------------------------------*/
/* Autotuning  																 */
/*---------------------------------------------------------------------------*/

// Creates a Non-GainScheduled controller that can be Autotuned
int CVIFUNC PidCreateWithAutotune (double kP, double tI, double tD, PidCallbackPtr callbackFunc, 
					   void* callbackData, PidAutotuneType autotuneType, PidHandle* handle);

// Closes the Autotuning Wizard Dialog
int CVIFUNC PidAutotuneCloseDialog (PidHandle handle);

// Aborts any autotuning activity and resets the Autotuner
int CVIFUNC PidAutotuneReset (PidHandle handle);

// Displays the Autotuning Wizard Dialog (and starts the Wizard)
int CVIFUNC PidAutotuneShowDialog (PidHandle handle);

// Starts the Autotuning (the Relays has to be started before calling this)
int CVIFUNC PidAutotuneStartTune (PidHandle handle, long numCycles);

// Starts estimating the Noise
int CVIFUNC PidAutotuneStartNoiseEstimate (PidHandle handle, long numCycles);

// Starts the Setpoint Relay
int CVIFUNC PidAutotuneStartRelay (PidHandle handle);

// Stops (aborts) the Autotuning process
int CVIFUNC PidAutotuneStopTune (PidHandle handle);

// Stops (aborts) the Noise Estimation process
int CVIFUNC PidAutotuneStopNoiseEstimate (PidHandle handle);

// Stops (aborts) the Setpoint Relay
int CVIFUNC PidAutotuneStopRelay (PidHandle handle);

// Gets the value of any Autotune Attribute
int CVIFUNC PidGetAutotuneAttribute (PidHandle handle, PidAutotuneAttr attr, void* value);

// Sets the value of any Autotune Attribute
int CVIFUNC_C PidSetAutotuneAttribute (PidHandle handle, PidAutotuneAttr attr, ...);
	
/*---------------------------------------------------------------------------*/
/* LeadLag Compensator  													 */
/*---------------------------------------------------------------------------*/

// Creates a LeadLag Compensator
int CVIFUNC PidLeadLagCreate (double gain, double lagTime, double leadTime, PidLeadLagHandle* handle);

// Discards a LeadLag Compensator
int CVIFUNC PidLeadLagDiscard (PidLeadLagHandle handle);

// Given the input, computes the output of a LeadLag Compensator
int CVIFUNC PidLeadLagNextOutput (PidLeadLagHandle handle, double input, double* output);

// Resets a LeadLag Compensator to its default state
int CVIFUNC PidLeadLagReset (PidLeadLagHandle handle);

// Gets the value of any LeadLag Attribute
int CVIFUNC PidGetLeadLagAttribute (PidLeadLagHandle handle, PidLeadLagAttr attr, void* value);

// Sets the value of any LeadLag Attribute
int CVIFUNC_C PidSetLeadLagAttribute (PidLeadLagHandle handle, PidLeadLagAttr attr, ...);

/*---------------------------------------------------------------------------*/
/* Ramp 																	 */
/*---------------------------------------------------------------------------*/

// Creates a Ramp Generator
int CVIFUNC PidRampCreate (double initialOutput, double rate, double setpoint, PidRampHandle* handle);

// Discards a Ramp Generator
int CVIFUNC PidRampDiscard (PidRampHandle handle);

// Computes the next output of the Ramp Generator
int CVIFUNC PidRampNextOutput (PidRampHandle handle, double* output);

// Resets the Ramp Generator to its default stae
int CVIFUNC PidRampReset (PidRampHandle handle);

// Gets the value of any Ramp Attribute
int CVIFUNC PidGetRampAttribute (PidRampHandle handle, PidRampAttr attr, void* value);

// Sets the value of any Ramp Attribute
int CVIFUNC_C PidSetRampAttribute (PidRampHandle handle, PidRampAttr attr, ...);

/*---------------------------------------------------------------------------*/
/* Setpoint Profiling														 */
/*---------------------------------------------------------------------------*/

//Creates a Setpoint Profile
int CVIFUNC PidSetpointProfileCreate(double time[], double setpoint[], long numItems, PidSetpointProfileHandle *handle);

//Discards a Setpoint Profile
int CVIFUNC PidSetpointProfileDiscard(PidSetpointProfileHandle handle);

// Computes the next Setpoint, of the Setpoint profile
int CVIFUNC PidSetpointProfileNextSetpoint(PidSetpointProfileHandle handle, double *setpoint);

// Reset the Setpoint Profile
int CVIFUNC PidSetpointProfileReset(PidSetpointProfileHandle handle);

// Gets the value of any Setpoint Profile attribute
int CVIFUNC PidGetSetpointProfileAttribute(PidSetpointProfileHandle handle, PidSetpointProfileAttr attr, void *value);

// Sets the value of any Setpoint Profile attribute
int CVIFUNC_C PidSetSetpointProfileAttribute(PidSetpointProfileHandle handle, PidSetpointProfileAttr attr, ...);


#ifdef __cplusplus
    }
#endif
	
#endif /* __PID_H__ */

