// Write a function setbits(x,p,n,y) that returns x with the n bits that begin
// at position p set to the rightmost n bits of y, leaving the other bits
// unchanged.

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  int ymask = (1 << n) - 1;

  int ybits = (y & ymask) << p - n + 1;

  int xmask = ~(ymask << p - n + 1);

  int xmasked = x & xmask;

  return xmasked | ybits;
}

int main()
{
  printf("%u\n", setbits(15, 2, 2, 13));

  return 0;
}