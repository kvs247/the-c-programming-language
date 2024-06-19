// Define a macro swap(t,x,y) that interchanges two arguments of type t.
// (Block structure will help.)

#include <stdio.h>

#define swap(t, x, y) t temp = x; x = y; y = temp;

int main()
{
  int x = 5;
  int y = 50;
  swap(int,x,y);
  printf("x: %d, y: %d\n", x, y);

  return 0;
}