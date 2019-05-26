//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

void main(void)
{
	
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN0);
    while(1);
	
}
