#include <unistd.h>
#include <stdio.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

int	ft_argv(char *argv)
{
	int	nb;
	nb = 0;
	while (*argv)
	{
		nb *= 10;
		nb += *argv - 48;
		argv++;
	}
	return (nb);
}

void	ft_rush(int x, int y)
{
	int	line;
	int	col;
	line = 1;
	col = 1;
	while (line <= y)
	{
		while (col <= x)
		{
			if (x == 1 && y == 1)
				ft_putchar('A');
			else if ((y == 1) && (col == x))
				ft_putchar('C');
			else if ((x == 1) && (line == y))
				ft_putchar('C');	
			else if ((col == 1 && line == 1) || (col == x && line == y))
				ft_putchar('A');
			else if ((col == x && line == 1) || (col == 1 && line == y))
				ft_putchar('C');
			else if (col == 1 || col == x || line == 1 || line == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			col++;
		}
		col = 1;
		line++;
		ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	if (argc != 3)
		return (0);
	x = ft_argv(argv[1]);
	y = ft_argv(argv[2]);
	ft_rush (x,y);
	return (0);
}
