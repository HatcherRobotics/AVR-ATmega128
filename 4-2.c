#include <avr/io.h>
#include <avr/interrupt.h>
#define LED PORTB

extern unsigned char led_buf[];
extern void disp_init(void);

void delay_us(unsigned int i)
{
  do
  {
    i--;
  }while(i);
}

void delay_ms(unsigned int j)
{
  do
  {
    j--;
    delay_us(999);
  }
  while(j);
}

ISR(INT4_vect)
{
  LED = 0xef;// 1110 1111
  led_buf[0] = 4;
  delay_ms(50);
}
ISR(INT5_vect)
{
  LED = 0xdf;// 1101 1111
  led_buf[0] = 5;
  delay_ms(50);
}
ISR(INT6_vect)
{
  LED = 0xbf;// 1011 1111
  led_buf[0] = 6;
  delay_ms(50);
}
ISR(INT7_vect)
{
  LED = 0x7f;// 0111 1111
  led_buf[0] = 7;
  delay_ms(50);
}
void port_init(void)
{
  DDRB=0xff; //output for B
  DDRE=0x00; //input for E
  PORTB=0xff; // 
  PORTE=0xff; // E high-rise
}

void int_init()
{
 //sei();

  SREG = 0b10000000;

  EIMSK = 0b11110000;
  EICRB = 0b11100100;
  EICRA = 0x00;
}

void main(void)
{
  port_init();
  int_init();
  disp_init();
}

