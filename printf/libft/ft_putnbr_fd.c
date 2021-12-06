/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:31:31 by seongjki          #+#    #+#             */
/*   Updated: 2021/07/05 12:32:57 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_len(long long nbr)
{
	int			cnt;

	cnt = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		cnt += 1;
		nbr /= 10;
	}
	return (cnt);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;
	char		ret[100];
	int			cnt;

	cnt = cnt_len(n) + (n <= 0);
	ret[cnt] = '\0';
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ret[0] = '-';
	}
	if (nbr == 0)
		ret[0] = '0';
	while (nbr)
	{
		ret[--cnt] = nbr % 10 + '0';
		nbr /= 10;
	}
	ft_putstr_fd(ret, fd);
}
