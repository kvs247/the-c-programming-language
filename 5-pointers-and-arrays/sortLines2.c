#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

/* sort input lines */
int main(int argc, char *argv[])
{
  clock_t start = clock();

  int nlines;      /* number of input lines to be read */
  int numeric = 0; /* 1 if numeric sort */

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    myqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
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
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int i, int j);

  if (left >= right) /* do nothing if array contains fewer than two elements */
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  myqsort(v, left, last - 1, comp);
  myqsort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define MAXLEN 1000 /* max length of ay input line */
int mygetline(char *, int);
char *alloc(int);

/* readlines: read input line */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = mygetline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else
    {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
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