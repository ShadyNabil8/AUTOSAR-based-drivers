/**
 * @file Compiler_Cfg.h
 * @version 1.0.0
 * @brief This file contains the specific parameters that are passed
 *        to the macros defined at cCompiler.h
 * @author Shady Nabil
 */

/**
 * Project          : AUTOSAR 4.4.0 MCAL
 * Platform         : AVR
 * peripheral       : ATmega16a
 * AUTOSAR version  : 4.4.0
 * AUTOSAR revision : ASR_REL_4_0_REV_000
 * SW version       : 1.0.0
 */

#ifndef _COMPILER_CFG_H_
#define _COMPILER_CFG_H_

/*=========================================================================
                            FILE VERSION INFORMATION
==========================================================================*/
#define COMPILER_VENDOR_ID_CFG 850

#define COMPILER_AR_RELEASE_MAJOR_VERSION 4
#define COMPILER_AR_RELEASE_MINOR_VERSION 4
#define COMPILER_AR_RELEASE_REVISION_VERSION 0

#define COMPILER_SW_MAJOR_VERSION 1
#define COMPILER_SW_MINOR_VERSION 0
#define COMPILER_SW_REVISION_VERSION 0

#define DIO_CODE
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOTINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR

#define PORT_CODE
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_CALLOUT_CODE
#define PORT_VAR_NOTINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR

#endif /* _COMPILER_CFG_H_ */