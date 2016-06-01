#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"
#include "dac.h"
#include "usart.h"

int main(void)
{	
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
    TIM2_Int_Init(9,2);         //DMA 触发时钟
    Dac1_Init();
    uart_init(115200);
   	while(1)
	{  
        delay_ms(500);
        LED1=!LED1;
	} 
}

