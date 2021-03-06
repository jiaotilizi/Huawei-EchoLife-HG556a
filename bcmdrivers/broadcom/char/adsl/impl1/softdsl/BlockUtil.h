/*
<:copyright-broadcom 
 
 Copyright (c) 2002 Broadcom Corporation 
 All Rights Reserved 
 No portions of this material may be reproduced in any form without the 
 written permission of: 
          Broadcom Corporation 
          16215 Alton Parkway 
          Irvine, California 92619 
 All information contained in this document is Broadcom Corporation 
 company private, proprietary, and trade secret. 
 
:>
*/
/* BlockUtil.h
 *
 *	Description:
 *		This file contains the interfaces for the fixed point block
 *		processing utilities.
 *
 * Copyright (c) 1993-1998 AltoCom, Inc. All rights reserved.
 * Authors: Mark Gonikberg, Haixiang Liang.
 *
 * $Revision: 1.1 $
 *
 * $Id: BlockUtil.h,v 1.1 2008/08/25 06:41:01 l65130 Exp $
 *
 * $Log: BlockUtil.h,v $
 * Revision 1.1  2008/08/25 06:41:01  l65130
 * 【变更分类】建立基线
 * 【问题单号】
 * 【问题描述】
 * 【修改说明】
 *
 * Revision 1.1  2008/06/20 06:21:21  z67625
 * *** empty log message ***
 *
 * Revision 1.1  2008/01/14 02:47:17  z30370
 * *** empty log message ***
 *
 * Revision 1.2  2007/12/16 10:09:55  z45221
 * 合入人:
 * s48571
 *
 * 合入内容：
 * ADSL驱动更新版本至A2x020h
 * ADSLfirmware版本更换版本至a2pb023k/b2pb023k
 *
 * 修改文件列表：
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCore.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCore.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCoreFrame.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCoreFrame.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslCoreMap.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslDrvVersion.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslFile.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslFile.h
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslSelfTest.c
 * /bcmdrivers/broadcom/char/adsl/impl1/AdslSelfTest.h
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslCore.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslCore.h
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiag.h
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiagLinux.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiagNone.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmAdslDiagRtems.c
 * /bcmdrivers/broadcom/char/adsl/impl1/BcmOs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/Makefile
 * /bcmdrivers/broadcom/char/adsl/impl1/adsl.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adsldrv.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_defs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_lmem.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_lmem.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_sdram.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348/adsl_sdram.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_defs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_lmem.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_lmem.h
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_sdram.c
 * /bcmdrivers/broadcom/char/adsl/impl1/adslcore6348B/adsl_sdram.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslCoreDefs.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMib.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMib.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMib.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMibObj.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslMibOid.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/AdslXfaceData.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/BlockUtil.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/CircBuf.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/DslFramer.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/DslFramer.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/Flatten.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/Flatten.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G992p3OvhMsg.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G992p3OvhMsg.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G992p3OvhMsg.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G997.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G997.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/G997.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/HdlcByte.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/HdlcFramer.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/HdlcFramer.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/MathUtil.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/MipsAsm.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/MiscUtil.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftAtmVc.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftDsl.gh
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftDsl.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftDslFrame.c
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftModem.h
 * /bcmdrivers/broadcom/char/adsl/impl1/softdsl/SoftModemTypes.h
 *
 * /bcmdrivers/broadcom/includeAdslMibDef.h
 * /bcmdrivers/broadcom/includeDiagDef.h
 * /bcmdrivers/broadcom/includeadsldrv.h
 * /bcmdrivers/broadcom/includebcmadsl.h
 *
 * /userapps/broadcom/adslctl/adslctl.c
 * /userapps/broadcom/adslctl/adsluser.c
 *
 * /userapps/broadcom/cfm/html/statsadsl.html
 * /userapps/broadcom/cfm/html/countrysupport/italy_vdf/info.html
 * /userapps/broadcom/cfm/inc/syscall.h
 * /userapps/broadcom/cfm/main/adslcfgmngr/adslctlapi.c
 * /userapps/broadcom/cfm/util/system/syscall.c
 * /userapps/broadcom/cfm/web/cgimain.c
 * /userapps/broadcom/cfm/web/cgimain.h
 *
 * Revision 1.23  2004/04/13 00:31:10  ilyas
 * Added standard header for shared ADSL driver files
 *
 * Revision 1.22  2003/07/11 01:49:01  gsyu
 * Added BlockShortClearByLong to speed up performance
 *
 * Revision 1.21  2003/07/10 22:35:23  gsyu
 * Speed up BlockByteXXX performance
 *
 * Revision 1.20  2003/07/10 22:15:51  gsyu
 * Added BlockByteMoveByWord to speed up performance
 *
 * Revision 1.19  2002/03/12 00:03:03  yongbing
 * Modify cplxScaleCplxSymbols to accept a shift value instead of an array of shifts
 *
 * Revision 1.18  2001/03/14 00:50:25  georgep
 * All targets use FEQ_PASS_FFTSHIFT, remove code for case where its not defined
 *
 * Revision 1.17  2000/11/30 03:54:09  khp
 * -BlockRealScaleCplxSymbols instead of BlockScaleComplexSymbols
 *
 * Revision 1.16  2000/11/29 20:42:12  liang
 * Add function for ADSL xmt gains with fixed shift.
 *
 * Revision 1.15  2000/10/02 19:24:08  georgep
 * Modify FEQ for new fft, fft outputs a shift for each block
 *
 * Revision 1.14  2000/09/09 00:23:48  liang
 * Add corresponding functions for the ComplexLong FEQ coef.
 *
 * Revision 1.13  2000/05/17 01:36:52  yongbing
 * Add Pentium MMX assembly codes for more block related functions
 *
 * Revision 1.12  2000/04/19 19:22:22  yongbing
 * Add BlockShortScaleby2 function used in G994p1
 *
 * Revision 1.11  2000/04/04 02:28:01  liang
 * Merged with SoftDsl_0_2 from old tree.
 *
 * Revision 1.11  2000/03/14 23:29:01  yongbing
 * Add Pentim MMX codes for BlockCplxSymbolUpdateCplxScale function
 *
 * Revision 1.10  2000/02/16 01:53:00  yongbing
 * Add Pentium MMX module for FEQ
 *
 * Revision 1.9  1999/11/02 02:49:55  liang
 * Add BlockComplexPower function.
 *
 * Revision 1.8  1999/08/05 19:42:34  liang
 * Merged with the softmodem top of the tree on 08/04/99 for assembly files.
 *
 * Revision 1.7  1999/06/16 00:54:39  liang
 * BlockRealScaleComplexSymbols takes a scale shift buffer now.
 *
 * Revision 1.6  1999/05/22 02:18:29  liang
 * Add one more parameter to BlockCplxSymbolUpdateCplxScale function.
 *
 * Revision 1.5  1999/05/14 22:49:39  liang
 * Added two more functions.
 *
 * Revision 1.4  1999/03/26 03:29:57  liang
 * Add function BlockComplexMultLongAcc.
 *
 * Revision 1.3  1999/02/22 22:40:59  liang
 * BlockByteSum takes uchar inputs instead of schar.
 *
 * Revision 1.2  1999/02/10 01:56:44  liang
 * Added BlockByteSum, BlockRealScaleComplexSymbols and BlockCplxScaleComplexSymbols.
 *
 * Revision 1.1  1998/10/28 01:35:38  liang
 * *** empty log message ***
 *
 * Revision 1.12  1998/07/08 17:09:25  scott
 * Removed unnecessary undefs
 *
 * Revision 1.11  1998/04/02 06:19:44  mwg
 * Added two new utilities.
 *
 * Revision 1.10  1998/03/26 23:20:55  liang
 * Added function BlockShortMultiply.
 *
 * Revision 1.9  1998/02/16  18:41:00  scott
 * Added MMX autodetect support
 *
 * Revision 1.8  1997/12/13 06:11:35  mwg
 * Added new functions:
 * BlockLongSubtract()
 * BlockLongAdd()
 * BlockLong2ShortSubtract()
 * BlockShort2LongMove()
 * BlockShortInterpolate()
 * BlockLongCorrelate()
 * BlockMapShort2Short()
 *
 * Revision 1.7  1997/03/19 18:35:10  mwg
 * Changed copyright notice.
 *
 * Revision 1.6  1997/02/11  00:08:18  mwg
 * Added BlockByteMove function
 *
 * Revision 1.5  1997/02/04  08:40:08  mwg
 * Changed interface forBlockReal2ComplexMacc()
 *
 * Revision 1.4  1997/01/23  02:04:28  mwg
 * Added return value to BlockShortMove
 *
 * Revision 1.3  1996/12/19  22:34:55  mwg
 * Added new function BlockFullPower().
 *
 * Revision 1.2  1996/02/21  03:59:15  mwg
 * Added new function BlockReal2ComplexMacc
 *
 * Revision 1.1.1.1  1996/02/14  02:35:13  mwg
 * Redesigned the project directory structure. Merged V.34 into the project.
 *
 * Revision 1.5  1995/04/04  06:09:32  mwg
 * Changed the SoftModem status reporting: now the status is a structure/union
 * where different fields used for different status code. This will enable
 * efficient status snooping for high level protocols on top of the softmodem.
 *
 */

