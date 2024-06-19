// Adapt the ideas of printd to write a recursive version of itoa; that is,
// convert an integer into a string by calling a recursive routine.

#include <stdio.h>

int itoa(int x, char s[])
{
  int i = 0;

  if (x / 10)
    i = itoa(x / 10, s);
  else if (x < 0)
    s[i++] = '-';
    
  s[i++] = ((x < 0 ? -x : x) % 10) + '0';
  s[i] = '\0';

  return i;
}

int main()
{
  char s[128];

  itoa(13, s);
  printf("itoa(13) = %s\n", s);
  itoa(2018281828, s);
  printf("itoa(2018281828) = %s\n", s);
  itoa(-76, s);
  printf("itoa(-76) = %s\n", s);
  itoa(-365, s);
  printf("itoa(-365) = %s\n", s);
  itoa(0, s);
  printf("itoa(0) = %s\n", s);

  return 0;
}