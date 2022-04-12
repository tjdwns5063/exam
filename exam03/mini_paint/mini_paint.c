#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

typedef struct s_field_info
{
    int		width;
    int		height;
    char	background;
} t_field_info;

typedef struct s_draw_info
{
    char	col;
    float	x;
    float	y;
    float	rad;
    char	ch;
} t_draw_info;

void	error_print(void)
{
	write(1, "Error: Operation file corrupted\n", 33);
	exit(1);
}

int	check_circle(float x, float y, int flag, t_draw_info draw_info)
{
	float newr;

	newr = powf((powf(x - draw_info.x,  2.0) + powf(y - draw_info.y, 2.0)), 0.5);
	if (flag && newr <= draw_info.rad)
		return (1);
	if (!flag && (newr - draw_info.rad) < 1.0 && (newr - draw_info.rad) >= 0.0)
		return (1);
	return (0);
}

void	draw_circle(char **matrix, t_field_info field_info, t_draw_info draw_info)
{
	int flag;

	if (draw_info.ch == 'c')
		flag = 0;
	else
		flag = 1;
	int x = 0;
	while (x < field_info.height)
	{
		int y = 0;
		while (y < field_info.width)
		{
			if (check_circle(x, y, flag, draw_info))
				matrix[x][y] = draw_info.col;
			y++;
		}
		x++;
	}
}

void	print_matrix(char **matrix, t_field_info field_info)
{
	int i = 0;
	while (i < field_info.height)
	{
		write(1, matrix[i], field_info.width);
		write(1, "\n", 1);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int main(int ac, char **av)
{
	t_field_info	field_info;
	t_draw_info		draw_info;
	int				err;
	FILE*			file;
	char**			matrix;
	int				i;

	if (ac != 2)
	{
		write(1, "Error: argument\n", 17);
		return (1);
	}
	file = fopen("oper", "r");
	if (!file)
		error_print();
	err = fscanf(file, "%d %d %c\n", &field_info.width, &field_info.height, &field_info.background);
	if (err != 3)
		error_print();
	printf("width: %d, height: %d, background: %c\n", field_info.width, field_info.height, field_info.background);

	matrix = (char **)malloc(sizeof(char *) * (field_info.height));
	if (!matrix)
		error_print();
	i = 0;
	while (i < field_info.height)
	{
		matrix[i] = (char *)malloc(sizeof(char) * (field_info.width));
		if (!matrix[i])
			error_print();
		memset(matrix[i], field_info.background, field_info.width);
		i++;
	}
	err = 5;
	while (err == 5)
	{
		err = fscanf(file, "%c %f %f %f %c\n", &draw_info.ch, &draw_info.x, &draw_info.y, &draw_info.rad, &draw_info.col);
		if (err == EOF)
			break ;
		if (err != 5 || (draw_info.ch != 'c' && draw_info.ch != 'C') || (draw_info.rad <= 0))
			error_print();
		draw_circle(matrix, field_info, draw_info);
	}
	print_matrix(matrix, field_info);
	return (0);
}