#ifndef	BlockUtilPh
#define	BlockUtilPh

extern	void	BlockLongAdd				(int, long*, long*, long*);
extern	void	BlockLong2ShortSubtract		(int, long*, long*, short*);
extern	void	BlockShort2LongMove			(int, short*, long*);
extern	void	BlockShortMultiply			(int, int, short*, short*, short*);
extern	void	BlockByteMoveUnaligned		(int size, uchar *srcPtr, uchar *dstPtr);
extern	void	BlockShortOffset			(int, short, short*, short*);
extern	long	BlockShortInterpolateWithIncrement (int size, long scaleFactor, long increment, int shift, short* src1Ptr, short* src2Ptr, short* dstPtr);
extern	void	BlockReal2ComplexMult		(int, short*, ComplexShort*, ComplexShort*);
extern	void	BlockComplexConjigateMult	(int, ComplexShort*, ComplexShort*, ComplexShort*);

extern	long	BlockSum					(int, short*);
extern	long	BlockByteSum				(int, uchar*);
extern	void	BlockComplexSum				(int, ComplexShort*, ComplexLong*);
extern	void	BlockComplexPower			(int, int, ComplexShort*, long*);
extern	long	BlockFullPower				(int, short*);
extern	long	BlockLongCorrelate			(int, long*, long*);

