/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:19:29 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 21:05:50 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	if (dstsize == 0)
		return (ft_strlen(src));
	index = 0;
	while (*(src + index) && index + 1 < dstsize)
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = '\0';
	while (*(src + index))
		index++;
	return (ft_strlen(src));
}
