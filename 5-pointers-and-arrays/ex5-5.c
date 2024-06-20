// Write versions of the library functions strncpy, strncat, and strncmp, which
// operate on at most the first n characters of their argument strings. For
// example, strncpy(s,t,n) copies at most n characters of t to s. Full
// descriptions are in Appendix B.

#include <stdio.h>
#include <string.h>

char *mystrncpy(char *dest, char *src, int n)
{
  char *res = dest;
  while (n-- > 0 && (*dest++ = *src++) != '\0');
  *dest = '\0';
  return res;
};

char *mystrncat(char *dest, char *src, int n)
{
  char *res = dest;
  dest += strlen(dest);
  while ((*dest++ = *src++) != '\0' && n-- > 0);
  *dest = '\0';
  return res;
};

int mystrncmp(char *str1, char *str2, int n)
{
  while (--n > 0 && *str1++ != '\0' && *str2++ != '\0')
    if (*str1 != *str2)
      return *str2 - *str1;
  return 0;
};

int main()
{
  char a[128];
  char b[] = "one two";
  int abn = 3;
  printf("%s - %s\n", a, mystrncpy(a, b, abn));

  char c[] = "first";
  char d[] = " second";
  int cdn = 9;
  printf("%s - %s\n", c, strncat(c, d, cdn));

  char e[] = "string";
  char f[] = "strinf";
  int efn = 6;
  printf("%d\n", mystrncmp(e, f, efn));

  return 0;
}