


#include "module.h"
#include "dma.h"
#include "usbd_cdc_if.h"
#include "crc.h"
#include "usart.h"
#include "main.h"

TxAnsver_Msg_TypeDef mm_tx_answer;
TxEvent_Msg_TypeDef mm_tx_event;
Rx_Msg_TypeDef mm_rx_msg;
uint8_t init_OK;

//extern void Mine_IncTic();

//uint32_t reverse_32(uint32_t data)
//{
//	__RBIT(data);
//        return data;
//};

void MM_Init(void){

	Spi_LED_Init();
	Buttons_Init();
	Debug_LED_Init();
	Out_Init();

//	HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n\033[36mParametrica.ru\033[0m\r\n", 27, 5);
//	init_OK = 1;
}


void HAL_IncTick(void)
{
  uwTick += uwTickFreq;
  if (init_OK){
	  Main_IncTic();
	  Debug_LED_IncTic();
	  Button_IncTick();
	  Spi_LED_IncTick();

  }
}

void MM_Tx_Answer (uint8_t* Send_Data, uint32_t Len){

	mm_tx_answer.Len = TXANSWER_MSG_SHIFT + Len;
	mm_tx_answer.Pver = 0x01;
	mm_tx_answer.MsgType = 0x03;
	mm_tx_answer.ModuleID = MODULE_VER << 24| YEAR << 17 | MONTH << 13 | DAY << 8 | SERIAL_N;
//	mm_tx_answer.Signature = 0x5c84fefd;
	mm_tx_answer.Rcode = 0x01;

	HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)Send_Data,(uint32_t)&mm_tx_answer + TXEVENT_MSG_SHIFT, Len);

	CDC_Transmit_FS((uint8_t*)&mm_tx_answer, TXANSWER_MSG_SHIFT + Len);

}
void MM_Tx_Event (uint8_t* Send_Data, uint32_t Len){

	mm_tx_event.Len = TXEVENT_MSG_SHIFT + Len;
	mm_tx_event.Pver = 0x01;
	mm_tx_event.MsgType = 0x02;
	mm_tx_event.ModuleID = MODULE_VER << 24| YEAR << 17 | MONTH << 13 | DAY << 8 | SERIAL_N;
	mm_tx_event.DeviceID = 0x0003;
	mm_tx_event.DeviceVer = 0x01;
	mm_tx_event.PortID = 0x01;
	mm_tx_event.Event = 0x01;

	HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)Send_Data,(uint32_t)&mm_tx_event + TXEVENT_MSG_SHIFT, Len);

	CDC_Transmit_FS((uint8_t*)&mm_tx_event, TXEVENT_MSG_SHIFT + Len);
}

void CDCDataReceivedCallback(uint8_t *Buf, uint16_t len){

	memcpy(&mm_rx_msg, Buf,  RX_MSG_SHIFT);
	static uint32_t res_CRC;

	res_CRC = MM_CRC_Calculate(Buf, len);

	CDC_Transmit_FS((uint8_t *)&res_CRC, 4);


}
//__weak void Mine_IncTic(void){

//}


uint32_t MM_CRC_Calculate(uint8_t* data, uint32_t len){
//	uint32_t temp, temp_1;
	uint32_t i;
//	uint8_t mod;
//	uint32_t tile;


//	mod = len & 0x03;

//---------------Расчёт CRC для 32 битных данных-------------------------------------
	CRC->CR = 1;									// Сброс модуля CRC
	while (i < len >> 2){
		CRC->DR = __RBIT(((uint32_t *)data)[i++]);
	};
	return ~__RBIT(__REV(CRC->DR));

//	temp = __RBIT(__REV(CRC->DR)) ^ 0xffffffff;
//---------------------------------------------------
//	temp_1 = __RBIT(CRC->DR);
//
//	if (mod){
//		CRC->DR = CRC->DR;
//		tile = *((uint32_t *)&data[len >> 2]);
//
//		switch (mod){
//		case 1: {				__RBIT(tile & 0xff)			}
//
//
//
//
//
//		}
//
//
//	}




}
























