/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:32:28 by seongjki          #+#    #+#             */
/*   Updated: 2021/07/05 12:33:27 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *str, char c)
{
	size_t	words;

	words = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			words++;
			str++;
			while (*str && *str != c)
				str++;
		}
	}
	return (words);
}

static void	get_words(char **split, char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && str[i + j] != c)
				j++;
			split[word] = ft_substr(str, i, j);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	char	*str;

	str = (char *)s;
	words = count_words(str, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (0);
	split[words] = 0;
	get_words(split, str, c);
	return (split);
}
