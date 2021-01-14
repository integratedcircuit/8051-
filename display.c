#include "display.h"
#include "config.h"
#include "LCD1602.h"
extern uchar display[];
extern uchar display2[];

void boot_Screen()	 //��ʼ����������
{				    
	unsigned char *p = "Uncompromising";  //������Э
	unsigned char *o = "      by Leon";
	InitLcd1602();          //1602��ʼ��
	LcdShowStr(0,0,p);
	LcdShowStr(0,1,o);
}
/*
  function: ����Ϊ��ʾ����ʱ�����ڵ���ʱ�нϴ���ʱ�����Ժ�������Ȼ������ʱ
*/
void Show_Countdown()  
{
	uchar  i;
   for(i=0;i<6;i++)
   {
    display2[i]=display[i]+0x30;  
   }
   	//�˴���һֻ��Ϊ��ʹ�ұ�3λ�ճ�������Ȼ���ò����ۿ����������������
    LCD1602_Dis_OneChar(13-1,1,display2[0]);
	LCD1602_Dis_OneChar(12-1,1,display2[1]);
	LCD1602_Dis_OneChar(11-1,1,':');
	LCD1602_Dis_OneChar(10-1,1,display2[2]);
	LCD1602_Dis_OneChar(9-1,1, display2[3]);
	LCD1602_Dis_OneChar(8-1,1,':');
	LCD1602_Dis_OneChar(7-1,1,display2[4]);
    LCD1602_Dis_OneChar(6-1,1,display2[5]);
	LCD1602_Dis_OneChar(5-1,1,':');

	DisplayOneStr(3-1,1,display[6]);

}
/*
  function: ��ʾѡ��ʱ�����
*/
void Show_interface(uint x)
{										    
   uchar code  cdis1[ ] = {"     3min    "};
   uchar code  cdis2[ ] = {"     7min    "};
   uchar code  cdis3[ ] = {"     10min   "};
   uchar code  cdis4[ ] = {"     15min   "};
   uchar code  cdis5[ ] = {"     20min   "};
   uchar code  cdis6[ ] = {"     40min   "};
   uchar code  cdis7[ ] = {"Yes"};		   //ָʾ
   /*��������дҳ�����չʾ7min��10min�ȵ�   ��취�밴������� */
   LcdShowStr(13,0,cdis7);  
   switch (x){
	case 1: LcdShowStr(0,0,cdis1);LcdShowStr(0,1,cdis2);break;
	case 2: LcdShowStr(0,0,cdis2);LcdShowStr(0,1,cdis3);break;	
	case 3: LcdShowStr(0,0,cdis3);LcdShowStr(0,1,cdis4);break;
	case 4: LcdShowStr(0,0,cdis4);LcdShowStr(0,1,cdis5);break;
	case 5: LcdShowStr(0,0,cdis5);LcdShowStr(0,1,cdis6);break;
	case 6: LcdShowStr(0,0,cdis6);LcdShowStr(0,1,cdis1);break;
	}
}
/*
  function:  ��ʱ��ֹ��ʾEND
*/
void Timing_end()
{
	uchar code  t [ ] = {"*******END*******"};
	LcdShowStr(0,0,t);
}