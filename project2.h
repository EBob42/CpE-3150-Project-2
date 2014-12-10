#ifndef PROJECT_H
#define PROJECT_H

#include "uart.h"
#include "music.h"
#include <reg932.h>

sbit LED1 = P2^4;
sbit LED2 = P0^6;
sbit LED3 = P2^5;
sbit LED4 = P0^5;
sbit LED5 = P1^6;
sbit LED6 = P0^7;
sbit LED7 = P2^7;
sbit LED8 = P0^4;
sbit LED9 = P2^6;

sbit SSA = P1^0;
sbit SSB = P1^1;
sbit SSC = P1^2;
sbit SSD = P1^3;
sbit SSE = P1^5;
sbit SSF = P3^0;
sbit SSG = P3^1;

sbit SPK = P1^7;

sbit SW1 = P2^0;
sbit SW2 = P0^2;
sbit SW3 = P2^1;
sbit SW4 = P0^1;
sbit SW5 = P1^4;
sbit SW6 = P0^3;
sbit SW7 = P2^3;
sbit SW8 = P0^0;
sbit SW9 = P2^2;

void transmit(char msg[], int size);
void mode1();
void mode2();
void mode3();
void delay();
void setSevenSeg();
void clearSevenSeg();
void Pattern();
void clearLED();

#endif
