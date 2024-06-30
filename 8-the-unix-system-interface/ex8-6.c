// The standard library function calloc(n,size) returns a pointer to n objects
// of size size, with the storage initialized to zero. Write calloc, by calling
// by calling malloc or by modifying it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mycalloc(int n, int size)
{
  size_t totalSize = n * size;

  void *p = malloc(totalSize);
  if (!p) return NULL;

  memset(p, 0, totalSize);

  return p;

}

int main()
{
  int *arr = mycalloc(5, sizeof(int));

  int i;

  for (i = 0; i < 5; i++)
  {
    arr[i] = i;
  }

  for (i = 0; i < 5;i++)
  {
    printf("%d\n", arr[i]);
  }

  free(arr);

  return 0;
}