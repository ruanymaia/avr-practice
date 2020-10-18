#define F_CPU 8000000

#include <avr/io.h>       // Header file for basic avr input/output
#include <util/delay.h>   // header file for delay generation

int main(void)
{
    DDRB=1;      // PORTB declared as output
    while(1==1)  // infinite loop as 1 is always equals 1
    {
        PORTB=0;
        _delay_ms(1000);
        PORTB=1;
        _delay_ms(1000);
    }
    return 0;
}