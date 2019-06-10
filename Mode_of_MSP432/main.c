//
//*****************************************************************************
//  DEMO:     Engineering Template
//  MCU:      MSP432
//	VERSION:  V1.1
//  describe: This is a engineering template with the dirverlib of MSP432.
//*****************************************************************************
//https://blog.csdn.net/weixin_44048162/article/details/90646189

#include "msp.h"
#include <DriverLib/driverlib.h>

void main(void)
{
	WDT_A_holdTimer();           // Stop watchdog timer
	GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
	GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN0);
	while(1);
}
