#include "beep.h"
#include "delay.h"
void BEEP_Init(void)
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //LED0-->PA4 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA4
}

void BEEP(void)
{
	beep_pin=1;
}

void BEEP_stop(void)
{
	beep_pin=0;
}
