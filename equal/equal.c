#include <stdio.h>
#include <stdlib.h>

int find_even_index(const int *values, int length) 
{
    int i;
    int pos;
    int left;
    int right;
    i = 0;
    pos = 0;
    while (pos < length)
    {
        left = 0;
        i = pos - 1;
        while (i >= 0)
        {
            left += values[i];
            i--;
        }
        right = 0;
        i = pos + 1;
        while (i < length)
        {
            right += values[i];
            i++;
        }
        if (left == right)
            return (pos);
        pos++;
    }
    return (-1);
}

int main()
{
    //int arr[] = { 1,2,3,4,3,2,1 };
    //int arr[] = { 1,100,50,-51,1,1 };
    //int arr[] = { 1,2,3,4,5,6 };
    //int arr[] = { 20,10,30,10,10,15,35 };
    //int arr[] = { 20,10,-80,10,10,15,35 };
    //int arr[] = { 10,-80,10,10,15,35,20 };
    //int arr[] = { 0,0,0,0,0 };
    int arr[] = { -1,-2,-3,-4,-3,-2,-1 };
    printf("%d\n", find_even_index(arr, 7));
}