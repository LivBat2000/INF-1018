#include <stdio.h>

int odd_ones(unsigned int x) {
  int y = 0;
  while (x)
  {
    if (x & 1)
    {
      y = y^1;
    }
    x = x>>1;
  }
  return y;
}

int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}