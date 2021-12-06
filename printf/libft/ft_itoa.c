/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:50:44 by seongjki          #+#    #+#             */
/*   Updated: 2021/12/02 17:12:27 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_len(long long n)
{
	int			cnt;

	cnt = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		cnt += 1;
	}
	return (cnt);
}

static void	make_str(char *str, int n, int cnt)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		*(str + cnt - 1) = nbr % 10 + '0';
		nbr /= 10;
		cnt--;
	}
}

char	*ft_itoa(int n)
{
	int			cnt;
	char		*ret;

	cnt = cnt_len(n) + (n <= 0);
	ret = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!ret)
		return (0);
	ret[cnt] = '\0';
	if (n < 0)
		*ret = '-';
	if (n == 0)
		*ret = '0';
	make_str(ret, n, cnt);
	return (ret);
}
