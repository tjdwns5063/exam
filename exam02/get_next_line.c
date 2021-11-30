#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 3

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

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*buf;
	char		*line;

	if (fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf[BUFFER_SIZE] = 0;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		printf("buf : %s\n", buf);
		str = ft_strjoin(str, buf);
		printf("str : %s\n", str);
	}
}

int	main(void)
{
	int fd;

	fd = open("test", O_RDONLY);
	while (get_next_line(fd));
	return (0);
}
