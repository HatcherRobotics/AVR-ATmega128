#include<avr/io.h>
void USART_init()
{
    UBRR0H=0X00;
    UBRR0L=0X0C;
    UCSR0A=0X02;
    UCSR0B=0X18;
    UCSR0C=0X86;
}
void USART0_transmit(unsigned char data)
{
    while((UCSR0A & 0X20)==0X00)
    {
        ;
    }
    UDR0=data;
}
unsigned char USART0_receive()
{
    while((UCSR0A & 0X80)==0X00)
    {
        ;
    }
    unsigned char data;
    data=UDR0;
    return data;
}
void main()
{
    unsigned char input=0;
    USART_init();
    while(1)
    {
        input=USRT0_receive();
        if(input!=0)
        {
            USRAT0_transmit(input);
        }
    }

}
