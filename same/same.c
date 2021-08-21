#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool comp(const int *a, const int *b, size_t n)
{
	int i;
	int j;
	int *str;
	size_t count;
	i = 0;
	j = 0;
	count = 0;
	str = malloc(sizeof(int) * n);
	memcpy(str, b, sizeof(int) * n);
	while (a[i])
	{
		while (str[j])
		{
			if (str[j] == (a[i] * a[i]))
			{
				count++;
				str[j] = -1;
				i++;
				j = 0;
			}
			j++;
		}
		i++;
		j = 0;
	}
	j = 0;
	if (count == n)
		return (true);
	return(false);
}

int main()
{
        //int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
        //int b[8] = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
       
    
        //int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
        //int b[8] = {14641, 20736, 361, 25921, 361, 20736, 362, 121};

        //int a[9] = {121, 144, 19, 161, 19, 144, 19, 11, 1008};
        //int b[9] = {14641, 20736, 361, 25921, 361, 20736, 362, 121, 12340};

int a [] = {121, 1440, 191, 161, 19, 144, 195, 11, 14641, 20736, 361, 25921, 361, 20736, 362, 121, 12340}
int b [] = {121, 14641, 2073600, 36481, 25921, 361, 20736, 38025, 121 ,1440, 191, 161, 19, 144, 195, 11, 14641 ,20736, 361, 25921, 361, 20736, 362, 121, 12340};


	printf("%d\n", comp (a, b, 8));
}
