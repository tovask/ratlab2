#include "UART.h"
#include "I2C.h"
#include "SPI.h"
#include "SwitchButton.h"
#include "GLCD.h"
#include "TemperatureSensor.h"
#include "AccelerationSensor.h"
#include "UartCommandSensor.h"
#include "AlertSensor.h"
#include "SwitchSensor.h"
#include "SensorPoller.h"
#include "TopLevelView.h"
#include "SwitchingView.h"
#include "DebugView.h"
#include "NiceView.h"
#include "UartCommandHandler.h"
#include "Log.h"
#include "Misc.h"

extern "C" {
#include "stm32f4xx_hal.h"
}

static void SystemClock_Config(void);

int main()
{
	HAL_Init();
	/* Configure the system clock to 168 MHz */
	SystemClock_Config();
	Misc::GetInstance().Init();
	UART uart;
	Log::GetInstance().Init(uart);

	SwitchButton viewModeSwitch(SwitchButton::Instances::ViewMode);
	SwitchSensor viewModeSwitchSensor(viewModeSwitch);

	SwitchButton flameSwitch(SwitchButton::Instances::Flame);
	SwitchSensor flameSwitchSensor(flameSwitch);

	I2C i2c(0xA0);
	TemperatureSensor temperatureSensor(i2c);

	SPI spi;
	AccelerationSensor accelerationSensor(spi);

	AlertSensor alertSensor(temperatureSensor, accelerationSensor);

	UartCommandHandler commandHandler(alertSensor,temperatureSensor);
	UartCommandSensor uartCommandSensor(uart, &commandHandler);

	SensorPoller poller;
	poller.Add(temperatureSensor);
	poller.Add(accelerationSensor);
	poller.Add(uartCommandSensor);
	poller.Add(viewModeSwitchSensor);
	poller.Add(flameSwitchSensor);
	poller.Add(alertSensor);

	// Nezetek letrehozasa. A TopLevelView a legfelsobb szintu.
	//	Minden tovabbi a konstruktor utolso parameterekent megkapja a szulojet,
	//	ahova regisztralja is magat.
	GLCD glcd;
	TopLevelView topLevelView(glcd);
	SwitchingView switchingView(viewModeSwitchSensor, &topLevelView);
	NiceView niceView(temperatureSensor, accelerationSensor, flameSwitchSensor,alertSensor, &switchingView);
	DebugView debugView(temperatureSensor, accelerationSensor, uartCommandSensor,alertSensor, &switchingView);

	LOG << "*****      Robotiranyitas Rendszertechnikaja Labor      *****\n\r";
	LOG << "***** Alkalmazasfejlesztes: C++ beagyazott kornyezetben *****\n\r";
	topLevelView.Redraw();
	while(1)
	{
		poller.PollAll();
		topLevelView.RedrawIfNeeded();
	}
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_StatusTypeDef result = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  assert_param(result == HAL_OK);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  result = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
  assert_param(result == HAL_OK);

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
}

void assert_failed(uint8_t* file, uint32_t line)
{
	while(1);
}
