/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:43:32 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 22:02:07 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	*d_ptr;

	s_ptr = (void *)src;
	d_ptr = dst;
	while (n)
	{
		*d_ptr = *s_ptr;
		if (*d_ptr == (unsigned char)c)
			return (d_ptr + 1);
		d_ptr++;
		s_ptr++;
		n--;
	}
	return (0);
}
