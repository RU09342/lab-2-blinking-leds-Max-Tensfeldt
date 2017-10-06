
//ButtonBlink5529

#include <msp430.h>


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= 0x01;					// configure P1.0 as output
	P1REN |= BIT1;
	P1OUT |= BIT1;
	volatile unsigned int j;
	int temp;
	while(1)
	{
	    temp = P1IN & BIT1;


	    if(temp == BIT1)        //Button has not been pressed so therefore the LED is off
	    {
	        P1OUT &= ~BIT0;
	    }
	    else
	    {
            j = 10000;                          // SW Delay
            do j--;
            while(j != 0);
            P1OUT ^= 0x01;      //Button is pressed so the LED is blinking
	    }
	}
}
