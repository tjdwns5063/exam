/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:32:20 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/15 16:04:51 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;
	size_t			i;

	d_ptr = dst;
	s_ptr = (void *)src;
	if (d_ptr > s_ptr)
	{
		i = len - 1;
		while (len--)
		{
			*(d_ptr + i) = *(s_ptr + i);
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
