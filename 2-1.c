#include<avr/io.h>
void USART_init()
{
    UBRR0H=0X00;
    UBRR0L=0X0C;
    UBRR1H=0X00;
    UBRR1L=0X0C;
    UCSR0A=0X02;
    UCSR0B=0X08;
    UCSR0C=0X86;
    UCSR1A=0X02;
    UCSR1B=0X10;
    UCSR1C=0X86;
}
void PORT_init()
{
    DDRB=0XFF;
    PORTB=0X00;
}
void USART0_transmit(unsigned char data)
{
    while((UCSR0A & 0X20)==0X00)
    {
        ;
    }
    UDR0=data;
}
unsigned char USART1_receive()
{
    while((UCSR1A & 0X80)==0X00)
    {
        ;
    }
    unsigned char data;
    data=UDR1;
    return data;
}
void delay(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
    {
        for(j=0;j<1000;j++)
        {
            ;
        }
    }
}
void main()
{
    USART_init();
    PORT_init();
    char data=0;
    while(1)
    {
        USART0_transmit(data);
        USART1_receive();
        data++;
    }
}
