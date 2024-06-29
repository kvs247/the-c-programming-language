// Write a program that converts upper case to lower or lower case to upper,
// depending on the name it is invoked with, as found in argv[0].

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int c;
  int lower = 1;

  if (strcmp(argv[0], "./upper") == 0)
    lower = 0;

  while ((c = getchar()) != EOF)
  {
    if (lower)
      putchar(tolower(c));
    else
      putchar(toupper(c));
  }  

  return 0;
}