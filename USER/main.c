#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "string.h"
#include "beep.h"
//ALIENTEK Mini STM32�����巶������3
//����ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾


/*
http���͵����ݸ�ʽ�����ã���ΪMQTT
#define POST \
	"POST /send HTTP/1.1\r\n"\
	"Host: 47.109.149.102:5000\r\n"\
	"Content-Type: application/x-www-form-urlencoded\r\n"\
	"Content-Length:54\r\n\r\n"\
	"ID=1&GPS_latitude=%.7lf&GPS_longitude=%.7lf"
   
*/
#define Get_GPS \
	"config,get,lbsloc\r\n"
	
/*MQTT�������ݸ�ʽ*/
/*	{"ID":_,"name":_,"phone":_,"GPS_latitude":_,"GPS_longitude":_}	*/

#define MQTT_send\
	"{\"ID\":\"%s\",\"name\":\"%s\",\"phone\":\"%s\",\"GPS_latitude\":%.7f,\"GPS_longitude\":%.7f}"


 int main(void)
 {	
	char  send_GPS[100];								//����POST����
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart1_init(115200);	 //����1��ʼ��Ϊ115200     ���Դ���
	uart2_init(115200);	 //����2��ʼ��Ϊ115200	   GPS+MQTT����
	uart3_init(115200);	 //����3��ʼ��Ϊ115200	   
	BEEP_Init();		 //��������ʼ��	
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
	LED0=0;
/*...............................................................................................................*/
/*���ܣ��ж��Ƿ�ע�ἴ��������û����Ӧ��Ϣ      �˴�ӦΪ��ȡ�ڲ�flash���ݣ��ڽ��յ��û���Ϣ�󣬽��û���Ϣ�����ڲ�flash�У�����ʱ��ԭ�����*/
	while(1)			
	{
		 if(strcmp(name,"")|| strcmp(phone,"")||strcmp(ID,""))
		 {	
			 printf("ID=%s,name=%s,phone=%s\r\n",ID,name,phone); 
			 break;
		 }
		 LED0=~LED0;
		 delay_ms(500);
	}
/*................................................................................................................*/
	
	LED0=1;
	
	
/******************************************************************************************************************	
	LED0=1;
	delay_ms(500);
	usartSendStr(USART2,Get_GPS);			//��ȡ��λ
	delay_ms(1000);
	printf("latitude=%.7f,GPS_longitude=%.7f",latitude,longitude);
	
	sprintf(send_GPS,MQTT_send,ID,name,phone,latitude,longitude);
	usartSendStr(USART2,send_GPS);			//���Ͷ�λ
	printf("%s\r\n",send_GPS);
******************************************************************************************************************/	
	while(1)
	{
		 LED1=~LED1;
		delay_ms(500);
	}
}

