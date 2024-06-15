// Write a function reverse(s) that reverses the character string s.
// Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(int len, char s[], char srev[]);
void wipe(char s[], int len);

int main()
{
  int len;

  char line[MAXLINE];
  char linerev[MAXLINE];

  while ((len = getLine(line, MAXLINE)) != 0)
  {
    wipe(linerev, MAXLINE);
    reverse(len, line, linerev);
    printf("%s", linerev);
  }

  return 0;
}

int getLine(char s[], int lim)
{
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n')
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

void reverse(int len, char s[], char srev[])
{
  int i;

  for (i = 0; i < len; i++)
  {
    srev[len - i - 1] = s[i];
  }

  srev[len] = '\0';
}

void wipe(char s[], int len)
{
  int i;
  for (i = 0; i < len; i++)
    s[i] = '\0';
}