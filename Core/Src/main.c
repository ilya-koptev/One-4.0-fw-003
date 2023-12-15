/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dma.h"
#include "fatfs.h"
#include "i2c.h"
#include "rng.h"
#include "rtc.h"
#include "sdio.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "module.h"
#include "stdlib.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define AT 0
#define JOYSTIC 1
#define TEST 2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
		uint8_t crc[16] = {0x00,0x00,0x00,0x0f,0x01,0x01,0xFF,0xFF,0xFF,0xFF,0x00,0x01,0x01,0x00,0x01,0x00};
		extern LED_ColorTypeDef Debug_LED1;
		extern LED_ColorTypeDef Debug_LED2;
		extern uint8_t init_OK;


		uint8_t rx_data[64] = "egor \r\n";

		uint8_t Regim = AT;
		uint16_t Velosity = 0;
		int16_t Rudder = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void shift_pixel(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_FATFS_Init();
  MX_TIM4_Init();
  MX_I2C2_Init();
  MX_RTC_Init();
  MX_SPI3_Init();
  MX_UART4_Init();
  MX_USB_DEVICE_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_RNG_Init();
  MX_SDIO_SD_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */

  	MM_Init();

	HAL_UART_Receive_IT(&huart2, rx_data, 1);

  	init_OK = 1;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

//	  Debug_LED1 = 	RED;
	  Debug_LED2 = BLACK;
	  HAL_Delay(200);
//	  Debug_LED1 = BLACK;

	  Debug_LED2 = GREEN;
	  HAL_Delay(800);
//	  CDC_Transmit_FS(rx_data, 10);
//	  HAL_UART_Transmit(&huart2, rx_data, 7, 10);

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);
}

