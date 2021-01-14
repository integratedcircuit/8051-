#include "LCD1602.h"


void Read_Busy()           //æ��⺯�����ж�bit7��0������ִ�У�1��ֹ
{
    unsigned char sta;      //
    LCD1602_DB = 0xff;
    LCD1602_RS = 0;
    LCD1602_RW = 1;
    do
    {
        LCD1602_EN = 1;
        sta = LCD1602_DB;
        LCD1602_EN = 0;    //ʹ�ܣ���������ͣ��ͷ�����
    }while(sta & 0x80);
}

void Lcd1602_Write_Cmd(unsigned char cmd)     //д����
{
    Read_Busy();
    LCD1602_RS = 0;
    LCD1602_RW = 0;
    LCD1602_DB = cmd;
    LCD1602_EN = 1;
    LCD1602_EN = 0;    
}

void Lcd1602_Write_Data(unsigned char dat)   //д����
{
      Read_Busy();
      LCD1602_RS = 1;
      LCD1602_RW = 0;
      LCD1602_DB = dat;
      LCD1602_EN = 1;
      LCD1602_EN = 0;
}

void LCD1602_Set_Cursor(uint8 x, uint8 y)  //������ʾ
{
	if(y) x |= 0x40;
	x |= 0x80;
	Lcd1602_Write_Cmd(x);

}
//*************************��ʾһ���ֽ�����
void LCD1602_Dis_OneChar(uchar X,uchar Y,uchar DData)
{
 if(Y) X|=0X40;   //Y=1��ʾ�ڶ��У�Y=0��ʾ��һ��
 X|=0X80;
 Lcd1602_Write_Cmd(X); //X����ѡ����һλ
 Lcd1602_Write_Data(DData); //DData����д����
}
/*=================================================
*�������ƣ�LCD1602_Clear_Screen
*�������ܣ�����
=================================================*/
void LCD1602_Clear_Screen()
{
	Lcd1602_Write_Cmd(0x01);
}
/*=================================================
*�������ƣ�LCD1602_Open_Cursor
*�������ܣ��򿪹�����˸Ч��
=================================================*/
void LCD1602_Open_Cursor()
{
	Lcd1602_Write_Cmd(0x0F);
}
/*=================================================
*�������ƣ�LCD1602_Close_Cursor
*�������ܣ��رչ����ʾ
=================================================*/
void LCD1602_Close_Cursor()
{
	Lcd1602_Write_Cmd(0x0C);
}
//��ʾ�����ַ�
void DisplayOneStr (uchar X,uchar Y,uchar DData)  //�������Դ�BCD ת��
{
	LCD1602_Dis_OneChar (X++,Y,DData/16 + '0');
	LCD1602_Dis_OneChar (X,Y,DData%16 + '0');
}

void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str)     //��ʾ�ַ���
{
    LCD1602_Set_Cursor(x,y);      //��ǰ�ַ�������
    while(*str != '\0')
    {
        Lcd1602_Write_Data(*str++);
    }
}

void InitLcd1602(){              //1602��ʼ��


    Lcd1602_Write_Cmd(0x38);    //�򿪣�5*8,8λ����
    Lcd1602_Write_Cmd(0x0c);
    Lcd1602_Write_Cmd(0x06);
    Lcd1602_Write_Cmd(0x01);    //����
	
}
