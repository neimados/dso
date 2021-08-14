#include<stdio.h>

int sum(int* numbers, int numbersCount)
{
  int i;
  int max;
  int min;
  int nmax;
  int nmin;
  int sum;
  i = 0;
  sum = 0;
  if (!numbersCount || numbersCount == 1)
    return (0);
    
  max = numbers[i];
  min = numbers[i];
  while (i < numbersCount)
  {
    if (max < numbers[i])
    {
      max = numbers[i];
      nmax = i;
    }
    else if (min > numbers[i])
    {
      min = numbers[i];
      nmin = i;
    }
    i++;
  }
  i = 0;
  while (i < numbersCount)
  {
    if (i != nmin && i != nmax)
      sum += numbers[i];
    i++;
}
  return (sum);
}

int main() {
  int array1[] = { 6, 2, 1, 8, 10 };
  printf("%d\n", sum(array1, 5));  
}
