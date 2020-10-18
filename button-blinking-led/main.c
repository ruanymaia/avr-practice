#define F_CPU 20000000

#include <avr/io.h>       // Header file for basic avr input/output
#include <util/delay.h>   // header file for delay generation

int main(void)
{
    DDRB |= (1<<0);      // PORTB pin 0 declared as output - led (|= set bit number)
    DDRC &= ~(1<<5);     // PORTC pin 5 declared as input - button (&=~ clear bit number)
    PORTC = 1<<5;     // PORTC pin 5 pull up resistor activated - button
    while(1==1)  // infinite loop as 1 is always equals 1
    {
        if (PINC ^ (1<<5)) // if PIN5 of PORTC is high
        {
            PORTB |= (1<<0); // then PIN0 of PORTB is high (|= set bit number)
        }
        else
        {
            PORTB &= ~(1<<0); // then PIN0 of PORTB remains low 
        }
    }
    return 0;
}


