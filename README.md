
# AUTOSAR-based modules
It is a good idea to try to delve deeper into the writing of AUTOSAR-based modules and try to understand the drivers of AUTOSAR systems. So in this project, I started writing two AUTOSAR drivers, ```SPI``` and ```Dio```.

## Dio module implemented functions

```c
void Dio_WriteChannel(
   Dio_ChannelType ChannelId,
   Dio_LevelType Level
)
```
```c
Dio_LevelType Dio_FlipChannel(
   Dio_ChannelType ChannelId
   )
```
## SPI module implemented functions
```c
void Spi_Init (
   const Spi_ConfigType* ConfigPtr
   )
```
```c
Std_ReturnType Spi_ReadIB(
   Spi_ChannelType Channel,
   Spi_DataBufferType *DataBufferPointer
   )
```

```c
Std_ReturnType Spi_SetAsyncMode(
   Spi_AsyncModeType Mode
   )
```