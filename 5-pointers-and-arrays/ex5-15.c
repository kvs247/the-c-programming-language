#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int mystrcmp(const char *, const char *);

int reverse = 0; /* 1 if reverse sort */
int fold = 0; /* 1 if fold upper and lower case together */

/* sort input lines */
int main(int argc, char *argv[])
{
  clock_t start = clock();

  int nlines;      /* number of input lines to be read */
  int numeric = 0; /* 1 if numeric sort */

  int c;
  while (--argc > 0 && (*++argv)[0] == '-')
  {
    while (c = *++argv[0])
    {
      switch (c)
      {
      case 'n':
        numeric = 1;
        break;
      case 'r':
        reverse = 1;
        break;
      case 'f':
        fold = 1;
        break;
      }
    }
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    myqsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : mystrcmp));
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
    return reverse ? 1 : -1;
  else if (v1 > v2)
    return reverse ? -1 : 1;
  else
    return 0;
}

void strlower(char *);

int mystrcmp(const char *s1, const char *s2)
{
  char *p1 = malloc(strlen(s1) + 1);
  char *p2 = malloc(strlen(s2) + 1);

  strcpy(p1, s1);
  strcpy(p2, s2);

  if (fold)
  {
    strlower(p1);
    strlower(p2);
  }

  if (reverse)
    return strcmp(p2, p1);
  else
    return strcmp(p1, p2);
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

void strlower(char *s)
{
  for (; *s; s++)
    *s = tolower(*s);
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