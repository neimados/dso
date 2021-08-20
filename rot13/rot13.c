#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rot13(const char *src)
{
	int	i;
	int	j;
	int	k;
	char base[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklm";
	i = 0;
	j = 0;
	k = 0;
	char *str;
	str = malloc(sizeof(char) * strlen(src) + 1);
	while (src[i])
	{
		if (src[i] >= 'a' && src[i] <= 'z')
		{
			while (base[j] != src[i])
				j++;
			str[k] = base[j + 13];
		}
		else
		{
			while (base[j] - 32 != src[i])
				j++;
			str[k] = base[j + 13] - 32;
		}
		j = 0;
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

int	main()
{
	const char *src      = "Test";
	printf("%s\n",rot13(src));
}
