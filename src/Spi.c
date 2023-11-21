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

#include "Spi.h"

static void Spi_SetMode(Spi_ModeType SpiMode)
{
    switch (SpiMode)
    {
    case SPI_MODE0:
        SPI_SET_MODE0();
        break;
    case SPI_MODE1:
        SPI_SET_MODE1();
        break;
    case SPI_MODE2:
        SPI_SET_MODE2();
        break;
    case SPI_MODE3:
        SPI_SET_MODE3();
        break;
    default:
        break;
    }
}

void Spi_Init(const Spi_ConfigType *ConfigPtr)
{
    if (ConfigPtr->SpiRule == SPI_MASTER)
    {
        SPI_SET_MASTER();
        Dio_SetChannelDirection(SPI_MOSI, DIO_OUTPUT);
        Dio_SetChannelDirection(SPI_SCK, DIO_OUTPUT);
    }
    else
    {
        SPI_SET_SLAVE();
        Dio_SetChannelDirection(SPI_MISO, DIO_OUTPUT);
        Dio_SetChannelDirection(SPI_MOSI, DIO_INPUT);
        Dio_SetChannelDirection(SPI_SCK, DIO_INPUT);
        Dio_SetChannelDirection(SPI_SS, DIO_INPUT);
    }

    if (ConfigPtr->DataOrder == SPI_LSB_FIRST)
        SPI_SET_LSB_FIRST();
    else
        SPI_SET_MSB_FIRST();

    Spi_SetMode(ConfigPtr->SpiMode);

    SPI_ENABLE();

    Spi_SetAsyncMode(ConfigPtr->AsyncMode);
}

Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPointer)
{
    /* Wait for reception complete */
    while (!(SPI->SPSR_REG & (1 << SPIF_BIT)))
        ;

    *DataBufferPointer = SPI->SPDR_REG;
    return E_OK;
}

Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    if (Mode == SPI_ASYNC_MODE)
    {
        SPI_ENABLE_INTERRUPT();
    }
    return E_OK;
}