#include "get_next_line.h"

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
	ret[idx] = 0;
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
	if (!ret)
		return (0);
	ret[size] = 0;
	r_idx = 0;
	idx = 0;
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
		r_idx++;
		idx++;
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
	char	*line;
	char	*tmp;
	int		n_idx;
	int		idx;

	n_idx = str_in_nl(*str);
	idx = 0;
	line = (char *)malloc(sizeof(char) * (n_idx + 2));
	if (!line)
		return (0);
	line[n_idx + 1] = 0;
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
	char		*line;
	int			size;

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
