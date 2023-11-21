/**
 * @file Compiler.h
 * @version 1.0.0
 * @brief Compiler abstraction - Based on AUTOSAR
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

#ifndef _COMPILER_H_
#define _COMPILER_H_

#include <Compiler_Cfg.h>

/*=========================================================================
                            FILE VERSION INFORMATION
==========================================================================*/
#define COMPILER_VENDOR_ID 850

#define COMPILER_AR_RELEASE_MAJOR_VERSION 4
#define COMPILER_AR_RELEASE_MINOR_VERSION 4
#define COMPILER_AR_RELEASE_REVISION_VERSION 0

#define COMPILER_SW_MAJOR_VERSION 1
#define COMPILER_SW_MINOR_VERSION 0
#define COMPILER_SW_REVISION_VERSION 0

/*=========================================================================
                                MACROS
==========================================================================*/
/**
 * @brief memory class AUTOMATIC shall be provided as empty definition, used for
    the declaration of local pointers.
*/
#define AUTOMATIC

/**
 * @brief The memory class TYPEDEF shall be provided as empty definition. This memory
    class shall be used within type definitions, where no memory qualifier can be
    specified. This can be necessary for defining pointer types, with e.g. P2VAR,
    where the macros require two parameters. First parameter can be specified in the
    type definition (distance to the memory location referenced by the pointer), but
    the second one (memory allocation of the pointer itself) cannot be defined at this
    time. Hence, memory class TYPEDEF shall be applied.
*/
#define TYPEDEF

/**
 * @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer
    to zero definition.
*/
#define NULL_PTR ((void *)0)

/**
 * @brief The compiler abstraction shall provide the INLINE define for abstraction of the
    keyword inline.
 * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction
    of the keyword inline in functions with “static” scope.
 * @brief Different compilers may require a different sequence of the keywords “static” and
    “inline” if this is supported at all.
*/
#ifdef _GNU_ARM_C_STM32F103_
#define INLINE inline
#define LOCAL_INLINE static inline
#define STATIC static
#endif /*_GNU_ARM_C_STM32F103_*/

/**
 * @brief The compiler abstraction shall define the FUNC macro for the declaration and 
    definition of functions that ensures correct syntax of function declarations as 
    required by a specific compiler.
*/
#define FUNC(rettype, memclass) memclass rettype




#endif /* _COOMPILER_H_ */
