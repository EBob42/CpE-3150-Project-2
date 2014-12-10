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
  P2M1 = 0;
  P1M1 = 0;
  P0M1 = 0;

	IEN0 = 0x88;
	
  transmit("song 1", 6);
  transmit("song 2", 6);

  //playSong(STAR);

  while(1)
  {
		mode1();
	    delay();

		mode2();
		delay();

		mode3();
		delay();
  }
}
