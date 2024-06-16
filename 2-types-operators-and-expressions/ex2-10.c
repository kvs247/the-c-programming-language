// Rewrite the function lower, which converts upper case letters to lower
// case, with a conditional expression instead of if-else.

#include <stdio.h>

#define DIFF_UPP_LOW 32

char lower(char c)
{
  return (65 <= c && c <= 90) ? c + DIFF_UPP_LOW : c;    
}

int main()
{
  printf("A -> %c\n", lower('A'));
  printf("Z -> %c\n", lower('Z'));
  printf("K -> %c\n", lower('K'));
  printf("y -> %c\n", lower('y'));
  printf("7 -> %c\n", lower('7'));
  printf("@ -> %c\n", lower('@'));

  return 0;
}