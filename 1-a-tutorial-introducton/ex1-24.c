// Write a program to check a C program for rudimentary syntax errors like
// unbalanced parentheses, brackets and braces. Don't forget about quotes,
// both single and double, escape sequences, and comments. (This program is
// hard if you do it in full generality.)

#include <stdio.h>
#include <stdlib.h>

#define CHAR_QUEUE_SIZE 1000

void die(char err[], int nl)
{
  printf("\nError: %s on line %d.\n", err, nl);
  exit(1);
}

int main()
{
  int c, i;
  char cq[CHAR_QUEUE_SIZE];
  int cqi = 0;
  int nl = 1;

  for (i = 0; i < CHAR_QUEUE_SIZE; i++)
    cq[i] = '\0';

  while ((c = getchar()) != EOF)
  {
    switch (c)
    {
    case '\n':
      nl++;
      break;
    case '(':
      cq[cqi++] = '(';
      break;
    case ')':
      if (cq[--cqi] != '(')
        die("missing closing \')\'", nl);
      break;
    case '[':
      cq[cqi++] = '[';
      break;
    case ']':
      if (cq[--cqi] != '[')
        die("missing closing \']\'", nl);
      break;
    case '{':
      cq[cqi++] = '{';
      break;
    case '}':
      if (cq[--cqi] != '{')
        die("missing closing \'}\'", nl);    
      break;
    case '\'':
      break;
    case '\"':
      break;
    case '\\':
      break;
    case '/':
      break;
    }
    putchar(c);
  }

  printf("\n%s\n", cq);

  printf("Passed!\n");

  return 0;
}