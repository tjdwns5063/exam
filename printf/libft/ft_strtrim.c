/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:58:22 by seongjki          #+#    #+#             */
/*   Updated: 2021/07/05 12:34:25 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_left_index(char *str, char *set)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (!ft_strchr(set, *ptr))
			break ;
		ptr++;
	}
	return (ptr);
}

static char	*find_right_index(char *str, char *set)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	while (ptr >= str)
	{
		if (!ft_strchr(set, *ptr))
			break ;
		ptr--;
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*ptr;
	char	*left;
	char	*right;

	if (!(*set))
		return (ft_strdup(s1));
	left = find_left_index((char *)s1, (char *)set);
	right = find_right_index((char *)s1, (char *)set);
	if (left > right)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (right - left + 2));
	if (!str)
		return (0);
	ptr = str;
	while (left <= right)
		*ptr++ = *left++;
	*ptr = '\0';
	return (str);
}
