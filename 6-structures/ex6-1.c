// Our version of getword does not properly handle underscores, string
// constants, comments, or preprocessor control lines. Write a better version.

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXWORD 100

int getword(char *, int);
int getch(void);
void ungetch(int);

int main()
{
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
    printf("%s\n", word);

  return 0;
}

int getword(char *word, int lim)
{
  int c;
  int inStrConst = 0;
  char *w = word;
  
  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c) && c != '_' && c != '\"' && c != '#')
  {
    *w = '\0';
    return c;
  }
  // printf("c: %c\n", c);
  int inStr = c == '\"' ? 1 : 0;
  for (; --lim > 0; w++)
  {
    *w = getch();
    if (c == '\"' && *w == '\"')
    {
      w++;
      break;
    }
    if (c != '\"' && !isalnum(*w) && *w != '_' && *w != '\"')
    {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp;          /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}