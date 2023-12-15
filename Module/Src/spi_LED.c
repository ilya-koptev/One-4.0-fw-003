



#include "Spi_LED.h"
#include "debug_LED.h"
#include "usart.h"
#include "spi.h"

uint8_t  Spi_LED_Cmplt_Frame_Flag;



struct RGB {
	uint8_t Green;
	uint8_t Red;
	uint8_t Blue;
	};

//	struct RGB OutputArray[0][LED_MAX];
//	struct RGB OutputArray[1][LED_MAX];
	struct RGB OutputArray[2][LED_MAX];

	struct RGB Color_Array[256];

	uint16_t Frame_Delay = 1000 / SPI_FREQ;

//	uint16_t Mapping_Array_0[LED_MAX];
//	uint16_t Mapping_Array_1[LED_MAX];

	uint8_t Bright32[32] = {0,1,2,3,4,5,7,9,11,13,15,17,19,23,30,37,43,49,55,63,91,101,113,127,141,157,171,189,205,219,231,255};


//=========================================================================================================

void Spi_LED_IncTick(void)
{

//-------------------------------------------------------------
	Frame_Delay--;

	if (Frame_Delay == 2) {
		if (Spi_LED_Cmplt_Frame_Flag & 0x01){
			//HAL_SPI_Transmit(&hspi1, &OutputArray[0][0].Green , 9, 10);
			HAL_SPI_Transmit_DMA(&hspi1, &OutputArray[0][0].Green , LED_MAX * 3);
			Spi_LED_Cmplt_Frame_Flag &= ~0x01;
		}
	}
	if (Frame_Delay == 1) {
		if (Spi_LED_Cmplt_Frame_Flag & 0x02){
			//HAL_SPI_Transmit(&hspi2, &OutputArray[0][0].Green , 9, 10);
			HAL_SPI_Transmit_DMA(&hspi2, &OutputArray[1][0].Green , LED_MAX * 3);
			Spi_LED_Cmplt_Frame_Flag &= ~0x02;
		}
	}
	if (Frame_Delay == 0) {
		Frame_Delay = 1000 / SPI_FREQ;
	}
}
//=========================================================================================================
void Spi_LED_Init(void){
	Spi_LED_Cmplt_Frame_Flag |= 0x01 | 0x02;

	extern DMA_HandleTypeDef hdma_spi1_tx;
	extern DMA_HandleTypeDef hdma_spi2_tx;

	HAL_DMA_Init(&hdma_spi1_tx);
	HAL_DMA_Init(&hdma_spi2_tx);

	for (uint16_t i = 0; i < LED_MAX; i++){
		OutputArray[0][i].Green = g;
		OutputArray[0][i].Red 	= r;
		OutputArray[0][i].Blue 	= b;
	}

	for (uint16_t i = 0; i < LED_MAX; i++){
		OutputArray[1][i].Green =	g;
		OutputArray[1][i].Red 	=	r;
		OutputArray[1][i].Blue 	=	b;
	}



//	Debug_UART((uint8_t *) "SPI_LED init\r\n", DBG_OK, 14);


}
//=========================================================================================================
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi){
	if (hspi->Instance == SPI1){Spi_LED_Cmplt_Frame_Flag |= 0x01;}
	if (hspi->Instance == SPI2){Spi_LED_Cmplt_Frame_Flag |= 0x02;}

//	uint32_t tmp;
//	tmp = hspi->Instance;
//	static uint8_t string[18] = "\r                ";
//	itoa(tmp, string + 2, 16);
//	string[14] = Spi_LED_Cmplt_Frame_Flag + 0x30;
//	if (string[15] == *" ") {string[15] = *".";} else {string[15] = *" ";}
//	HAL_UART_Transmit(&huart2, string, 16, 2);

}
//=========================================================================================================
void Spi_LED_Set_Full_Color(Spi_LED_ChannellTypeDef channel, uint16_t index, uint8_t red, uint8_t green, uint8_t blue){
	if (channel == CHANNEL0) {
		OutputArray[0][index].Green = green;
		OutputArray[0][index].Red 	= red;
		OutputArray[0][index].Blue 	= blue;
	}
	if (channel == CHANNEL1) {
		OutputArray[1][index].Green = green;
		OutputArray[1][index].Red 	= red;
		OutputArray[1][index].Blue 	= blue;
	}
}
//=========================================================================================================
void Spi_LED_Set_Custom_Color(Spi_LED_ChannellTypeDef channel, uint16_t index, uint8_t color){
	if (channel == CHANNEL0) {
		OutputArray[0][index].Green = Color_Array[color].Green;
		OutputArray[0][index].Red 	= Color_Array[color].Red;
		OutputArray[0][index].Blue 	= Color_Array[color].Blue;
	}
	if (channel == CHANNEL1) {
		OutputArray[1][index].Green = Color_Array[color].Green;
		OutputArray[1][index].Red 	= Color_Array[color].Red;
		OutputArray[1][index].Blue 	= Color_Array[color].Blue;
	}
}
//=========================================================================================================
void Spi_LED_Set_Color(uint8_t index, uint8_t red, uint8_t green, uint8_t blue){

	Color_Array[index].Green = green;
	Color_Array[index].Red	=	red;
	Color_Array[index].Blue = blue;

}
//=========================================================================================================
void Spi_LED_Set_Fix_Color(uint16_t index, uint8_t bright, LED_ColorTypeDef color){

	Spi_LED_ChannellTypeDef channel = CHANNEL0;
	if (index >= LED_MAX){ index -= LED_MAX; channel = CHANNEL1;}
	if (index > LED_MAX) {return;}

	if (channel == CHANNEL0) {
		if (color == WHITE) {
			OutputArray[0][index].Green = bright;
			OutputArray[0][index].Red 	= bright;
			OutputArray[0][index].Blue 	= bright;
		}
		else if (color == RED) {
			OutputArray[0][index].Green = g;
			OutputArray[0][index].Red 	= bright;
			OutputArray[0][index].Blue 	= b;
		}
		else if (color == YELLOW) {
			OutputArray[0][index].Green = bright;
			OutputArray[0][index].Red 	= bright;
			OutputArray[0][index].Blue 	= b;
		}
		else if (color == GREEN) {
			OutputArray[0][index].Green = bright;
			OutputArray[0][index].Red 	= r;
			OutputArray[0][index].Blue 	= b;
		}
		else if (color == EMERALD) {
			OutputArray[0][index].Green = bright;
			OutputArray[0][index].Red 	= r;
			OutputArray[0][index].Blue 	= bright;
		}
		else if (color == BLUE) {
			OutputArray[0][index].Green = g;
			OutputArray[0][index].Red 	= r;
			OutputArray[0][index].Blue 	= bright;
		}
		else if (color == PURPLE) {
			OutputArray[0][index].Green = g;
			OutputArray[0][index].Red 	= bright;
			OutputArray[0][index].Blue 	= bright;
		}
		else if (color == BLACK) {
			OutputArray[0][index].Green = g;
			OutputArray[0][index].Red 	= r;
			OutputArray[0][index].Blue 	= b;
		}
	}
	if (channel == CHANNEL1) {
		if (color == WHITE) {
			OutputArray[1][index].Green = bright;
			OutputArray[1][index].Red 	= bright;
			OutputArray[1][index].Blue 	= bright;
		}
		else if (color == RED) {
			OutputArray[1][index].Green = g;
			OutputArray[1][index].Red 	= bright;
			OutputArray[1][index].Blue 	= b;
		}
		else if (color == YELLOW) {
			OutputArray[1][index].Green = bright;
			OutputArray[1][index].Red 	= bright;
			OutputArray[1][index].Blue 	= b;
		}
		else if (color == GREEN) {
			OutputArray[1][index].Green = bright;
			OutputArray[1][index].Red 	= r;
			OutputArray[1][index].Blue 	= b;
		}
		else if (color == EMERALD) {
			OutputArray[1][index].Green = bright;
			OutputArray[1][index].Red 	= r;
			OutputArray[1][index].Blue 	= bright;
		}
		else if (color == BLUE) {
			OutputArray[1][index].Green = g;
			OutputArray[1][index].Red 	= r;
			OutputArray[1][index].Blue 	= bright;
		}
		else if (color == PURPLE) {
			OutputArray[1][index].Green = g;
			OutputArray[1][index].Red 	= bright;
			OutputArray[1][index].Blue 	= bright;
		}
		else if (color == BLACK) {
			OutputArray[1][index].Green = g;
			OutputArray[1][index].Red 	= r;
			OutputArray[1][index].Blue 	= b;
		}
	}
}
//=========================================================================================================

//=========================================================================================================

