extern	int		BlockSymbol2Byte			(int, int, ushort*, uchar*);
extern	int		BlockByte2Symbol			(int, int, uchar*, ushort*);

extern	void	BlockMapShort2Complex		(int, ushort*, ComplexByte*, ComplexShort*);
extern	void	BlockMapShort2Short			(int size, ushort *srcPtr, short *mapPtr, short *dstPtr);
extern	void	BlockMapByte2Byte			(int size, uchar *srcPtr, uchar *mapPtr, uchar *dstPtr);
extern	void	BlockMapByte2Short			(int size, uchar *srcPtr, short *mapPtr, short *dstPtr);
extern	void	BlockShortMult				(int size, int shift, short* src1Ptr, short* src2Ptr, short* dstPtr);

extern	int		SM_DECL Idle(void);

extern	void	BlockGenerateAngles(int size, ComplexShort *anglePtr, ComplexShort *incPtr, ComplexShort *dstPtr);
extern	void	BlockExtractRealPart(int size, ComplexShort *srcPtr, short *dstPtr);
extern	void	BlockShortScaleByShift (int size, int shift, short* srcPtr, short* dstPtr);

#ifndef PENTIUM_REDEFS /* only if these have not been redefined to function pointers */
extern	long	BlockPower					(int, short*);
extern	void	BlockReal2ComplexMacc		(int, int, short*, ComplexShort*, ComplexLong*);
extern	void	BlockComplexMult			(int, ComplexShort*, ComplexShort*, ComplexShort*);
extern	void	BlockShortScale				(int, short, int, short*, short*);
extern	int		SM_DECL BlockShortMove				(int, short*, short*);
extern	long	BlockCorrelate				(int, short*, short*);

extern	void	BlockRealScaleComplexSymbols(int, int, uchar*, short*, ComplexShort*, ComplexShort*);
/* FIXME -- the following 3 functions can be removed */
extern	void	BlockCplxScaleComplexSymbols(int, int, int, ComplexShort*, ComplexShort*, ComplexShort*);
extern	void	BlockCplxSymbolUpdateCplxScale(int, int, int, uchar*, ComplexShort*,
					ComplexShort*, ComplexShort*, ComplexShort*);
extern	void	BlockComplexShortFill		(int, short, short, ComplexShort*);


extern	void	BlockRealScaleCplxSymbols(int, int, int, short*, ComplexShort*, ComplexShort*);
extern	void	BlockCplxLongConjigateMultCplxShort(int, ComplexLong*, ComplexShort*, ComplexLong*);

extern	void	BlockCplxLongScaleCplxSymbols(int, int, int, ComplexLong*, ComplexShort*, short*, ComplexShort*);
extern	void	BlockCplxSymbolUpdateCplxLongScale(int, int, int, int,
					ComplexShort*, short *, ComplexLong*, ComplexShort*);

extern	void	BlockComplexLongFill		(int, long, long, ComplexLong*);

extern	void	BlockShortSubtract			(int, short*, short*, short*);
extern	void	BlockLongSubtract			(int, long*, long*, long*);
extern	void	BlockShortAdd				(int, short*, short*, short*);
extern	void	BlockByteMove				(int, uchar*, uchar*);
extern	void	BlockByteMoveByLong			(int, uchar*, uchar*);
extern	void	SM_DECL BlockByteFill		(int, uchar, uchar*);
extern	void	BlockByteFillByLong 		(int, uchar, uchar*);
extern	void	BlockByteClear				(int, uchar*);
extern	void	BlockByteClearByLong		(int, uchar*);
extern	void	BlockShortFill				(int, short, short*);
extern	void	BlockShortClear				(int, short*);
extern	void	BlockShortClearByLong		(int, short*);
extern	void	BlockLongFill				(int, long, long*);
extern	void	BlockLongClear				(int, long*);
extern	void	BlockComplexShortClear		(int, ComplexShort*);
extern	void	BlockShortInvert			(int, short*, short*);
extern	void	BlockShortScaleDown			(int, short*);
extern	void	BlockLongMove				(int, long*, long*);
extern	void	BlockShortInterpolate		(int, short, int, short*, short*, short*);
extern	void	BlockComplexMultLongAcc     (int, int, ComplexShort*, ComplexShort*, ComplexLong*);

#endif

#endif	/* BlockUtilPh */
