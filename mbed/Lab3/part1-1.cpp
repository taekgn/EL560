{\rtf1\ansi\ansicpg1252\cocoartf2576
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fswiss\fcharset0 Helvetica-Bold;\f2\froman\fcharset0 TimesNewRomanPSMT;
}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\ri-340\sl259\slmult1\partightenfactor0

\f0\fs16 \cf0 #include "mbed.h"\
\
volatile int counter = 0;\
volatile char drive = 0x08;\
void T1_isr (void); // Prototype\
\
Ticker Step; \
BusOut leds(LED1,LED2,LED3,LED4);\
\
void T1_isr ()\
\{  counter++; \
   if (counter >= 2000) //
\f1\b Multiplied counter by 2 for 2 seconds
\f2\b0 \

\f0      \{\
      if (drive == 0x01) drive = 0x08; //wrap round\
      else drive >>= 1;     //Binary Left Shift Operator\
      counter = 0;\
      leds = drive;      // update drive waveform\
      \}\
\}\
\
int main()\
\{ \
   Step.attach_us(&T1_isr, 1000);   //initializes ticker with period of 1msec\
                                  //and attaches it to T1 ISR\
   leds = drive; //output first pattern\
    while(1) \{ //do nothing\
        \}\
\}\
}