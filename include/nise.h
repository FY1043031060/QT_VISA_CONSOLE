/*============================================================================*/
/*                        NI Switch Executive                                 */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2001.  All Rights Reserved.          */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       nise.h                                                        */
/* Purpose:     Include file for NI Switch Executive runtime interface        */
/*                                                                            */
/*============================================================================*/


#ifndef __NISE_H__
#define __NISE_H__

#include <visatype.h>

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef _CVI_
    #pragma  EnableLibraryRuntimeChecking
#endif

/*============================================================================*/
/* Type Definitions                                                           */
/*============================================================================*/

typedef long            NISESession;
typedef long            NISEInt32;
typedef const char *    NISEConstString;
typedef char            NISEBuffer;
typedef long            NISEStatus;
typedef unsigned short  NISEBoolean;


/*============================================================================*/
/* Defined Values                                                             */
/*============================================================================*/

/* Defined values for NISEBoolean type */
#define NISE_FALSE                                    (0)
#define NISE_TRUE                                     (1)

/* Multiconnect Mode for niSE_Connect and niSE_ConnectAndDisconnect */
#define NISE_VAL_USE_DEFAULT_MODE                     (-1L)
#define NISE_VAL_NO_MULTICONNECT                      (0L)
#define NISE_VAL_MULTICONNECT_ROUTES                  (1L)

/* Operation Order for niSE_ConnectAndDisconnect */
#define NISE_VAL_BREAK_BEFORE_MAKE                    (1L)
#define NISE_VAL_BREAK_AFTER_MAKE                     (2L)

/* Route Capability for niSE_FindRoute */
#define NISE_VAL_PATH_NEEDS_HARDWIRE                  (-2L)
#define NISE_VAL_PATH_NEEDS_CONFIG_CHANNEL            (-1L)
#define NISE_VAL_PATH_AVAILABLE                       (1L)
#define NISE_VAL_PATH_EXISTS                          (2L)
#define NISE_VAL_PATH_UNSUPPORTED                     (3L)
#define NISE_VAL_RSRC_IN_USE                          (4L)
#define NISE_VAL_SOURCE_CONFLICT                      (5L)
#define NISE_VAL_EXCLUSION_CONFLICT                   (5L)
#define NISE_VAL_CHANNEL_NOT_AVAILABLE                (6L)
#define NISE_VAL_CHANNELS_HARDWIRED                   (7L)

/* Infinite for niSE_WaitForDebounce */
#define NISE_VAL_INFINITE                             (-1L)

/* Expand Action for niSE_ExpandRouteSpec */
#define NISE_VAL_EXPAND_TO_ROUTES                     (0L)
#define NISE_VAL_EXPAND_TO_PATHS                      (1L)

/* File Format for niSE_ExportSpecific and niSE_ImportSpecific */
#define NISE_VAL_NI_SWITCH_EXECUTIVE_EXPORT_FILE      (1L)  /* legacy deployment format */
#define NISE_VAL_EXCEL_XLS_WORKBOOK                   (2L)  /* editable format */
#define NISE_VAL_EXCEL_XLSX_WORKBOOK                  (3L)  /* editable format */
#define NISE_VAL_TAB_DELIMITED_FILE                   (4L)  /* editable format */
#define NISE_VAL_NI_CONFIGURATION_EXPORT_FILE         (5L)  /* preferred deployment format */

/* Previous File Format for niSE_ExportPrevious */
#define NISE_VAL_NI_SWITCH_EXECUTIVE_EXPORT_FILE_2_0 (1L)
#define NISE_VAL_NI_SWITCH_EXECUTIVE_EXPORT_FILE_2_1 (2L)
#define NISE_VAL_NI_SWITCH_EXECUTIVE_EXPORT_FILE_3_0 (3L)
#define NISE_VAL_EXCEL_XLS_WORKBOOK_3_0              (4L)
#define NISE_VAL_EXCEL_XLSX_WORKBOOK_3_0             (5L)
#define NISE_VAL_TAB_DELIMITED_FILE_3_0              (6L)

/*============================================================================*/
/* Error Code Defines                                                         */
/*============================================================================*/

#define NISE_ERROR_BASE                               (0xFFFF8EB8)
#define NISE_ERROR_NONE                               (0L)

