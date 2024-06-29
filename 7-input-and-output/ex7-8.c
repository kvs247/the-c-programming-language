// Write a program to print a set of files, starting each new one on a new
// page, with a title and a running page count for each file.

#include <stdio.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
  FILE *fp;
  int page = 0;
  char line[MAXLINE];

  while (--argc > 0)
  {
    if ((fp = fopen(*++argv, "r")) == NULL)
    {
      fprintf(stderr, "%s: error opening %s\n", argv[0], *argv);
      continue;
    }

    printf("\n~~~%s - page %d~~~\n", *argv, ++page);
    while (fgets(line, MAXLINE, fp) != NULL)
      printf("%s", line);
  }

  return 0;
}