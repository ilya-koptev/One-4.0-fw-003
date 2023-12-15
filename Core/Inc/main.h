/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define Out2_Pin GPIO_PIN_0
#define Out2_GPIO_Port GPIOC
#define Out3_Pin GPIO_PIN_1
#define Out3_GPIO_Port GPIOC
#define Out4_Pin GPIO_PIN_2
#define Out4_GPIO_Port GPIOC
#define Tx_Pin GPIO_PIN_0
#define Tx_GPIO_Port GPIOA
#define Rx_Pin GPIO_PIN_1
#define Rx_GPIO_Port GPIOA
#define Out1_Pin GPIO_PIN_4
#define Out1_GPIO_Port GPIOA
#define Pout7_Pin GPIO_PIN_6
#define Pout7_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOC
#define Out7_Pin GPIO_PIN_5
#define Out7_GPIO_Port GPIOC
#define Pout5_Pin GPIO_PIN_0
#define Pout5_GPIO_Port GPIOB
#define Pout6_Pin GPIO_PIN_1
#define Pout6_GPIO_Port GPIOB
#define In6_Pin GPIO_PIN_2
#define In6_GPIO_Port GPIOB
#define In4_Pin GPIO_PIN_12
#define In4_GPIO_Port GPIOB
#define In3_Pin GPIO_PIN_14
#define In3_GPIO_Port GPIOB
#define In5_Pin GPIO_PIN_15
#define In5_GPIO_Port GPIOB
#define In1_Pin GPIO_PIN_6
#define In1_GPIO_Port GPIOC
#define In2_Pin GPIO_PIN_7
#define In2_GPIO_Port GPIOC
#define Out6_Pin GPIO_PIN_10
#define Out6_GPIO_Port GPIOA
#define Out5_Pin GPIO_PIN_15
#define Out5_GPIO_Port GPIOA
#define Pout1_Pin GPIO_PIN_6
#define Pout1_GPIO_Port GPIOB
#define Pout2_Pin GPIO_PIN_7
#define Pout2_GPIO_Port GPIOB
#define Pout3_Pin GPIO_PIN_8
#define Pout3_GPIO_Port GPIOB
#define Pout4_Pin GPIO_PIN_9
#define Pout4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
