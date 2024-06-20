// Write the function strend(s,t) which returns 1 if the string t occurs at
// the end of the string s, and zero otherwise.

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
  int sl = strlen(s);
  int tl = strlen(t);

  if (tl > sl)
    return 0;

  s += sl - tl;
  for (;*t != '\0'; s++, t++)
    if (*s != *t)
      return 0;

  return 1;
}

int main()
{
  int x = strend("start", "art");
  printf("x: %d\n", x);

  return 0;
}