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
    unsigned int step[8] ={0XFE,0XFC,0XF8,0XF0,0XE0,0XC0,0X80,0X00};
    while(1)
    {
        for(int i=1;i<8;i++)
        {
            PORTB=step[i];
            delay(100);
        }
    }
}
