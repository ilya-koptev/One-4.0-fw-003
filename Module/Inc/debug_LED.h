
#include "gpio.h"

typedef enum {
	DBG_OK,
	DBG_ERROR,
	DBG_BTN,
	DBG_NONE
}Dbg_msg_TypeDef;


void Debug_LED_Init (void);
void Debug_LED_IncTic(void);
void Debug_UART (uint8_t* msg, Dbg_msg_TypeDef dbg_msg, uint8_t len);
