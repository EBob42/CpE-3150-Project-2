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

int mode1(int mode)  //plays random sound when button is pressed
{
  bool x = true;
  LED9 = 0;
  //transmit("Mode 1", 6);

  while(x == true)
  {
    if(!SW1)  //500hz sound
    {
	  x = play_note(500, 1);
    }

    else if(!SW2) //4000hz sound
    {
      x = play_note(4000, 1);
    }

    else if(!SW3) //10000hz sound
    {
      x = play_note(10000, 1);
    }
	else if (!SW9)
	{
	  x = 0;
	}
  }

  LED9 = 1;

  return mode + 1;
}

int mode2(int mode)
{
	bool x = true;
	LED8 = 0;
	
	while(x == true)
	{
		if(SW1 == 0)
		{
			x = playSong(STAR);
		}
		else if(SW2 == 0)
		{
			x = playSong(SORC);
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

	LED8 = 1;
	
	return mode + 1;
}

//TODO: Decide if we need a 3rd mode
int mode3(int mode)
{
	return mode + 1;
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
