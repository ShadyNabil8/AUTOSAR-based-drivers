/**
 * @file Platform_Types.h
 * @version 1.0.0
 * @brief Platform dependent data types definitions - Based on AUTOSAR
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

#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_

/*=========================================================================
                            FILE VERSION INFORMATION
==========================================================================*/
#define PLATFORM_MODULE_ID_CFG 120

#define PLATFORM_AR_RELEASE_MAJOR_VERSION 4
#define PLATFORM_AR_RELEASE_MINOR_VERSION 4
#define PLATFORM_AR_RELEASE_REVISION_VERSION 0

#define PLATFORM_SW_MAJOR_VERSION 1
#define PLATFORM_SW_MINOR_VERSION 0
#define PLATFORM_SW_REVISION_VERSION 0

/*=========================================================================
                                MACROS
==========================================================================*/
#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

#define MSB_FIRST 0
#define LSB_FIRST 1

#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST 1

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define CPU_TYPE (CPU_TYPE_8)
#define CPU_BIT_ORDER (LSB_FIRST)
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST)

/*=========================================================================
                                TYPEDEFINES
==========================================================================*/
#if (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;

typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;

typedef signed long sint8_least;
typedef signed long sint16_least;
typedef signed long sint32_least;

typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_8)
//typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;

typedef float float32;
typedef double float64;
#endif

#endif /* PLATFORM_TYPES_H_*/