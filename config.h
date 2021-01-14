#ifndef _CONFIG_H
#define _CONFIG_H
/****************************************************************
 通用头文件
****************************************************************/
#include <reg52.h>
#include <intrins.h>

#define MAIN_Fosc		11059200UL	//宏定义主时钟HZ

/****************************************************************
已有数据类型重新定义
****************************************************************/
typedef signed char int8;  //8位有符号型
typedef signed int  int16; //16位有符号型
typedef unsigned char uint8;  //8位无符号型
typedef unsigned char uchar;  //8位无符号型
typedef unsigned int  uint16; //16位无符号型
typedef unsigned int  uint; //16位无符号型
typedef unsigned long uint32; //32位无符号型

/****************************************************************
 硬件接口定义
****************************************************************/

/*独立按键*/
sbit KEY_S2 = P3^0;	//S2独立按键
sbit KEY_S3 = P3^1;	//S3独立按键
sbit KEY_S4 = P3^2;	//S4独立按键
sbit KEY_S5 = P3^3;	//S5独立按键

/*LCD1602*/
#define LCD1602_DB  P0      //data bus 数据总线
sbit LCD1602_RS = P3^5;		//LCD1602液晶命令/数据选择引脚
sbit LCD1602_RW = P3^6;		//LCD1602液晶读/写选择引脚
sbit LCD1602_EN = P3^4;	 	//LCD1602液晶使能引脚

sbit BEEP = P2^3;
 
sbit led0=P1^0;
sbit led1=P1^1;
sbit led2=P1^2;
#endif