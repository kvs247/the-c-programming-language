// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments do not
// nest.

#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void removeComment(char s[]);

int main()
{
  char line[MAXLINE];
  int len = 0;

  while ((len = getLine(line, MAXLINE)) != 0)
  {
    removeComment(line);
    printf("%s", line);
  }

  return 0;
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

void removeComment(char s[])
{
  int c, i;
  int inComment, inSQuote, inDQuote;

  inComment = inSQuote = inDQuote = 0;
  i = 0;
  while ((c = s[i++]) != '\0')
  {
    if (c == '\'')
      inSQuote = !inSQuote;
    if (c == '\"')
      inDQuote = !inDQuote;

    if (!inSQuote && !inDQuote)
    {
      if (c == '/')
      {
        if (inComment)
        {
          s[i - 2] = '\n';
          s[i - 1] = '\0';
        }
        else
          inComment = 1;
      }
    }
  }

  int isEmpty = 1;
  i = 0;
  while ((c = s[i++]) != '\0')
  {
    if (c != ' ' && c != '\t' && c != '\n')
    {
      isEmpty = 0;
      break;
    }
  }
  if (isEmpty && inComment)
    s[0] = '\0';
}