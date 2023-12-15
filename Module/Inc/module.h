/*
 * module.h
 *
 *  Created on: Jan 24, 2022
 *      Author: i
 */


#include "spi_LED.h"
#include "debug_LED.h"
#include "buttons.h"
#include "out.h"
#include "main.h"


#define PROTOCOL_VER 	0x01
#define MODULE_VER 		0x40
#define YEAR			22
#define MONTH			1
#define DAY				27
#define SERIAL_N		0x01

//device id

#define MODULE_DID 		1
#define DEBUG_LED_DID	2
//define BUZZER_DID		3

#define POWER_OUTS_DID	101
#define WEAK_OUTS_DID	102
#define	SPI_LED_DID		103
#define BUTTONS_DID		104


//================================================================
#pragma pack(push, 1)
#pragma scalar_storage_order big-endian


typedef struct {
	uint32_t Len;
	uint8_t Pver;
	uint8_t MsgType;
	uint32_t ModuleID;
	uint16_t DeviceID;
	uint8_t DeviceVer;
	uint8_t PortID;
	uint8_t Comand;
	uint8_t* Rx_Data;
}Rx_Msg_TypeDef;

typedef struct {
	uint32_t 	Len;
	uint8_t 	Pver;
	uint8_t 	MsgType;
	uint32_t 	ModuleID;
	uint16_t 	DeviceID;
	uint8_t 	DeviceVer;
	uint8_t 	PortID;
	uint8_t 	Event;
	uint8_t 	Send_Msg[1000];
}TxEvent_Msg_TypeDef;

typedef struct {
	uint32_t Len;
	uint8_t Pver;
	uint8_t MsgType;
	uint32_t ModuleID;
	uint32_t Signature;
	uint8_t Rcode;
	uint8_t Send_Msg[1000];
}TxAnsver_Msg_TypeDef;
#pragma pack(pop)
#pragma scalar_storage_order little-endian
//========================================================================





#define RX_MSG_SHIFT 15
#define TXEVENT_MSG_SHIFT 15
#define TXANSWER_MSG_SHIFT 15

uint32_t reverse_32(uint32_t data);
void MM_Init(void);
void MM_Tx_Answer (uint8_t* Send_Data, uint32_t Len);
void MM_Tx_Event (uint8_t* Send_Data, uint32_t Len);

void CDCDataReceivedCallback(uint8_t *Buf, uint16_t len);

uint32_t MM_CRC_Calculate(uint8_t* data, uint32_t Len);

__weak void Mine_IncTic(void);

















