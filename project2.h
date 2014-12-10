#ifndef PROJECT_H
#define PROJECT_H

#include "uart.h"
#include "music.h"
#include <reg932.h>

/**********************************************************
	* LED Declarations
**********************************************************/
sbit LED1 = P2^4;
sbit LED2 = P0^6;
sbit LED3 = P2^5;
sbit LED4 = P0^5;
sbit LED5 = P1^6;
sbit LED6 = P0^7;
sbit LED7 = P2^7;
sbit LED8 = P0^4;
sbit LED9 = P2^6;

/**********************************************************
	* Seven Segment Display Declarations
**********************************************************/
sbit SSA = P1^0;
sbit SSB = P2^4;
sbit SSC = P2^3;
sbit SSD = P0^0;
sbit SSG = P0^1;
sbit SSE = P1^4;
sbit SSF = P0^3;

/**********************************************************
	* Speaker Declarations
**********************************************************/
sbit SPK = P1^7;

/**********************************************************
	* Button Declarations
**********************************************************/
sbit SW1 = P2^0;
sbit SW2 = P0^2;
sbit SW3 = P2^1;
//sbit SW4 = P0^1;
//sbit SW5 = P1^4;
//sbit SW6 = P0^3;
sbit SW7 = P2^3;
//sbit SW8 = P0^0;
sbit SW9 = P2^2;

/**********************************************************
	* transmit
	*	@desc		Transmits serially using the uart library
	*
	*	@param1 String to be sent serially
	*	@param2 Size of the string to be sent
**********************************************************/
void transmit(char msg[], char size);

/**********************************************************
	* mode1
	*	@desc		Operates mode 1 of the program:
	*					Playing sounds on button press,
	*					similar to a keyboard
**********************************************************/
void mode1();

/**********************************************************
	* mode2
	*	@desc		Operates mode 2 of the program:
	*					Playing music stored in code memory
	*					on button press
**********************************************************/
void mode2();

/**********************************************************
	* mode3
	*	@desc		Operates mode 3 of the program:
	*					Counter from 0 to F with rollover
	*					(similar to project 1)
	*					Output on the connected
	*					7 segment display
**********************************************************/
void mode3();

/**********************************************************
	* delay
	*	@desc		A delay function, approximately
	*					0.2 seconds. Also, works without
	*					stopping timer 1 if running
**********************************************************/
void delay();

/**********************************************************
	* setSevenSeg
	*	@desc		Turns on all segments
	*					on the seven segment display
**********************************************************/
void setSevenSeg();

/**********************************************************
	* clearSevenSeg
	*	@desc		Turns off all segments
	*					on the seven segment display
**********************************************************/
void clearSevenSeg();

/**********************************************************
	* Pattern
	*	@desc		Timer 1 interrupt, for use
	*					during mode 2, to generate
	*					a simple light pattern while
	*					playing the song,
	*					with a .2 second delay
	*					between pattern changes
**********************************************************/
void Pattern();

/**********************************************************
	* clearLED
	*	@desc		Turns off all LED's
	*					on the board
**********************************************************/
void clearLED();

/**********************************************************
	* smDelay
	*	@desc		Smaller delay function,
	*					approximately 0.1 seconds
**********************************************************/
bool smDelay();

/**********************************************************
	* updateCount
	*	@desc		Updates the seven segment display to
	*					show the current count
	*
	* @param1 The value to be updated on the display
**********************************************************/
void updateCount(unsigned char count);

#endif
