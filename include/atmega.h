/**
 * @file atmega.h
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

#ifndef _ATMEGA_H_
#define _ATMEGA_H_

#include "Std_Types.h"

typedef struct
{
    uint8 PIN;
    uint8 DDR;
    uint8 PORT;
} GPIO_TypeDef;

typedef struct
{
    uint8 SPCR_REG;
    uint8 SPSR_REG;
    uint8 SPDR_REG;
} SPI_TypeDef;

#define _REG_IO8(io_addr) _MEMIO_BYTE(io_addr)
#define _MEMIO_BYTE(mem_addr) ((volatile uint8 *)(mem_addr))

#define GPIOA_BASE (_REG_IO8(0x39))
#define GPIOB_BASE (_REG_IO8(0x36))
#define GPIOC_BASE (_REG_IO8(0x33))
#define GPIOD_BASE (_REG_IO8(0x30))
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)

#define SPI_BASE (_REG_IO8(0x2D))
#define SPI ((SPI_TypeDef *)SPI_BASE)

#define DIO_GET_PORT(CHANNELID) ((CHANNELID >> 4) & 0X0F)
#define DIO_GET_PIN(CHANNELID) ((CHANNELID) & 0X0F)

/**
 * @brief most significant 4-bits defines the port number
 *          The least significant 4-bits defines the pin number
 */
#define DIO_PINA0 0X00
#define DIO_PINA1 0X01
#define DIO_PINA2 0X02
#define DIO_PINA3 0X03
#define DIO_PINA4 0X04
#define DIO_PINA5 0X05
#define DIO_PINA6 0X06
#define DIO_PINA7 0X07

#define DIO_PINB0 0X10
#define DIO_PINB1 0X11
#define DIO_PINB2 0X12
#define DIO_PINB3 0X13
#define DIO_PINB4 0X14
#define DIO_PINB5 0X15
#define DIO_PINB6 0X16
#define DIO_PINB7 0X17

#define DIO_PINC0 0X20
#define DIO_PINC1 0X21
#define DIO_PINC2 0X22
#define DIO_PINC3 0X23
#define DIO_PINC4 0X24
#define DIO_PINC5 0X25
#define DIO_PINC6 0X26
#define DIO_PINC7 0X27

#define DIO_PIND0 0X30
#define DIO_PIND1 0X31
#define DIO_PIND2 0X32
#define DIO_PIND3 0X33
#define DIO_PIND4 0X34
#define DIO_PIND5 0X35
#define DIO_PIND6 0X36
#define DIO_PIND7 0X37

#define DIO_OUTPUT 0X01
#define DIO_INPUT 0X00

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define SPR0_BIT 0
#define SPR1_BIT 1
#define CPHA_BIT 2
#define CPOL_BIT 3
#define MSTR_BIT 4
#define DORD_BIT 5
#define SPE_BIT 6
#define SPIE_BIT 7

#define SPI2X_BIT 0
#define WCOL_BIT 6
#define SPIF_BIT 7

#define SPI_SCK DIO_PINB7
#define SPI_MISO DIO_PINB6
#define SPI_MOSI DIO_PINB5
#define SPI_SS DIO_PINB4

#endif /*_ATMEGA_H_*/