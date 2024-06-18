// Extend atof to handle scientific notation of the form 123.45e-6 where a
// floating-point number may be followed by e or E and an optionally signed
// exponent.

#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
  int i, j, c, exp, sign, esign;
  double val, power;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++)
  {
    val = val * 10.0 + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;
  esign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;

  for (exp = 0; isdigit(s[i]); i++)
  {
    exp = (exp * 10) + (s[i] - '0');
  }

  double mult = (esign > 0) ? 0.1 : 10;
  while (exp > 0)
  {
    power *= mult; 
    exp--;
  }

  return sign * val / power;
}

int main()
{
  char s[128];

  printf("121: %g\n", atof("121"));
  printf("   42069: %g\n", atof("    42069"));
  printf("-44: %g\n", atof("-44"));
  printf("123.456: %g\n", atof("123.456"));
  printf("-0.001: %g\n", atof("-0.001"));
  printf("123.45e-6: %g\n", atof("123.45e-6"));
  printf("-2.746E4: %g\n", atof("-2.746E4"));
  
  return 0;
}