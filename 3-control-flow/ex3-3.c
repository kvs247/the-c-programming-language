// Write a function expand(s1, s2) that expands shorthand notations like a-z
// in the stinrg s1 into the equivalent complete list abc...xyz in s2. Allow
// for letters of either case and digits, and be prepared to handle cases like
// a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailling - is taken
// literally.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void wipe(char s2[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    s2[i] = '\0';
  }
}

void expand(char s1[], char s2[])
{
  int c, i, j;

  for (i = 0, j = 0; (c = s1[i]) != '\0'; i++)
  {
    if (c == '-')
    {
      char last = s1[i - 1];
      char next = s1[i + 1];
      int isMatch = (
        (isdigit(last) && isdigit(next)) || 
        (isupper(last) && isupper(next)) || 
        (islower(last) && islower(next))
      );
      if (isMatch)
      {
        int start = s1[i - 1] + 1;
        int end = s1[i + 1] - 1;
        while (start <= end)
        {
          s2[j++] = start++;
        }
      }
      else
      {
        s2[j++] = c;
      }
    }
    else
    {
      s2[j++] = c;
    }
  }
  s2[j] = '\0';
}

int main()
{
  char s1[100];
  char s2[100];

  strcpy(s1, "a-z");
  expand(s1, s2);
  printf("%s: %s\n", s1, s2);
  wipe(s2, 100);

  strcpy(s1, "A-Z");
  expand(s1, s2);
  printf("%s: %s\n", s1, s2);
  wipe(s2, 100);

  strcpy(s1, "a-b-c");
  expand(s1, s2);
  printf("%s: %s\n", s1, s2);
  wipe(s2, 100);

  strcpy(s1, "a-z0-9");
  expand(s1, s2);
  printf("%s: %s\n", s1, s2);
  wipe(s2, 100);

  strcpy(s1, "-a-z");
  expand(s1, s2);
  printf("%s: %s\n", s1, s2);
  wipe(s2, 100);

  strcpy(s1, "a-z-");
  expand(s1, s2);
  printf("%s: %s\n", s1, s2);
  wipe(s2, 100);

  return 0;
}