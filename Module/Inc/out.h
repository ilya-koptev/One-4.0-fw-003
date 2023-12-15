
#include "gpio.h"

typedef enum {
	P_OUT_1,
	P_OUT_2,
	P_OUT_3,
	P_OUT_4,
	P_OUT_5,
	P_OUT_6,
	P_OUT_7,
	W_OUT_1,
	W_OUT_2,
	W_OUT_3,
	W_OUT_4,
	W_OUT_5,
	W_OUT_6,
	W_OUT_7,
	P_OUT_1234,
	P_OUT_567

} PowerChannelTypeDef;



void Set_Out(PowerChannelTypeDef Channel, uint16_t volume);
void Set_PWM_Freq(PowerChannelTypeDef Channel, uint16_t volume);
void Out_Init(void);
