#include <stdlib.h>
#include <stdio.h>

char *alphabet_position(const char *text) 
{
	char base [] = "abcdefghijklmnopqrstuvwxyz";
	char *str;
	int	i;
	int	j;
	int	k;
	int	length;
	i = 0;
	length = 0;
	while (text[i])
	{
		if ((text[i] >= 'a' && text[i] <= 'i') || (text[i] >= 'A' && text[i] <= 'I'))
		{	
			length += 2;
		}
		else if ((text[i] >= 'j' && text[i] <= 'z') || (text[i] >= 'J' && text[i] <= 'Z'))
		{
			length += 3;
		}
		i++;
	}
	str =  malloc(sizeof(char) * length);
	i = 0;
	j = 0;
	k = 0;
	str[length - 1] = '\0';
	while (text[i])
	{
		while (base[j])
		{
			if (text[i] == base[j] || text[i] == base[j] - 32)
			{
				if ((j + 1) < 10)
				{
					str[k] = (j + 1) + '0';
					k++;
				}
				else
				{
					str[k] = ((j + 1) / 10) + '0';
					str[k + 1] = ((j + 1) % 10) + '0';
					k += 2;
				}
				if (k < length - 1)
				{
					str[k] = 32;
					k++;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (str);
}

int main()
{
	printf("%s\n", alphabet_position("j"));
}
