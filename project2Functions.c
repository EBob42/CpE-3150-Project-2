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

int mode1(int mode)  //plays random sound when button is pressed
{
  LED9 = 0;
  transmit("Mode 1", 6);

  while(SW9)
  {
    if(SW1)  //500hz sound
    {
			play_note(500, 1);
    }

    else if(SW2) //4000hz sound
    {
      play_note(4000, 1);
    }

    else if(SW3) //10000hz sound
    {
      play_note(10000, 1);
    }

    else if(SW9)
    {
      mode++;
      break;
    }
  }

  return mode;
}

int mode2(int mode)
{
	return mode;
}


int mode3(int mode)
{
	return mode;
}