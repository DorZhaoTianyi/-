/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "my_lib.h"
int QuanShu;
int ITjishu;
uint16_t ADC1_number = 0;
uint16_t ADC2_number = 0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
int fputc(int ch, FILE *f){
HAL_UART_Transmit (&huart1,(uint8_t *)&ch,1,0xffff);
	return ch;
}
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#include <stdio.h>
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
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

	HAL_TIM_Base_Start_IT(&htim4);//������ʱ���ж�
	HAL_TIM_Base_Start_IT(&htim3);//������ʱ���ж�
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);//������ʱ���ж�
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);//������ʱ���ж�
	__HAL_TIM_SetAutoreload(&htim4,800);		//�����ٶȿ���
	__HAL_TIM_SetAutoreload(&htim3,800);		//�����ٶȿ���
	__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, 250);//��������  �ò���
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 250);//��������  �ò���
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,HAL_MAX_DELAY);
		ADC1_number = (uint16_t)HAL_ADC_GetValue(&hadc1);
		
		HAL_ADC_Start(&hadc2);
		HAL_ADC_PollForConversion(&hadc2,HAL_MAX_DELAY);
		ADC2_number = (uint16_t)HAL_ADC_GetValue(&hadc2);
		
//		if(ADC1_number >= 2248 && ADC1_number <= 4095 && ADC2_number )
//		{
//			dianji1_kongzhi(up,250,800);
//		}
//		else if(ADC1_number >= 0 && ADC1_number <= 1848)
//		{
//			dianji1_kongzhi(down,250,800);
//		}
//		else if(ADC1_number < 2248 && ADC1_number > 1848)
//		{
//			dianji1_kongzhi(up,0,0);
//		}
//		if(ADC2_number >= 2248 && ADC2_number <= 4095)
//		{
//			dianji2_kongzhi(up,250,800);
//		}
//		else if(ADC2_number >= 0 && ADC2_number <= 1848)
//		{
//			dianji2_kongzhi(down,250,800);
//		}
//		else if(ADC2_number < 2248 && ADC2_number > 1848)
//		{
//			dianji2_kongzhi(down,0,0);
//		}
/*
 *�涨up��˳ʱ�룬down����ʱ��
 */
		if(ADC1_number >= 3500 && ADC1_number <= 3650 && ADC2_number >= 1750 && ADC2_number <= 1870)//��
		{
			dianji1_kongzhi(up,700,800);//�м�ֵΪ�ٶȣ�ֵԽ���ٶ�ԽС
			dianji2_kongzhi(up,700,800);
		}
		else if(ADC1_number >= 1700 && ADC1_number <= 1800 && ADC2_number >= 3400 && ADC2_number <= 3650)//��
		{
			dianji1_kongzhi(down,700,800);
			dianji2_kongzhi(up,700,800);
		}
		else if(ADC1_number >= 1700 && ADC1_number <= 1800 && ADC2_number == 0)//��
		{
			dianji1_kongzhi(up,700,800);
			dianji2_kongzhi(down,700,800);
		}
		else if(ADC1_number == 0 && ADC2_number >= 1720 && ADC2_number <= 1850)//��
		{
			dianji1_kongzhi(down,700,800);
			dianji2_kongzhi(down,700,800);
		}
		else if(ADC1_number >= 1700 && ADC1_number <= 1800 && ADC2_number >= 1720 && ADC2_number <= 1850)//ֹͣ
		{
			dianji1_kongzhi(up,0,800);
			dianji2_kongzhi(down,0,800);
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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
