#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_recursive(int number, char *str, int i)
{
	if (number > 9)
		ft_recursive(number / 10, str, i + 1);
	str[i] = (number % 10) + 48;
	printf("%c\n", str[i]);
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
	while (nb > 9)
	{
		nb /= 10;
		length++;
	}
	str = malloc(sizeof(char) * length + 1);
	ft_recursive(number, str, i);
	str[length] = '\0';
	return (str);
}

int main()
{
	printf("%s\n", number_to_string(1234));
}
