/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:48:55 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 15:07:01 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (*(s + index))
	{
		if (*(s + index) == (char)c)
			return ((char *)s + index);
		index++;
	}
	if (*(s + index) == (char)c)
		return ((char *)s + index);
	return (0);
}
