#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART_REC_LEN  			200  	//�����������ֽ��� 200
	
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	

extern u8  USART3_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART3_RX_STA;         		//����״̬���	

extern u8  USART2_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART2_RX_STA;         		//����״̬���	

extern double longitude, latitude;
extern char name[50];
extern char phone[15];
extern char ID[5];
//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart1_init(u32 bound);
void uart3_init(u32 bound);
void uart2_init(u32 bound);
void usartSendByte(USART_TypeDef* USARTx, uint16_t Data);
void usartSendStr(USART_TypeDef* USARTx,char *str);
void removeSpaces(char* str);

#endif
