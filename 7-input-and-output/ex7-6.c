// Write a program to comapre two files, printing the first line where they
// differ.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char line1[MAXLINE], line2[MAXLINE];

  if (argv[1] == NULL || argv[2] == NULL)
  {
    fprintf(stderr, "error: provide two files to compare\n");
    exit(1);
  }

  if ((fp1 = fopen(argv[1], "r")) == NULL)
    fprintf(stderr, "error opening file 1\n");
  if ((fp2 = fopen(argv[2], "r")) == NULL)
    fprintf(stderr, "error opening file 2\n");

  while (fgets(line1, MAXLINE, fp1) != NULL && fgets(line2, MAXLINE, fp2) != NULL)
  {
    if (strcmp(line1, line2) != 0)
    {
      printf("Not the same:\n%s\n%s", line1, line2);
      exit(0);
    }
  }

  printf("No difference.\n");

  fclose(fp1);
  fclose(fp2);

  return 0;
}