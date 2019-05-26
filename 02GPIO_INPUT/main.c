//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

void main(void)
{
	
    //WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    WDT_A_holdTimer();
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);                  //设置P1.0为输出
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4); //设置P1.4为输入，默认为高电平

    while(1)
    {
    	while(! GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4))
    	{
    		SysTick_setPeriod(150000); //SysTick初始化，当检测到按键按下时，延时5ms消抖
    		SysTick_enableModule();
    		while(SysTick_getValue()&15000); //计数至零再次判断是否按下
    		SysTick_disableModule();
    		if(! GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4))
    		{
    			GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0); //输出翻转
    			while(! GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4)); //保持到按键释放
    			SysTick_setPeriod(150000); //SysTick初始化，延时5ms消抖
    			SysTick_enableModule();
    			while(SysTick_getValue()&15000);
    			SysTick_disableModule();   //关闭定时器
    			GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4); //设置P1.4为输入，默认为高电平
    		}
    	}
    }
}
