// Write the function strrindex(s,t), which returns the position of the
// rightmost occurence of t in s, or -1 if there is none.

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[])
{
  int sLen = strlen(s);

  int i, j, k;

  for (i = sLen - 1; i >= 0; i--)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
    if (k > 0 && t[k] == '\0')
      return i;
  }

  return -1;
}

int main()
{
  char s[] = "noise noisenoise patternnoisenoise patternnoise";
  char t[] = "pattern";

  printf("The result should be 35. Result: %d\n", strrindex(s, t));

  return 0;
}