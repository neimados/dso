#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wave(const char *y, char **target)
{
	int	i;
	int	j;
	int	k;
	i = 0;
	j = 0;
	k = 0;
	while (i < strlen(y))
  	{
		while (y[j])
		{
			if (j == k)
				target[k][j] = y[j] - 32;
			else
				target[k][j] = y[j];
			j++;
		}
		target[k][j] = '\0';
 		j = 0;
		i++;
		k++;
	}
}

int main() 
{
  const char *tests[] = {"hello", "codewars", "two words", " gap "};
  for (int i = 0; i < 4; i++)
  {
    int r = 0;
    for (int m = 0; tests[i][m] != '\0'; m++) 
    {
      if (tests[i][m] != ' ') r ++;
    }
    char *target[r]; 
    for (int i = 0; i < r; i++) 
    {
      target[i] = (char *)calloc((r + 1) , sizeof(char));
    }
    wave(tests[i], target);
    for (int j = 0; j < r; j++)
    {
	printf("%s\n", target[j]);
      free(target[j]);
    }
  }
}
