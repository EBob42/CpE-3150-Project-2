#include "project2.h"

/*****************************************************
	*	main
	*	@desc	Primary running of the program
	***************************************************/
void main()
{
  P2M1 = 0;
  P1M1 = 0;
  P0M1 = 0;
  clearSevenSeg();
  
  IEN0 = 0x88;
	
  transmit("song 1", 6);
  transmit("song 2", 6);

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
