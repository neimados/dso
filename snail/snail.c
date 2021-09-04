#include <stdio.h>
#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) 
{
    int i;
    size_t x;
    size_t y;
    size_t left;
    size_t right;
    size_t top;
    size_t bottom;
    int *str;
    int size;
    i = 0;
    x = 0;
    y = 0;
    left = 0;
    right = cols;
    top = 1;
    bottom = rows;
    *outsz = rows * cols;
    str = malloc(sizeof(int) * (*outsz));
    while (i < size)
    {
        while (y < right)
        {
            str[i] = mx[x][y];
            i++;
            y++;
        }
        right--;
        while (x < bottom)
        {
            str[i] = mx[x][y];
            i++;
            x++;
        }
        bottom--;
        while (y >= left)
        {
            str[i] = mx[x][y];
            i++;
            y--;
        }
        left++;
        while (x <= top)
        {
            str[i] = mx[x][y];
            i++;
            x--;
        }
        top++;
    }
  return (str);
}

int main()
{
    int *str;
    int i;
    int j;
    int *sz;
    i = 0;
    j = 0;
    const int mx [3][3] = { { 1,2,3}, {4,5,6}, {7,8,9} };
    str = snail(sz, mx, 3, 3);
    printf("test : %d\n", mx [2][0]);
        while (mx[i][j])
        {
            printf ("%d ", mx[i][j]);
            j++;
        }
    //while (str[i])
    //{
    //    printf("%d\n, str[i]");
    //    i++;
    //}
}