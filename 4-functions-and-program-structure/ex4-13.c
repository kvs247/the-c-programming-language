// Write a recursive version of the function reverse(), which reverses the
// string in place.

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
  int tempc;
  int left = 0;
  int right = strlen(s) - 1;
  
  tempc = s[left];
  s[left++] = s[right];
  s[right--] = tempc;
 
  if (left < right)
  {
    int i = 0;
    char subs[128];
    while (i <= right - left + 1)
      subs[i++] = s[left + i + 1];
      reverse(subs);
  }
  else
    return;
}

int main()
{
    char s[128];

    // Reverse "reverse" and store in s
    strcpy(s, "reverse");
    reverse(s);
    printf("%s\n", s);

    // Reverse "racecar" and store in s
    strcpy(s, "racecar");
    reverse(s);
    printf("%s\n", s);

    // Reverse "hhhihhh" and store in s
    strcpy(s, "hhhihhh");
    reverse(s);
    printf("%s\n", s);

    return 0;
}