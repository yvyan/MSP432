//
//*****************************************************************************
//  DEMO:     GPIO_INTERRUPT
//  MCU:      MSP432
//	NUMBER:   03
//  describe: 使用了串口中断进行控制，P1.1和P1.4均可控制，并且调用了LPM3省电模式
//*****************************************************************************
//https://blog.csdn.net/weixin_44048162/article/details/90646189

#include "msp.h"
#include <DriverLib/driverlib.h>

volatile uint32_t status; //用于记录中断发生的端口号
/*volatile关键词影响编译器编译的结果，用volatile声明的变量表示该变量随时可能发生变化，
与该变量有关的运算，不要进行编译优化，以免出错*/

void gpio_isr(); //GPIO中断服务程序

void main(void)
{
	WDT_A_holdTimer();                                             //关闭看门狗
	GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);                  //设置P1.0为输出
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1); //设置P1.1为输入，默认为高电平
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4); //设置P1.4为输入，默认为高电平
	GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);              //清除中断标志
	GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN4);              //清除中断标志
	GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);                 //使能P1.1中断
	GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN4);                 //使能P1.4中断
	Interrupt_enableInterrupt(INT_PORT1);
	GPIO_registerInterrupt(GPIO_PORT_P1, gpio_isr);                //注册gpio_isr为GPIO_P1中断服务程序

	while (1)
	{
		PCM_gotoLPM3(); //进入LPM3省电模式
	}
}

void gpio_isr() //GPIO中断服务程序
{
	status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P1); //记录端口号
	GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);       //反转GPIO状态，实现灯的控制
	GPIO_clearInterrupt(GPIO_PORT_P1, status);             //清除相应口的标志
}
