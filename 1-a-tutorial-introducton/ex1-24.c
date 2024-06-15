// Write a program to check a C program for rudimentary syntax errors like
// unbalanced parentheses, brackets and braces. Don't forget about quotes,
// both single and double, escape sequences, and comments. (This program is
// hard if you do it in full generality.)

// definitely not complete but good enough for now

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
  int nl = 1;
  int inEsc = 0;
  int inComment = 0;
  int inSQuote = 0;
  int inDQuote = 0;
  char cq[CHAR_QUEUE_SIZE];
  int cqi = 0;

  for (i = 0; i < CHAR_QUEUE_SIZE; i++)
    cq[i] = '\0';

  while ((c = getchar()) != EOF)
  {
    if (inEsc)
    {
      if (
          c == 'a' ||
          c == 'b' ||
          c == 'e' ||
          c == 'f' ||
          c == 'n' ||
          c == 'r' ||
          c == 't' ||
          c == 'v' ||
          c == '?' ||
          c == '\\' ||
          c == '\'' ||
          c == '\"')
      {
        putchar(c);
        inEsc = 0;
        continue;
      }
      else
        die("invalid escape sequence", nl);
    }

    if (!inSQuote && !inDQuote && !inComment && cq[cqi - 1] == '/')
    {
      if (c == '*')
        inComment = 1;
      else
        cq[--cqi] = '\0';
    }
    if (inComment && cq[cqi - 1] == '*')
    {
      if (c == '/')
      {
        inComment = 0;
        cq[--cqi] = '\0';
        cq[--cqi] = '\0';
      }
    }

    switch (c)
    {
    case '\n':
    {
      if (inSQuote)
        die("missing closing \'", nl);
      if (inDQuote)
        die("missing closing \"", nl);
      nl++;
    }
    break;
    case '(':
    case '[':
    case '{':
      if (!inSQuote && !inDQuote)
        cq[cqi++] = c;
      break;
    case ')':
      if (!inSQuote && !inDQuote && cq[--cqi] != '(')
        die("unmatched closing )", nl);
      cq[cqi] = '\0';
      break;
    case ']':
      if (!inSQuote && !inDQuote && cq[--cqi] != '[')
        die("unmatched closing ]", nl);
      cq[cqi] = '\0';
      break;
    case '}':
      printf("\n%s\n", cq);
      if (!inSQuote && !inDQuote && cq[--cqi] != '{')
        die("unmatched closing }", nl);
      cq[cqi] = '\0';
      break;
    case '\'':
      if (!inSQuote && !inDQuote)
      {
        cq[cqi++] = '\'';
        inSQuote = 1;
      }
      else if (inSQuote)
      {
        if (cq[--cqi] != '\'')
          die("unmatched closing \'", nl);
        cq[cqi] = '\0';
        inSQuote = 0;
      }
      break;
    case '\"':
      if (!inSQuote && !inDQuote)
      {
        cq[cqi++] = '\"';
        inDQuote = 1;
      }
      else if (inDQuote)
      {
        if (cq[--cqi] != '\"')
          die("unmatched closing \"", nl);
        cq[cqi] = '\0';
        inDQuote = 0;
      }
      break;
    case '\\':
      if (inSQuote || inDQuote)
        inEsc = 1;
      break;
    case '/':
      if (!inSQuote && !inDQuote && !inComment)
        cq[cqi++] = c;
      break;
    case '*':
      if (inComment)
        cq[cqi++] = c;
    default:
      inEsc = 0;
    }
    putchar(c);
  }

  if (cq[0] != '\0')
  {
    printf("\n%s\n", cq);
    die("unclosed item", nl);
  }

  printf("\nPassed!\n");

  return 0;
}