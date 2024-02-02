/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define PAD2_Pin GPIO_PIN_2
#define PAD2_GPIO_Port GPIOE
#define PAD3_Pin GPIO_PIN_3
#define PAD3_GPIO_Port GPIOE
#define PAD4_Pin GPIO_PIN_4
#define PAD4_GPIO_Port GPIOE
#define PAD5_Pin GPIO_PIN_5
#define PAD5_GPIO_Port GPIOE
#define PAD6_Pin GPIO_PIN_6
#define PAD6_GPIO_Port GPIOE
#define RD_Pin GPIO_PIN_0
#define RD_GPIO_Port GPIOF
#define MUTE_Pin GPIO_PIN_1
#define MUTE_GPIO_Port GPIOF
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOF
#define LED2_Pin GPIO_PIN_10
#define LED2_GPIO_Port GPIOF
#define RAD0_Pin GPIO_PIN_0
#define RAD0_GPIO_Port GPIOC
#define RAD1_Pin GPIO_PIN_1
#define RAD1_GPIO_Port GPIOC
#define RAD2_Pin GPIO_PIN_2
#define RAD2_GPIO_Port GPIOC
#define RAD3_Pin GPIO_PIN_3
#define RAD3_GPIO_Port GPIOC
#define RA8_Pin GPIO_PIN_0
#define RA8_GPIO_Port GPIOA
#define RA9_Pin GPIO_PIN_1
#define RA9_GPIO_Port GPIOA
#define RA20_Pin GPIO_PIN_2
#define RA20_GPIO_Port GPIOA
#define RA21_Pin GPIO_PIN_3
#define RA21_GPIO_Port GPIOA
#define RA22_Pin GPIO_PIN_4
#define RA22_GPIO_Port GPIOA
#define RAD4_Pin GPIO_PIN_4
#define RAD4_GPIO_Port GPIOC
#define RAD5_Pin GPIO_PIN_5
#define RAD5_GPIO_Port GPIOC
#define D0_Pin GPIO_PIN_0
#define D0_GPIO_Port GPIOG
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOG
#define PAD7_Pin GPIO_PIN_7
#define PAD7_GPIO_Port GPIOE
#define PA8_Pin GPIO_PIN_8
#define PA8_GPIO_Port GPIOE
#define PA9_Pin GPIO_PIN_9
#define PA9_GPIO_Port GPIOE
#define PA10_Pin GPIO_PIN_10
#define PA10_GPIO_Port GPIOE
#define PA11_Pin GPIO_PIN_11
#define PA11_GPIO_Port GPIOE
#define A0_Pin GPIO_PIN_12
#define A0_GPIO_Port GPIOE
#define A1_Pin GPIO_PIN_13
#define A1_GPIO_Port GPIOE
#define POE_Pin GPIO_PIN_14
#define POE_GPIO_Port GPIOE
#define PMPX_Pin GPIO_PIN_15
#define PMPX_GPIO_Port GPIOE
#define SPI1_CS_Pin GPIO_PIN_14
#define SPI1_CS_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOG
#define D3_Pin GPIO_PIN_3
#define D3_GPIO_Port GPIOG
#define D4_Pin GPIO_PIN_4
#define D4_GPIO_Port GPIOG
#define D5_Pin GPIO_PIN_5
#define D5_GPIO_Port GPIOG
#define D6_Pin GPIO_PIN_6
#define D6_GPIO_Port GPIOG
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOG
#define GOMB_Pin GPIO_PIN_8
#define GOMB_GPIO_Port GPIOG
#define RAD6_Pin GPIO_PIN_6
#define RAD6_GPIO_Port GPIOC
#define RAD7_Pin GPIO_PIN_7
#define RAD7_GPIO_Port GPIOC
#define IC_Pin GPIO_PIN_8
#define IC_GPIO_Port GPIOA
#define CS_Pin GPIO_PIN_9
#define CS_GPIO_Port GPIOA
#define WR_Pin GPIO_PIN_10
#define WR_GPIO_Port GPIOA
#define ROE_Pin GPIO_PIN_0
#define ROE_GPIO_Port GPIOD
#define RMPX_Pin GPIO_PIN_1
#define RMPX_GPIO_Port GPIOD
#define RA23_Pin GPIO_PIN_3
#define RA23_GPIO_Port GPIOD
#define PAD0_Pin GPIO_PIN_0
#define PAD0_GPIO_Port GPIOE
#define PAD1_Pin GPIO_PIN_1
#define PAD1_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
