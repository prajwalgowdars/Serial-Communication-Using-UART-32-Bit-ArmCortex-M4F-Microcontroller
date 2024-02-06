//PRAJWAL GOWDA RAMPURA SURESH
//1002064165
//Transmitter side

#include <stdio.h>
#include <stdint.h>
#include <stm32f407xx.h>

char data[1];

void GPIO_PORT_Init();
void USART2_GPIOInit();
void USART2_Init();
void delay();
USART_Handle_t usart2_handle;

void USART2_Init()
{
	usart2_handle.pUSARTx = USART2;
	usart2_handle.USART_Config.USART_Baud = USART_STD_BAUD_1200;
	usart2_handle.USART_Config.USART_Mode = USART_MODE_TXRX;
	usart2_handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	usart2_handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	usart2_handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	usart2_handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	USART_Init(&usart2_handle);
}

void USART2_GPIOInit()
{
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Handle_t usart_gpios;
	usart_gpios.pGPIOx = GPIOA;
	usart_gpios.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	usart_gpios.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	usart_gpios.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	usart_gpios.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	usart_gpios.GPIO_PinConfig.GPIO_PinAltFunMode = 7;

	//For Transmission
	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GPIO_Init(&usart_gpios);

	//For Receiver
	usart_gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	GPIO_Init(&usart_gpios);
}

void GPIO_PORT_Init()
{

	GPIO_PeriClockControl(GPIOD, ENABLE);

	//Orange Led GPIO pin 13 configuration

	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	//GPIO Pin configurations for PD0, PD1, PD2 and PD3 as outputs which are connected to R1, R2, R3 and R4 of keypad respectively.

	GPIO_Handle_t GpioPortD0;
	GpioPortD0.pGPIOx = GPIOD;
	GpioPortD0.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioPortD0.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD0.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioPortD0.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD0.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;

	GPIO_Handle_t GpioPortD1;
	GpioPortD1.pGPIOx = GPIOD;
	GpioPortD1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioPortD1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioPortD1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;

	GPIO_Handle_t GpioPortD2;
	GpioPortD2.pGPIOx = GPIOD;
	GpioPortD2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioPortD2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioPortD2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;

	GPIO_Handle_t GpioPortD3;
	GpioPortD3.pGPIOx = GPIOD;
	GpioPortD3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioPortD3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD3.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioPortD3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;

	//GPIO Pin configurations for PD8, PD9, PD10 and PD11 as inputs(pull-up) which are connected to C1, C2, C3 and C4 of keypad respectively.

	GPIO_Handle_t GpioPortD8;
	GpioPortD8.pGPIOx = GPIOD;
	GpioPortD8.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioPortD8.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD8.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GpioPortD8.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD8.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;

	GPIO_Handle_t GpioPortD9;
	GpioPortD9.pGPIOx = GPIOD;
	GpioPortD9.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioPortD9.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD9.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GpioPortD9.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD9.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_9;

	GPIO_Handle_t GpioPortD10;
	GpioPortD10.pGPIOx = GPIOD;
	GpioPortD10.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioPortD10.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD10.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GpioPortD10.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD10.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_10;

	GPIO_Handle_t GpioPortD11;
	GpioPortD11.pGPIOx = GPIOD;
	GpioPortD11.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioPortD11.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioPortD11.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GpioPortD11.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioPortD11.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_11;

	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioPortD0);
	GPIO_Init(&GpioPortD1);
	GPIO_Init(&GpioPortD2);
	GPIO_Init(&GpioPortD3);
	GPIO_Init(&GpioPortD8);
	GPIO_Init(&GpioPortD9);
	GPIO_Init(&GpioPortD10);
	GPIO_Init(&GpioPortD11);
}

void delay()
{
	for(uint32_t i = 0; i < 900000; i++);
}

int main(void)
{
	uint8_t data1[1];
	USART2_Init();
	USART2_GPIOInit();
	GPIO_PORT_Init();
	USART_PeriClockControl(USART2, ENABLE);
	while(1)
	{

		//Make all rows High

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_0, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_1, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_2, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_3, SET);

		//Make R1 low

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_0, RESET);

		//Scan for C1 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_8)))
		{
			delay();
			data[0] = '1';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scanning for C2 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_9)))
		{
			delay();
			data[0] = '2';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C3 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_10)))
		{
			delay();
			data[0] = '3';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C4 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_11)))
		{
			delay();
			data[0] = 'A';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Make All rows High

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_0, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_1, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_2, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_3, SET);

		//Make R2 Row Low

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_1, RESET);

		//Scan for C1 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_8)))
		{
			delay();
			data[0] = '4';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C2 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_9)))
		{
			delay();
			data[0] = '5';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C3 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_10)))
		{
			delay();
			data[0] = '6';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C4 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_11)))
		{
			delay();
			data[0] = 'B';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Make All rows High

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_0, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_1, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_2, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_3, SET);

		//Make R3 Row Low

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_2, RESET);

		//Scan for C1 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_8)))
		{
			delay();
			data[0] = '7';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C2 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_9)))
		{
			delay();
			data[0] = '8';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C3 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_10)))
		{
			delay();
			data[0] = '9';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C4 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_11)))
		{
			delay();
			data[0] = 'C';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Make All rows High

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_0, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_1, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_2, SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_3, SET);

		//Make R3 Row Low
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_3, RESET);

		//Scan for C1 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_8)))
		{
			delay();
			data[0] = '*';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C2 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_9)))
		{
			delay();
			data[0] = '0';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C3 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_10)))
		{
			delay();
			data[0] = '#';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}

		//Scan for C4 Column

		if(!(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_11)))
		{
			delay();
			data[0] = 'D';
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
			data1[0] = data[0];
			USART_SendData(&usart2_handle, (uint8_t*)data1, 1);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}
	}
}

