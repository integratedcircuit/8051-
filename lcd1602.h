#ifndef __LCD_H_
#define __LCD_H_
#include <reg52.h>

#include "config.h"

/**********************************
函数声明
**********************************/

void Read_Busy();           //忙检测函数，判断bit7是0，允许执行；1禁止
void Lcd1602_Write_Cmd(unsigned char cmd);     //写命令
void Lcd1602_Write_Data(unsigned char dat);   //写数据
void LCD1602_Set_Cursor(uint8 x, uint8 y);  //坐标显示
void LCD1602_Dis_OneChar(uchar X,uchar Y,uchar DData); // 写一个字节
void DisplayOneStr (uchar X,uchar Y,uchar DData);//显示一个字节字符
void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str);     //显示字符串
void InitLcd1602();              //1602初始化
//添加的新函数

void LCD1602_Close_Cursor();//LCD1602关闭光标显示
void LCD1602_Open_Cursor();	//LCD1602打开光标显示
void LCD1602_Clear_Screen();//LCD1602清屏					  
void boot_Screen();

#endif
