/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_xtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:54:05 by seongjki          #+#    #+#             */
/*   Updated: 2021/07/05 12:32:00 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_cnt(unsigned long long target)
{
	int	cnt;

	cnt = 0;
	while (target > 0)
	{
		target /= 16;
		cnt++;
	}
	return (cnt + (cnt == 0));
}

static void	fill_target(char **ret, unsigned long long target, int cnt)
{
	char	*base_x;
	int		num;
	int		idx;

	base_x = "0123456789abcdef";
	idx = cnt - 1;
	while (target > 0)
	{
		num = target % 16;
		target /= 16;
		(*ret)[idx] = base_x[num];
		idx--;
	}
}

char	*ft_long_xtoa(long long value)
{
	unsigned long long	target;
	int					cnt;
	char				*ret;

	target = value;
	cnt = get_cnt(target);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	ret[cnt] = '\0';
	if (target == 0)
		ret[0] = '0';
	fill_target(&ret, target, cnt);
	return (ret);
}
