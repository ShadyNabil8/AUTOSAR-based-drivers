/**
 * @file Dio.h
 * @version 1.0.0
 * @brief
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

#ifndef _DIO_H_
#define _DIO_H_

#include "Std_Types.h"
#include "Dio_Cfg.h"
#include "atmega.h"
#include "macros.h"

#define DIO_VENDOR_ID 850
#define DIO_MODULE_ID 120

#define DIO_AR_RELEASE_MAJOR_VERSION 4
#define DIO_AR_RELEASE_MINOR_VERSION 4
#define DIO_AR_RELEASE_REVISION_VERSION 0

#define DIO_SW_MAJOR_VERSION 1
#define DIO_SW_MINOR_VERSION 0
#define DIO_SW_REVISION_VERSION 0

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (DIO_MODULE_ID != DIO_MODULE_ID_CFG)
#error "Dio.h and Dio_Cfg.h have different module ID"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (DIO_VENDOR_ID != DIO_VENDOR_ID_CFG)
#error "Dio.h and Dio_Cfg.h have different vendor ID"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((DIO_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DIO_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
#error "Dio.h and Std_Types.h have different AUTOSAR versions"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG))
#error "Dio.h and Dio_Cfg.h have different AUTOSAR versions"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((DIO_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION_CFG) || \
     (DIO_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION_CFG) || \
     (DIO_SW_REVISION_VERSION != DIO_SW_REVISION_VERSION_CFG))
#error "Dio.h and Dio_Cfg.h have different software versions"
#endif
#endif

/**
 * @brief Invalid channel requested
 */
#define DIO_E_PARAM_INVALID_CHANNEL_ID ((uint8)0x0A)

/**
 * @brief Invalid port requested
 */
#define DIO_E_PARAM_INVALID_PORT_ID ((uint8)0x14)

/**
 * @brief Invalid channel group requested
 */
#define DIO_E_PARAM_INVALID_GROUP ((uint8)0x1F)

/**
 * @brief API service called with a NULL pointer
 */
#define DIO_E_PARAM_POINTER ((uint8)0x20)


/**
 * @brief Numeric ID of a DIO channel.
 */
typedef uint8 Dio_ChannelType;

/**
 * @brief Numeric ID of a DIO port.
 */
typedef uint8 Dio_PortType;

/**
 * @brief Direction in a pin.
 */
typedef uint8 Dio_DirectionType;

/**
 * @brief Type for the definition of a channel group, which consists of several adjoining
          channels within a port.
*/
typedef struct
{
     /**
      * @brief: This element mask which defines the positions of the channel group.
      */
     uint8 mask;
     /**
      * @brief: This element shall be the position of the Channel Group on the port, counted
               from the LSB.
     */
     uint8 offset;
     /**
      * @brief: This shall be the port on which the Channel group is defined.
      */
     Dio_PortType port;
} Dio_ChannelGroupType;

/**
 * @brief These are the possible levels a DIO channel can have (input or output).
 * @details STD_LOW(Physical state 0V) or STD_HIGH(Physical state 5V or 3.3V)
 */
typedef uint8 Dio_LevelType;

/**
 * @brief If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType
          inherits the size of the largest port.
 */
typedef uint8 Dio_PortLevelType;

/**
 * @brief Returns the value of the specified DIO channel.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 * @brief Service to set a level of a channel.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
 * @brief Returns the level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 * @brief Service to set a value of the port.
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/**
 * @brief This Service reads a subset of the adjoining bits of a port.
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);

/**
 * @brief Service to set a subset of the adjoining bits of a port to a specified level.
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);

/**
 * @brief Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return
          the level of the channel after flip.
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/**
 * @brief Service to set the value of a given port with required mask.
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

/**
 * @brief Service to set the direction of a channel.
 */
void Dio_SetChannelDirection(Dio_ChannelType ChannelId, Dio_DirectionType direction);

#endif /* _DIO_H_ */