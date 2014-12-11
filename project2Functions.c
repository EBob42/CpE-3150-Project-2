#include "project2.h"

/**********************************************************
	* transmit
	*	@desc		Transmits serially using the uart library
	*
	*	@param1 String to be sent serially
	*	@param2 Size of the string to be sent
**********************************************************/
void transmit(unsigned char msg[], unsigned char size)
{
  unsigned char i = 0;

	uart_init();
	EA = 1;
	
  for(i = 0; i < size; i++)
  {
    uart_transmit(msg[i]);
  }
	uart_transmit('\n');
  uart_transmit('\0');
	
	EA = 0;
	
  return;
}

/**********************************************************
	* mode1
	*	@desc		Operates mode 1 of the program:
	*					Playing sounds on button press,
	*					similar to a keyboard
**********************************************************/
void mode1()
{
  bool x = true;
  LED9 = 0;

  while(x == true)
  {
    if(!SW1)  //C sound
    {
			setSevenSeg();
			SSB = 0;
			SSC = 0;
			SSG = 0;
			x = play_note(C6, 1);
			clearSevenSeg();
    }

    else if(!SW2) //D sound
    {
			setSevenSeg();
			SSA = 0;
			SSF = 0;
      x = play_note(D6, 1);
			clearSevenSeg();
    }

    else if(!SW3) //E sound
    {
			setSevenSeg();
			SSB = 0;
			SSC = 0;
      x = play_note(E6, 1);
			clearSevenSeg();
    }
		else if (!SW9)
		{
			x = 0;
		}
  }

  LED9 = 1;
}

/**********************************************************
	* mode2
	*	@desc		Operates mode 2 of the program:
	*					Playing music stored in code memory
	*					on button press
**********************************************************/
void mode2()
{
	bool x = true;
	
	while(x == true)
	{
		LED8 = 0;
		if(SW1 == 0)
		{			
			clearSevenSeg();

			SSB = 1;
			SSC = 1;
			x = playSong(STAR);
			SSB = 0;
			SSC = 0;
		}
		else if(SW2 == 0)
		{
		  setSevenSeg();
      SSC = 0;
			SSF = 0;

			x = playSong(SORC);

			clearSevenSeg();
		}
		else if (SW9 == 0)
		{
		  x = false;
		}
	}

  clearSevenSeg();
	LED8 = 1;
}

/**********************************************************
	* mode3
	*	@desc		Operates mode 3 of the program:
	*					Counter from 0 to F with rollover
	*					(similar to project 1)
	*					Output on the connected
	*					7 segment display
**********************************************************/
void mode3()
{
  bool x = true;
	bool y = true;
	unsigned char count = 0;
	unsigned char adder;
	bool adding = false;
	
	LED7 = 0;
	
	updateCount(count);
	
	while(x)
	{
		if(!SW1)
		{
			count++;
			if(count == 16)
			{
				count = 0;
				play_note(C6, 6);
				play_note(E6, 6);
				play_note(G6, 6);
				play_note(C7, 6);
			}
			updateCount(count);
	  }

		if(!SW3)
		{
		  count--;
			if(count == 255)
			{
				count = 15;
				play_note(C7, 6);
				play_note(G6, 6);
				play_note(E6, 6);
				play_note(C6, 6);
			}
			updateCount(count);
		}
		
		delay();
		
	  if(SW9 == 0)
		{
			x = false;
		}

		if(!SW2)
		{
			y = true;

   		delay();
			clearSevenSeg();
		  while(y)
			{
				SSA = 1;
				y = smDelay();
					
				if(!y)
					break;
						
				SSA = 0;
				SSB = 1;
				y = smDelay();
						
				if(!y)
					break;
					
				SSB = 0;
				SSC = 1;
				y = smDelay();
					
				if(!y)
					break;
					
				SSC = 0;
				SSD = 1;
				y = smDelay();
					
				if(!y)
					break;
					
				SSD = 0;
				SSE = 1;
				y = smDelay();
					
				if(!y)
					break;
					
				SSE = 0;
				SSF = 1;
				y = smDelay();
					
				if(!y)
					break;
			
				SSF = 0;
			}
			updateCount(count);
		}
		
		if(!SW4)
		{
			if(adding == 0)
			{
				adder = count;
				count = 0;
				updateCount(count);
				adding = true;
			}
			
			else
			{
				count = adder + count;
				if (count > 15)
				{
					count = count % 16;
					play_note(B6, 1);
					play_note(E7, 7);
				}
				adding = false;
				updateCount(count);
			}
			
			delay();
		}
	}
	
	clearSevenSeg();
	LED7 = 1;
}

