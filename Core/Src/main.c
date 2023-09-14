/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "gpio.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "button.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

static const char big_msg[] = "a191f8d6ea9cadff3ff58a915d6f0318f6caf45e1762fa381\
61c7266ad4ab1b5ddd530a72f3ef17c592805e3ea60aa69ae103a079fa6a9e471d06d5b441bf0f2b\
62f40fd7c6c58e5548e18e0690376b317a143d3795a479c4c2f680a792be26eaa9c7745c52d8ded6\
b3c7a9f0335c7a9e1039b176a15c1805f09fcefcbd94890b985f7ecdbe33b11d564c38cfa35a9f9a\
65cbb1bbc1d1a85a60a035ceb5d7d1c409854692ea30796615d516ee9a9f7c7418b8809d01ae9763\
e992b57884335143e2b65de13e77013479b12d7e150135f7500f86891e31df4e351a5fd60c5a1229\
bae58fa81a82421c54dceaf9cd77297bc76edc6ca4df462e6c26b02b18e4341f96e8cd68df581306\
62c4836c5f6c150ca7c42a539558e080d6efdaf015710d347eb5e14b69c07052f388d398f9bfe02c\
e01075b180d86ac9a5ad47a67f353c40849b88fc842d72508b1eadec6fb40fe184d6af61822d9a4f\
53224c9d99f1b5978b0f502273d0811a0f0468d6ad4c8423cf14218d0b5f3edef6fb48d2b1e86456\
6a728d03d0615a6b86327e6d86ca695c168f932aaf4d925d915a42229a717ca9a372e3e2b45947dd\
402fe7a74a8dda1a7843096f9ea8224cfc0c833238b083abc172379ca508ae8bf759e87e3a487dc3\
61c7266ad4ab1b5ddd530a72f3ef17c592805e3ea60aa69ae103a079fa6a9e471d06d5b441bf0f2b\
62f40fd7c6c58e5548e18e0690376b317a143d3795a479c4c2f680a792be26eaa9c7745c52d8ded6\
b3c7a9f0335c7a9e1039b176a15c1805f09fcefcbd94890b985f7ecdbe33b11d564c38cfa35a9f9a\
65cbb1bbc1d1a85a60a035ceb5d7d1c409854692ea30796615d516ee9a9f7c7418b8809d01ae9763\
bae58fa81a82421c54dceaf9cd77297bc76edc6ca4df462e6c26b02b18e4341f96e8cd68df581306\
62f40fd7c6c58e5548e18e0690376b317a143d3795a479c4c2f680a792be26eaa9c7745c52d8ded6\
b3c7a9f0335c7a9e1039b176a15c1805f09fcefcbd94890b985f7ecdbe33b11d564c38cfa35a9f9a\
65cbb1bbc1d1a85a60a035ceb5d7d1c409854692ea30796615d516ee9a9f7c7418b8809d01ae9763\
e992b57884335143e2b65de13e77013479b12d7e150135f7500f86891e31df4e351a5fd60c5a1229\
bae58fa81a82421c54dceaf9cd77297bc76edc6ca4df462e6c26b02b18e4341f96e8cd68df581306\
62c4836c5f6c150ca7c42a539558e080d6efdaf015710d347eb5e14b69c07052f388d398f9bfe02c\
e01075b180d86ac9a5ad47a67f353c40849b88fc842d72508b1eadec6fb40fe184d6af61822d9a4f\
53224c9d99f1b5978b0f502273d0811a0f0468d6ad4c8423cf14218d0b5f3edef6fb48d2b1e86456\
6a728d03d0615a6b86327e6d86ca695c168f932aaf4d925d915a42229a717ca9a372e3e2b45947dd\
402fe7a74a8dda1a7843096f9ea8224cfc0c833238b083abc172379ca508ae8bf759e87e3a487dc3\
e992b57884335143e2b65de13e77013479b12d7e150135f7500f86891e31df4e351a5fd60c5a1229\
bae58fa81a82421c54dceaf9cd77297bc76edc6ca4df462e6c26b02b18e4341f96e8cd68df581306\
62c4836c5f6c150ca7c42a539558e080d6efdaf015710d347eb5e14b69c07052f388d398f9bfe02c\
e01075b180d86ac9a5ad47a67f353c40849b88fc842d72508b1eadec6fb40fe184d6af61822d9a4f\
53224c9d99f1b5978b0f502273d0811a0f0468d6ad4c8423cf14218d0b5f3edef6fb48d2b1e86456\
6a728d03d0615a6b86327e6d86ca695c168f932aaf4d925d915a42229a717ca9a372e3e2b45947dd\
402fe7a74a8dda1a7843096f9ea8224cfc0c833238b083abc172379ca508ae8bf759e87e3a487dc3\
61c7266ad4ab1b5ddd530a72f3ef17c592805e3ea60aa69ae103a079fa6a9e471d06d5b441bf0f2b\
62f40fd7c6c58e5548e18e0690376b317a143d3795a479c4c2f680a792be26eaa9c7745c52d8ded6\
b3c7a9f0335c7a9e1039b176a15c1805f09fcefcbd94890b985f7ecdbe33b11d564c38cfa35a9f9a\
65cbb1bbc1d1a85a60a035ceb5d7d1c409854692ea30796615d516ee9a9f7c7418b8809d01ae9763\
e992b57884335143e2b65de13e77013479b12d7e150135f7500f86891e31df4e351a5fd60c5a1229\
65cbb1bbc1d1a85a60a035ceb5d7d1c409854692ea30796615d516ee9a9f7c7418b8809d01ae9763\
e992b57884335143e2b65de13e77013479b12d7e150135f7500f86891e31df4e351a5fd60c5a1229\
bae58fa81a82421c54dceaf9cd77297bc76edc6ca4df462e6c26b02b18e4341f96e8cd68df581306\
62c4836c5f6c150ca7c42a539558e080d6efdaf015710d347eb5e14b69c07052f388d398f9bfe02c\
e01075b180d86ac9a5ad47a67f353c40849b88fc842d72508b1eadec6fb40fe184d6af61822d9a4f\
bae58fa81a82421c54dceaf9cd77297bc76edc6ca4df462e6c26b02b18e4341f96e8cd68df581306\
62c4836c5f6c150ca7c42a539558e080d6efdaf015710d347eb5e14b69c07052f388d398f9bfe02c\
e01075b180d86ac9a5ad47a67f353c40849b88fc842d72508b1eadec6fb40fe184d6af61822d9a4f\
53224c9d99f1b5978b0f502273d0811a0f0468d6ad4c8423cf14218d0b5f3edef6fb48d2b1e86456\
6a728d03d0615a6b86327e6d86ca695c168f932aaf4d925d915a42229a717ca9a372e3e2b45947dd\
402fe7a74a8dda1a7843096f9ea8224cfc0c833238b083abc172379ca508ae8bf759e87e3a487dc3\
a915a66fd4e2da9484811bb0c8dcc644bd9acd8a8081d90240aa700a97240033dd0d4f2gz37h6dr4\
rf5r54dceaf9cd77297bc76ed24cfc08fc842d7c83v6gh";

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void user_click_event(void);
void enter_sequence_running(void);
void enter_sequence_stanby(void);
void stop_sequence(void);

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
    MX_RTC_Init();
    MX_TIM17_Init();
    MX_USART2_UART_Init();
    /* USER CODE BEGIN 2 */

    infoPrintln("Device started !");

    reset_button_variables();

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {

        if (get_button_state() == BTN_CLICK) {
            user_click_event();
        }

        if (get_button_state() == BTN_DOUBLE_CLICK) {
            /* Send the big frame over UART */
            uart2_print(big_msg, sizeof(big_msg));
        }

        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef       RCC_OscInitStruct = { 0 };
    RCC_ClkInitTypeDef       RCC_ClkInitStruct = { 0 };
    RCC_PeriphCLKInitTypeDef PeriphClkInit     = { 0 };

    /** Configure LSE Drive Capability
     */
    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_HIGH);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSE;
    RCC_OscInitStruct.LSEState            = RCC_LSE_ON;
    RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
        | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
        Error_Handler();
    }
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_RTC;
    PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
    PeriphClkInit.RTCClockSelection    = RCC_RTCCLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */

