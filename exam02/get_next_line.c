#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_append(char *s, char c)
{
	char	*str;
	int		idx;

	idx = 0;
	while (s[idx])
		idx++;
	if (!(str = malloc(sizeof(char) * (idx + 2))))
		return (0);
	idx = 0;
	while (s[idx])
	{
		str[idx] = s[idx];
		idx++;
	}
	str[idx] = c;
	str[idx + 1] = 0;
	free(s);
	return (str);
}

int	get_next_line(char **line)
{
	char	buf;
	int		ret;

	if (!line || !(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	while ((ret = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n')
			break ;
		*line = ft_append(*line, buf);
	}
	return (ret);
}

int	main(void)
{
	char	*line;

	while (get_next_line(&line))
		printf("%s\n", line);
	return (0);
}
