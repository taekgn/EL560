{\rtf1\ansi\ansicpg1252\cocoartf2576
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\froman\fcharset0 TimesNewRomanPSMT;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\ri-340\sl259\slmult1\partightenfactor0

\f0\fs16 \cf0 #include "mbed.h"\
#include "C12832.h"\
\
C12832 lcd(p5, p7, p6, p8, p11);\
\
volatile int counter = 0, seconds = 0, minutes = 0, hours = 0;
\f1 \

\f0 volatile int flag = 0;\
\
void led_switch(void);         //Prototypes\
void T1_isr(void);\
\
Ticker tick;\
DigitalOut myled(LED1);\
\
void led_switch()              //function blinks led\
\{\
    myled = !myled;\
\}\
\
void T1_isr()\
/* 1 interrupt every 10 milli sec \'96 so after 100 interrupts increase seconds and set flag */\
\{\
    counter++;\
    if (counter >= 10)       //1 second has passed?\
    \{\
        seconds++;        // Yes increment seconds\
        counter = 0;          // reset counter\
        flag = 1;             // set flag to update display\
        if (seconds >= 60) \{seconds = 0; minutes++; if(minutes >= 60) \{minutes = 0; hours++; if(hours >= 24) \{hours=0;\}\}\}
\f1 \

\f0     \}\
\}\
\
int main()\
/*initialise ticker with period of 10msec and attach it to T1_isr */\
\{\
    tick.attach_us(&T1_isr, 10000);//initializes the ticker with period of 10msec\
    //and attaches it to T1 ISR\
    lcd.cls();  //clear lcd display\
    lcd.locate(0, 0); //show charcters on top left\
    lcd.printf("Elapsed Time Monitor");\
    while (1) \{\
        while (flag == 0);
\f1 \

\f0         lcd.locate(0, 15);\
        lcd.printf("Elapsed H M S: %d %d %d", hours, minutes, seconds);     \
        flag = 0; //reset flag\
        led_switch();  //blink light\
    \}\
\}
\f1 \
}