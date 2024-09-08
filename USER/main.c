#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "string.h"
#include "beep.h"
//ALIENTEK Mini STM32开发板范例代码3
//串口实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司


/*
http发送的数据格式，弃用，改为MQTT
#define POST \
	"POST /send HTTP/1.1\r\n"\
	"Host: 47.109.149.102:5000\r\n"\
	"Content-Type: application/x-www-form-urlencoded\r\n"\
	"Content-Length:54\r\n\r\n"\
	"ID=1&GPS_latitude=%.7lf&GPS_longitude=%.7lf"
   
*/
#define Get_GPS \
	"config,get,lbsloc\r\n"
	
/*MQTT发送数据格式*/
/*	{"ID":_,"name":_,"phone":_,"GPS_latitude":_,"GPS_longitude":_}	*/

#define MQTT_send\
	"{\"ID\":\"%s\",\"name\":\"%s\",\"phone\":\"%s\",\"GPS_latitude\":%.7f,\"GPS_longitude\":%.7f}"


 int main(void)
 {	
	char  send_GPS[100];								//发送POST请求
	delay_init();	    	 //延时函数初始化	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	uart1_init(115200);	 //串口1初始化为115200     调试串口
	uart2_init(115200);	 //串口2初始化为115200	   GPS+MQTT串口
	uart3_init(115200);	 //串口3初始化为115200	   
	BEEP_Init();		 //蜂鸣器初始化	
	LED_Init();		  	 //初始化与LED连接的硬件接口 
	LED0=0;
/*...............................................................................................................*/
/*功能：判断是否注册即板子中有没有相应信息      此处应为读取内部flash数据（在接收到用户信息后，将用户信息存在内部flash中），因时间原因放弃*/
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
	usartSendStr(USART2,Get_GPS);			//获取定位
	delay_ms(1000);
	printf("latitude=%.7f,GPS_longitude=%.7f",latitude,longitude);
	
	sprintf(send_GPS,MQTT_send,ID,name,phone,latitude,longitude);
	usartSendStr(USART2,send_GPS);			//发送定位
	printf("%s\r\n",send_GPS);
******************************************************************************************************************/	
	while(1)
	{
		 LED1=~LED1;
		delay_ms(500);
	}
}

