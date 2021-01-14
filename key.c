#include "config.h"
#include "app.h"
#include "Key.h"
#include "main.h"


/************测试************/
bit KEY_S2_ON=1;
bit KEY_S3_ON=1;
bit KEY_S4_ON=1;
bit KEY_S5_ON=1;
 /********************/

void KeyScan(){

		if(KEY_S4 == 0)//判断S4是否被按下
		{
			Delay_Ms(20);//按键消抖
			if(KEY_S4 == 0){
				KEY_S4_ON=0;
			}
			while(!KEY_S4);//松手检测
		}	
		
		else if(KEY_S2 == 0)//判断S2是否被按下
		{
			Delay_Ms(20);//按键消抖
			if(KEY_S2 == 0){
				KEY_S2_ON=0;
			}
				while(!KEY_S2);//松手检测
		}
		else if(KEY_S3 == 0)//判断S3是否被按下
		{
			Delay_Ms(20);//按键消抖
			if(KEY_S3 == 0){
				KEY_S3_ON=0;
			}
				while(!KEY_S3);//松手检测
		}
		else if(KEY_S5 == 0)//判断S5是否被按下
		{
			Delay_Ms(20);//按键消抖
			if(KEY_S5 == 0){
				KEY_S5_ON=0;
			}
				while(!KEY_S5);//松手检测
		}
			
}		


