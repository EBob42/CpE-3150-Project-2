#include "project2.h"

void transmit(char msg[], int size)
{
  int i = 0;
  EA = 1;

  uart_init();

  for(i = 0; i < size; i++)
  {
    uart_transmit(msg[i]);
  }
  uart_transmit('\0');
  EA = 0;

  return;
}


//TODO: Determine if this is the desired functionality, or if
//			something more musical is desired.
//			Also, check the condition on this loop, determine how to
//			make sure we can change mode properly and what-not
//			And be sure of active high or low buttons, make sure 
//			if statements reflect that properly
//
//			Determine if the return and parameter are still needed

void mode1()  //plays random sound when button is pressed
{
  bool x = true;
  LED9 = 0;
  //transmit("Mode 1", 6);

  while(x == true)
  {
    if(!SW1)  //C sound
    {
	  x = play_note(C6, 1);
    }

    else if(!SW2) //D sound
    {
      x = play_note(D6, 1);
    }

    else if(!SW3) //E sound
    {
      x = play_note(E6, 1);
    }
	else if (!SW9)
	{
	  x = 0;
	}
  }

  LED9 = 1;
}

void mode2()
{
	bool x = true;
	LED8 = 0;
	
	while(x == true)
	{
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
		else if (SW3 == 0)
		{
			x = playSong(POKE);
		}
		else if (SW9 == 0)
		{
		  x = false;
		}
	}

    clearSevenSeg();
	LED8 = 1;
}

//TODO: Decide if we need a 3rd mode
void mode3()
{
  	bool x = true;
	bool y = true;
	int count = 0;
	
	LED7 = 0;
	
	while(x)
	{
		if(!SW1)
		{
			count++;
	  	}

		if(!SW3)
		{
		    count--;
		}
		
		delay();
		
	  if(SW9 == 0)
		{
			x = false;
		}
		
		else
		{
			if(count == 0)
			{
				setSevenSeg();
				SSG = 0;
			}
			
			else if (count == 1)
			{
				clearSevenSeg();
				SSB = 1;
				SSC = 1;
			}
			
			else if (count == 2)
			{
			  setSevenSeg();
				SSC = 0;
				SSF = 0;
			}
			
			else if (count == 3)
			{
			  setSevenSeg();
			  SSE = 0;
			  SSF = 0;
			}
			
			else if (count == 4)
			{
			  setSevenSeg();
				SSA = 0;
				SSD = 0;
				SSE = 0;
			}
			
			else if (count == 5)
			{
				setSevenSeg();
				SSB = 0;
				SSE = 0;
			}
			
			else if (count == 6)
			{
				setSevenSeg();
				SSA = 0;
				SSB = 0;
			}
			
			else if (count == 7)
			{
				clearSevenSeg();
				SSA = 1;
				SSB = 1;
				SSC = 1;
			}
			
			else if (count == 8)
			{
				setSevenSeg();
			}
			
			else if (count == 9)
			{
				setSevenSeg();
				SSD = 0;
				SSE = 0;
			}
			
			else if (count == 10)
			{
				setSevenSeg();
				SSD = 0;
			}
			
			else if (count == 11)
			{
				setSevenSeg();
				SSA = 0;
				SSB = 0;
			}
			
			else if (count == 12)
			{
				setSevenSeg();
				SSB = 0;
				SSC = 0;
				SSG = 0;
			}
			
			else if (count == 13)
			{
				setSevenSeg();
				SSA = 0;
				SSF = 0;
			}
			
			else if (count == 14)
			{
				setSevenSeg();
				SSB = 0;
				SSC = 0;
			}
			
			else if (count == 15)
			{
				setSevenSeg();
				SSB = 0;
				SSC = 0;
				SSD = 0;
			}
	    
			else if (count > 15)
			{
				count = 0;
				x = play_note(C6, 8);
				x = play_note(D6, 8);
				x = play_note(E6, 8);
			}

			else if(count < 0)
			{
			    count = 15;
				x = play_note(E6, 8);
				x = play_note(D6, 8);
				x = play_note(C6, 8);
			}
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
			}
	}
	
	clearSevenSeg();
	LED7 = 1;
}

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

void Pattern() interrupt 3
{
	static bool current = 0;
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
}

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

bool smDelay()
{
  int i;
  bool x;

  TMOD = 0x01;
  TH0 = -255;
  TR0 = 1;

  for(i = 0; i < 5; i++)
  {
    while(!TF0);  
	TF0 = 0;
  }

  if(!SW2)
    x = false;
  
  return x;
}
