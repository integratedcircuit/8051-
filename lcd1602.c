#include "LCD1602.h"


void Read_Busy()           //忙检测函数，判断bit7是0，允许执行；1禁止
{
    unsigned char sta;      //
    LCD1602_DB = 0xff;
    LCD1602_RS = 0;
    LCD1602_RW = 1;
    do
    {
        LCD1602_EN = 1;
        sta = LCD1602_DB;
        LCD1602_EN = 0;    //使能，用完就拉低，释放总线
    }while(sta & 0x80);
}

void Lcd1602_Write_Cmd(unsigned char cmd)     //写命令
{
    Read_Busy();
    LCD1602_RS = 0;
    LCD1602_RW = 0;
    LCD1602_DB = cmd;
    LCD1602_EN = 1;
    LCD1602_EN = 0;    
}

void Lcd1602_Write_Data(unsigned char dat)   //写数据
{
      Read_Busy();
      LCD1602_RS = 1;
      LCD1602_RW = 0;
      LCD1602_DB = dat;
      LCD1602_EN = 1;
      LCD1602_EN = 0;
}

void LCD1602_Set_Cursor(uint8 x, uint8 y)  //坐标显示
{
	if(y) x |= 0x40;
	x |= 0x80;
	Lcd1602_Write_Cmd(x);

}
//*************************显示一个字节数据
void LCD1602_Dis_OneChar(uchar X,uchar Y,uchar DData)
{
 if(Y) X|=0X40;   //Y=1显示第二行，Y=0显示第一行
 X|=0X80;
 Lcd1602_Write_Cmd(X); //X用来选择哪一位
 Lcd1602_Write_Data(DData); //DData用来写数据
}
/*=================================================
*函数名称：LCD1602_Clear_Screen
*函数功能：清屏
=================================================*/
void LCD1602_Clear_Screen()
{
	Lcd1602_Write_Cmd(0x01);
}
/*=================================================
*函数名称：LCD1602_Open_Cursor
*函数功能：打开光标的闪烁效果
=================================================*/
void LCD1602_Open_Cursor()
{
	Lcd1602_Write_Cmd(0x0F);
}
/*=================================================
*函数名称：LCD1602_Close_Cursor
*函数功能：关闭光标显示
=================================================*/
void LCD1602_Close_Cursor()
{
	Lcd1602_Write_Cmd(0x0C);
}
//显示两个字符
void DisplayOneStr (uchar X,uchar Y,uchar DData)  //本函数自带BCD 转换
{
	LCD1602_Dis_OneChar (X++,Y,DData/16 + '0');
	LCD1602_Dis_OneChar (X,Y,DData%16 + '0');
}

void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str)     //显示字符串
{
    LCD1602_Set_Cursor(x,y);      //当前字符的坐标
    while(*str != '\0')
    {
        Lcd1602_Write_Data(*str++);
    }
}

void InitLcd1602(){              //1602初始化


    Lcd1602_Write_Cmd(0x38);    //打开，5*8,8位数据
    Lcd1602_Write_Cmd(0x0c);
    Lcd1602_Write_Cmd(0x06);
    Lcd1602_Write_Cmd(0x01);    //清屏
	
}
