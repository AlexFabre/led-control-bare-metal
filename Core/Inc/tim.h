/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.h
 * @brief   This file contains all the function prototypes for
 *          the tim.c file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim17;

/* USER CODE BEGIN Private defines */

/* TIM clock frequency in Hertz */
#define TIM_CLOCK                   (8000000)
/* TIM prescaler */
#define TIM_PRESCALER               (8000)
/* TIM counter frequency (TIM_CLOCK / TIM_PRESCALER) */
#define TIM_FREQUENCY               (1000)
/* TIM tick period (TIM_PRESCALER / TIM_CLOCK) */
#define TIM_TICK_PERIOD_MS          (1)
/* Convert milliseconds to TIM ticks */
#define CONVERT_MS_TO_TIM_TICK(ms)  (ms / TIM_TICK_PERIOD_MS)
/* Convert TIM tick */
#define CONVERT_TIM_TICK_TO_MS(tck) (tck * TIM_TICK_PERIOD_MS)

/* Stop LED periodic wakeup */
#define stop_TIM_periodic_wkup() HAL_TIM_Base_Stop_IT(&htim17)

/* USER CODE END Private defines */

void MX_TIM17_Init(void);

/* USER CODE BEGIN Prototypes */

/* Set next LED wakeup */
void start_TIM_periodic_wkup(uint16_t milliseconds);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */
