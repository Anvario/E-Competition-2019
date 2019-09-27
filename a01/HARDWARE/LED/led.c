#include "led.h"



//��ʼ��LED0��LED1Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
	
 RCC_APB2PeriphClockCmd(LED0_GPIO_RCC_CLK|LED1_GPIO_RCC_CLK, ENABLE);	 //ʹ��PB,PE�˿�ʱ��

 GPIO_InitStructure.GPIO_Pin = LED0_PIN;				       //LED0�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(LED0_GPIO, &GPIO_InitStructure);					   //�����趨������ʼ��LED0
 GPIO_SetBits(LED0_GPIO,LED0_PIN);						         //LED0�����

 GPIO_InitStructure.GPIO_Pin = LED1_PIN;	    		     //LED1�˿�����, �������
 GPIO_Init(LED1_GPIO, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(LED1_GPIO,LED1_PIN); 						         //LED1����� 
}
 
