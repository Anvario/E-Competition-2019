
/*  key.c  */


#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"



u8 Key_Sta[4]={0};//������״̬


//������ʼ������
void Key_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(KEY0_RCC_CLK,ENABLE);//ʹ��PORTA,PORTEʱ��
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK,ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4
	
	GPIO_InitStructure.GPIO_Pin=KEY0_GPIO_PIN|KEY1_GPIO_PIN|KEY2_GPIO_PIN|KEY3_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_GPIO_PORT,&	GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEY4_GPIO_PIN|KEY5_GPIO_PIN|KEY6_GPIO_PIN|KEY7_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_GPIO_PORT,&	GPIO_InitStructure);
}


//������������������
//���ذ���ֵ
//0��û���κΰ�������
//1��KEY0����

//mode  ����,��㴫��һ��ֵ��OK
//
u8 Key_Scan(u8 mode)
{
	//key0
	if(Key_Sta[0]==0){
		if(KEY0_HARD_STA){
			delay_ms(10);
			if(KEY0_HARD_STA){
				Key_Sta[0]=1;
				return KEY0_PRES;
			}
		}
	}
	else{
		if(!(KEY0_HARD_STA)){
			Key_Sta[0]=0;
		}
	}
 	return 0;// �ް�������
}

//��ȡ�����ĵ�ǰ״̬
u8 Key_GetSta(u8 key){
	if(key<=3){
		return Key_Sta[key];
	}
	return 0;
}


int Read_KeyVal(void)//ʵ�־�����̡�����ֵΪ���������ļ�ֵ���˼�ֵ���û��Լ�����
{
	int KeyVal=0;  //keyValΪ��󷵻صļ�ֵ
  
	GPIO_Write(KEY_GPIO_PORT ,(KEY_GPIO_PORT ->ODR & 0xfff0 | 0xf)); //����PD0��PD3ȫ�������
	if((KEY_GPIO_PORT ->IDR & 0x00f0)==0x0000)  //�����PD4��PD7ȫΪ0����û�м����¡���ʱ������ֵΪ-1
	return -1;
	else 
	{
		delay_ms(100);//��ʱȥ����
		if((KEY_GPIO_PORT ->IDR & 0x00f0)==0x0000)  //�������ʱ5ms��PD4��PD7��ȫΪ0,�򣬸ղ����ŵĵ�λ�仯�Ƕ���������.
		return -1;
	}
	GPIO_Write(KEY_GPIO_PORT ,(KEY_GPIO_PORT ->ODR & 0xfff0 | 0x1)); //��PD3��PD0��������Ƶ�0001.
	switch(KEY_GPIO_PORT ->IDR & 0x00f0) //��PD4��PD7��ֵ�����ж�,�������ͬ�ļ�ֵ
	{
		case 0x0010: KeyVal=0x0D; break;
		case 0x0020: KeyVal=0x0C; break;
		case 0x0040: KeyVal=0x0B; break;
		case 0x0080: KeyVal=0x0A; break; 
	}
	GPIO_Write(KEY_GPIO_PORT ,(KEY_GPIO_PORT ->ODR & 0xfff0 | 0x2)); //��PD3��PD0��������Ƶ�0010. 
	switch(KEY_GPIO_PORT ->IDR & 0x00f0)//��PD4��PD7��ֵ�����ж�,�������ͬ�ļ�ֵ��
		{
		case 0x0010: KeyVal=0x0F; break;
		case 0x0020: KeyVal=0x09; break;
		case 0x0040: KeyVal=0x06; break; 
		case 0x0080: KeyVal=0x03; break;  
		} 
	GPIO_Write(KEY_GPIO_PORT ,(KEY_GPIO_PORT ->ODR & 0xfff0 | 0x4)); //��PD3��PD0��������Ƶ�0100. 
	switch(KEY_GPIO_PORT ->IDR & 0x00f0)//��PD4��PD7��ֵ�����жϣ��������ͬ�ļ�ֵ��	
	{
		case 0x0010: KeyVal=0x00; break;
		case 0x0020: KeyVal=0x08; break;
		case 0x0040: KeyVal=0x05; break;
		case 0x0080: KeyVal=0x02; break; 
	}
	GPIO_Write(KEY_GPIO_PORT ,(KEY_GPIO_PORT ->ODR & 0xfff0 | 0x8)); //��PD3��PD0��������Ƶ�1000. 
	switch(KEY_GPIO_PORT ->IDR & 0x00f0)//��PD4��PD7��ֵ�����жϣ��������ͬ�ļ�ֵ��
	{
		case 0x0010: KeyVal=0x0E; break;
		case 0x0020: KeyVal=0x07; break;
		case 0x0040: KeyVal=0x04; break;
		case 0x0080: KeyVal=0x01; break;
	}
	return KeyVal;
		
}







