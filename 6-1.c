#include<avr/io.h>
//OC1A PB5 OC1B PB6 OC1C PB7
void port_init(void)
{
    DDRB=0xff;
    PORTB=0xff;
}
//8位PWM，256分频
//模式5， 01 TOP 0x00FF
void timer1_init(int i)
{
    //OCR1A OCR1B OCR1C 输出比较寄存器 16位寄存器 
    //和T/C做比较，比较匹配结果置位比较匹配标志， 产生输出比较中断请求
    OCR1AL=i;//1000000/(256*6.667)-1=584.9
    OCR1BL=i+80;
    OCR1CL=i+160;
    //TCCR1A TCCR1B TCCR1C 控制寄存器 8位寄存器
    TCCR1A=0b10101001;
    //模式5，00 0 01 100
    TCCR1B=0b00000010;
    TCCR1C=0b00000000;
    
}
void delay(unsigned int t)
{
    int i=0,j=0;
    for(i=0;i<1000;i++)
        {for(j=0;j<t;j++)
        {
        }
        }
}
void main()
{
    port_init();
    timer1_init(10);
    int num=0;
    while(1)
    {
         OCR1AL=num;
         OCR1BL=num+80;
         OCR1CL=num+160;
         num=num+5;
         delay(10);
    }
}
