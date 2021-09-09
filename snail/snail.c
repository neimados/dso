#include <stdio.h>
#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) 
{
    int i;
    int j = 0;
    size_t x;
    size_t y;
    size_t left;
    size_t right;
    size_t top;
    size_t bottom;
    int *str;
    size_t size;
    i = 1;
    x = 0;
    y = 0;
    left = 1;
    right = cols - 1;
    top = 2;
    bottom = rows - 1;
    size = rows * cols;
    outsz = &size;
    str = malloc(sizeof(int) * size);
    while (i < size)
    {
        while (y < right)
        {
            y++;
            str[i] = mx[x][y];
            i++;
        }
        right--;
        while (x < bottom)
        {
            x++;
            str[i] = mx[x][y];
            i++;
        }
        bottom--;
        while (y >= left)
        {
            y--;
            str[i] = mx[x][y];
            i++;
        }
        left++;
        while (x >= top)
        {
            x++;
            str[i] = mx[x][y];
            i++;
        }
        top++;
    }
  return (str);
}