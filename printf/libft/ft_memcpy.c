/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:43:35 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/15 16:08:14 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	*d_ptr;

	s_ptr = (unsigned char *)src;
	d_ptr = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*d_ptr++ = *s_ptr++;
	}
	return (dst);
}
