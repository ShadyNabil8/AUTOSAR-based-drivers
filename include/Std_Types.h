/**
 * @file Std_Types.h
 * @version 1.0.0
 * @brief Standered types definitions - Based on AUTOSAR
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
#ifndef _STD_TYPES_
#define _STD_TYPES_

#include "Platform_Types.h"
#include "Compiler.h"

/*=========================================================================
                            FILE VERSION INFORMATION
==========================================================================*/
#define STD_VENDOR_ID 850

#define STD_AR_RELEASE_MAJOR_VERSION 4
#define STD_AR_RELEASE_MINOR_VERSION 4
#define STD_AR_RELEASE_REVISION_VERSION 0

#define STD_SW_MAJOR_VERSION 1
#define STD_SW_MINOR_VERSION 0
#define STD_SW_REVISION_VERSION 0

/*=========================================================================
                            FILE VERSION CHECK
==========================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((STD_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
     (STD_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
#error "Std_Types.h and Platform_Types.h have different AUTOSAR versions"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((STD_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
     (STD_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
#error "Std_Types.h and Platform_Types.h have different AUTOSAR versions"
#endif
#endif

/*=========================================================================
                                MACROS
==========================================================================*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u

#define STD_LOW 0x00u
#define STD_HIGH 0x01u

#define STD_IDLE 0x00u
#define STD_ACTIVE 0x01u

#define STD_OFF 0x00u
#define STD_ON 0x01u

/*=========================================================================
                                TYPEDEFINES
==========================================================================*/
typedef uint8 Std_ReturnType;
typedef struct
{
     uint16 vendorID;
     uint16 moduleID;
     uint8 sw_major_version;
     uint8 sw_minor_version;
     uint8 sw_patch_version;
} Std_VersionInfoTyp;

#endif
