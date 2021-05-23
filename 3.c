#include<avr/io.h>

extern void disp_init(void);
extern unsigned char led_buf[];

void init_ADC(void)
{
    ADMUX=0X80;
    ADCSRA=0XC3;
    while(!(ADCSRA&0X10));
    ADCSRA|=0X10;
}
unsigned int ADC_READ(unsigned char channel)
{
    unsigned int v,vh,vl;
    ADMUX=0X80|channel;
    ADCSRA|=0X43;
    while(!(ADCSRA&0X10));
    ADCSRA|=0X10;
    vl=ADCL;
    vh=ADCH;
    v=vl|(vh<<8);
    return v;
}

void delay(unsigned int t)
{
    unsigned int a,b;
        for(a=0;a<1000;++a)
            for(b=0;b<t;++b);
}

int main()
{
    unsigned int adc_value = 12.34f;
    unsigned int channel = 0;
    unsigned int pin_e = 0;

    disp_init();
    init_ADC();

    DDRE = 0x00;
    PORTE = 0xff;

    while(1)
        {
            delay(10);
            adc_value=ADC_READ(0);
            adc_value=adc_value*5000.0f/1024.0f;
            led_buf[0]=(int)(adc_value*0.1)%10;
            led_buf[1]=(int)(adc_value*0.01)%10;
            led_buf[2]=(int)(adc_value*0.001)%10;
            led_buf[3]=(int)(adc_value*0.0001)%10;
            led_buf[4]=2;
        }
}
