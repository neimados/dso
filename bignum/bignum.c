#include <stdlib.h>
#include <stdio.h>

long long ft_size(long long nba)
{
	long long i;
	i = 1;
	while (nba / 10 != 0)
	{
		nba /= 10;
		i++;
	}
	return (i);
}

void ft_putnb(unsigned long nba, char *str)
{
	static int	i;
	i = 0;
	if (nba / 10 != 0)
	{
		ft_putnb(nba / 10, str);
	}
	str[i] = (nba % 10) + '0';
	i++;
}

char *add(const char *a, const char *b) 
{
	int	i;
	long long	nba;
	long long	nbb;
	long long	length;
	char	*str;
	i = 0;
	nba = 0;
	nbb = 0;
	length = 0;
	while (a[i])
	{
		nba *= 10;
		nba += a[i] - '0';
		i++;
	}
	i = 0;
	while (b[i])
	{
		nbb *= 10;
		nbb += b[i] - '0';
		i++;
	}
	nba += nbb;
	length = ft_size(nba);
	str = malloc(sizeof(char) * length + 1);
	ft_putnb(nba, str);
	str[length] = '\0';
	return (str); 
}

int	main()
{
    printf("%s\n",add("1", "1"));
    printf("%s\n",add("123", "456"));
    printf("%s\n",add("888", "222"));
    printf("%s\n",add("1372", "69"));
    printf("%s\n",add("12", "456"));
    printf("%s\n",add("101", "100"));
    printf("%s\n",add("63829983432984289347293874", "90938498237058927340892374089"));
}
