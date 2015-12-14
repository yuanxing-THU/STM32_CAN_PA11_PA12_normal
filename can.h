#ifndef CAN_H
#define CAN_H
#include "stm32f10x.h"					//���õĿ��ļ�
/*CAN*/
#define CAN_GPIO 								 GPIOA
#define CAN_CLK									 RCC_APB1Periph_CAN1
#define CAN_GPIO_CLK						 RCC_APB2Periph_GPIOA
#define CAN_RX									 GPIO_Pin_11
#define CAN_TX									 GPIO_Pin_12


void CAN_Configuration(void);							   
void CAN_SEND(uint8_t ID,int i,uint8_t* data);
void Init_RxMes(CanRxMsg *RxMessage);
void CAN_RECIEVE(void); 
#endif

