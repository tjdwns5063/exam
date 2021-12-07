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
		r_idx++;
		idx++;
	}
	idx = 0;
	free(str);
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