/**********************************************************
	* delay
	*	@desc		A delay function, approximately
	*					0.2 seconds. Also, works without
	*					stopping timer 1 if running
**********************************************************/
void delay()
{
	char i = 0;

  TMOD = TMOD & 0xf0;
	TMOD = TMOD | 0x01;
	TH0 = 0x00;
	TL0 = 0x00;
	for(i = 0; i < 12; i++)
	{
	  TR0 = 1;
	  while(TF0 == 0);
	  TR0 = 0;
	  TF0 = 0;
	}

  return;
}

/**********************************************************
	* setSevenSeg
	*	@desc		Turns on all segments
	*					on the seven segment display
**********************************************************/
void setSevenSeg()
{
	SSA = 1;
	SSB = 1;
	SSC = 1;
	SSD = 1;
	SSE = 1;
	SSF = 1;
	SSG = 1;

	return;
}

/**********************************************************
	* clearSevenSeg
	*	@desc		Turns off all segments
	*					on the seven segment display
**********************************************************/
void clearSevenSeg()
{
	SSA = 0;
	SSB = 0;
	SSC = 0;
	SSD = 0;
	SSE = 0;
	SSF = 0;
	SSG = 0;
	
	return;
}

/**********************************************************
	* Pattern
	*	@desc		Timer 1 interrupt, for use
	*					during mode 2, to generate
	*					a simple light pattern while
	*					playing the song,
	*					with a .2 second delay
	*					between pattern changes
**********************************************************/
void Pattern() interrupt 3
{
	static bool current = 0;
	static unsigned char x = 0;
	if (x == 0)
	{
		TF1 = 0;
		switch (current)
		{
			case 0:
				LED1 = 0;
				LED2 = 1;
				LED3 = 0;
				LED4 = 1;
				LED5 = 0;
				LED6 = 1;
				LED7 = 0;
				LED8 = 1;
				LED9 = 0;
				current = 1;
				break;
		
			case 1:
				LED1 = 1;
				LED2 = 0;
				LED3 = 1;
				LED4 = 0;
				LED5 = 1;
				LED6 = 0;
				LED7 = 1;
				LED8 = 0;
				LED9 = 1;
				current = 0;
				break;
		}
		x++;
	}
	else
	{
		x++;
		x = x % 12;
	}
}

/**********************************************************
	* clearLED
	*	@desc		Turns off all LED's
	*					on the board
**********************************************************/
void clearLED()
{
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	LED4 = 1;
	LED5 = 1;
	LED6 = 1;
	LED7 = 1;
	LED8 = 1;
	LED9 = 1;
}

/**********************************************************
	* smDelay
	*	@desc		Smaller delay function,
	*					approximately  seconds
**********************************************************/
bool smDelay()
{
  int i;
  bool x;
	
	TMOD = TMOD & 0xf0;
	TMOD = TMOD | 0x01;
  TH0 = 0;
	TL0 = 0;
  TR0 = 1;

  for(i = 0; i < 6; i++)
  {
    while(!TF0);  
		TF0 = 0;
  }

  if(!SW2)
    x = false;
  
  return x;
}

/**********************************************************
	* updateCount
	*	@desc		Updates the seven segment display to
	*					show the current count
**********************************************************/
void updateCount(unsigned char count)
{
	switch(count)
	{
		case 0:
			setSevenSeg();
			SSG = 0;
			break;
		
		case 1:
			clearSevenSeg();
			SSB = 1;
			SSC = 1;
			break;
	
		case 2:
			setSevenSeg();
			SSC = 0;
			SSF = 0;
			break;
		
		case 3:
			setSevenSeg();
			SSE = 0;
			SSF = 0;
			break;
			
		case 4:
			setSevenSeg();
			SSA = 0;
			SSD = 0;
			SSE = 0;
			break;
			
		case 5:
			setSevenSeg();
			SSB = 0;
			SSE = 0;
			break;
			
		case 6:
			setSevenSeg();
			SSB = 0;
			break;
			
		case 7:
			clearSevenSeg();
			SSA = 1;
			SSB = 1;
			SSC = 1;
		
		case 8:
			setSevenSeg();
			break;
	
		case 9:
			setSevenSeg();
			SSE = 0;
			break;
		
		case 10:
			setSevenSeg();
			SSD = 0;
			break;
			
		case 11:
			setSevenSeg();
			SSA = 0;
			SSB = 0;
			break;
			
		case 12:
			setSevenSeg();
			SSB = 0;
			SSC = 0;
			SSG = 0;
			break;
			
		case 13:
			setSevenSeg();
			SSA = 0;
			SSF = 0;
			break;
		
		case 14:
			setSevenSeg();
			SSB = 0;
			SSC = 0;
			break;
			
		case 15:
			setSevenSeg();
			SSB = 0;
			SSC = 0;
			SSD = 0;
			break;
	}
}
