// Write getfloat, the floating-point analog of getint. What type does
// getfloat return as its function value?

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
  int c, sign, power;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c); /* it's not a number*/
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '-' || c == '+')
  {
    ungetch(c);
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.')
  {
    power = 1;
    while((c = getch()) != EOF && isdigit(c))
    {
      *pn = 10 * *pn + (c - '0');
      power *= 10;
    }
    *pn /= power;
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main()
{
  float n = -999.999;
  float *pn = &n;

  int res = getfloat(pn);
  printf("res: %d\n", res);

  printf("n: %f\n", n);

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