#define NISE_ERROR_INTERNAL                           (NISE_ERROR_BASE - 0L)
#define NISE_ERROR_IVI_DRIVER_NO_SIMULATION           (NISE_ERROR_BASE - 1L)
#define NISE_ERROR_INVALID_VIRTUAL_DEVICE_NAME        (NISE_ERROR_BASE - 2L)
#define NISE_ERROR_INVALID_SESSION                    (NISE_ERROR_BASE - 3L)
#define NISE_ERROR_INSUFFICIENT_SYSTEM_RESOURCES      (NISE_ERROR_BASE - 4L)
#define NISE_ERROR_AMBIGUOUS_NAME                     (NISE_ERROR_BASE - 5L)
#define NISE_ERROR_INVALID_IVI_LOGICAL_NAME           (NISE_ERROR_BASE - 6L)
#define NISE_ERROR_INVALID_ROUTE_SPECIFICATION        (NISE_ERROR_BASE - 7L)
#define NISE_ERROR_EVAL_TIMED_OUT                     (NISE_ERROR_BASE - 8L)
#define NISE_ERROR_INVALID_NAME                       (NISE_ERROR_BASE - 9L)
#define NISE_ERROR_RUNTIME_IMPORTING_EVAL             (NISE_ERROR_BASE - 10L)
#define NISE_ERROR_EVAL_EXPIRED_IMPORTING             (NISE_ERROR_BASE - 11L)
#define NISE_ERROR_RUNTIME_EXPORTING                  (NISE_ERROR_BASE - 12L)
#define NISE_ERROR_IMPORTING_FILE_ACCESS              (NISE_ERROR_BASE - 13L)
#define NISE_ERROR_IMPORTING_FILE_FORMAT              (NISE_ERROR_BASE - 14L)
#define NISE_ERROR_INVALID_END_POINTS                 (NISE_ERROR_BASE - 15L)
#define NISE_ERROR_INVALID_PATH                       (NISE_ERROR_BASE - 16L)
#define NISE_ERROR_INVALID_CHANNEL_SPECIFICATION      (NISE_ERROR_BASE - 17L)
#define NISE_ERROR_DLL_NOT_FOUND                      (NISE_ERROR_BASE - 18L)
#define NISE_ERROR_FUNCTION_NOT_FOUND                 (NISE_ERROR_BASE - 19L)
#define NISE_ERROR_MAX_TIME_EXCEEDED                  (NISE_ERROR_BASE - 20L)
#define NISE_ERROR_ROUTE_ALREADY_EXISTS               (NISE_ERROR_BASE - 21L)
#define NISE_ERROR_ROUTE_EXISTS_AS_UNSHAREABLE        (NISE_ERROR_BASE - 22L)
#define NISE_ERROR_ROUTE_EXISTS_BY_DIFFERENT_PATH     (NISE_ERROR_BASE - 23L)
#define NISE_ERROR_ROUTE_DOES_NOT_EXIST               (NISE_ERROR_BASE - 24L)
#define NISE_ERROR_PARTIAL_DISCONNECT                 (NISE_ERROR_BASE - 25L)
#define NISE_ERROR_RESOURCE_IN_USE                    (NISE_ERROR_BASE - 26L)
#define NISE_ERROR_FILE_WRITE                         (NISE_ERROR_BASE - 27L)
#define NISE_ERROR_FILE_READ                          (NISE_ERROR_BASE - 28L)
#define NISE_ERROR_INVALID_MULTICONNECT_MODE          (NISE_ERROR_BASE - 29L)
#define NISE_ERROR_INVALID_OPERATION_ORDER            (NISE_ERROR_BASE - 30L)
#define NISE_ERROR_CONFIG_CHANNEL_CONFLICT            (NISE_ERROR_BASE - 31L)
#define NISE_ERROR_SOURCE_CHANNEL_CONFLICT            (NISE_ERROR_BASE - 32L)
#define NISE_ERROR_ROUTE_EXISTS_WITH_DIFFERENT_MODE   (NISE_ERROR_BASE - 33L)
#define NISE_ERROR_DISABLED_CHANNEL                   (NISE_ERROR_BASE - 34L)
#define NISE_ERROR_CANNOT_CONNECT_TO_ITSELF           (NISE_ERROR_BASE - 35L)
#define NISE_ERROR_ROUTE_NOT_FOUND                    (NISE_ERROR_BASE - 36L)
#define NISE_ERROR_EXCEL_BUSY                         (NISE_ERROR_BASE - 37L)
#define NISE_ERROR_INVALID_IVI_SESSION                (NISE_ERROR_BASE - 38L)
#define NISE_ERROR_INVALID_FILE_FORMAT                (NISE_ERROR_BASE - 39L)
#define NISE_ERROR_INVALID_IVI_DRIVER_SW_MODULE       (NISE_ERROR_BASE - 40L)
#define NISE_ERROR_INVALID_DEVICE_NAME                (NISE_ERROR_BASE - 41L)
#define NISE_ERROR_DEVICE_NAME_CONFLICT               (NISE_ERROR_BASE - 42L)
#define NISE_ERROR_INVALID_EXPAND_ACTION              (NISE_ERROR_BASE - 43L)

