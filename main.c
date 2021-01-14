
/****************************

ǰ�ԣ�
		������Ϊ����˼�������ⶨʱ�������ð�������
		Ŀ��ʱ���Ѷ��ֻ�Timer��������
		��·ͼ��Proteus������ƣ������·�������������ӵ���������
		��ӭ��Ҷ��Ҵ��벻���Ƶĵط�����ָ��,����32������С���Ҳ�ɲο��ҵĴ���ܹ�
		���ʣ�Ϊʲô��д32�ĳ���ֱ���ú������32�����𣿴��ҵ�oled����С�����Ų��������32������ûbeep��
		��������ʱ��Ļ�����AD���Ƶ�·�壬��ʱ���������Я����:)

        ��Դ���зḻע�͡�
		��Ѽ���Ϳ��е����ͣ�

����˵����
         
		 ϵͳ�ϵ����п�����ʾ��Uncompromising����ζ���������Լ��������и����������Э����
		 �������治���Զ���ʧ
		 ����s3��ʱ���Ϲ�����s3��ʱ���¹������Խ���ѡ��ʱʱ��
		 ����s2 ��ʼ��ʱ/��ֹ��ʱ
		 ����s5 ����ѡ��ʱʱ��״̬��ע��:ֻ���ڼ�ʱ��ֹʱ������Ч��

  					���ߣ�Leon
  					ʱ�䣺2021/1/14
  					��λ��Hefei University of Technology


*****************************/
#include "main.h"
#include "LCD1602.h"
#include "Key.h"
#include "display.h"
#include "config.h"
/****************************
  ���ݳ�
*****************************/
uchar display[] =  {0x00,0x00,0x00,0x00,0x00,0x00,0x00};  //���ڿ�ʼ����40min�������ݳظ�Ϊ39��50��00��ʼ��ʱ
uchar display2[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/****************************
  flag
*****************************/
#define flag_3min  0x03
#define flag_7min  0x07
#define flag_10min 0x10
#define flag_15min 0x15
#define flag_20min 0x20
#define flag_40min 0x40 

// bit flag1s ; //һ��ʱ�䵽
 uint flag_over;  //��ʱʱ�䵽

/****ϵͳ״̬��ʼ��****/
enum eStaSystem staSystem = E_SET_TIME;  //ϵͳ����״̬
/****************************
  ��ʱ����
*****************************/
void Delay_Ms(uint16 ms)
{
     uint16 i;
	 do{
	      i = MAIN_Fosc / 96000; 
		  while(--i);   
     }while(--ms);
}

/*********************************************************
 ��ʱ����1
*********************************************************/
void delay1(int ms)
{
   unsigned char n;
   while(ms--)
   {
     for(n = 0; n<250; n++)
    {
      _nop_();
      _nop_();
      _nop_();
      _nop_();
    }
   }
}
/*********************************************************
 ��������һ��                                           
**********************************************************/
void Delay(uint num)//��ʱ����2
{
  while( --num );
}
void beep()
{
    unsigned char y;
    for (y=0;y<180;y++)
    {
      BEEP=!BEEP;                //BEEPȡ��
	  Delay(70);
    } 
    BEEP=1;                      //�رշ�����
}
/*********************************************************
		��ʱ����
*********************************************************/
 void Set_Time(uint t)
 {
  	switch(t)
	{
	   case  flag_3min :  flag_over = flag_3min;  break;
	   case  flag_7min :  flag_over = flag_7min;  break;
	   case  flag_10min : flag_over = flag_10min;	break;
	   case  flag_15min : flag_over = flag_15min;  break;
	   case  flag_20min : flag_over = flag_20min; break;
	   case  flag_40min : flag_over = flag_40min; break;
	}
 }
/*��ʼ����ʱ��0 ��ʱ5ms*/	
void Init_Timer0()
{	EA =1 ;         //������ʱ��
	TMOD = 0x01;  	//��ʱ��x16Ϊ��������ģʽ
	TH0 =0xdc;
	TL0 =0x00; 		//5ms
	ET0 = 1; 		//����ʱ��0�ж�
	TR0 = 1;		//������ʱ��0
}

void main()
{

   Init_Timer0();
   InitLcd1602();
   boot_Screen();

   while(1){         
   		KeyDriver(); 		//�������
   		if(staSystem == E_Timing) 
		{
	   	   Show_Countdown();
		    //��ʱʱ�䵽
  		   if(display[4] == flag_over||(display[4]== flag_over%16 && display[5]== flag_over/16)	) 
		    {
		     Timing_end();
			 beep();	 
	    	} 
		}
	   delay1(50);
   }
 
}

void Time0(void) interrupt 1 using 0
{
   TH0=0xdc;               //10ms��ʱ
   TL0=0x00;

   display[0]++;         //0.01S  

   if(display[0]==10)
   {
    display[0]=0;
	display[1]++;         //0.1S
	KeyScan();			  //����ɨ��
   }
   if(display[1]==10)
   {
    display[1]=0;
    display[2]++;         //���λ
   }
   if(display[2]==10)
   {
    display[2]=0;
    display[3]++;         //��ʮλ
   }
   if(display[3]==6)
   {
    display[3]=0;
    display[4]++;         //�ָ�λ
   }
   if(display[4]==10)
   {
    display[4]=0;
    display[5]++;         //��ʮλ
   }
   if(display[5]==6)
   {
    display[5]=0;
    display[6]++;        //ʱ
   }
   if(display[6]==24)
   {
     display[6]=0;
   } 
   
}
