// Rewrite appropriate programs from earlier chapters and exercises with
// pointers instead of array indexing. Good possibilities include getline
// (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
// reverse (Chapter 3), and strindex and getop (Chapter 4).

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

int mygetline(char *s, int lim)
{
  int c;
  int i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
  {
    *s++ = c;
    i++;
  }
  if (c == '\n')
  {
    *s++ = '\n';
    i++;
  }
  *s = '\0';
  return i;
}

int atoi(char *s)
{
  int n, sign;

  for (;isspace(*s); s++);

  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;

  for (n = 0; isdigit(*s); s++)
    n = 10 * n + (*s - '0');

  return sign * n;
}

void reverse(char *s)
{
  int c;
  char *e = s + strlen(s) - 1;

  for (; s < e; s++, e--)
  {
    c = *s;
    *s = *e;
    *e = c;
  }
}

void itoa(int n, char *s)
{
  int sign = (n < 0) ? -1 : 1;
  if (n < 0)
    n = -n;

  do
  {
    *s++ = n % 10 + '0';
  } while (( n /= 10) != 0);

  if (sign == -1)
    *s++ = '-';

  reverse(s);
  *s = '\0';
}

void prtstr(char *s)
{
  for (; *s != '\0'; s++)
    printf("%c", *s);
  printf("_\n");
}


int main()
{
  char a[MAXLINE];
  printf("%d: %s\n", mygetline(a, MAXLINE), a);

  printf("%d\n", atoi("  -314"));

  char b[] = "hello";
  reverse(b);
  printf("%s\n", b);

  char c[128];
  itoa(17, c);
  printf("itoa: %s\n", c);
  prtstr(c);

  return 0;
}