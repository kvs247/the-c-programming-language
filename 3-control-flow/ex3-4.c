// void itoa(int n, char s[])
// {
//   int i, sign;

//   if ((sign = n) < 0)
//     n = -n;
//   i = 0;
//   do
//   {
//     s[i++] = n % 10 + '0';
//   } while (n /= 10 != 0);
//   if (sign > 0)
//     s[i++] = '-';
//   s[i] = '\0';
//   reverse(s);
// }
// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to 
// -2^(wordsize - 1). Explain why not. Modify it to print that value correctly,
// regardless of the machine on which it runs.

// Explanation:
// The reason that this function can't handle the largest negative number is
// the line n = -n. This conversion will cause an integer overflow, so n is now
// not the correct bit reperesentation for that number.

#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[])
{
  int i, j, temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    temp = s[i];
    s[i] = s[j];
    s[j]  = temp;
  }
}

void itoa(int n, char s[])
{
  int i, sign;
  unsigned un = n;

  if ((sign = n) < 0)
    un = -n;

  i = 0;
  do
  {
    s[i++] = un % 10 + '0';
  } while ((un /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main()
{
  printf("int min: %d\n", INT_MIN);

  char s[128];
  itoa(INT_MIN, s);

  printf("%s\n", s);

  return 0;
}