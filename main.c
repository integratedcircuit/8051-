
/****************************

前言：
		初衷是为考雅思做个做题定时器，采用按键控制
		目的时摆脱对手机Timer的依赖。
		电路图用Proteus软件绘制（这个电路还能跑能设闹钟的万年历）
		欢迎大家对我代码不完善的地方进行指正,想用32开发的小伙伴也可参考我的代码架构
		（问：为什么不写32的程序，直接用函数库的32不香吗？答：我的oled屏过小，看着不方便而且32板子上没beep）
		后续我有时间的话会用AD绘制电路板，到时候就能随身携带了:)

        开源且有丰富注释。
		烤鸭党和考研党加油！

操作说明：
         
		 系统上电后会有开机显示“Uncompromising”意味着我们与自己的懒惰和懈怠“毫不妥协”。
		 开机界面不会自动消失
		 按下s3（时间上滚）、s3（时间下滚）可以进行选择定时时间
		 按下s2 开始计时/中止计时
		 按下s5 返回选择定时时间状态（注意:只有在计时中止时才能有效）

  					作者：Leon
  					时间：2021/1/14
  					单位：Hefei University of Technology


*****************************/
#include "main.h"
#include "LCD1602.h"
#include "Key.h"
#include "display.h"
#include "config.h"
/****************************
  数据池
*****************************/
uchar display[] =  {0x00,0x00,0x00,0x00,0x00,0x00,0x00};  //现在开始测试40min，把数据池改为39：50：00开始计时
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

// bit flag1s ; //一秒时间到
 uint flag_over;  //定时时间到

/****系统状态初始化****/
enum eStaSystem staSystem = E_SET_TIME;  //系统运行状态
/****************************
  延时函数
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
 延时函数1
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
 蜂鸣器响一声                                           
**********************************************************/
void Delay(uint num)//延时函数2
{
  while( --num );
}
void beep()
{
    unsigned char y;
    for (y=0;y<180;y++)
    {
      BEEP=!BEEP;                //BEEP取反
	  Delay(70);
    } 
    BEEP=1;                      //关闭蜂鸣器
}
/*********************************************************
		定时函数
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
/*初始化定时器0 定时5ms*/	
void Init_Timer0()
{	EA =1 ;         //开启定时器
	TMOD = 0x01;  	//定时器x16为计数工作模式
	TH0 =0xdc;
	TL0 =0x00; 		//5ms
	ET0 = 1; 		//开定时器0中断
	TR0 = 1;		//启动定时器0
}

void main()
{

   Init_Timer0();
   InitLcd1602();
   boot_Screen();

   while(1){         
   		KeyDriver(); 		//按键检测
   		if(staSystem == E_Timing) 
		{
	   	   Show_Countdown();
		    //定时时间到
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
   TH0=0xdc;               //10ms定时
   TL0=0x00;

   display[0]++;         //0.01S  

   if(display[0]==10)
   {
    display[0]=0;
	display[1]++;         //0.1S
	KeyScan();			  //按键扫描
   }
   if(display[1]==10)
   {
    display[1]=0;
    display[2]++;         //秒个位
   }
   if(display[2]==10)
   {
    display[2]=0;
    display[3]++;         //秒十位
   }
   if(display[3]==6)
   {
    display[3]=0;
    display[4]++;         //分个位
   }
   if(display[4]==10)
   {
    display[4]=0;
    display[5]++;         //分十位
   }
   if(display[5]==6)
   {
    display[5]=0;
    display[6]++;        //时
   }
   if(display[6]==24)
   {
     display[6]=0;
   } 
   
}
