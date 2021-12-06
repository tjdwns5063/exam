/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:49:44 by seongjki          #+#    #+#             */
/*   Updated: 2021/05/14 15:01:47 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*next;
	t_list		*current;

	current = *lst;
	*lst = 0;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
}
