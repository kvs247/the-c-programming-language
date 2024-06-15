// Revise the main routine of the longest-line program so it will correctly
// print the length of arbitrarilt long input lines, and as much as possible
// of the text.

#include <stdio.h>
#define MAXLINE 10

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)
    printf("%s\n", longest);

  return 0;
}

int getLine(char s[], int lim)
{
  int c, si, len;

  len = 0;
  si = 0;
  while ((c = getchar()) != EOF && c != '\n')
  {
    ++len;
    if (si < lim)
    {
      s[si] = c;
      ++si;
    }
  }
  if (c == '\n' && si < lim)
  {
    s[si] = c;
    ++len;
  }

  s[si - 1] = '\0';
  return len;
};

void copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
};