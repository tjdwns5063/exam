/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:31:04 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 18:35:48 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sptr;
	size_t	index;

	index = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sptr = (char *)malloc((len + 1) * sizeof(char));
	if (!sptr)
		return (0);
	sptr[len] = 0;
	while (index < len)
		*(sptr + index++) = *(s + start++);
	return (sptr);
}
