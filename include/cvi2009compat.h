/*============================================================================*/
/*                        L a b W i n d o w s / C V I                         */
/*----------------------------------------------------------------------------*/
/*    Copyright (c) National Instruments 2009-2009.   All Rights Reserved.    */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Title:       cvi2009compat.h                                               */
/* Purpose:     Include file that allows programs written in CVI 2009 or      */
/*              later to compile in previous versions of CVI                  */
/*                                                                            */
/*============================================================================*/

#ifndef _CVI2009COMPAT_H
#define _CVI2009COMPAT_H

#include "cvidef.h"

#if !defined (_CVI_LIBS_) || _CVI_LIBS_ < 910

#define CmtTSQHandle            int
#define CmtTSQCallbackID        int
#define CmtThreadPoolHandle     int
#define CmtThreadPoolCallbackID int
#define CmtThreadFunctionID     int
#define CmtTLVHandle            int
#define CmtTSVHandle            int
#define CmtThreadLockHandle     int

#endif 

#endif  /* ndef _CVI2009COMPAT_H */
