// Write the program tail, which prints the last n lines of its input. By
// default, n is 10, let us say, but it can be changed by an optional argument,
// so that
//     tail -n
// prints the last n lines. The program should behave rationally no matter how
// unreasonable the input or the value of n. Write the program so it makes the
// best use of available storage; lines should be stored as in the sorting
// program of Section 5.6, not in a two-dimensional array of fixed size.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

int mygetline(char *, int);
void shift(char **, int, int);

int main(int argc, char *argv[])
{
  int i;
  int n = 10;

  while (--argc > 0 && (*++argv)[0] == '-') 
    n = atoi(*argv + 1);

  char **lineptr = malloc(n * sizeof(char *));
  for (i = 0; i < n; i++)
    lineptr[i] = malloc(MAXLEN * sizeof(char));

  int len, nlines = 0;
  char line[MAXLEN];
  while ((len = mygetline(line, MAXLEN)) > 0)
  {
    strncpy(lineptr[nlines % n], line, len);
    nlines++;
  }

  shift(lineptr, n, nlines % n);


  for (i = 0; i < n; i++)
    printf("%s", lineptr[i]);
}

void shift(char **lineptr, int n, int x)
{
  int i;
  int ti = x;

  char **temp = malloc(n * sizeof(char *));
  for (i = 0; i < n; i++)
    temp[i] = lineptr[i];

  for (i = 0; i < n; i++, ti++)
    lineptr[i] = temp[ti % n];
  
  free(temp);
}

int mygetline(char s[], int lim)
{
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n')
  {
    *s++ = c;
    i++;
  }
  if (c == '\n')
  {
    *s++ = c;
    i++;
  }
  *s = '\0';
  return i;
}