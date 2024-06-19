// Add access to library functions like sin, exp, and pow. See <math.h> in
// Appendix B, Section 4.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define IDENTIFIER '1'
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);
void printtop(void);
void duplicate(void);
void swaptop(void);
void clear(void);
void handlename(char[]);

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
      // printf("%f\n", atof(s));
      push(atof(s));
      break;
    case IDENTIFIER:
      // printf("%s\n", s);
      handlename(s);
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
      break;
    case '?':
      printtop();
      break;
    case '#':
      duplicate();
      break;
    case '~':
      swaptop();
      break;
    case '!':
      clear();
      break;
    case '\n':
      printf("res:\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

void handlename(char s[])
{
  // printf("s: %s\n", s);
  if (strcmp(s, "sin") == 0)
    push(sin(pop()));
  else if(strcmp(s, "cos") == 0)
    push(cos(pop()));
  else if(strcmp(s, "exp") == 0)
    push(exp(pop()));
  else
    printf("Unknown identifier\n");

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
  int i = 0;
  int c, sign;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  /* check for word */
  if (isalpha(c))
  {
    while(isalpha(s[i++] = c))
    {
      c = getch();
    }
    s[--i] = '\0';
    if (c == EOF)
      ungetch(c);
    return IDENTIFIER;
  }

  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */

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

void printtop() /* print top element of stack without popping it */
{
  printf("Top: ");
  if (sp > 0)
    printf("%f\n", val[sp - 1]);
  else
    printf("empty\n");
}

void duplicate() /* duplicate top element of stack */
{
  double temp = pop();
  push(temp);
  push(temp);
}

void swaptop() /* swap the two top elements */
{
  if (sp < 2)
    printf("Less than two items in stack\n");
  else
  {
    double ele1 = pop();
    double ele2 = pop();

    push(ele1);
    push(ele2);
  }
}

void clear() /* clear stack */
{
  sp = 0;
}
