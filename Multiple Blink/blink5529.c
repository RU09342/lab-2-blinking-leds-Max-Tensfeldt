
//Multiblink5529

#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output
	P4DIR |= 0x80;

	volatile unsigned int i;
	volatile unsigned int j = 0;

	while(1)
	{
	    if(j == 3)      //this counter will have the Green LED blink every third state change of the red LED
	    {
	        P4OUT ^= 0x80;
	        j = 0;
	    }
	    j++;

		P1OUT ^= 0x01;				// toggle P1.0
		for(i=10000; i>0; i--);     // delay
	}
}
