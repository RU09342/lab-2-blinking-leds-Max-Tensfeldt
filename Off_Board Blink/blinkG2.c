
//OffBoardBlinkG2

#include <msp430g2553.h>

/**
 * blink.c
 */

 int temp;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer
    P1DIR |= 0x41;                  // configure P1.0 as output
    P1DIR &= 0xF7;
    P1REN |= BIT3;
    P1OUT |= 0x08;

    volatile unsigned int j;

    while(1)
    {

        temp = P1IN & BIT3;        //For this project, an off board button is providing an input for the chip's code
                                   //When the button is pressed, the LED P1.0 will blink


        if (temp == BIT3)
        {
            P1OUT &= ~BIT0;
        }
        else
        {

            P1OUT ^= 0x01;
        }

        P1OUT ^= 0x40;              //Regardless of the button, LED P1.6 will blink
        j = 10000; // SW Delay
        do j--;
        while(j != 0);

    }
}
