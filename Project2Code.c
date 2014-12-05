#include "project2.h"

void test() interrupt 2
{
  transmit("interrupt", 9);
  return;
}


//TODO: Come up with the extra stuff we want to add
//			(each person decide stuff, we can probably
//			work together to make it happen).
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

  //playSong(STAR);

  while(1)
  {
		mode = mode1(mode);
	    delay();

		mode = mode2(mode);
		delay();

		mode = mode3(mode);
		delay();

		mode = 0;
  }
}
