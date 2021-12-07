#include <unistd.h>

int	main(int ac, char **av)
{
	char	inter[255] = { 0 };
	int		x;
	int		y;

	if (ac == 3)
	{
		x = 2;
		while (x > 0)
		{
			y = 0;
			while (av[x][y])
			{
				if (x == 2 && !inter[(unsigned char)av[x][y]])
					inter[(unsigned char)av[x][y]] = 1;
				if (x == 1 && inter[(unsigned char)av[x][y]] == 1)
				{
					write(1, &av[x][y], 1);
					inter[(unsigned char)av[x][y]] = 2;
				}
				y++;
			}
			x--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
