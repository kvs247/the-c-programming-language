// Modify the programs entab and detab (written as exercises in Chapter 1) to
// accept a list of tab stops as arguments. Use the default tab setting if
// there are no arguments.

#include <stdio.h>

#define DEFAULT_TAB_STOP 2

int main(int argc, char *argv[])
{
  while (--argc > 0)
  {
    char *c = *++argv;
    printf("%s\n", c);
  }

  char x = getchar();
  printf("%c\n", x);

  return 0;
}