#include <avr/io.h>
#include <avr/interrupt.h>

#define LDO 262
#define LRE 294
#define LMI 330
#define LFA 349
#define LSO 392
#define LLA 440
#define LXI 494
#define DO 523
#define RE 587
#define MI 659
#define FA 698
#define SO 784
#define LA 880
#define XI 988
#define HDO 1047
#define HRE 1175
#define HMI 1319
#define HFA 1397
#define HSO 1568
#define HLA 1760
#define HXI 1976

unsigned char status = 0;

unsigned int song[] =
{
    SO,LA,SO,FA,MI,RE,
    DO,SO,
    DO,MI,HDO,XI,LA,MI,
    SO,SO,
    LA,XI,LA,SO,FA,MI,
    RE,LA,
    LXI,LLA,LSO,LSO,DO,RE,
    MI,MI,
    SO,LA,SO,FA,MI,RE,
    DO,SO,
    DO,MI,HDO,XI,HRE,HDO,
    LA,LA,
    HDO,XI,LA,SO,
    LA,SO,FA,MI,
    XI,LLA,LSO,LSO,RE,
    DO,DO
};

void delay()
{
    unsigned int i , j ;
    for(i=0 ; i<50; i++)  
    {
        for (j = 0 ; j < 175 ; j++ )
            ;
    }
}
void port_init(void)
{
    DDRB = 0xff; 
    PORTB = 0xff;
    DDRE = 0xff;
    PORTE = 0B11111111;
}

ISR(INT7_vect) 
{
    if (status == 0)
    {
        status = 1;
        return;
    }

    DDRB = 0B00001111;
    PORTB = 0xf0;
    
    while(1)
    {
        if (PINE == 0b10111111)
            break;
    }
    PORTB = 0x00;
    DDRB = 0B00100000;
}

void interrupt_init()
{
    
    
    SREG = 0b10000000;//状态寄存器 I为全局中断触发禁止位

    EIMSK = 0b10000000;//外部中断屏蔽寄存器  外部中断请求7使能
    EICRA = 0x00;//外部中断控制寄存器A
    EICRB = 0b10000000;//外部中断控制寄存器B ，只要信号持续时间大于一个时钟周期，中断就会发生
    sei();//全局中断使能
}
void timer_init()
{   
    TCCR1A = 0b01000000;//通道A的比较输出模式 比较匹配时OC1A电平取反
    TCCR1B = 0b00001001;//CTC mode    时钟源无预分频
    TCCR1C = 0b10000000;//强制输出比较通道A
    
}

void main(void)
{   
    port_init();
    interrupt_init();
    timer_init();
    

   while(1)
    {
        while(1)
    {
        if (status == 0)                   
        {
            if (PINE == 0xfe)                 //BUTTON 0
            {
                OCR1A = 1000000/2/ HDO;
                DDRB = 0x20;
            }
            else if (PINE == 0xfd)          //BUTTON 1
            {
                OCR1A = 1000000/2/HRE;
                DDRB = 0x20;

            }
            else if (PINE == 0xfb)        //BUTTON2
            {
                OCR1A = 1000000/2/HMI;

                DDRB = 0x20;
            }
            else if (PINE == 0xf7)        //BUTT6ON3
            {
                OCR1A = 1000000/2/HFA;

                DDRB = 0x20;
            }
            else if (PINE == 0xef)         //BUTTON4
            {
                OCR1A = 1000000/2/HSO;

                DDRB = 0x20;
            }
            else if (PINE == 0xdf)         //BUTTON5
            {
                OCR1A = 1000000/2/HLA;

                DDRB = 0x20;
            }
            else if (PINE == 0xbf)          //BUTTON6
            {
                OCR1A = 1000000/2/HXI;

                DDRB = 0x20;
            }
            else
            {   
                DDRB = 0x00;
            }   
        }
        else if (status == 1)
        {
            DDRB = 0x20; //PB5 00100000
                int len = sizeof(song) / sizeof(unsigned int);
                int step = 0;
                while(step<len)
                {
                    OCR1A = 1000000/2/song[step];
                    delay();
                    step++;
                }
                status = 0;
        }
    }
    }
}
