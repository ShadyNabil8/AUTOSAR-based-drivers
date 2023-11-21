/**
 * @file Spi.h
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

#include "Std_Types.h"
#include "Spi_ATmega.h"
#include "Dio.h"
#include "atmega.h"

/**
 * @brief: The SPI Handler/Driver is not initialized or not usable.
 */
#define SPI_UNINIT 0x00

/**
 * @brief: The SPI Handler/Driver is not currently transmitting any Job.
 */
#define SPI_IDLE 0x01

/**
 * @brief: The last transmission of the Job has been finished successfully.
 */
#define SPI_JOB_OK 0x00

/**
 * @brief: The SPI Handler/Driver is performing a SPI Job. The meaning of this status is equal to SPI_BUSY.
 */
#define SPI_JOB_PENDING 0x01

/**
 * @brief: The last transmission of the Job has failed.
 */
#define SPI_JOB_FAILED 0x02

/**
 * @brief: An asynchronous transmit Job has been accepted, while actual transmission for this Job has not started yet.
 */
#define SPI_JOB_QUEUED 0x03

/**
 * @brief: The asynchronous mechanism is ensured by polling, so interrupts related to SPI busses handled asynchronously are disabled
 */
#define SPI_POLLING_MODE 0x00

/**
 * @brief: The asynchronous mechanism is ensured by interrupt, so interrupts related to SPI busses handled asynchronously are enabled.

*/
#define SPI_INTERRUPT_MODE 0x01

typedef uint8 Spi_RuleType; /* Master or slave */
typedef uint8 Spi_DataOrderType;
typedef uint8 Spi_ClockPolarityType;
typedef uint8 Spi_ClockPhaseType;
typedef uint8 Spi_PrescallerType;
typedef uint8 Spi_ModeType;

/**
 * @breif: This type defines a range of specific status for SPI Handler/Driver.
 */
typedef uint8 Spi_StatusType;

/**
 * @breif: This type defines a range of specific Jobs status for SPI Handler/Driver.
 */
typedef uint8 Spi_JobResultType;

/**
 * @breif: Type of application data buffer elements.
 */
typedef uint8 Spi_DataBufferType;

/**
 * @breif: Specifies the asynchronous mechanism mode for SPI busses handled asynchronously.
 */
typedef uint8 Spi_AsyncModeType;

/**
 * @breif: Specifies the identification (ID) for a sequence of jobs..
 */
typedef uint8 Spi_SequenceType;

/**
 * @breif: Specifies the identification (ID) for a Channel.
 */
typedef uint8 Spi_ChannelType;

/**
 * @breif: Specifies the asynchronous mechanism mode for SPI busses handled asynchronously.

 */
typedef struct
{
    Spi_RuleType SpiRule; /* Master or slave */
    Spi_DataOrderType DataOrder;
    Spi_ModeType SpiMode;
    Spi_PrescallerType Prescaller;
    Spi_AsyncModeType AsyncMode;
} Spi_ConfigType;

/**
 * @brief: Service for SPI initialization
 * @note: function is Non Reentrant
 */
void Spi_Init(const Spi_ConfigType *ConfigPtr);

/**
 * @brief: Service for SPI de-initialization.
 * @note: function is Non Reentrant
 */
Std_ReturnType Spi_DeInit(void);

/**
 * @brief: Service for writing one or more data to an IB SPI Handler/Driver Channel specified by parameter.
 * @note: Pointer to source data buffer. If this pointer is null,
          it is assumed that the data to be transmitted is not relevant
          and the default transmit value of this channel will be used instead.
 */
// Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr);

/**
 * @brief: Service for SPI de-initialization.
 * @note: function is Non Reentrant
 */

/**
 * @brief: Service to transmit data on the SPI bus
 */
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);

/**
 * @brief: Service to transmit data on the SPI bus
 */
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);

/**
 * @brief: Service to set the asynchronous mechanism mode for SPI busses handled asynchronously.
 */
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);

/**
 * @brief: Service for reading synchronously one or more data from an IB SPI Handler/Driver Channel specified by parameter.
 */
Std_ReturnType Spi_ReadIB (Spi_ChannelType Channel,Spi_DataBufferType* DataBufferPointer);

