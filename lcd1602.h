#ifndef __LCD_H_
#define __LCD_H_
#include <reg52.h>

#include "config.h"

/**********************************
��������
**********************************/

void Read_Busy();           //æ��⺯�����ж�bit7��0������ִ�У�1��ֹ
void Lcd1602_Write_Cmd(unsigned char cmd);     //д����
void Lcd1602_Write_Data(unsigned char dat);   //д����
void LCD1602_Set_Cursor(uint8 x, uint8 y);  //������ʾ
void LCD1602_Dis_OneChar(uchar X,uchar Y,uchar DData); // дһ���ֽ�
void DisplayOneStr (uchar X,uchar Y,uchar DData);//��ʾһ���ֽ��ַ�
void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str);     //��ʾ�ַ���
void InitLcd1602();              //1602��ʼ��
//��ӵ��º���

void LCD1602_Close_Cursor();//LCD1602�رչ����ʾ
void LCD1602_Open_Cursor();	//LCD1602�򿪹����ʾ
void LCD1602_Clear_Screen();//LCD1602����					  
void boot_Screen();

#endif
