// Write a private version of scanf analogous to minprintf from the previous
// section.

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void minscanf(char *fmt, ...)
{
  va_list ap;
  char *p;
  char word[100];
  int *iArg;
  char *sArg;

  va_start(ap, fmt);
  for (p = fmt; *p; p++)
  {
    if (*p != '%')
      continue;
      
    scanf("%s", word);
    switch(*++p)
    {
    case 's':
      sArg = va_arg(ap, char *);
      strcpy(sArg, word);
      break;
    case 'd':
      iArg = va_arg(ap, int *);
      *iArg = atoi(word);
      break;
    }
  }
  va_end(ap);
}

int main()
{
  int i, j;
  char s[100];
  
  minscanf("%d %s %d", &i, s, &j);

  printf("%d %s %d\n", i, s, j);
}