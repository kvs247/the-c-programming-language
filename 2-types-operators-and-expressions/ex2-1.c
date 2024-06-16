// Write a program to determine the ranges of char, short, int, and long
// variables, both signed and unsigned, by printing appropriate values from
// standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  printf("char min: %d\n", CHAR_MIN);
  printf("char max: %d\n", CHAR_MAX);
  printf("signed char min: %d\n", SCHAR_MIN);
  printf("signed char max: %d\n", SCHAR_MAX);
  printf("unsigned char max: %u\n", UCHAR_MAX);

  printf("\n");

  printf("(signed) short min: %d\n", SHRT_MIN);
  printf("(signed) short max: %d\n", SHRT_MAX);
  printf("unsigned short max: %d\n", USHRT_MAX);

  printf("\n");

  printf("(signed) int min: %d\n", INT_MIN);
  printf("(signed) int max: %d\n", INT_MAX);
  printf("unsigned int max: %u\n", UINT_MAX);

  printf("\n");

  printf("(signed) long min: %ld\n", LONG_MIN);
  printf("(signed) long max: %ld\n", LONG_MAX);
  printf("unsigned long max: %lu\n", ULONG_MAX);

  printf("\n");

  printf("(single) float min: %e\n", FLT_MIN);
  printf("(single) float max: %e\n", FLT_MAX);
  printf("double min: %e\n", DBL_MIN);
  printf("double max: %e\n", DBL_MAX);

  return 0;
}