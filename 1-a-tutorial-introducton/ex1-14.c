// Write a program to print a histogram of the frequencies of different characters in its input.

#include <stdio.h>

#define N_ASCII 128

int main()
{
  int i, j;
  int c;
  int freq[N_ASCII];

  for (i = 0; i < N_ASCII; i++)
    freq[i] = 0;

  while ((c = getchar()) != EOF)
  {
    freq[c]++;
  }

  for (i = 0; i < N_ASCII; i++)
  {
    if (freq[i] != 0)
    {
      printf("%c ", i);
      for (j = 0; j < freq[i]; j++)
      {
        printf("@");
      }
      printf("\n");
    }
  }

  return 0;
}