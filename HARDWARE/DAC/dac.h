#ifndef __DAC_H
#define __DAC_H	 
#include "sys.h"	    
								    
#define Abs_code       PAout(2)
#define Rela_code      PAout(3)
#define CLK            PAout(6)


void Dac1_Init(void);//回环模式初始化		 	 
void Dac1_Set_Vol(u16 vol);
void Input_Init(void);
#endif

















