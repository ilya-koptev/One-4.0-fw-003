#include "spi_LED.h"
#include "usart.h"
#include "debug_LED.h"

LED_ColorTypeDef Debug_LED1;
LED_ColorTypeDef Debug_LED2;

void Debug_LED_IncTic(void){

	static uint8_t switch_timer = 22;
	switch_timer--;
	if (switch_timer == 11) {
		switch (Debug_LED1) {
			case GREEN: 	{	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
								GPIOC->MODER |= GPIO_MODER_MODE4_0; 	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET); break;}
			case RED: 		{	GPIOC->MODER &= ~(GPIO_MODER_MODE4);
								GPIOC->MODER |= GPIO_MODER_MODE13_0;	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET); break;}
			case YELLOW: 	{	GPIOC->MODER |= GPIO_MODER_MODE4_0;		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
								GPIOC->MODER |= GPIO_MODER_MODE13_0;	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET); break;}
			case BLACK: 	{ 	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
								GPIOC->MODER &= ~(GPIO_MODER_MODE4); break;}
			default:		{break;}
		}
	}
	if (switch_timer == 0) {
		switch (Debug_LED2) {
			case GREEN: 	{	GPIOC->MODER &= ~(GPIO_MODER_MODE4);
								GPIOC->MODER |= GPIO_MODER_MODE13_0; 	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); break;}
			case RED: 		{	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
								GPIOC->MODER |= GPIO_MODER_MODE4_0;		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET); break;}
			case YELLOW: 	{	GPIOC->MODER |= GPIO_MODER_MODE13_0;	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
								GPIOC->MODER |= GPIO_MODER_MODE4_0;		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET); break;}
			case BLACK: 	{ 	GPIOC->MODER &= ~(GPIO_MODER_MODE13);
								GPIOC->MODER &= ~(GPIO_MODER_MODE4); break;}
			default:		{break;}
		}
		switch_timer = 22;
	}

}
void Debug_LED_toggle(uint8_t led){
	if (led == 1){
		static LED_ColorTypeDef old_Debug_LED1;
		if (Debug_LED1) {
			old_Debug_LED1 = Debug_LED1;
			Debug_LED1 = BLACK;
		}
		else {
			Debug_LED1 = old_Debug_LED1;
		}
	}
	if (led == 2){
		static LED_ColorTypeDef old_Debug_LED2;
		if (Debug_LED2) {
			old_Debug_LED2 = Debug_LED2;
			Debug_LED2 = BLACK;
		}
		else {
			Debug_LED2 = old_Debug_LED2;
		}
	}

}



void Debug_LED_Init (void){

	Debug_LED1 = BLACK;
	Debug_LED2 = BLACK;
//	Debug_UART( "Debug_LED init\r\n", DBG_OK, 16);

}

void Debug_UART (uint8_t *msg, Dbg_msg_TypeDef dbg_msg, uint8_t len){

	if (dbg_msg == DBG_ERROR ){	HAL_UART_Transmit(&huart2, "[\033[31mError\033[0m] ", 20, 2);}
	else if(dbg_msg == DBG_OK)  {HAL_UART_Transmit(&huart2, "[\033[32mOk\033[0m] ", 16, 2);}
	else if(dbg_msg == DBG_BTN)  {HAL_UART_Transmit(&huart2, "[\033[33mpress\033[0m] ", 20, 2);}
	else  {HAL_UART_Transmit(&huart2, "[--] ", 5, 2);}
	HAL_UART_Transmit(&huart2, msg, len, 5);
//	HAL_Delay(2);

}
