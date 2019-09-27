/*  key.h  */

#ifndef __KEY_H
#define __KEY_H
#include "sys.h"


//��������
#define KEY0  0


//key0 PB12   yuanlaiPE4



/********************* ��������GPIO�ں궨�� ***************************/
#define KEY0_GPIO GPIOB
#define KEY0_PIN GPIO_Pin_12
/****************************** end *********************************/


/********************* ��������GPIO��ʱ�Ӻ궨�� *********************/
#define KEY0_RCC_CLK  RCC_APB2Periph_GPIOB
/****************************** end *********************************/



/********************* ����Ӳ��״̬��ȡ�궨�� ***********************/
#define KEY0_HARD_STA  ((KEY0_GPIO->IDR & (uint16_t)KEY0_PIN)==0)
/****************************** end *********************************/

 
 
/********************* �������·���ֵ�궨�� *************************/
#define KEY0_PRES 	1	//KEY0����
/****************************** end *********************************/



/********************* ������������ *********************************/

void Key_Init(void);   //IO��ʼ��
u8 Key_Scan(u8);  	   //����ɨ�躯��
u8 Key_GetSta(u8 key); //������ǰ״̬��ȡ  1:�ѱ�����  0:δ������


/****************************** end *********************************/



#define KEY_ON  1
#define KEY_OFF 0

#define KEY0_GPIO_PIN GPIO_Pin_0
#define KEY1_GPIO_PIN GPIO_Pin_1
#define KEY2_GPIO_PIN GPIO_Pin_2
#define KEY3_GPIO_PIN GPIO_Pin_3
#define KEY4_GPIO_PIN GPIO_Pin_4
#define KEY5_GPIO_PIN GPIO_Pin_5
#define KEY6_GPIO_PIN GPIO_Pin_6
#define KEY7_GPIO_PIN GPIO_Pin_7

#define KEY_GPIO_PORT  GPIOC
#define KEY_GPIO_CLK   RCC_APB2Periph_GPIOC

void KEY_GPIO_InitStruct(void);
int Read_KeyVal(void);










#endif











