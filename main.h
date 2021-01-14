 #ifndef _MAIN_H
#define _MAIN_H	  
#include "config.h"
enum eStaSystem {  //系统运行状态枚举
    E_Timing , E_SET_TIME , E_T_END
};

#ifndef _MAIN_C

extern enum eStaSystem staSystem;

#endif
void Init_Timer0();
void Delay_Ms(uint16 ms);
void delay1(int ms);
void Set_Time(uint t);
void beep();
#endif