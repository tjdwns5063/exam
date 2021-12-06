/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:16:00 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 18:34:51 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*rptr;
	size_t			len;

	len = count * size;
	rptr = (unsigned char *)malloc(len);
	if (!rptr)
		return (0);
	while (len--)
		*(rptr + len) = 0;
	return ((void *)rptr);
}
