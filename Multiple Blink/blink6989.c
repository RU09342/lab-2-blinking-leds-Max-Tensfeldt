
//MultiBlink6989

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P9DIR |= 0x80;
    volatile unsigned int i;            // volatile to prevent optimization
    volatile unsigned int j = 0;

    for(;;) {

        if(j == 3)      //this counter will have the Green LED blink every third state change of the red LED
        {
            P9OUT ^= 0x80;
            j = 0;
        }

        j++;


        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
        i = 10000;                          // SW Delay
        do i--;
        while(i != 0);
    }
}
