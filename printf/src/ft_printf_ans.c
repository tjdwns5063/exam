#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define base "0123456789"
#define base_l "0123456789abcdef"

typedef struct	s_info
{
	int		size;
	char	spc;
}	t_info;

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	cnt_num_len(long n, int base_len)
{
	long	num;
	int		ret;

	num = n;
	if (num < 0)
		num *= -1;
	ret = 0;
	while (num > 0)
	{
		num /= base_len;
		ret++;
	}
	return (ret + (n == 0));
}

char	*ft_xtoa(long n, int base_len, int size)
{
	long	num;
	char	*ret;
	int		idx;

	num = n;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = 0;
	idx = size - 1;
	if (num < 0)
	{
		num *= -1;
		ret[0] = '-';
	}
	if (num == 0)
		ret[0] = '0';
	while (num > 0)
	{
		if (base_len == 10)
			ret[idx] = base[num % base_len];
		else if (base_len == 16)
			ret[idx] = base_l[num % base_len];
		num /= base_len;
		idx--;
	}
	return (ret);
}

int	make_s(va_list ap, t_info *info)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		str = "(null)";
		info->size = 6;
	}
	else
		info->size = ft_strlen(str);
	write(1, str, info->size);
	return (info->size);
}

int	make_d(va_list ap, t_info *info)
{
	char	*str;
	int		d;

	d = va_arg(ap, int);
	info->size = cnt_num_len(d, 10) + (d < 0);
	str = ft_xtoa(d, 10, info->size);
	write(1, str, info->size);
	free(str);
	return (info->size);
}

int	make_x(va_list ap, t_info *info)
{
	char			*str;
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	info->size = cnt_num_len(x, 16);
	str = ft_xtoa(x, 16, info->size);
	write(1, str, info->size);
	free(str);
	return (info->size);
}

int	ft_printf(const char *str, ...)
{
	t_info	info;
	char	*s;
	va_list	ap;
	int		ret;

	s = (char *)str;
	ret = 0;
	va_start(ap, str);
	info.spc = 0;
	info.size = 0;
	while (*s)
	{
		if (*s == '%')
		{
			info.spc = *(s + 1);
			if (info.spc == 's')
				ret += make_s(ap, &info);
			else if (info.spc == 'd')
				ret += make_d(ap, &info);
			else if (info.spc == 'x')
				ret += make_x(ap, &info);
			else
			{
				ret += 1;
				write(1, &info.spc, 1);
			}
			info.spc = 0;
			info.size = 0;
			s = s + 2;
		}
		else
		{
			write(1, &(*s), 1);
			ret++;
			s++;
		}
	}
	va_end(ap);
	return (ret);
}
