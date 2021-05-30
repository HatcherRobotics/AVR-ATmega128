#include <avr/io.h>
#include <avr/interrupt.h>

#define PITCH_1 523
#define PITCH_2 587
#define PITCH_3 659
#define PITCH_4 698
#define PITCH_5 783
#define PITCH_6 880
#define PITCH_7 987

void init_port()
{
    DDRE =1<<3 ;  111000000
    PORTE =1<<3;
}
void init_timer()
{
    TCCR1A = 0b10000000;
    TCCR1B = 0b00001001;
    TCCR1C = 0b10000000;

    TIMSK = 0b00010000;

    OCR1A = 1250;

    asm("SEI");
}

void paly(int freq)
{
    OCR1A = 1000000.0f / 2.0f / freq;
}


ISR(TIMER1_COMPA_vect)
{
    PORTE = ~PORTE;
}

void delay(unsigned int t)
{
    unsigned int i,j;
    for (i=0;i<1000;++i)
        for (j=0;j<t;++j);
}
int main()
{
    init_port();
    init_timer();
    
    while(1)
    {
        delay(50);
        paly(PITCH_3);

        delay(70);
        paly(PITCH_6);

        delay(20);
        paly(PITCH_2);

        delay(10);
        paly(PITCH_4);

        delay(20);
        paly(PITCH_6);

        delay(50);
        paly(PITCH_2);

        delay(50);
        paly(PITCH_1);

