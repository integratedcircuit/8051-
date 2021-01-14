#include "config.h"
#include "Lcd1602.h"
#include "Key.h"
#include "main.h"
#include "app.h"
#include "display.h"

extern uchar display[];	          //Ϊ������������ʱʱ����ʱ�����㿪ʼ��ʱ
static uint cnt=0;				  //���ֻ��roll_up���Զ����ں����ڣ�����roll_down��Ҫ���ô˱���

void begin_end()				  
{  uint z;
   static uint k=0;   //Ϊ������ֹ��ʱ�����޴˾�̬���������޷���ʼ��begin����ʱ
   
   if (staSystem == E_SET_TIME || staSystem == E_T_END)  //	״̬��������ʱΪbegin
   {
       Init_Timer0();            //��ʼ��ʱ
	   for(z=0;z<7;z++)	display[z]=0;		 //ȫ�����㿪ʼ����	���ڲ���ʱ���������ע�͵������Գɹ�

   	   staSystem = E_Timing;	//�ı����Ϊ��ʱ״̬	   
   }
   if(staSystem == E_Timing && k%2==1)	//���Ϊ��ʱ״̬����Ҫ��ʱ��ֹ
   {
   	  staSystem = E_T_END;			//��״̬�����main��������ʹ��ʾ���ڰ���ťʱ��ʱ��
   } 
   k++ ;
   KEY_S2_ON=1;
}
/*
   function:��Ļ�Ϲ�����
   			��Show_interface(cnt)������Set_Time(uint t)Ƕ�룬�����Ŀ���Ƿ�����ʾ�����Ķ���λ��
   			�Լ���ÿ�������Ĵ�����������������׶�������ά��
*/
void Roll_up()
{  
  if (staSystem == E_SET_TIME)
  {  
   	 Show_interface(1);	 //��ʼ��
	 cnt++;				 //cnt++��λ����Ҫע��
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
   function:��Ļ�¹�����
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
   function:���غ���
	   ע�⣺ֻ�е���ʱ��ֹ����s2���ٴΰ��º󣩴˰���������Ч
*/
void Back()
{
  if (staSystem == E_T_END)  
   	 staSystem = E_SET_TIME;
	 Roll_up();				  //Ϊ�˻ص���ʾ����
   KEY_S5_ON=1;
}
/************����ϵͳ**************/

void KeyDriver(){

	   if(KEY_S2_ON==0){	  //ȷ��/��ʱ��ʼ/��ֹ
	   	 begin_end();

	   }
	   
	   else if(KEY_S3_ON==0){ //�Ϲ�
	   	  Roll_up();

	   }
	   else if(KEY_S4_ON==0){ //�¹� 
	   	  Roll_down();

	  }
	  else if(KEY_S5_ON==0){ // back
	   	  Back();

	  }
 }
	   

