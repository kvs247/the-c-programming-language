// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
// others unchanged.

#include <stdio.h>

int invert(int x, int p, int n)
{
  int mask = ((1 << n) - 1) << p - n + 1;

  int flippedBits = ~x & mask;

  int xMasked = x & ~mask;

  return xMasked | flippedBits;
}

int main()
{
  printf("19: %d\n", invert(31, 3, 2));
  printf("31: %d\n", invert(19, 3, 2));
  printf("19: %d\n", invert(21, 2, 2));

  return 0;
}