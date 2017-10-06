
//ButtonBlink2311

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR = 0x01;
    P2DIR = 0x01;
    P1REN |= BIT1;    //enables the pull up resistor at P1.1
    P1OUT |= BIT1;

        volatile unsigned int j;

    for(;;) {
        int temp = P1IN & BIT1;



        if(temp == 2)  //GREEN light is held on in this state representing the button has not been pressed
        {
            P1OUT &= BIT1;
            P2OUT |= 0x01;
        }
        else   //Green light is turned off and red light blinks due to button being pressed
        {
            j = 10000;                          // SW Delay
            do j--;
            while(j != 0);
            P1OUT ^= 0x01;
            P2OUT &= 0x00;
        }



    }
}
