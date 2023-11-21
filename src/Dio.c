/**
 * @file Dio.c
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

#include "Dio.h"

static GPIO_TypeDef *gpio[] = {GPIOA, GPIOB, GPIOC, GPIOD};

void Dio_SetChannelDirection(Dio_ChannelType ChannelId, Dio_DirectionType direction)
{
    Dio_ChannelType Pin_Number = DIO_GET_PIN(ChannelId);
    Dio_PortType Port_Number = DIO_GET_PORT(ChannelId);
    if (direction == DIO_OUTPUT)
        DIO_SET_BIT(gpio[Port_Number]->DDR, Pin_Number);
    else if (direction == DIO_INPUT)
        DIO_CLEAR_BIT(gpio[Port_Number]->DDR, Pin_Number);
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_ChannelType Pin_Number = DIO_GET_PIN(ChannelId);
    Dio_PortType Port_Number = DIO_GET_PORT(ChannelId);
    if (Level == STD_HIGH)
        DIO_SET_BIT(gpio[Port_Number]->PORT, Pin_Number);
    else if (Level == STD_LOW)
        DIO_CLEAR_BIT(gpio[Port_Number]->PORT, Pin_Number);
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_ChannelType Pin_Number = DIO_GET_PIN(ChannelId);
    Dio_PortType Port_Number = DIO_GET_PORT(ChannelId);
    DIO_TOGGLE_BIT(gpio[Port_Number]->PORT, Pin_Number);

    return STD_HIGH; /*wil be handeled*/
}
