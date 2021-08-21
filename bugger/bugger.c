#include <stdio.h>

int ft_recursive(int n)
{
	if (n / 10 == 0)
		return n % 10;
	return (n % 10 * ft_recursive(n / 10));
}

int persistence(int n)
{
	int	nb;
	int	i;
	if (n < 10)
		return (0);
	nb = ft_recursive(n);
	i = 1;
	while (nb > 9)
	{
		nb = ft_recursive(nb);
		i++;
	}
	return (i);
}

int main()
{
	printf("%d\n", persistence(4));
}
