/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:37:25 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 18:37:35 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rptr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	rptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!rptr)
		return (0);
	ft_memmove(rptr, s1, ft_strlen(s1));
	ft_memmove(rptr + ft_strlen(s1), s2, ft_strlen(s2));
	*(rptr + len) = '\0';
	return (rptr);
}
