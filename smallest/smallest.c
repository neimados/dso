#include <stdio.h>

int find_smallest_int(int *vec, size_t len)
{
  int nb;
  unsigned long i;
  i = 0;
  nb = vec[0];
  while (i < len)
  {
    if (nb > vec[i])
      nb = vec[i];
    i++;
  }
  return (nb);
}

int	main()
{
	printf("%d\n",find_smallest_int((int[]){34, 15, 88, 2}, 4));
	printf("%d\n",find_smallest_int((int[]){34, -345, -1, 100}, 4));
	printf("%d\n",find_smallest_int((int[]){78, 56, 232, 12, 11, 43}, 6));
}
