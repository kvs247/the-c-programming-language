// Write a function rightrot(x,n) that returns the value if the integer x
// rotated to the right by n bit positions.

#include <stdio.h>

int rightrot(int x, int n)
{
  // number of bits
  int nbits = 0;
  int xcpy = x;
  while (xcpy != 0)
  {
    xcpy >>= 1;
    nbits++;
  }

  int wrap = 0;
  while(n-- > 0)
  {
    wrap = x & 1;

    x >>= 1;
    if (wrap)
    {
      x = x | (1 << nbits - 1);
      wrap = 0;
    }
  }

  return x;
}

int main()
{
  printf("5: %d\n", rightrot(10, 1));
  printf("12: %d\n", rightrot(17, 2));
  printf("1: %d\n", rightrot(32, 5));
  printf("15: %d\n", rightrot(27, 3));
}