#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	moins;
	int	nb;
	i = 0;
	moins = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			moins++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	if (moins % 2 != 0)
		nb = -nb;
	return (nb);
}

int	main()
{
	printf("%d", ft_atoi(" 	 	---++-1234zklzef"));
	return (0);
}
