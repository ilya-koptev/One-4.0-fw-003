

#include "out.h"
#include "tim.h"
#include "debug_LED.h"

void Set_Out(PowerChannelTypeDef Channel, uint16_t volume){
	if (Channel == P_OUT_1){TIM4->CCR1 = volume;}
	if (Channel == P_OUT_2){TIM4->CCR2 = volume;}
	if (Channel == P_OUT_3){TIM4->CCR3 = volume;}
	if (Channel == P_OUT_4){TIM4->CCR4 = volume;}
	if (Channel == P_OUT_5){TIM3->CCR3 = volume;}
	if (Channel == P_OUT_6){TIM3->CCR4 = volume;}
	if (Channel == P_OUT_7){TIM3->CCR1 = volume;}

}

void Set_PWM_Freq(PowerChannelTypeDef Channel, uint16_t frequency){

	uint16_t volume = 48000U / frequency;

	if (Channel == P_OUT_1234){TIM4->PSC = volume;}
	if (Channel == P_OUT_567){TIM3->PSC = volume;}


}
void Out_Init(void){
//	HAL_TIM_Base_Start(&htim4);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

//	Debug_UART((uint8_t *) "Out init\r\n", DBG_OK, 10);

}
