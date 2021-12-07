#include "get_next_line.h"

static char	*make_line(char **str)
{
	char	*line;
	char	*tmp;
	int		n_idx;
	int		idx;

	n_idx = str_in_nl(*str);
	line = (char *)malloc(sizeof(char) * (n_idx + 2));
	if (!line)
		return (0);
	line[n_idx + 1] = 0;
	idx = 0;
	while (idx <= n_idx)
	{
		line[idx] = (*str)[idx];
		idx++;
	}
	tmp = ft_strdup(*str + (n_idx + 1));
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	int			size;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = 0;
		str = ft_strjoin(str, buf);
		if (str_in_nl(str) >= 0)
		{
			free(buf);
			line = make_line(&str);
			return (line);
		}
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (size < 0)
		return (0);
	else if (str && str_in_nl(str) >= 0)
	{
		line = make_line(&str);
		return (line);
	}
	else if (str && *str != 0)
	{
		line = ft_strdup(str);
		free(str);
		str = 0;
		return (line);
	}
	free(str);
	return (0);
}
