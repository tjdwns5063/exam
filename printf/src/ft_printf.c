#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define base "0123456789"
#define base_l "0123456789abcdef"

typedef struct	s_info
{
	char	spc;
	int		size;
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
	ret = 0;
	if (n < 0)
		num *= -1;
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
	int		idx;
	char	*ret;

	num = n;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = 0;
	if (n < 0)
	{
		num *= -1;
		ret[0] = '-';
	}
	else if (n == 0)
		ret[0] = '0';
	idx = size - 1;
	while (num > 0)
	{
		if (base_len == 10)
			ret[idx] = base[num % base_len];
		else if (base_len == 16)
			ret[idx] = base_l[num % base_len];
		idx--;
		num /= base_len;
	}
	return (ret);
}

int	make_s(va_list ap, t_info *info)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		s = "(null)";
		info->size = 6;
	}
	else
		info->size = ft_strlen(s);
	write(1, s, info->size);
	return (info->size);
}

int	make_d(va_list ap, t_info *info)
{
	int		d;
	char	*str;

	d = va_arg(ap, int);
	info->size = cnt_num_len(d, 10) + (d < 0);
	str = ft_xtoa(d, 10, info->size);
	write(1, str, info->size);
	free(str);
	return (info->size);
}

int	make_x(va_list ap, t_info * info)
{
	unsigned int	x;
	char			*str;

	x = va_arg(ap, unsigned int);
	info->size = cnt_num_len(x, 16);
	str = ft_xtoa(x, 16, info->size);
	write(1, str, info->size);
	free(str);
	return (info->size);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	int		ret;
	va_list	ap;
	t_info	info;

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
				write(1, &info.spc, 1);
				ret++;
			}
			s = s + 2;
		}
		else
		{
			write(1, &(*s), 1);
			s++;
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
