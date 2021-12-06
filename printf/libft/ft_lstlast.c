/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:16:36 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 15:02:24 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		size;

	if (!lst)
		return (0);
	size = ft_lstsize(lst) - 1;
	while (size)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}