/* USER CODE BEGIN 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	static uint8_t index = 0;
	Debug_LED2 = GREEN;

	if ((rx_data[index] != 0x0d) && (index < 64)){
		HAL_UART_Transmit(&huart2, rx_data + index++, 1, 10);
		if (Regim == JOYSTIC){
			if (rx_data[0] == 0x38){ // Быстрее
				Velosity += 50; if (Velosity > 1000) {Velosity = 1000;}
				Set_Out(P_OUT_1, Velosity);
				Debug_UART((uint8_t *) "Set velosity ", DBG_OK, 13);
				uint8_t range[10] = "          ";
				utoa(Velosity,range,10);
				HAL_UART_Transmit(&huart2, range, 4, 10);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}
			if (rx_data[0] == 0x32){ // Медленнее
				if (Velosity < 50) {Velosity = 0;} else {Velosity -= 50;}
				Set_Out(P_OUT_1, Velosity);
				Debug_UART((uint8_t *) "Set velosity ", DBG_OK, 13);
				uint8_t range[10] = "          ";
				utoa(Velosity,range,10);
				HAL_UART_Transmit(&huart2, range, 4, 10);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}
			if (rx_data[0] == 0x35){ // Стоп
				Velosity = 0;
				Set_Out(P_OUT_1, Velosity);
				Debug_UART((uint8_t *) "Set STOP ", DBG_OK, 9);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}
			if (rx_data[0] == 0x34){ // Вправо
				Rudder -= 10; if (Rudder <= -50) {Rudder = -50;}
				Set_Out(P_OUT_7, 930 + Rudder);
				Debug_UART((uint8_t *) "Left ", DBG_OK, 5);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}
			if (rx_data[0] == 0x36){ // Вправо
				Rudder += 10; if (Rudder >= 50) {Rudder = 50;}
				Set_Out(P_OUT_7, 930 + Rudder);
				Debug_UART((uint8_t *) "Right ", DBG_OK, 6);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}


			index = 0;
		}
		HAL_UART_Receive_IT(&huart2, rx_data + index, 1);
	}
	else {
		if (Regim == JOYSTIC) {
			Regim = AT;
			HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			Debug_UART((uint8_t *) "Set AT command ", DBG_OK, 15);
			HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
		}
		HAL_UART_Transmit(&huart2, (uint8_t *)" \r\n", 3, 10);
		HAL_UART_Receive_IT(&huart2, rx_data, 1);
		if ((rx_data[0] == 0x41) && (rx_data[1] == 0x54) && (rx_data[2] == 0x2b)){								// AT+
			if (rx_data[3] == 0x52) {Debug_LED1 = RED; Debug_UART((uint8_t *) "RED ON \r\n", DBG_OK, 9);}		//R
			if (rx_data[3] == 0x47) {Debug_LED1 = GREEN;Debug_UART((uint8_t *) "GREEN ON \r\n", DBG_OK, 11);}	//G
			if (rx_data[3] == 0x42) {Debug_LED1 = BLACK;Debug_UART((uint8_t *) "LED OFF \r\n", DBG_OK, 10);}	//B
			if (rx_data[3] == 0x59) {Debug_LED1 = YELLOW;Debug_UART((uint8_t *) "YELLOW ON \r\n", DBG_OK, 12);}	//Y
			if (rx_data[3] == 0x50) {																			//P
				Set_Out(rx_data[4] - 0x31, atoi(&rx_data[6]));
				Debug_UART((uint8_t *) "Set bright ", DBG_OK, 11);
				uint8_t range[10] = "          ";
				utoa(atoi(&rx_data[6]),range,10);
				HAL_UART_Transmit(&huart2, range, 4, 10);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}
			if (rx_data[3] == 0x46) {																			//F
				Set_PWM_Freq(rx_data[4] - 0x31 + 14, atoi(&rx_data[6]));
				Debug_UART((uint8_t *) "Set freq ", DBG_OK, 9);
				uint8_t range[10] = "          ";
				utoa(atoi(&rx_data[6]),range,10);
				HAL_UART_Transmit(&huart2, range, 4, 10);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);
			}
			if (rx_data[3] == 0x4a) {
				Regim = JOYSTIC;
				Set_PWM_Freq(P_OUT_1234, 1000);
				Set_PWM_Freq(P_OUT_567, 50);
				Set_Out(P_OUT_1, 0);
				Set_Out(P_OUT_7, 930);
				Debug_UART((uint8_t *) "Set JOYSTIC ", DBG_OK, 12);
				HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);

			}
		}
		index = 0;
	}



	//			uint8_t range[10] = " = 0x          ";
	//			utoa(rx_data[0], range + 5, 16);
	//			HAL_UART_Transmit(&huart2, range, 8, 10);
	//			HAL_UART_Transmit(&huart2,(uint8_t *)" \r\n", 3, 10);


}



void Main_IncTic(void){
//	static uint16_t girlyanda_timer = 10;
//	static uint8_t current_LED;
//	static uint8_t current_color = 1;
//	if (girlyanda_timer){girlyanda_timer--;}
//	else{
//		girlyanda_timer = 10;
//
//		Spi_LED_Set_Fix_Color(current_LED, rand()%10, current_color);
//		current_LED = rand()%149;
//		Spi_LED_Set_Fix_Color(current_LED, rand()%250, current_color);
//		current_color++;
//		if (current_color > WHITE){current_color = 1;}
//
//	}
//	static uint8_t zvezda[5][10] = {{4, 5,13,14,22,23,31,32,40,41},
//									{3, 6,12,15,21,24,30,33,39,42},
//									{2, 7,11,16,20,25,29,34,38,43},
//									{1, 8,10,17,19,26,28,35,37,44},
//								   {45, 9, 9,18,18,27,27,36,36,45}};
//	static uint16_t zvezda_timer = 100;
//	if (zvezda_timer) {zvezda_timer--;}
//	else{
//		zvezda_timer = 100;
//		static uint8_t current_bright[10] = {10,20,50,100,200,10,20,50,100,200};
//		static uint8_t shift = 9;
//		for (uint8_t j = 0; j < 5; j++){
//			for (uint8_t i = 0; i < 10; i++){Spi_LED_Set_Fix_Color(zvezda[j][i] + 149, current_bright[shift], RED);}
//			if (--shift){} else {shift = 9;}
//		}
//
//
//	}

//static uint16_t shift_timer = 300;
//	if (Regim == TEST){
//		if (shift_timer) {shift_timer--;}
//		else {
//			shift_timer == 1000;
//
//
//			static uint8_t shift = 0;
//			for (uint16_t i = shift; i < ((LED_MAX<<1) - 4); i += 4){
//				Spi_LED_Set_Fix_Color(i, 50, WHITE);
//				Spi_LED_Set_Fix_Color(i + 1, 0, BLACK);
//				Spi_LED_Set_Fix_Color(i + 2, 0, BLACK);
//				Spi_LED_Set_Fix_Color(i + 3, 0, BLACK);
//			}
//			shift++;
//			if (shift == 3) {shift = 0;}
//
//
//		}
//	}
}

void Buttons_Handler (uint8_t Butt, Button_events_TypeDef Event){
//	if ((Butt == 0) && (Event == SHORT_CLC)) {
//
//		Debug_LED1 = GREEN;
//		uint32_t temp;
//		CRC->CR = 1;
//		CRC->DR = 0x11111111;
//		temp = CRC->DR;
//		CRC->DR = temp;
//		temp = CRC->DR;
//
//
//
////
////
//////		static uint8_t for_crc[16] = {0x00, 0x00, 0x00, 0x0f, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x01, 0x00, 0x01 };
////		static uint32_t for_crc[4];
////		static uint32_t out_crc[16];
////
//////		out_crc[0] = HAL_CRC_Calculate(&hcrc, (uint32_t*)for_crc, 4);
//////		out_crc[1] = HAL_CRC_Calculate(&hcrc, (uint32_t*)for_crc, 3);
////
////		for_crc[0] = 0x11223344;
////		for_crc[1] = __RBIT(for_crc[0]);
////		for_crc[2] = __REV(for_crc[0]);
////		for_crc[3] = __RBIT(for_crc[2]);
////
//////		CDC_Transmit_FS((uint8_t*)for_crc, 16);
////
////		CRC->CR = 1;
////		CRC->DR = for_crc[0];
////		out_crc[0] = CRC->DR;
////
////		CRC->CR = 1;
////		CRC->DR = for_crc[1];
////		out_crc[1] = CRC->DR;
////
////		CRC->CR = 1;
////		CRC->DR = for_crc[2];
////		out_crc[2] = CRC->DR;
////
////		CRC->CR = 1;
////		CRC->DR = for_crc[3];
////		out_crc[3] = CRC->DR;
////
////
//////		CDC_Transmit_FS((uint8_t*)out_crc, 16);
////
////		out_crc[4] = __RBIT(out_crc[0]);
////		out_crc[5] = __RBIT(out_crc[1]);
////		out_crc[6] = __RBIT(out_crc[2]);
////		out_crc[7] = __RBIT(out_crc[3]);
////
////		out_crc[8] = out_crc[4] ^ 0XFFFFFFFF;
////		out_crc[9] = out_crc[5] ^ 0XFFFFFFFF;
////		out_crc[10] = out_crc[6] ^ 0XFFFFFFFF;
////		out_crc[11] = out_crc[7] ^ 0XFFFFFFFF;
////
////
////
////
////
////		CDC_Transmit_FS((uint8_t*)out_crc, 48);
//
//	}
//
//	if ((Butt == 1) && (Event == SHORT_CLC)) {
//
//
//	}
//
//
//
//
	static uint8_t shift = 0;
	if ((Butt == 0) && (Event == SHORT_CLC)) {
		Regim = AT;
		shift++;
		for (uint16_t i = 0; i < (LED_MAX << 1); i++) {Spi_LED_Set_Fix_Color(i, 10, GREEN);}
		for (uint16_t i = shift; i <(LED_MAX << 1); i += 10) {Spi_LED_Set_Fix_Color(i, 10, RED);}
		for (uint16_t i = shift; i <(LED_MAX << 1); i += 100) {Spi_LED_Set_Fix_Color(i, 10, BLUE);}
		if (shift > 9) {shift = 0;}
	}
	if ((Butt == 0) && (Event == DOUBLE_CLC)) {
		Regim = AT;
		shift = 0;
		for (uint16_t i = 0; i < (LED_MAX << 1); i++) {Spi_LED_Set_Fix_Color(i, 10, GREEN);}
		for (uint16_t i = shift; i <(LED_MAX << 1); i += 10) {Spi_LED_Set_Fix_Color(i, 10, RED);}
		for (uint16_t i = shift; i <(LED_MAX << 1); i += 100) {Spi_LED_Set_Fix_Color(i, 10, BLUE);}

	}
	if ((Butt == 0) && (Event == LONG_CLC)) {
		Regim = TEST;
	}

}






/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	Debug_LED2 = RED;
//  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
