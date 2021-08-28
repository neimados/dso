#include <stdbool.h>
#include <stdio.h>

bool narcissistic(int num)
{
	int length;
	int nb;
	int i;
	int tmp;
	int total;
	length = 1;
	nb = num;
	i = 0;
	tmp = 0;
	total = 0;
	while (nb / 10 != 0)
	{
		nb /= 10;
		length++;
	}
	nb = num;
	while (nb > 0)
	{
		tmp = nb % 10;
		while (i < length - 1)
		{
			tmp *= nb % 10;
			i++;
		}
		total += tmp;
		nb /= 10;
		i = 0;
	}
	if (total == num)
		return (true);
	return (false);
}

int main ()
{
	printf("%d\n", narcissistic(153));
	printf("%d\n", narcissistic(1652));
}
