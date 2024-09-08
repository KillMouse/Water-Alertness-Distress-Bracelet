#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART_REC_LEN  			200  	//定义最大接收字节数 200
	
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	

extern u8  USART3_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART3_RX_STA;         		//接收状态标记	

extern u8  USART2_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART2_RX_STA;         		//接收状态标记	

extern double longitude, latitude;
extern char name[50];
extern char phone[15];
extern char ID[5];
//如果想串口中断接收，请不要注释以下宏定义
void uart1_init(u32 bound);
void uart3_init(u32 bound);
void uart2_init(u32 bound);
void usartSendByte(USART_TypeDef* USARTx, uint16_t Data);
void usartSendStr(USART_TypeDef* USARTx,char *str);
void removeSpaces(char* str);

#endif
