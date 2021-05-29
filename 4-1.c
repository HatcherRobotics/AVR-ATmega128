#include<avr/io.h>
#include<avr/interrupt.h>

extern void disp_init(void);
extern unsigned char led_buf[];

void init_port()
{
    DDRB=0xff;
    DDRE=0x00;
    PORTB=0x00;
    PORTE=0xff;
}

void init_interrupt()
{
    EICRA=0x00;
    
    
    EICRB=0xe4;//EICRB

   
    EIMSK=0xf0; //EIMSK
    
    asm("SEI");
}

void delay(unsigned int t)//去抖
{
    unsigned int a,b;
        for(a=0;a<1000;++a)
            for(b=0;b<t;++b);
}
ISR(INT4_vect)
{
    PORTB=~(1<<4);
    led_buf[0]=4;
    delay(10);
}
ISR(INT5_vect)
{
    PORTB=~(1<<5);
    led_buf[0]=5;
    delay(10);
}
ISR(INT6_vect)
{
    PORTB=~(1<<6);
    led_buf[0]=6;
    delay(10);
}
ISR(INT7_vect)
{
    PORTB=~(1<<7);
    led_buf[0]=7;
    delay(10);
}

void main()
{
    init_port();
    init_interrupt();
    disp_init;
    while(1)
    {
        PORTB=0xff;
    }
}
