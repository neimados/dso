#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int tickets(size_t length, const int people[length])
{
	int twenty;
	int fifty;
	int i;
	twenty = 1;
	fifty = 0;
	i = 1;
	if (people[0] != 25)
		return (0);
	while (i < length)
	{
		if (people[i] == 25)
			twenty++;
		else if (people[i] == 50)
		{
			if (twenty <= 0)
				return (0);
			else
				twenty--;
			fifty++;
		}
		else if (people[i] == 100)
		{
			if (twenty <= 0)
			{
				return (0);
			}
			else if (fifty <= 0 && twenty < 3)
				return (0);
			else
			{
				if (fifty > 0)
				{
					fifty--;
					twenty--;
				}
				else
					twenty -= 3;
			}
		}
		i++;	
	}
	return (1);
}

int main()
{
  printf("%d\n", tickets(3, (int[]){25, 25, 50}));
  printf("%d\n", tickets(2, (int[]){25, 100}));
}
