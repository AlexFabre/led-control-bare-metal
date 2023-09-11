/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.c
 * @brief   This file provides code for the configuration
 *          of the TIM instances.
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
/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

TIM_HandleTypeDef htim17;

/* TIM17 init function */
void MX_TIM17_Init(void)
{

    /* USER CODE BEGIN TIM17_Init 0 */

    /* USER CODE END TIM17_Init 0 */

    /* USER CODE BEGIN TIM17_Init 1 */

    /* USER CODE END TIM17_Init 1 */
    htim17.Instance               = TIM17;
    htim17.Init.Prescaler         = 7999;
    htim17.Init.CounterMode       = TIM_COUNTERMODE_UP;
    htim17.Init.Period            = 65535;
    htim17.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    htim17.Init.RepetitionCounter = 0;
    htim17.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim17) != HAL_OK) {
        Error_Handler();
    }
    /* USER CODE BEGIN TIM17_Init 2 */

    /* USER CODE END TIM17_Init 2 */
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *tim_baseHandle)
{

    if (tim_baseHandle->Instance == TIM17) {
        /* USER CODE BEGIN TIM17_MspInit 0 */

        /* USER CODE END TIM17_MspInit 0 */
        /* TIM17 clock enable */
        __HAL_RCC_TIM17_CLK_ENABLE();

        /* TIM17 interrupt Init */
        HAL_NVIC_SetPriority(TIM17_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(TIM17_IRQn);
        /* USER CODE BEGIN TIM17_MspInit 1 */

        /* USER CODE END TIM17_MspInit 1 */
    }
}

void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *tim_baseHandle)
{

    if (tim_baseHandle->Instance == TIM17) {
        /* USER CODE BEGIN TIM17_MspDeInit 0 */

        /* USER CODE END TIM17_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_TIM17_CLK_DISABLE();

        /* TIM17 interrupt Deinit */
        HAL_NVIC_DisableIRQ(TIM17_IRQn);
        /* USER CODE BEGIN TIM17_MspDeInit 1 */

        /* USER CODE END TIM17_MspDeInit 1 */
    }
}

/* USER CODE BEGIN 1 */

void start_TIM_periodic_wkup(uint16_t milliseconds)
{
    uint16_t tim_tick = (uint16_t)CONVERT_MS_TO_TIM_TICK(milliseconds);

    /* Configure timer register */
    __HAL_TIM_SetAutoreload(&htim17, tim_tick - 1);
    __HAL_TIM_SetCounter(&htim17, 0);

    /* Start timer if currently stopped */
    if (HAL_TIM_Base_GetState(&htim17) == HAL_TIM_STATE_READY) {
        HAL_TIM_Base_Start_IT(&htim17);
    }
}

/* USER CODE END 1 */
