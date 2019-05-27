//*****************************************************************************
//  DEMO:   GPIO_OUTPUT
//  MCU:    MSP432
//	NUMBER: 01
//****************************************************************************

#include "msp.h"
#include <DriverLib/driverlib.h>

void main(void)
{
	
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN0);
    while(1);
	
}
