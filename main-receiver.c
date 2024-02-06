//PRAJWAL GOWDA RAMPURA SURESH
//1002064165
//Receiver side

#include<stdio.h>
#include<string.h>
#include<stm32f407xx.h>

#define RS 0x0001 //Masking for PC0 LCD R/S
#define RW 0x0002 //Masking for PC1 LCD R/W
#define EN 0x0004 //Masking for PC2 LCD EN

uint32_t * const pRccRegPortEnable = (uint32_t*)0x40023830; //Setting the RCC Register for Port Enable

uint32_t * const pPortDModeReg = (uint32_t*)0x40020C00; //Setting the Port D Mode Register
uint32_t * const pPortCModeReg = (uint32_t*)0x40020800; //Setting the Port C Mode Register

uint32_t * const pPortDDataReg = (uint32_t*)0x40020C14; //Setting the Port D Data Output Register
uint32_t * const pPortCDataReg = (uint32_t*)0x40020814; //Setting the Port C Data Output Register

void delayMs(uint32_t n);
void LCD_data(char data);
void LCD_init(void);
void PORTS_init(void);

char data[128];

USART_Handle_t usart2_handle;

void USART2_Init(void)
{
	usart2_handle.pUSARTx = USART2;
	usart2_handle.USART_Config.USART_Baud = USART_STD_BAUD_1200;
	usart2_handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	usart2_handle.USART_Config.USART_Mode = USART_MODE_TXRX;
	usart2_handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	usart2_handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	usart2_handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	USART_Init(&usart2_handle);
}

void USART2_GPIOInit(void)
{
	GPIO_Handle_t Usart_Gpios;

	//USART2 Transmitter
	Usart_Gpios.pGPIOx = GPIOA;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
	GPIO_Init(&Usart_Gpios);

	//USART2 Receiver
	Usart_Gpios.pGPIOx = GPIOA;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Usart_Gpios.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
	GPIO_Init(&Usart_Gpios);
}

void delay(void)
{
	for(uint32_t i; i<900000; i++); // to delay
}

int main(void)
{
	char data[128];

	GPIO_PeriClockControl(GPIOA, ENABLE);
	PORTS_Init();
	LCD_Init();
	delayMs(100);

	USART2_GPIOInit();

	USART2_Init();

	USART_PeripheralControl(USART2, ENABLE);

	while(1)
	{
		USART_ReceiveData(&usart2_handle, (uint8_t*)data, 1);
		LCD_Data((uint8_t)*data);
		delayMs(200);
	}

	return 0;

}
