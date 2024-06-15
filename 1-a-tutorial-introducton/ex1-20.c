// Write a program `detab` that replaces tabs in the input with the proper
// number of blanks to space to the next tab stop. Assume a fixed set of tab
// stops, say every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define TAB_STOP 2

int main()
{
  int c, i;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      for (i = 0; i < TAB_STOP; i++)
        putchar(' ');
    }
    else
      putchar(c);
  }
}