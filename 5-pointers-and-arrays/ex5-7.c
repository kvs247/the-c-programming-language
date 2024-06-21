// Rewrite readlines to store lines in an array supplied by main, rather than
// calling alloc to maintain storage. How much faster is the program?

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of ay input line */
#define MAXSTORE 10000 /* max space allowed for all lines */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], char *p, int nlines);
void writelines(char *lineptr[], int nlines);
char *alloc(int);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
  clock_t start = clock();

  int nlines; /* number of input lines to be read */
  char linestore[MAXSTORE];

  if ((nlines = readlines(lineptr, linestore, MAXLINES)) >= 0)
  {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    printf("runtime: %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
  }
  else
  {
    printf("error: input too big to sort\n");
    return 1;
  }
}

/* qsort: sort v[left]...v[right] into increasing order*/
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) /* do nothing if array contains fewer than two elements */
    return;
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int mygetline(char *, int);

/* readlines: read input line */
int readlines(char *lineptr[], char *ls, int maxlines)
{
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  char *p = ls + strlen(ls);
  while ((len = mygetline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || (strlen(ls) + len) > MAXSTORE)
      return -1;
    else
    {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
    }
  }
  return nlines;
}

int mygetline(char s[], int lim)
{
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF && c != '\n')
  {
    s[i] = c;
    ++i;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;

char *alloc(int n) /* return pointer to n characters*/
{
  if (allocbuf + ALLOCSIZE - allocp >= n) /* if it fits */
  {
    allocp += n;
    return allocp - n; /* old p */
  }
  else /* not enough room */
    return 0;
}