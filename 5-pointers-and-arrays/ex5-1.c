// As written, getint treats a + or - not followed by a digit as a valid
// representation of zero. Fix it to push such a character back on the input.

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))  /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c); /* it's not a number*/
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '-' || c == '+')
  {
    if (!isdigit(c = getch()))
    {
      ungetch(c);
      ungetch(sign == -1 ? '-' : '+');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main()
{
  int n = -999;
  int *pn = &n;

  int res = getint(pn);
  printf("res: %d\n", res);

  printf("n: %d\n", n);

  return 0;
}

#define BUFSIZE 128

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("Buffer full\n");
  else
    buf[bufp++] = c;

  int i;
  printf("buf: ");
  for (i = 0; i < bufp; i++)
    printf("%c", buf[i]);
  printf("\n");
}