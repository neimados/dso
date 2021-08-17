#include<stdlib.h>
#include<stdio.h>
#include<string.h>


char *add(const char *a, const char *b)
{
	char	*tmp;
	char	*nb;
	int	i;
	int	j;
	int	length;
	int	dif;
	i = 0;
	if (strlen(a) < strlen(b))
	{
		length = strlen(b);
		dif = strlen(b) - strlen(a);
		tmp = calloc((length + 2), sizeof(char));
		while (i < dif + 1)
			tmp[i++] = '0';
		strcat (tmp, a);
		tmp[length + 1] = '\0';
		i = strlen(b) - 1;
		j = i + 1;
		dif = 0;
		while (j >= 0)
		{
			if (i >= 0)
			{
				dif += (b[i] - '0') + (tmp[j] - '0');
				tmp[j] = (dif % 10) + '0';
				if (dif < 10)
					dif = 0;
				else
					dif = 1;
				i--;
				j--;
			}
			else
			{
				tmp[j--] = dif + '0';
				j = -1;
			}
		}
		length = 0;
		i = 0;
		j = 0;
		if (tmp[0] == '0')
		{
			j = 1;
			length = strlen(tmp);
			nb = malloc(sizeof(char) * length);
			while (i < length)
			{
				nb[i] = tmp[j];
				i++;
				j++;
			}
			nb[length - 1] = '\0';
		}
		else
		{
			length = strlen(tmp) + 1;
			nb = malloc(sizeof(char) * length);
			strcpy (nb, tmp);
		}
		free(tmp);
		return (nb);	
	}
	else if (strlen(a) > strlen(b))
	{
		length = strlen(a);
		dif = strlen(a) - strlen(b);
		tmp = calloc((length + 2), sizeof(char));
		while (i < dif + 1)
			tmp[i++] = '0';
		strcat (tmp, b);
		tmp[length + 1] = '\0';
		i = strlen(a) - 1;
		j = i + 1;
		dif = 0;
		while (j >= 0)
		{
			if (i >= 0)
			{
				dif += (a[i] - '0') + (tmp[j] - '0');
				tmp[j] = (dif % 10) + '0';
				if (dif < 10)
					dif = 0;
				else
					dif = 1;
				i--;
				j--;
			}
			else
			{
				tmp[j--] = dif + '0';
				j = -1;
			}
		}
		length = 0;
		i = 0;
		j = 0;
		if (tmp[0] == '0')
		{
			j = 1;
			length = strlen(tmp);
			nb = malloc(sizeof(char) * length);
			while (i < length)
			{
				nb[i] = tmp[j];
				i++;
				j++;
			}
			nb[length - 1] = '\0';
		}
		else
		{
			length = strlen(tmp) + 1;
			nb = malloc(sizeof(char) * length);
			strcpy (nb, tmp);
		}
		free(tmp);
		return (nb);
	}
	else
	{
		length = strlen(b);
		tmp = calloc((length + 2), sizeof(char));
		tmp[0] = '0';
		strcat(tmp, b);
		tmp[length + 1] = '\0';
		i = strlen(a) - 1;
		j = i + 1;
		dif = 0;
		while (j >= 0)
		{
			if (i >= 0)
			{
				dif += (a[i] - '0') + (tmp[j] - '0');
				tmp[j] = (dif % 10) + '0';
				if (dif < 10)
					dif = 0;
				else
					dif = 1;
				i--;
				j--;
			}
			else
			{
				tmp[j--] = dif + '0';
				j = -1;
			}
		}
		length = 0;
		i = 0;
		j = 0;
		if (tmp[0] == '0')
		{
			j = 1;
			length = strlen(tmp);
			nb = malloc(sizeof(char) * length);
			while (i < length)
			{
				nb[i] = tmp[j];
				i++;
				j++;
			}
			nb[length - 1] = '\0';
		}
		else
		{
			length = strlen(tmp) + 1;
			nb = malloc(sizeof(char) * length);
			strcpy (nb, tmp);
		}
	free(tmp);
	}	
	return (nb);
}

int	main()
{
    printf("%s\n",add("999999999", "1"));
    printf("%s\n",add("313618344430", "964777073129524361354603988334733"));
    printf("%s\n",add("50550021460340707161769", "9271381"));
    printf("%s\n",add("1372", "69"));
    printf("%s\n",add("123", "456"));
    printf("%s\n",add("101", "100"));
    printf("%s\n",add("63829983432984289347293874", "90938498237058927340892374089"));
}

