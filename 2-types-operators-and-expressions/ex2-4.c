// void squeeze(char s[], int c)
// {
//   int i, j;

//   for (i = j = 0; s[i] != '\0'; i++)
//   {
//     if (s[i] != c)
//     {
//       s[j++] = s[i];
//     }
//   }
//   s[j] = '\0';
// }
// Write an alternate version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[])
{
  int i, j, k;

  for (i = j = 0; s1[i] != '\0'; i++)
  {
    if (strchr(s2, s1[i]) == NULL)
    {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

int main()
{
  char s1[] = "Hello, my hoomans!";
  char s2[] = "yosha, man!";

  squeeze(s1, s2);

  printf("%s\n", s1);

  return 0;
}