// Given the basic framework, it's straightforward to extend the calulator. 
// Add the modulus (%) operator and provisions for negative numbers.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calulator */
int main()
{
  int type;
  double op1, op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      printf("%f\n", atof(s));
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push((double)((int)pop() % (int)op2));
      else
        printf("error: zero divisor\n");
    case '\n':
      printf("res:\t%.8g\n", pop());
      return 0;
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack error\n");
    return 0.0;
  }
}

int getch(void);
void ungetch(int);

/* get next operator or numeric operand */
int getop(char s[])
{
  int i, c, sign;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */

  i = 0;

  /* check for negative number */
  if (c == '-')
  {
    c = getch();
    if (!isdigit(c))
    {
      ungetch(c);
      return '-';
    }
    s[++i] = c;
  }

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fractional part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
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
