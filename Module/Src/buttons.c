/*
Опрос входов.Создание события Event.
Отсеивание помех меньше 10 мс.
Короткое нажатие -  до 300 мс
Двойное нажатие,
Длинное нажатие -  до 800 мс
Переключение.
*/

#include "buttons.h"
#include "debug_LED.h"

struct Button_Struct{
	GPIO_TypeDef* Port;
	uint16_t Pin;
	uint8_t PinState;
	uint16_t Timer;
	Button_events_TypeDef Event;
} ;

struct Button_Struct Button[BUTTONS];


void Button_IncTick(void){
	static uint8_t inc_div;
	if (inc_div) {inc_div--;}	//Входной делитель частоты опроса
	else{
		inc_div = DIVIDER;		//на 10
		for (uint8_t i = 0; i < BUTTONS; i++){									//Перебор всех кнопок
			uint8_t tmp = HAL_GPIO_ReadPin(Button[i].Port, Button[i].Pin);
			// =================Если на входе ничего не изменилось========================================================
			if (tmp == Button[i].PinState) {
				if (Button[i].Timer) {
					Button[i].Timer++;
					if(Button[i].Timer == SHORT_TIME){
						if ((Button[i].Event == SHORT_CLC)||(Button[i].Event == DOUBLE_CLC)){
							Event_Button(i, Button[i].Event);					// отправка по таймеру
						}
					}
					if(Button[i].Timer == LONG_TIME){							// Тут мы если вместо кнопки переключатель
						Button[i].Event = SWITCH;
						Event_Button(i, Button[i].Event);
					}
				}
			}
			// =======================Если событие==========================================================================
			else {																// если произошло изменение состояния.
				Button[i].PinState = tmp;
				if (Button[i].Timer > NOISE_TIME){								// если таймер больше 10 мс.
					if(Button[i].Timer < SHORT_TIME){							// если это меньше 300 мс
						Button[i].Timer = 1;
						if(Button[i].Event == PRESS){							// если в событиях было пусто
							Button[i].Event = SHORT_CLC;						// То фиксируем первое нажатие. Но не отправляем, а запускаем таймер снова
						}
						else if(Button[i].Event == SHORT_CLC){					// если нажатие уже было
							Button[i].Event = DOUBLE_CLC; 						// Фиксируем двойное нажатие
						}
						else if(Button[i].Event == DOUBLE_CLC){					//
							Event_Button(i, Button[i].Event); 					// Двойное отправляем сразу или по таймеру.
						}
					}
					else if(Button[i].Timer < LONG_TIME){						// Если мы были в нажатом положении больше 200 мс
						if(Button[i].Event == PRESS){							//
							Button[i].Event = LONG_CLC; 						// Фиксируем длинное нажатие
							Event_Button(i, Button[i].Event);
						}
					}
					else {
						Button[i].Timer = 0;
					}
				}
				else {															// обработка помех
					if (Button[i].Timer) {										// если таймер меньше 10 мс.
						Button[i].Timer = 0;
						Button[i].Event = NONE;
					}
					else{
						Button[i].Event = PRESS;
						Button[i].Timer = 1;									// Первре срабатывание.
					}
				}
			}
		}
	}
}
void Event_Button (uint8_t Butt, Button_events_TypeDef Event){


	Buttons_Handler(Butt, Event);
	uint8_t Send_msg[25] = "Button [x] type [x]\r\n";
	Send_msg[8] = Butt + 0x30;
	Send_msg[17] = Event + 0x30;
	Debug_UART( Send_msg, DBG_BTN,  21);

	Button[Butt].Event = NONE;
	Button[Butt].Timer = 0;

}

__weak void Buttons_Handler (uint8_t Butt, Button_events_TypeDef Event){



};


void Buttons_Init (void){

	Button[0].Port = In1_GPIO_Port;
	Button[1].Port = In2_GPIO_Port;
	Button[2].Port = In3_GPIO_Port;
	Button[3].Port = In4_GPIO_Port;
	Button[4].Port = In5_GPIO_Port;
	Button[5].Port = In6_GPIO_Port;

	Button[0].Pin = In1_Pin;
	Button[1].Pin = In2_Pin;
	Button[2].Pin = In3_Pin;
	Button[3].Pin = In4_Pin;
	Button[4].Pin = In5_Pin;
	Button[5].Pin = In6_Pin;

	Button[0].PinState = HAL_GPIO_ReadPin(Button[0].Port, Button[0].Pin);
	Button[1].PinState = HAL_GPIO_ReadPin(Button[1].Port, Button[1].Pin);
	Button[2].PinState = HAL_GPIO_ReadPin(Button[2].Port, Button[2].Pin);
	Button[3].PinState = HAL_GPIO_ReadPin(Button[3].Port, Button[3].Pin);
	Button[4].PinState = HAL_GPIO_ReadPin(Button[4].Port, Button[4].Pin);
	Button[5].PinState = HAL_GPIO_ReadPin(Button[5].Port, Button[5].Pin);

	Button[0].Event = NONE;
	Button[1].Event = NONE;
	Button[2].Event = NONE;
	Button[3].Event = NONE;
	Button[4].Event = NONE;
	Button[5].Event = NONE;

//	Debug_UART( "Button init\r\n", DBG_OK,  13);

}
