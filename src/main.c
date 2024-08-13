/*
 * AVR Boilerplate Test Code
 * -------------------------
 * This example tests the boilerplate setup by blinking an LED connected to PB0 (pin 14 on ATmega328P).
 * It toggles the LED every 500ms, ensuring that your toolchain and microcontroller are working correctly.
 *
 * Hardware: 
 * - AVR microcontroller (e.g., ATmega328P)
 * - LED + current-limiting resistor connected to PB0
 *
 * Note: 
 * You can also test this code with the included Proteus simulation project.
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set PB0 (pin 14 on ATmega328P) as output
    DDRB = (1 << PB0);

    while (1)
    {
        // Toggle PB0
        PORTB ^= (1 << PB0);
        _delay_ms(500);
    }
}