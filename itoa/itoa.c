#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_recursive(int number, char *str, int length)
{
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	if (number > 9)
		ft_recursive(number / 10, str, length - 1);
	str[length] = (number % 10) + 48;
}

const char* number_to_string(int number) 
{
	char *str;
	int nb;
	int i;
	int length;
	nb = number;
	i = 0;
	length = 1;
	if (number < 0)
	{
		length++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb /= 10;
		length++;
	}
	str = malloc(sizeof(char) * length + 1);
	ft_recursive(number, str, length - 1);
	str[length] = '\0';
	return (str);
}

int main()
{
	printf("%s\n", number_to_string(-1234));
}
