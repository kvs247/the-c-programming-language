// Write a program that prints its input one word per line.

#include <stdio.h>

int main()
{
  int c;
  int inWord = 1;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (inWord)
      {
        putchar('\n');
        inWord = 0;
      }
    }
    else
    {
      inWord = 1;
      putchar(c);
    }
  }

  return 0;
}