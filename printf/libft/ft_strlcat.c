/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:49:43 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 15:07:53 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	temp_index;

	index = 0;
	temp_index = 0;
	while (*(dst + index) && index < dstsize)
		index++;
	while (*(src + temp_index) && (index + temp_index + 1) < dstsize)
	{
		*(dst + (index + temp_index)) = *(src + temp_index);
		temp_index++;
	}
	if (index < dstsize)
		*(dst + (index + temp_index)) = '\0';
	return (index + ft_strlen(src));
}
