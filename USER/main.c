#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"
#include "dac.h"
#include "usart.h"

int main(void)
{	
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
    TIM2_Int_Init(9,2);         //DMA ����ʱ��
    Dac1_Init();
    uart_init(115200);
   	while(1)
	{  
        delay_ms(500);
        LED1=!LED1;
	} 
}

