/*****************************************************
	*	Project2Code.c
	*
	*	Main method for project 2
	*
	*	Eric Hopkins, Dillion Klobe, Brandon Becker
	***************************************************/

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
	
  while(1)
  {
		transmit("Keyboard", 8);
		mode1();
	  delay();

		transmit("Play Songs", 10);
		mode2();
		delay();

		transmit("Counter", 7);
		mode3();
		delay();
  }
}
