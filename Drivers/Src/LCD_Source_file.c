/*
 * LCD_Source_file.c
 *
 *  Created on: Nov 20, 2022
 *      Author: praju
 */
#include "LCD_Header_file.h"

void delayMs(uint32_t n)
{
	uint32_t i;
	for(; n>0;n--)
		for(i = 0;i<3195;i++);
}

void LCD_Data(char data)
{
	//Register Select is set to 1 (Select data Register Allows User to send Data)
	GPIO_WriteToOutputPin(GPIOC, 0, 1);

	//R/W Allows user to read or write to LCD for Reading 1 for writing 0
	GPIO_WriteToOutputPin(GPIOC, 1, 0);

	//Calls the Character to ascii value converter function
	Char_to_Binary(data);

	//Setting Enable pin to High
	GPIO_WriteToOutputPin(GPIOC, 2, 1);

	delayMs(10);

	//Enable Pin to Low
	GPIO_WriteToOutputPin(GPIOC, 2, 0);

	delayMs(20);
}


void LCD_Init()
{
	//Ports Initialization
	PORTS_Init();

	//Clear Desplay Screen
	LCD_command(0x1);

	//Mode 2 lines
	LCD_command(0x38);

	//Display On And Cursor Blinking
	LCD_command(0xF);

	//Force Cursor to Begining of first Line
	LCD_command(0x80);
}


void PORTS_Init()
{
	//RCC Clock Enable for PORT D and PORT C
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_PeriClockControl(GPIOC, ENABLE);


	//Data Ports from DB0 to DB7

	GPIO_Handle_t gpioPD0;
	gpioPD0.pGPIOx = GPIOD;
	gpioPD0.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	gpioPD0.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD0.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD0.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD0.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD1;
	gpioPD1.pGPIOx = GPIOD;
	gpioPD1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	gpioPD1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD1.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD2;
	gpioPD2.pGPIOx = GPIOD;
	gpioPD2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	gpioPD2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD2.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD3;
	gpioPD3.pGPIOx = GPIOD;
	gpioPD3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	gpioPD3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD3.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD3.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD4;
	gpioPD4.pGPIOx = GPIOD;
	gpioPD4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4;
	gpioPD4.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD4.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD4.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD4.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD5;
	gpioPD5.pGPIOx = GPIOD;
	gpioPD5.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpioPD5.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD5.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD5.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD5.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD6;
	gpioPD6.pGPIOx = GPIOD;
	gpioPD6.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	gpioPD6.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD6.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD6.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD6.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPD7;
	gpioPD7.pGPIOx = GPIOD;
	gpioPD7.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
	gpioPD7.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPD7.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPD7.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPD7.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	//Ports for Register Select,Read/Write,Enable

	GPIO_Handle_t gpioPC0;
	gpioPC0.pGPIOx = GPIOC;
	gpioPC0.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	gpioPC0.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPC0.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPC0.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPC0.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPC1;
	gpioPC1.pGPIOx = GPIOC;
	gpioPC1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
	gpioPC1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPC1.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPC1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPC1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Handle_t gpioPC2;
	gpioPC2.pGPIOx = GPIOC;
	gpioPC2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	gpioPC2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioPC2.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
	gpioPC2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	gpioPC2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;

	GPIO_Init(&gpioPD0);
	GPIO_Init(&gpioPD1);
	GPIO_Init(&gpioPD2);
	GPIO_Init(&gpioPD3);
	GPIO_Init(&gpioPD4);
	GPIO_Init(&gpioPD5);
	GPIO_Init(&gpioPD6);
	GPIO_Init(&gpioPD7);

	GPIO_Init(&gpioPC0);
	GPIO_Init(&gpioPC1);
	GPIO_Init(&gpioPC2);

}


void LCD_command(unsigned char data)
{

	//Select Command Register RS = 0
	GPIO_WriteToOutputPin(GPIOC, 0, 0);

	//Clear Display Screen
	if(data == 0x1)
	{
		GPIO_WriteToOutputPin(GPIOD, 0, 1);
		GPIO_WriteToOutputPin(GPIOD, 1, 0);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 3, 0);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
	}

	//Return Cursor Home
	if(data == 0x2)
	{
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 1);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 3, 0);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
	}

	//Increment Cursor (shift Cursor to right)
	if(data == 0x6)
	{
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 1);
		GPIO_WriteToOutputPin(GPIOD, 2, 1);
		GPIO_WriteToOutputPin(GPIOD, 3, 0);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
	}

	//Display On Cursor Blinking

	if(data == 0xF)
	{
		GPIO_WriteToOutputPin(GPIOD, 0, 1);
		GPIO_WriteToOutputPin(GPIOD, 1, 1);
		GPIO_WriteToOutputPin(GPIOD, 2, 1);
		GPIO_WriteToOutputPin(GPIOD, 3, 1);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
	}

	//Force Cursor to Beginning of first Line

	if(data == 0x80)
	{
		GPIO_WriteToOutputPin(GPIOD, 7, 1);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 0);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 3, 0);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 0);
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
	}

	//Force Cursor to Beginning of Second Line

	if(data == 0xC0)
	{
		GPIO_WriteToOutputPin(GPIOD, 7, 1);
		GPIO_WriteToOutputPin(GPIOD, 6, 1);
		GPIO_WriteToOutputPin(GPIOD, 5, 0);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 3, 0);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 0);
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
	}

	//Mode : 2 Lines and 5*7 Characters (8-Bit data)

	if(data == 0x38)
	{
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 1);
		GPIO_WriteToOutputPin(GPIOD, 4, 1);
		GPIO_WriteToOutputPin(GPIOD, 3, 1);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 0);
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
	}

	//Mode : 2 Lines and 5*7 Characters (4-Bit Data)

	if(data == 0x28)
	{
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 1);
		GPIO_WriteToOutputPin(GPIOD, 4, 0);
		GPIO_WriteToOutputPin(GPIOD, 3, 1);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 0);
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
	}

	//Initialization Command

	if(data == 0x30)
	{
		GPIO_WriteToOutputPin(GPIOD, 7, 0);
		GPIO_WriteToOutputPin(GPIOD, 6, 0);
		GPIO_WriteToOutputPin(GPIOD, 5, 1);
		GPIO_WriteToOutputPin(GPIOD, 4, 1);
		GPIO_WriteToOutputPin(GPIOD, 3, 0);
		GPIO_WriteToOutputPin(GPIOD, 2, 0);
		GPIO_WriteToOutputPin(GPIOD, 1, 0);
		GPIO_WriteToOutputPin(GPIOD, 0, 0);
	}

	//Setting Enable Pin High
	GPIO_WriteToOutputPin(GPIOC, 2, 1);

	//Delay for 10 ms
	delayMs(10);

	//Enable Pin to Low
	GPIO_WriteToOutputPin(GPIOC, 2, 0);

	//Delay for 20 ms
	delayMs(20);

}

//Function to convert Character to Binary

void Char_to_Binary(char data)
{
	int bin;
	char ch = data;
	for (uint32_t i = 0; i < 8; i++)
	{
		bin = ((ch << i) & 0x80) ? 1 : 0;
		GPIO_WriteToOutputPin(GPIOD, (7-i), bin);
		bin = 0;
	}
}





