#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *str, char *buf);
int		str_in_nl(char *str);

#endif
