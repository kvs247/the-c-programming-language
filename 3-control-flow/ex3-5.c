// Write the function(n,s,b) that converts the integer n into a base b
// character representation in the string s. In particular, itob(n,s,16)
// formats n as a hexadecimal integer in s.

#include <stdio.h>

void itob(int n, char s[], int b)
{
  if (b < 2 || b > 36)
  {
    printf("Invalid base %d\n", b);
    s[0] = '\0';
    return;
  }

  int i = 0;
  
  if (n == 0)
  {
    s[i++] = '0';
    s[i] = '\0';
    return;
  }

  if (n < 0)
  {
    s[i++] = '-';
    n = -n;
  }

  int p;
  int v = 1; // b ^ p

  for (p = 0; v * b <= n; p++)
  {
    v *= b;
  }

  int m;

  while (n > 0)
  {
    m = n / v;

    s[i++] = m < 10 ? m + '0' : (m - 10) + 'a';

    n -= m * v;
    v /= b;
  }

  s[i] = '\0';
}

int main()
{
  char s[128];

  // base 2
  printf("\nbase 2:\n");
  itob(21, s, 2);
  printf("21 => 10101; res: %s\n", s);
  itob(365, s, 2);
  printf("365 => 101101101; res: %s\n", s);

  // base 8
  printf("\nbase 8:\n");
  itob(21, s, 8);
  printf("21 => 25; res: %s\n", s);
  itob(365, s, 8);
  printf("365 => 555; res: %s\n", s);

  // base 16
  printf("\nbase 16:\n");
  itob(21, s, 16);
  printf("21 => 15; res: %s\n", s);
  itob(365, s, 16);
  printf("365 => 16d; res: %s\n", s);
  itob(-559, s, 16);
  printf("-559 => 22f; res: %s\n", s);
  itob(43983, s, 16);
  printf("43983 => abcf; res: %s\n", s);

  return 0;
}