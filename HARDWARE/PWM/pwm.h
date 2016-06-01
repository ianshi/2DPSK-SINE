#ifndef __PWM_H
#define __PWM_H
#include "sys.h"

#define   div_16KHz   
#define   div_8KHz    8
#define   div_4KHz    17

void TIM1_PWM_Init(u16 arr,u16 psc);

#endif