/*============================================================================*/
/* Exported Functions                                                         */
/*============================================================================*/

NISEStatus __stdcall niSE_OpenSession(NISEConstString virtualDeviceName,
                                      NISEConstString options,
                                      NISESession * sessionHandle);

NISEStatus __stdcall niSE_CloseSession(NISESession sessionHandle);

NISEStatus __stdcall niSE_Connect(NISESession sessionHandle,
                                  NISEConstString connectSpec,
                                  NISEInt32 multiconnectMode,
                                  NISEBoolean waitForDebounce);

NISEStatus __stdcall niSE_Disconnect(NISESession sessionHandle,
                                     NISEConstString disconnectSpec);

NISEStatus __stdcall niSE_ConnectAndDisconnect(NISESession sessionHandle,
                                               NISEConstString connectSpec,
                                               NISEConstString disconnectSpec,
                                               NISEInt32 multiconnectMode,
                                               NISEInt32 operationOrder,
                                               NISEBoolean waitForDebounce);

NISEStatus __stdcall niSE_DisconnectAll(NISESession sessionHandle);

NISEStatus __stdcall niSE_WaitForDebounce(NISESession sessionHandle,
                                          NISEInt32 maxTime);

NISEStatus __stdcall niSE_IsDebounced(NISESession sessionHandle,
                                      NISEBoolean * isDebounced);

NISEStatus __stdcall niSE_FindRoute(NISESession sessionHandle,
                                    NISEConstString channel1,
                                    NISEConstString channel2,
                                    NISEBuffer * routeSpec,
                                    NISEInt32 * routeSpecSize,
                                    NISEInt32 * routeCapability);

NISEStatus __stdcall niSE_GetError(NISESession sessionHandle,
                                   NISEStatus * errorNumber,
                                   NISEBuffer * errorDescription,
                                   NISEInt32 * errorDescriptionSize);

NISEStatus __stdcall niSE_ClearError(NISESession sessionHandle);

NISEStatus __stdcall niSE_GetIviDeviceSession(NISESession sessionHandle,
                                              NISEConstString iviLogicalName,
                                              ViSession * iviSessionHandle);

NISEStatus __stdcall niSE_IsConnected(NISESession sessionHandle,
                                      NISEConstString routeSpec,
                                      NISEBoolean * isConnected);

NISEStatus __stdcall niSE_GetAllConnections(NISESession sessionHandle,
                                            NISEBuffer * routeSpec,
                                            NISEInt32 * routeSpecSize);

NISEStatus __stdcall niSE_ExpandRouteSpec(NISESession sessionHandle,
                                          NISEConstString routeSpec,
                                          NISEInt32 expandAction,
                                          NISEBuffer * expandedRouteSpec,
                                          NISEInt32 * expandedRouteSpecSize);


/* Configuration management functions */

/* NI LabWindows/CVI exports these functions via the niseCfg library */

#ifndef _CVI_

NISEStatus __stdcall niseCfg_Export(NISEConstString virtualDeviceName,
                                    NISEConstString path);

NISEStatus __stdcall niseCfg_Import(NISEConstString virtualDeviceName,
                                    NISEConstString path,
                                    NISEInt32 overwriteExisting);

NISEStatus __stdcall niseCfg_ExportSpecific(NISEConstString virtualDeviceName,
                                            NISEConstString path,
                                            NISEInt32 fileFormat);

NISEStatus __stdcall niseCfg_ExportPrevious(NISEConstString virtualDeviceName,
                                            NISEConstString path,
                                            NISEInt32 previousFileFormat);

NISEStatus __stdcall niseCfg_ImportSpecific(NISEConstString virtualDeviceName,
                                            NISEConstString path,
                                            NISEInt32 fileFormat,
                                            NISEInt32 overwriteExisting);

#endif /* _CVI_ */

#ifdef __cplusplus
    }
#endif

#endif /* __NISE_H__ */
