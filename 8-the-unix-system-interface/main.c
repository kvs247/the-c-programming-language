#include <stdio.h>
#include <sys/file.h>

int main(void)
{
  perror("what");
  printf("%d\n", O_RDWR);  

  return 0;
}
