// Write a program to "fold" long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input. Make sure your program does something intelligent with very long
// lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define MAXLINE 100
#define MAXCOL 25
#define TAB_STOP 4

void printLine(char s[], int len);
int getLine(char s[], int lim);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) != 0)
  {
    printLine(line, len);
  }

  return 0;
}

void printLine(char s[], int len)
{
  int i, j, c;
  int lastSpaceIdx = 0;
  int mult = 1;

  i = 0;
  int indent = 0;
  while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
  {
    indent++;
    if (s[i] == '\t')
      indent += TAB_STOP - 1;

    i++;
  }

  for (i = 0; i < len; i++)
  {
    c = s[i];
    if (c == ' ' || c == '\t' || c == '\n')
    {
      if (i >= MAXCOL * mult && lastSpaceIdx > 0)
      {
        printf("\n");
        for (j = 0; j < indent - 1; j++)
          printf(" ");
        mult++;
      }
      for (j = lastSpaceIdx; j < i; j++)
        printf("%c", s[j]);

      lastSpaceIdx = i;
    }
  }
  putchar('\n');
}

int getLine(char s[], int lim)
{
  int c, i;

  i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
  {
    s[i] = c;
    ++i;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
