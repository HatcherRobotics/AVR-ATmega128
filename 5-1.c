#include<avr/io.h>
#include<avr/interrupt.h>
void init_port()
{ 
    DDRB=0xff;
    PORTB=0x00;
}
void init_timer()
{
    TCCR1A=0b10000000;
    TCCR1B=0b00001010;
    TCCR1C=0b10000000; 
    TIMSK=0b00010000;
    OCR1A=1250;
    asm("SEI");
}
unsigned int counter=0;
ISR(TIMER1_COMPA_vect)
{
    counter++;
    if(counter<100)
    {
        return;
    }
    PORTB=~(1<<0);
   counter=0;
   
}
void main()
{
    init_port();
    init_timer();
    while(1);
}
