//
//*****************************************************************************
//  DEMO:     Timer32
//  MCU:      MSP432
//	NUMBER:   04
//  describe: 使用Timer32定时器实现LED 1s闪烁
//*****************************************************************************
//https://me.csdn.net/weixin_44048162

#include "msp.h"
#include <DriverLib/driverlib.h>

void Timer32IsrHandler();

int main()
{
	WDT_A_holdTimer();                                                  //关闭看门狗
	CS_initClockSignal(CS_MCLK, CS_LFXTCLK_SELECT, CS_CLOCK_DIVIDER_1); //时钟初始化，设置MCLK时钟的时钟源为LFXTCLK，不分频
	GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);                       //设置P1.0为输出
	GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);                    //P1.0默认输出低电平

	Timer32_initModule(TIMER32_0_BASE, TIMER32_PRESCALER_1, TIMER32_32BIT, TIMER32_PERIODIC_MODE);
	/*Timer32定时器选择timer0（第一个定时器）。定时器不分频，32位大小，周期运行模式*/
	Timer32_setCount(TIMER32_0_BASE, 0x8000);                     //Timer0中装入初值0x8000（32768）
	Interrupt_registerInterrupt(INT_T32_INT1, Timer32IsrHandler); //注册Timer32IsrHandler为INT_T32_INT1中断服务程序
	Interrupt_enableInterrupt(INT_T32_INT1);                      //使能Timer32中断服务程序
	Timer32_enableInterrupt(TIMER32_0_BASE);                      //使能Timer32中断
	Timer32_startTimer(TIMER32_0_BASE, false);                    //启动Timer32定时器，反复循环计数

	while (1)
	{
		__sleep();
	}

	return 0;
}

void Timer32IsrHandler()
{
	Timer32_clearInterruptFlag(TIMER32_0_BASE);      //清除Timer32中断标志
	GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0); //反转GPIO状态，实现灯的控制
}
