#include "project2.h"
#include <reg932.h>

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

int mode1(int mode)  //plays random sound when button is pressed
{
  LED9 = 0;
  transmit(mode1, 5);

  while(SW9)
  {
    if(SW1)  //500hz sound
    {
      TMOD = 0x01;
      TL0 = 0xCD;
      TH0 = 0xF8;
      TR0 = 1;

      if(TF0)
      {
        TR0 = 0;
        TF0 = 0;
        SPK = ~SPK;
      }

    }

    else if(SW2) //4000hz sound
    {
      TMOD = 0x01;
      TL0 = 0x1A;
      TH0 = 0xFF;
      TR0 = 1;

      if(TF0)
      {
        TR0 = 0;
        TF0 = 0;
        SPK = ~SPK;
      }

    }

    else if(SW3) //10000hz sound
    {
      TMOD = 0x01;
      TL0 = 0xA4;
      TH0 = 0xFF;
      TR0 = 1;

      if(TF0)
      {
        TR0 = 0;
        TF0 = 0;
        SPK = ~SPK;
      }
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