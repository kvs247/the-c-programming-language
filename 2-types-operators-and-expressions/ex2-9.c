// int bitcount(unsigned x)
// {
//   int b;

//   for (b = 0; x != 0; x >>= 1)
//   {
//     if (x & 01)
//       b++;
//   }
//   return b;
// }
// In a two's complement number system, x &= (x-1) deletes the rightmost bit
// in x. Explain why. Use this observation to write a faster version of
// bitcount.

// Explanation:
// The action of -1 in binary will decrement the rightmost 1-bit by 1, and
// then increment all remaining bits (which are 0) by 1. Then, taking the &
// operation of the original number with the new -1 number will necessarily
// result in the removal of the rightmost 1 from the original number since the
// -1 number has a 0 in that position, and the remaining bits in the original 
// number are 0 so they will all result to 0 after the & operation.

#include <stdio.h>

int bitcount(unsigned x)
{
  int b = 0;

  while (x != 0)
  {
    x &= (x - 1);
    b++;
  }

  return b;
}

int main()
{
  printf("2: %d\n", bitcount(10));
  printf("2: %d\n", bitcount(17));
  printf("1: %d\n", bitcount(32));
  printf("4: %d\n", bitcount(27));
  printf("5: %d\n", bitcount(31));

  return 0;
}