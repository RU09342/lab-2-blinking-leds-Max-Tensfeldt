
//MultiBlink5994

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x03;                          // Set P1.0 and P1.1 to output direction
    P1OUT |= 0x00;
    volatile unsigned int j;            // volatile to prevent optimization
    volatile unsigned int i = 0;


    for(;;) {


        if(i == 3)      //this counter will have the Green LED blink every third state change of the red LED
        {
            P1OUT ^= 0x02;
            i = 0;
        }

        i++;

        P1OUT ^= 0x01;              // toggle P1.0
        j = 10000;                          // SW Delay
        do j--;
        while(j != 0);
    }
}
