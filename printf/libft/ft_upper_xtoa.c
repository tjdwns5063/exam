/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_xtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:03:32 by seongjki          #+#    #+#             */
/*   Updated: 2021/12/02 17:13:04 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_cnt(unsigned int target)
{
	int		cnt;

	cnt = 0;
	while (target > 0)
	{
		target /= 16;
		cnt++;
	}
	return (cnt + (cnt == 0));
}

static void	fill_target(char *ret, unsigned int target, int cnt)
{
	char	*base_x;
	int		num;
	int		idx;

	base_x = "0123456789ABCDEF";
	idx = cnt - 1;
	while (target > 0)
	{
		num = target % 16;
		target /= 16;
		ret[idx] = base_x[num];
		idx--;
	}
}

char	*ft_upper_xtoa(int value)
{
	unsigned int	target;
	int				cnt;
	char			*ret;

	target = value;
	cnt = get_cnt(target);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	ret[cnt] = '\0';
	if (target == 0)
		ret[0] = '0';
	fill_target(ret, target, cnt);
	return (ret);
}
