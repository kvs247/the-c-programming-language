// The below binary search makes two tests inside the loop, when one would
// suffice (at the price of more tests outside). Write a verison with only one
// test inside the loop and measure the difference in run-time.

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int  n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (high + low) / 2;
    if (x < v[mid])
    {
      high = mid - 1;
    }
    else if (x > v[mid])
    {
      low = mid + 1;
    }
    // found match
    else
    {
      return mid;
    }
  }
  return -1; // no match
}

int binsearchSingleTest(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x <= v[mid])
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  if (low < n && x == v[low])
  {
    return low;
  }
  return -1; // no match
}

int main()
{
  int x = 5;
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 10;

  clock_t start = clock();
  printf("res1: %d\n", binsearch(x, v, n));
  clock_t end = clock();
  printf("t: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  printf("res1: %d\n", binsearchSingleTest(x, v, n));
  end = clock();
  printf("t: %10lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}