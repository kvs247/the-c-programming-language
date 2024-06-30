// Rewrite the program cat from Chapter 7 using read, write, open, and close
// instead of their standard library equivalents. Perform experiments to
// determine the relative speeds of the two versions.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void cat1(int, char *[]);
void cat2(int, char*[]);

int main(int argc, char *argv[])
{
  clock_t start;
  double t;

  start = clock();
  cat1(argc, argv);
  t = (double)(clock() - start) / CLOCKS_PER_SEC;
  printf("\nRUNTIME: %.10fs\n", t);

  freopen(NULL, "r", stdin);

  start = clock();
  cat2(argc, argv);
  t = (double)(clock() - start) / CLOCKS_PER_SEC;
  printf("\nRUNTIME: %.10fs\n", t);

  return 0;
}

void cat1(int argc, char *argv[])
{
  FILE *fp;
  void filecopy1(FILE *, FILE *);
  char *prog = argv[0];

  if (argc == 1)
    filecopy1(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL)
      {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
      }
      else
      {
        filecopy1(fp, stdout);
        fclose(fp);
      }
  if (ferror(stdout))
  {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
}

void cat2(int argc, char *argv[])
{
  int fd;
  void filecopy2(int, int);

  if (argc == 1)
    filecopy2(0, 1);
  else 
  {
    while (--argc > 0)
    if ((fd = open(*++argv, O_RDONLY, 0)) == -1)
    {
      // error handling that i'd rather not do now (ever?)
    }
    else
    {
      filecopy2(fd, 1);
      close(fd);
    }
  }
}

void filecopy1(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

void filecopy2(int ifd, int ofd)
{
  char buf[BUFSIZ];
  int n;

  while ((n = read(ifd, buf, BUFSIZ)) > 0)
    write(ofd, buf, n);
}