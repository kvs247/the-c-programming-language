// Write the program expr, which evalutaes a reverse Polish expression from
// the command line, where each operator or operand is a separate argument. For
// example,
//     expr 2 3 4 + *
// evaluates 2 x (3 + 4)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void push(double);
double pop();
void top();

int main(int argc, char *argv[])
{
  double op2;

  while (--argc > 0)
  {
    char *c = (*++argv);

    if (isdigit(*c))
    {
      push(atof(c));
      continue;
    }

    if (strlen(c) > 1)
      printf("handle non char input\n");

    switch (*c)
    {
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else 
        printf("error: divide by zero");
      break;
    }
  }
  printf("result: %.8g\n", pop());

  return 0;
}

#define MAXVAL 1024

int valp = 0;
double val[MAXVAL];

void push(double x)
{
  if (valp < MAXVAL)
    val[valp++] = x;
  else
    printf("push() error: value stack is full\n");
}

double pop()
{
  if (valp != 0)
    return val[--valp];
  else
  {
    printf("pop() error: stack is empty\n");
    return 0.0;
  }
}

void top()
{
  printf("t: %f\n", val[valp - 1]);
}