#include<avr/io.h>
void port_init(void)
{
    DDRB=0xff;
    PORTB=0xff;
}
void timer1_init(void)
{
    OCR1A=1;
    OCR1B=292;
    OCR1C=439;
    TCCR1A=0b10101001;
    TCCR1B=0b00001010;
    TCCR1C=0b00000000;
}
void main()
{
    port_init();
    timer1_init();
    while(1);
}
