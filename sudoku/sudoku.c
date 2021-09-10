#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkBlock(unsigned int board[9][9], int x, int y)
{
    int *tab;
    int i = 0;
    int j = 1;
    int k = 0;
    int l = 0;
    k = x + 3;
    l = y + 3;
    tab = calloc(9, sizeof(int));
    while (x < k)
    {
        while (y < l)
        {
            tab[i] = board[x][y];
            i++;
            y++;
        }
        x++;
        y = 0;
    }
    i = 0;
    while (i < 8)
    {
        while (j < 9)
        {
            if (tab[i] == tab[j])
            {
                free(tab);
                return(false);
            }
            j++;    
        }
        i++;
        j = i + 1;
    }
    free(tab);
    return (true);
}

bool validSolution(unsigned int board[9][9])
{
    int i = 1;
    int x = 0;
    int y = 0;
    while (x < 9)//test horizontal
    {
        while (y < 8)
        {
            while (i < 9)
            {
                if (board[x][y] < 1 || board[x][y] > 9)
                    return (false);
                else if (board[x][y] == board[x][i])
                    return (false);
                i++;
            }
            y++;
            i = y + 1;
        }
        x++;
        y = 0;
        i = 1;
    }
    x = 0;
    while (y < 9)//test vertical
    {
        while (x < 8)
        {
            while (i < 9)
            {
                if (board[x][y] == board[i][y])
                    return (false);
                i++;
            }
            x++;
            i = x + 1;
        }
        y++;
        x = 0;
        i = 1;
    }
    y = 0;
    while (x < 7)//check blocks
    {
        while (y < 7)
        {
            if (checkBlock(board,0 , 0) == false)
                return (false);
            y += 3;
        }
        x += 3;
        y = 0;
    }
    return (true);
}

int main()
{
    unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 
                             
    unsigned int example2[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                              {6, 7, 2, 1, 9, 0, 3, 4, 8},
                              {1, 0, 0, 3, 4, 2, 5, 6, 0},
                              {8, 5, 9, 7, 6, 1, 0, 2, 0},
                              {4, 2, 6, 8, 5, 3, 7, 9, 1},
                              {7, 1, 3, 9, 2, 4, 8, 5, 6},
                              {9, 0, 1, 5, 3, 7, 2, 1, 4},
                              {2, 8, 7, 4, 1, 9, 6, 3, 5},
                              {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    unsigned int example3[9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                    {2, 3, 1, 5, 6, 4, 8, 9, 7}, 
                                    {3, 1, 2, 6, 4, 5, 9, 7, 8}, 
                                    {4, 5, 6, 7, 8, 9, 1, 2, 3}, 
                                    {5, 6, 4, 8, 9, 7, 2, 3, 1}, 
                                    {6, 4, 5, 9, 7, 8, 3, 1, 2}, 
                                    {7, 8, 9, 1, 2, 3, 4, 5, 6}, 
                                    {8, 9, 7, 2, 3, 1, 5, 6, 4}, 
                                    {9, 7, 8, 3, 1, 2, 6, 4, 5}}; 

    printf("%d\n", validSolution(example1));
    printf("%d\n", validSolution(example2));
    printf("%d\n", validSolution(example3));
}