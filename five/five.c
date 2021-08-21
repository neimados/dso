#include <stdio.h>

int dontGiveMeFive(int start, int end)
{
	int count;
	int i;
	count = 0;
	i = start;
	while (i <= end)
	{
		if ((i % 10 == 5 || i / 10 == 5) || (i % 10 == -5 || i / 10 == -5))
			i++;
		else
		{
			count++;
			i++;
		}
	}
return (count);
}

int main()
{
	printf("%d\n", dontGiveMeFive(-14, -1));
	//printf("%d\n", dontGiveMeFive(4, 17));
}
