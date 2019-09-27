/*  beep.c  */

#include "beep.h"

void Beep_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
	
 RCC_APB2PeriphClockCmd(BEEP_GPIO_RCC_CLK, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
  
  BEEP_OFF();
  
 GPIO_InitStructure.GPIO_Pin = BEEP_PIN;				       //LED0�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(BEEP_GPIO, &GPIO_InitStructure);					   //�����趨������ʼ��LED0
 //GPIO_SetBits(BEEP_GPIO,BEEP_PIN);						         //LED0�����
}
 
