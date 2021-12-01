/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define BTN_02_Pin GPIO_PIN_13
#define BTN_02_GPIO_Port GPIOC
#define BTN_01_Pin GPIO_PIN_14
#define BTN_01_GPIO_Port GPIOC
#define KEY_04_Pin GPIO_PIN_15
#define KEY_04_GPIO_Port GPIOC
#define KEY_03_Pin GPIO_PIN_0
#define KEY_03_GPIO_Port GPIOD
#define KEY_02_Pin GPIO_PIN_1
#define KEY_02_GPIO_Port GPIOD
#define KEY_01_Pin GPIO_PIN_0
#define KEY_01_GPIO_Port GPIOA
#define RS485_EN2_Pin GPIO_PIN_1
#define RS485_EN2_GPIO_Port GPIOA
#define RS485_TX2_Pin GPIO_PIN_2
#define RS485_TX2_GPIO_Port GPIOA
#define RS485_RX2_Pin GPIO_PIN_3
#define RS485_RX2_GPIO_Port GPIOA
#define RLY_08_Pin GPIO_PIN_4
#define RLY_08_GPIO_Port GPIOA
#define RLY_07_Pin GPIO_PIN_5
#define RLY_07_GPIO_Port GPIOA
#define RLY_06_Pin GPIO_PIN_6
#define RLY_06_GPIO_Port GPIOA
#define RLY_05_Pin GPIO_PIN_7
#define RLY_05_GPIO_Port GPIOA
#define RLY_04_Pin GPIO_PIN_0
#define RLY_04_GPIO_Port GPIOB
#define RLY_03_Pin GPIO_PIN_1
#define RLY_03_GPIO_Port GPIOB
#define RLY_02_Pin GPIO_PIN_2
#define RLY_02_GPIO_Port GPIOB
#define RLY_01_Pin GPIO_PIN_10
#define RLY_01_GPIO_Port GPIOB
#define RF_SIG_Pin GPIO_PIN_12
#define RF_SIG_GPIO_Port GPIOB
#define RF_SIG_EXTI_IRQn EXTI15_10_IRQn
#define LED_01_Pin GPIO_PIN_14
#define LED_01_GPIO_Port GPIOB
#define RS485_EN1_Pin GPIO_PIN_8
#define RS485_EN1_GPIO_Port GPIOA
#define RS485_TX1_Pin GPIO_PIN_9
#define RS485_TX1_GPIO_Port GPIOA
#define RS485_RX1_Pin GPIO_PIN_10
#define RS485_RX1_GPIO_Port GPIOA
#define BTN_12_Pin GPIO_PIN_11
#define BTN_12_GPIO_Port GPIOA
#define BTN_11_Pin GPIO_PIN_12
#define BTN_11_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define BTN_10_Pin GPIO_PIN_15
#define BTN_10_GPIO_Port GPIOA
#define BTN_09_Pin GPIO_PIN_3
#define BTN_09_GPIO_Port GPIOB
#define BTN_08_Pin GPIO_PIN_4
#define BTN_08_GPIO_Port GPIOB
#define BTN_07_Pin GPIO_PIN_5
#define BTN_07_GPIO_Port GPIOB
#define BTN_06_Pin GPIO_PIN_6
#define BTN_06_GPIO_Port GPIOB
#define BTN_05_Pin GPIO_PIN_7
#define BTN_05_GPIO_Port GPIOB
#define BTN_04_Pin GPIO_PIN_8
#define BTN_04_GPIO_Port GPIOB
#define BTN_03_Pin GPIO_PIN_9
#define BTN_03_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
