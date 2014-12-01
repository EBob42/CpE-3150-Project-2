#include "project2.h"

void test() interrupt 2
{
  transmit("interrupt", 9);
  return;
}

int main()
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
    switch mode
    {
      case 0:
        mode1(mode);

      case 1:
        mode2(mode);

      case 2:
        mode3(mode);
    }
  }
  return 0;
}
