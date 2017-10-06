Button Blink
Max Tensfeldt
Intro to Embedded - Section 2

The last section that was completed on all boards was button blink where a on board button was used to control an LED. The LEDs flashed when activated with the same speed as simple blink.

* MSP430G2553
LED = P1.0
Button = P1.3
Simply put, when button P1.3 is pressed, LED P1.0 flashes at a constant speed.

* MSP430F5529
LED = P1.0
Button = P1.1
Same as before, when button P1.1 is pressed, LED P1.0 flashes at a constant speed.

* MSP430FR2311
LEDs = P1.0 and P2.0
Button = P1.1
For this board, LED P2.0 ran solid while the button P1.1 was not pressed. When the button was pressed, the LED P1.1 turned off and LED P1.0 blinked just like the two boards above.


* MSP430FR5994
LEDs used were P1.0 and P1.1
Buttons used were P5.5 and P5.6
This button blink was run a bit differently than the rest where it had two LEDs and two buttons run in the same code block yet completely separate from each other. When the P5.6 button was pressed, it activated the P1.0 LED; and the P5.5 button activated the P1.1 LED. No matter what configuration the buttons where pressed and released at, they operated their assigned LEDs exclusively.

* MSP430FR6989
LED = P1.0
Button = P1.1
Same as FR2311, when button P1.1 is pressed, LED P1.0 flashes at a constant speed.
