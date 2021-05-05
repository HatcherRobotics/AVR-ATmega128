#include<avr/io.h>
void delay(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
    {
        for(j=0;j<1141;j++)
        {
            ;
        }
    }
}
void main()
{
    DDRB=0Xff;
    PORTB=0Xff;
    while(1)
    {
        for(int i=0;i<3;i++)
        {
            PORTB=0b00001111;
            delay(1000);
            PORTB=0b11111111;
            delay(1000);
        }
        for(int j=0;j<3;j++)
        {
            PORTB=0b11110000;
            delay(1000);
            PORTB=0b11111111;
            delay(1000);
        }
        for(int m=0;m<3;m++)
        {
            PORTB=0b00111100;
            delay(1000);
            PORTB=0b11111111;
            delay(1000);
        }
    }
}
