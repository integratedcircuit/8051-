#include "config.h"
#include "Lcd1602.h"
#include "Key.h"
#include "main.h"
#include "app.h"
#include "display.h"

extern uchar display[];	          //为了能在启动计时时将定时器从零开始计时
static uint cnt=0;				  //如果只有roll_up可以定义在函数内，但是roll_down需要共用此变量

void begin_end()				  
{  uint z;
   static uint k=0;   //为了能中止计时，若无此静态变量，则无法开始（begin）计时
   
   if (staSystem == E_SET_TIME || staSystem == E_T_END)  //	状态变量，此时为begin
   {
       Init_Timer0();            //开始计时
	   for(z=0;z<7;z++)	display[z]=0;		 //全部回零开始计数	，在测试时这里别忘了注释掉，测试成功

   	   staSystem = E_Timing;	//改变变量为计时状态	   
   }
   if(staSystem == E_Timing && k%2==1)	//如果为计时状态，需要计时中止
   {
   	  staSystem = E_T_END;			//换状态，配合main函数可以使显示卡在按按钮时的时间
   } 
   k++ ;
   KEY_S2_ON=1;
}
/*
   function:屏幕上滚函数
   			将Show_interface(cnt)函数和Set_Time(uint t)嵌入，其根本目的是分离显示函数的定义位置
   			以及简化每个函数的代码行数，这样简洁易读，便于维护
*/
void Roll_up()
{  
  if (staSystem == E_SET_TIME)
  {  
   	 Show_interface(1);	 //初始化
	 cnt++;				 //cnt++的位置需要注意
	 if(cnt==7) cnt=0;
	 switch (cnt){
	 case 1:  Show_interface(cnt); Set_Time(0x03);break;
	 case 2:  Show_interface(cnt); Set_Time(0x07);break;
	 case 3:  Show_interface(cnt); Set_Time(0x10);break;
	 case 4:  Show_interface(cnt); Set_Time(0x15);break;
	 case 5:  Show_interface(cnt); Set_Time(0x20);break;
	 case 6:  Show_interface(cnt); Set_Time(0x40);break;
	}
  }
   KEY_S3_ON=1;
}
/*
   function:屏幕下滚函数
*/
void Roll_down()
{

  if (staSystem == E_SET_TIME)
  {  
	 cnt--;
	 if(cnt==0) cnt=5;
	 switch (cnt){
	 case 1:  Show_interface(cnt); Set_Time(0x03);break;
	 case 2:  Show_interface(cnt); Set_Time(0x07);break;
	 case 3:  Show_interface(cnt); Set_Time(0x10);break;
	 case 4:  Show_interface(cnt); Set_Time(0x15);break;
	 case 5:  Show_interface(cnt); Set_Time(0x20);break;
	 case 6:  Show_interface(cnt); Set_Time(0x40);break;

	} 
  }
   KEY_S4_ON=1;
}
/*
   function:返回函数
	   注意：只有当计时中止（即s2被再次按下后）此按键才能生效
*/
void Back()
{
  if (staSystem == E_T_END)  
   	 staSystem = E_SET_TIME;
	 Roll_up();				  //为了回到显示界面
   KEY_S5_ON=1;
}
/************按键系统**************/

void KeyDriver(){

	   if(KEY_S2_ON==0){	  //确定/计时开始/中止
	   	 begin_end();

	   }
	   
	   else if(KEY_S3_ON==0){ //上滚
	   	  Roll_up();

	   }
	   else if(KEY_S4_ON==0){ //下滚 
	   	  Roll_down();

	  }
	  else if(KEY_S5_ON==0){ // back
	   	  Back();

	  }
 }
	   

