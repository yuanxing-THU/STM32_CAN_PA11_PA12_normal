/*
STM32F10X_MD CAN test 
by zyx 2015/12/13 
CAN USART2 TIM3  
*/
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"				
#include "stdio.h"
#include "rcc.h"
#include "CAN.h"
#include "USART.h"
#include "TIMER.h"

int fputc(int ch, FILE *f);
void TIM3_Handler(void); //TIM3外部中断

//CAN
CanRxMsg RxMessage;
int can_flag_receive = 0;
int flag_ask_status = 0;
/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int main(void)
{
	u32 i;
  RCC_Configuration();
	USART_Configuration();
	TIM_Congfiguration();
  CAN_Configuration();
	printf("Here is Modular Robot master!\r\n");
	TIM_Cmd(TIM3, ENABLE);
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);	 //开接收中断
	
	while(1)
	{
		if(flag_ask_status == 1)  //send data to CAN
		{
			uint8_t data = 0 ;
			CAN_SEND(0X00,1,&(data));
			flag_ask_status = 0;
		}
		
		if(can_flag_receive == 1) //revieved data from CAN
		{
			printf("Received !\r\n");
			can_flag_receive = 0;
		}
	}
}
void TIM3_Handler(void)
{
	flag_ask_status = 1;
	TIM_Cmd(TIM3, ENABLE);
}

int fputc(int ch, FILE *f)
{
    //USART_SendData(USART2, (uint8_t) ch);
    USART2->DR = (uint8_t) ch;
    //USART_SendData(USART2,(uint8_t)ch);
    /* Loop until the end of transmission */
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
    {
    }
    return ch;
}

