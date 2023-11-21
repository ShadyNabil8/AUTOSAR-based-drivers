// #include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "atmega.h"
#include "Dio.h"
#include <avr/interrupt.h>

Spi_DataBufferType Spi_Buffer;
volatile uint8 received;
volatile uint8 receivedData;

ISR(SPI_STC_vect) // Inerrrput routine function
{
  receivedData = SPI->SPDR_REG; // Get the received data from SPDR register
  received = 1;                 // Sets received as True
}
Spi_ConfigType spi = {.AsyncMode = SPI_SYNC_MODE,
                      .DataOrder = SPI_MSB_FIRST,
                      .Prescaller = SPI_PRESCALLER_4,
                      .SpiMode = SPI_MODE0,
                      .SpiRule = SPI_SLAVE};
int main()
{
  DIO_SET_BIT(SREG, 7);

  Spi_Init(&spi);

  // MCUCSR |= 1 << JTD;
  // MCUCSR |= 1 << JTD;
  Dio_SetChannelDirection(DIO_PINA0, DIO_OUTPUT);
  Dio_WriteChannel(DIO_PINA0, STD_HIGH);
  while (1)
  {

    Spi_ReadIB(0, &Spi_Buffer);
    if (Spi_Buffer == 'N')
      Dio_WriteChannel(DIO_PINA0, STD_HIGH);
    else /* if (Spi_Buffer == 'F')*/
      Dio_FlipChannel(DIO_PINA0);
    if (received)
    {
      SPDR = receivedData; // send back the received data, this is not necessary, only for demo purpose
      received = 0;
      if ((char)receivedData == 'N')
      {
        Dio_WriteChannel(DIO_PINA0, STD_HIGH);
      }
      else
      {
        Dio_WriteChannel(DIO_PINA0, STD_LOW);
        // Dio_FlipChannel(DIO_PINA0);
      }
    }
    // Dio_FlipChannel(DIO_PINA0);
    // _delay_ms(500);
  }

  return 0;
}
// #include <Arduino.h>
// #include <SPI.h>
// // put function declarations here:
// // String readString;
// char operation;
// volatile boolean received;
// volatile uint8_t receivedData;
// ISR(SPI_STC_vect) // Inerrrput routine function
// {
//   receivedData = SPDR; // Get the received data from SPDR register
//   received = true;     // Sets received as True
// }

// // ====================================================================
// // Arduino code example for SPI Slave Mode
// // Read unsigned short (two bytes) from SPI, send word to serial port
// // On 16 MHz Arduino, can work at > 500 words per second
// // J.Beale July 19 2011
// // ====================================================================

// void SlaveInit(void)
// {
//   // Set MISO output, all others input
//   pinMode(SCK, INPUT);
//   pinMode(MOSI, INPUT);
//   pinMode(MISO, OUTPUT); // (only if bidirectional mode needed)
//   pinMode(SS, INPUT);
//   SPCR = (1 << SPE) | (0 << DORD) | (0 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
//   /*  Setup SPI control register SPCR
//   SPIE - Enables the SPI interrupt when 1
//   SPE - Enables the SPI when 1
//   DORD - Sends data least Significant Bit First when 1, most Significant Bit first when 0
//   MSTR - Sets the Arduino in master mode when 1, slave mode when 0
//   CPOL - Sets the data clock to be idle when high if set to 1, idle when low if set to 0
//   CPHA - Samples data on the trailing edge of the data clock when 1, leading edge when 0
//   SPR1 and SPR0 - Sets the SPI speed, 00 is fastest (4MHz) 11 is slowest (250KHz)   */

//   // enable SPI subsystem and set correct SPI mode
//   // SPCR = (1<<SPE)|(0<<DORD)|(0<<MSTR)|(0<<CPOL)|(0<<CPHA)|(0<<SPR1)|(1<<SPR0);
// }

// // SPI status register: SPSR
// // SPI data register: SPDR
// void setup()
// {
//   // pinMode(PINA0, OUTPUT);
//   DDRA |= (1 << 0);
//   // digitalWrite(PINA0, HIGH);
//   PORTA |= (1 << 0);
//   // Serial.begin(115200);
//   SlaveInit(); // set up SPI slave mode
//   received = false;
//   // SPI.attachInterrupt(); // Activate SPI Interuupt
//   delay(10);
//   // Serial.println("SPI port reader v0.1");
// }
// void loop()
// {
//   if (received)
//   {
//     SPDR = receivedData; // send back the received data, this is not necessary, only for demo purpose
//     received = false;
//     // Serial.println("Data Received");
//     if ((char)receivedData == 'N')
//     {
//       PORTA |= (1 << 0);
//       //digitalWrite(PINA0, HIGH);
//       // Serial.println("Led ON");
//     }
//     else
//     {
//       PORTA &= ~(1 << 0);
//       //digitalWrite(PINA0, LOW);
//       // Serial.println("Led Off");
//     }
//   }
// }
