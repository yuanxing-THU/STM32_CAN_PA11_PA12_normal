#include "rcc.h"
void RCC_Configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | \
			RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD,\
                           ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);	  //ʹ����APB1ʱ�ӿ��Ƶ������е�CAN1�˿�
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	
 
}