/* Possible states of the device */
typedef enum {
    APP_SHUTDOWN,
    APP_RUNNING,
    APP_STANDBY
} app_state_t;

/* Current state of the device */
static app_state_t _app_state = APP_SHUTDOWN;

/* Process device state change consecutive to button press */
void user_click_event(void)
{
    infoPrintln("User click");

    switch (_app_state) {
    case APP_SHUTDOWN:
        _app_state = APP_RUNNING;
        enter_sequence_running();
        break;
    case APP_RUNNING:
    case APP_STANDBY:
        _app_state = APP_SHUTDOWN;
        stop_sequence();
        break;
    default:
        break;
    }
}

/* Process device state change consecutive to RTC IRQ */
void RTC_wakeup_IRQ(void)
{
    stop_RTC_periodic_wkup();

    switch (_app_state) {
    case APP_RUNNING:
        _app_state = APP_STANDBY;
        enter_sequence_stanby();
        break;
    case APP_STANDBY:
        _app_state = APP_RUNNING;
        enter_sequence_running();
        break;
    case APP_SHUTDOWN:
        /* Should never happen */
        stop_sequence();
        break;
    default:
        break;
    }
}

/* The device starts running for 20s */
void enter_sequence_running(void)
{
    /* TODO: Currently the led toggles every 300ms. (300ms ON - 300ms OFF)
     * We would rather prefer the led to make a short blink every 3s (150ms ON - 2.850s OFF)
     *
     * Send on UART2 the message "Enter running !" */

    infoPrintln("Enter running !");

    start_TIM_periodic_wkup(300);
    start_RTC_periodic_wkup(20);
}

/* The device enters standby for 40s */
void enter_sequence_stanby(void)
{
    /* TODO: Currently the led toggles every 600ms. (600ms ON - 600ms OFF)
     * We would rather prefer the led to make a short blink every 10s (150ms ON - 9.850s OFF)
     *
     * Send on UART2 the message "Enter standby !" */

    infoPrintln("Enter standby !");

    start_TIM_periodic_wkup(600);
    start_RTC_periodic_wkup(40);
}

/* The device cycle stops */
void stop_sequence(void)
{
    /* TODO: We would like a 4 blink scheme as soon as the cycle stops, to inform the user
     * that the app effectively stopped running: (150ms ON - 150ms OFF) x4
     *
     * Send on UART2 the message "Enter shutdown !" */

    infoPrintln("Enter shutdown !");

    stop_RTC_periodic_wkup();
    stop_TIM_periodic_wkup();
    set_LED(false);
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
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
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
