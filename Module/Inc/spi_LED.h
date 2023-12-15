
#include "spi.h"


#define VerH 0
#define VerL 3

#define LED_MAX 1000


#define SPI_FREQ 20

#define G 0xfe
#define R 0xfe
#define B 0xfe

#define g 0x00
#define r 0x00
#define b 0x00

#define MIX_B_C(b,c) ((b) << 3) | ((uint8_t)(c) & 0x07)

 typedef enum
{ BLACK,
  RED,
  YELLOW,
  GREEN,
  EMERALD,
  BLUE,
  PURPLE,
  WHITE,

  BLINK = 0x10,
  FAST = 0x20

} LED_ColorTypeDef;

typedef enum
{
  CHANNEL0,
  CHANNEL1
} Spi_LED_ChannellTypeDef;






void Spi_LED_Init(void);
void Spi_LED_IncTick(void);
void Spi_LED_Handler_Frame(Spi_LED_ChannellTypeDef channel);
void Spi_LED_Set_Fix_Color(uint16_t index, uint8_t bright, LED_ColorTypeDef color);
void Spi_LED_Set_Custom_Color(Spi_LED_ChannellTypeDef channel, uint16_t index, uint8_t color);
void Spi_LED_Set_Color(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);





