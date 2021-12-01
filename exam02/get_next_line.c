#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 4

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		idx;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (0);
	idx = 0;
	while (str[idx])
	{
		ret[idx] = str[idx];
		idx++;
	}
	return (ret);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*ret;
	int		size;
	int		r_idx;
	int		idx;

	if (!str)
	{
		ret = ft_strdup(buf);
		return (ret);
	}
	size = ft_strlen(str) + ft_strlen(buf);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = 0;
	idx = 0;
	r_idx = 0;
	if (!ret)
		return (0);
	while (str[idx])
	{
		ret[r_idx] = str[idx];
		idx++;
		r_idx++;
	}
	free(str);
	idx = 0;
	while (buf[idx])
	{
		ret[r_idx] = buf[idx];
		idx++;
		r_idx++;
	}
	return (ret);
}

int	str_in_nl(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*make_line(char **str)
{
	char	*ret;
	char	*tmp;
	int		s_idx;
	int		idx;

	s_idx = str_in_nl(*str);
	ret = (char *)malloc(sizeof(char) * (s_idx + 2));
	idx = 0;
	while (idx <= s_idx)
	{
		ret[idx] = (*str)[idx];
		idx++;
	}
	ret[idx] = 0;
	tmp = ft_strdup(*str + (s_idx + 1));
	free(*str);
	*str = tmp;
	return (ret);	
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	int			size;

	if (fd < 0 | BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
	{
		free(buf);
		return (0);
	}
	while (size > 0)
	{
		buf[size] = 0;
		str = ft_strjoin(str, buf);
		if (str_in_nl(str) >= 0)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (size == 0)
	{
		free(line);
		line = 0;
		line = str;
		str = 0;
		return (line);
	}
	line = make_line(&str);
	return (line);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("test2", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("line : %s\n", line);
		free(line);
	}
//	printf("line : %s\n", line);
	system("leaks a.out | grep leaked");
}
