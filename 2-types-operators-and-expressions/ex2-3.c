// Write the function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char s[])
{
  int c;
  int n = 0;
  int i = 0;

  // skip 0's or 0x prefeix
  i = 0;
  while (s[i] == '0' || s[i] == 'x' || s[i] == 'X')
  {
    i++;
  }

  // computation
  while ((c = tolower(s[i])) != '\0')
  {
    if (isdigit(c))
    {
      c = c - '0';
    }
    else
    {
      c = c - 'a' + 10;
    }
    n = 16 * n + c;
    i++;
  }
  return n;
}

int main()
{
  printf("1 => 1: %d\n", htoi("1"));
  printf("1A => 26: %d\n", htoi("1A"));
  printf("FF => 255: %d\n", htoi("FF"));
  printf("AbC => 2748: %d\n", htoi("AbC"));
  printf("aBc => 2748: %d\n", htoi("aBc"));
  printf("0x10 => 16: %d\n", htoi("0x10"));
  printf("0X1a => 26: %d\n", htoi("0X1a"));
  printf("000FF => 255: %d\n", htoi("000FF"));

  return 0;
}