/*
 * buttons.h
 *
 *  Created on: 3 дек. 2021 г.
 *      Author: i
 */

#include "gpio.h"

#define BUTTONS 6

typedef enum {
	NONE,
	PRESS,
	SHORT_CLC,
	DOUBLE_CLC,
	LONG_CLC,
	SWITCH
}Button_events_TypeDef;

#define DIVIDER 10

#define NOISE_TIME 20 / DIVIDER
#define SHORT_TIME 300 / DIVIDER
#define LONG_TIME 800 / DIVIDER



void Button_IncTick(void);
void Buttons_Init (void);
void Event_Button (uint8_t Butt, Button_events_TypeDef Event);
void Buttons_Handler (uint8_t Butt, Button_events_TypeDef Event);
