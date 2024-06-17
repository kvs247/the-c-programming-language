// Write a version of itoa that accepts three arguments instead of two. The
// third argument is a minimum field width; the converted number must be padded
// with blanks on the left if necessary to make it wide enough;

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
  int i, j, temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

void itoa(int n, char s[], int len)
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

  int l = sign < 0 ? len - 1 :  len; 
  if (i < l)
  {
    while (i < l)
    {
      s[i++] = '0';
    }
  }

  if (sign < 0)
    s[i++] = '-';
  
  printf("i: %d\n", i);

  s[i] = '\0';
  reverse(s);
}

int main()
{
  char buffer[20];

  // Test cases
  itoa(123, buffer, 5);
  printf("123 with min length 5: %s\n", buffer); // Should print "00123"

  itoa(-456, buffer, 6);
  printf("-456 with min length 6: %s\n", buffer); // Should print "-00456"

  itoa(7890, buffer, 4);
  printf("7890 with min length 4: %s\n", buffer); // Should print "7890"

  itoa(0, buffer, 3);
  printf("0 with min length 3: %s\n", buffer); // Should print "000"

  itoa(42, buffer, 2);
  printf("42 with min length 2: %s\n", buffer); // Should print "42"

  itoa(-5, buffer, 3);
  printf("-5 with min length 3: %s\n", buffer); // Should print "-05"

  return 0;
}