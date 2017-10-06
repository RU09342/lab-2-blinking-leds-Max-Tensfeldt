
//ButtonBlink5994

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x03;                          // Set P1.0 to output direction
    P5REN |= 0x60;                          //Set P5 button resistors on
    P1OUT &= 0x00;
    P5OUT |= 0xFF;                          //Set the direction of the resistors to pull up
    int temp1;
    int temp2;

    volatile unsigned int j;            // volatile to prevent optimization


    for(;;)
    {


        temp1 = P5IN & BIT6;    //Comparator for the buttons to register that they have been pushed
        temp2 = P5IN & BIT5;


        if (temp1 == BIT6)
        {
            P1OUT &= ~BIT0;     //Shuts off the blinking P1.0 Red light
        }
        else
        {
            P1OUT ^= 0x01;
        }

        if(temp2 == BIT5)
        {
            P1OUT &= ~BIT1;     //Shuts off the blinking P1.1 Green light
        }
        else
        {
            P1OUT ^= 0x02;
        }

        j = 10000; // SW Delay
        do j--;
        while(j != 0);

    }
}
