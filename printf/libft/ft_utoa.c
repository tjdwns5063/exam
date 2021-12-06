/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:23:06 by seongjki          #+#    #+#             */
/*   Updated: 2021/12/02 17:13:33 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_len(unsigned int target)
{
	int		cnt;

	cnt = 0;
	while (target > 0)
	{
		target /= 10;
		cnt++;
	}
	return (cnt + (cnt == 0));
}

static void	fill_target(char *ret, unsigned int target, int cnt)
{
	int		num;
	int		idx;

	idx = cnt - 1;
	while (target > 0)
	{
		num = target % 10;
		target /= 10;
		ret[idx] = num + '0';
		idx--;
	}
}

char	*ft_utoa(int value)
{
	unsigned int	target;
	int				cnt;
	char			*ret;

	target = value;
	cnt = cnt_len(target);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	ret[cnt] = '\0';
	if (target == 0)
		ret[0] = '0';
	fill_target(ret, target, cnt);
	return (ret);
}
