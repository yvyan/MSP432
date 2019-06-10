//
//*****************************************************************************
//  DEMO:     GPIO_OUTPUT
//  MCU:      MSP432
//	NUMBER:   01
//  describe: 单纯使用io口进行输出
//*****************************************************************************
//https://blog.csdn.net/weixin_44048162/article/details/90646189

#include "msp.h"
#include <DriverLib/driverlib.h>

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
	GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
	GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN0);
	while(1);
}
