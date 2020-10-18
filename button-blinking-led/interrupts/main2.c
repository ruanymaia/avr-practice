#define F_CPU 20000000

#include <avr/io.h>       // Header file for basic avr input/output
#include <avr/interrupt.h>

int main(void)
{
    DDRB |= _BV(DDB0);     // Configure PB0 as an output using the Port B Data Direction Register (DDRB) - '|=' set bit number
    
    DDRC &= ~_BV(DDC5);    // Configure PC5 as an input using the PORT C Data Direction Register C (DDRC) - led - '&=~' clear bit number
    PORTC |= _BV(PORTC5);       // Enable the pull-up resistor on PC5 using the Port C Data Register (PORTC)- button
    
    PCMSK0 |= _BV(PCINT0);   // Enable pin change interrupt on the PCINT13 pin using Pin Change Mask Register 1 (PCMSK1)
    PCICR |= _BV(PCIE0);      // Enable pin change interrupt 1 using the Pin Change Interrrupt Control Register (PCICR)
    
    sei();              // Enable interrupts

    while(1)
    {
        // Loop forever
    }
}

ISR(PCINT0_vect)
{
    // Read PC5 using the Port D Pin Input Register (PIND)
    if (PINC & _BV(PINC5))      // If PC5 is high - button pressed
    {
        PORTB |= _BV(PORTB0);    // Set PB0 high using the Port B Data Register (PORTB) - led on
    }
    else                    // PC5 is low - button not pressed
    {
        PORTB &= ~_BV(PORTB0);   // Set PB0 low using the Port B Data Register (PORTB) - led off
    }
}