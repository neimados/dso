#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int	ft_size(size_t n)
{
	if (n < 10)
		return (1);
	return 1 + ft_size (n / 10);
}

int	ft_putnb(size_t n, char *nb)
{
	int	i;
	i = 0;
	if (n >= 10)
		i = ft_putnb(n / 10, nb);
	nb[i++] = (n % 10) + '0';
	return (i);
}

char *likes(size_t n, const char *const names[n]) 
{
	char noone[] = "no one likes this";
	char onetxt[] =" likes this";
	char and[] = " and ";
	char like[] = " like this";
	char comma[] = ", ";
	char others[] = " others";
	char *nb;
	char *str;
	int length;
	int i;
  
	if (n == 0)
	{
		length = strlen(noone) + 1;
 		str = malloc(sizeof(char) * length);
		strcpy(str, noone);
		str[length - 1] = '\0';
		return (str);
	}
	if (n == 1)
	{
  		length = strlen(names[0]) + strlen(onetxt) + 1;
  		str = malloc(sizeof(char) * length);
  		strcpy(str, names[0]);
  		str[length - 1] = '\0';
		strcat(str, onetxt);
		return (str);
	}
	else if (n == 2)
	{
		length = (strlen(names[0]) + strlen(names[1]) + strlen(and) + strlen(like) + 1);
		str = malloc(sizeof(char) * length);
		str[length - 1] = '\0';
		strcpy(str, names[0]);
		strcat(str, and);
		strcat(str, names[1]);
		strcat(str, like);
		return (str);
	}
	else if (n == 3)
	{
		length = (strlen(names[0]) + strlen(names[1]) + strlen(names[2]) + strlen(and) + strlen(like) + strlen(comma) + 1);
		str = malloc(sizeof(char) * length);
		str[length - 1] = '\0';
		strcpy(str, names[0]);
		strcat(str, comma);
		strcat(str, names[1]);
		strcat(str, and);
		strcat(str, names[2]);
		strcat(str, like);
		return (str);
	}
	else
	{
		i = ft_size(n);
		nb = malloc(sizeof(char) * i + 1);
		nb[i] = '\0';
		ft_putnb(n - 2, nb);
		length = (strlen(names[0]) + strlen(names[1]) + strlen(others) + strlen(and) + strlen(like) + strlen(comma) + i + 1);
		str = malloc(sizeof(char) * length);
		str[length - 1] = '\0';
		strcpy(str, names[0]);
		strcat(str, comma);
		strcat(str, names[1]);
		strcat(str, and);
		strcat(str, nb);
		strcat(str, others);
		strcat(str, like);
		return (str);
	}
	return (NULL);
}

int	main()
{
    const char *const names[0] = {};
    printf("%s",likes(0, names));	
}
