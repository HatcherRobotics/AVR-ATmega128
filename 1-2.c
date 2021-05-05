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
    DDRB=0XFF;
    PORTB=0XFF;
    DDRE=0X00;
    PORTE=0xFF;
    unsigned char data_PORTB;
    while(1)
    {
    data_PORTB=PINE;
    PORTB=data_PORTB;
    delay(1000);
    }
}
