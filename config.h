#ifndef _CONFIG_H
#define _CONFIG_H
/****************************************************************
 ͨ��ͷ�ļ�
****************************************************************/
#include <reg52.h>
#include <intrins.h>

#define MAIN_Fosc		11059200UL	//�궨����ʱ��HZ

/****************************************************************
���������������¶���
****************************************************************/
typedef signed char int8;  //8λ�з�����
typedef signed int  int16; //16λ�з�����
typedef unsigned char uint8;  //8λ�޷�����
typedef unsigned char uchar;  //8λ�޷�����
typedef unsigned int  uint16; //16λ�޷�����
typedef unsigned int  uint; //16λ�޷�����
typedef unsigned long uint32; //32λ�޷�����

/****************************************************************
 Ӳ���ӿڶ���
****************************************************************/

/*��������*/
sbit KEY_S2 = P3^0;	//S2��������
sbit KEY_S3 = P3^1;	//S3��������
sbit KEY_S4 = P3^2;	//S4��������
sbit KEY_S5 = P3^3;	//S5��������

/*LCD1602*/
#define LCD1602_DB  P0      //data bus ��������
sbit LCD1602_RS = P3^5;		//LCD1602Һ������/����ѡ������
sbit LCD1602_RW = P3^6;		//LCD1602Һ����/дѡ������
sbit LCD1602_EN = P3^4;	 	//LCD1602Һ��ʹ������

sbit BEEP = P2^3;
 
sbit led0=P1^0;
sbit led1=P1^1;
sbit led2=P1^2;
#endif