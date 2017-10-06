
//ButtonBlinkG2

#include <msp430g2553.h>

/**
 * blink.c
 */

 int temp;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output
	P1DIR &= 0xF7;
	P1REN |= BIT3;
	P1OUT |= 0x08;

	volatile unsigned int j;

	while(1)
	{

		temp = P1IN & BIT3;         //Comparator for the button to register that they have been pushed


		if (temp == BIT3)
		{
            P1OUT &= ~BIT0;       //button not pressed state, LED off
		}
		else                      //button pressed state, LED flashing
		{
            j = 10000; // SW Delay
            do j--;
            while(j != 0);
            P1OUT ^= 0x01;
		}
	}
}
