// Write a pointer version of the function strcat that we showed in Chapter 2:
// strcat(s,t) copies the string t to the end of s.

#include <stdio.h>
#include <string.h>

void strCat(char *s, char *t)
{
  s += strlen(s);
  while (*s++ = *t++);
}

int main()
{
  char s[] = "first string";
  char t[] = " second string";

  strCat(s, t);

  printf("%s\n", s);

  return 0;
}