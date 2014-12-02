#include "project2.h"

void test() interrupt 2
{
  transmit("interrupt", 9);
  return;
}

void main()
{
  int mode = 0;
  P2M1 = 0;
  P1M1 = 0;
  P0M1 = 0;

  EA = 1;
  EX0 = 1;
  EX1 = 1;

  transmit("song 1", 6);
  transmit("song 2", 6);

  while(1)
  {
		mode = mode1(mode);
		mode = mode2(mode);
		mode = mode3(mode);
		mode = 0;
    /*switch (mode)
    {
      case 0:
        mode = mode1(mode);
				break;

      case 1:
        mode = mode2(mode);
				break;

      case 2:
        mode = mode3(mode);
				break;
			
			case 3:
				mode = 0;
    }*/
  }
}
