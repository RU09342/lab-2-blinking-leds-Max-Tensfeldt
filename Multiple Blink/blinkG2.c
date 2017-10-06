
//MultiBlinkG2

#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x41;
	P1OUT = 0x00;

	volatile unsigned int j;		// volatile to prevent optimization
	volatile unsigned int i = 0;
	while(1)
	{

	    if(i == 3)          //this counter will have the Green LED blink every third state change of the red LED
	            {
	               P1OUT ^= 0x40;
	               i = 0;
	            }

	    i++;

		P1OUT ^= 0x01;				// toggle P1.0
		j = 10000;                          // SW Delay
		do j--;
		while(j != 0);
	}
}
