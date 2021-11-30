#include <unistd.h>

int	main(int ac, char **av)
{
	char	union_[255] = { 0 };
	int		x;
	int		y;

	if (ac == 3)
	{
		x = 1;
		while (x < ac)
		{
			y = 0;
			while (av[x][y])
			{
				if (!union_[(unsigned char)av[x][y]])
				{
					write(1, &av[x][y], 1);
					union_[(unsigned char)av[x][y]] = 1;
				}
				y++;
			}
			x++;
		}
	}
	write(1, "\n", 1);
}
