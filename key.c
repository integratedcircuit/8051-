#include "config.h"
#include "app.h"
#include "Key.h"
#include "main.h"


/************����************/
bit KEY_S2_ON=1;
bit KEY_S3_ON=1;
bit KEY_S4_ON=1;
bit KEY_S5_ON=1;
 /********************/

void KeyScan(){

		if(KEY_S4 == 0)//�ж�S4�Ƿ񱻰���
		{
			Delay_Ms(20);//��������
			if(KEY_S4 == 0){
				KEY_S4_ON=0;
			}
			while(!KEY_S4);//���ּ��
		}	
		
		else if(KEY_S2 == 0)//�ж�S2�Ƿ񱻰���
		{
			Delay_Ms(20);//��������
			if(KEY_S2 == 0){
				KEY_S2_ON=0;
			}
				while(!KEY_S2);//���ּ��
		}
		else if(KEY_S3 == 0)//�ж�S3�Ƿ񱻰���
		{
			Delay_Ms(20);//��������
			if(KEY_S3 == 0){
				KEY_S3_ON=0;
			}
				while(!KEY_S3);//���ּ��
		}
		else if(KEY_S5 == 0)//�ж�S5�Ƿ񱻰���
		{
			Delay_Ms(20);//��������
			if(KEY_S5 == 0){
				KEY_S5_ON=0;
			}
				while(!KEY_S5);//���ּ��
		}
			
}		


