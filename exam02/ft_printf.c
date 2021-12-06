#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define base "0123456789"
#define base_l "0123456789abcdef"


typedef struct s_info
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
	long num;
	int	ret;

	num = n;
	if (num < 0)
		num *= -1;
	ret = 0;
	while (num > 0)
	{
		num /= base_len;
		ret++;
	}
	return (ret + (num == 0));
}

int	make_s(va_list ap, t_info *info)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == 0)
	{
		info->size = 6;
		s = "(null)";
	}
	else
		info->size = ft_strlen(s);
	write(1, s, info->size);
	return (info->size);
}

int	make_d(va_list ap, t_info *info)
{
	long	d;
	char	*str;
	int		idx;

	d = va_arg(ap, int);
	info->size = cnt_num_len(d, 10) + (d < 0);
	str = (char *)malloc(sizeof(char) * (info->size + 1));
	str[info->size] = 0;
	if (d < 0)
		str[0] = '-';
	if (d == 0)
		str[0] = '0';
	if (d <= -1)
		d *= -1;
	idx = info->size - 1;
	while (d > 0)
	{
		str[idx] = base[d % 10];
		d /= 10;
		idx--;
	}
	write(1, str, info->size);
	free(str);
	return (info->size);
}

int	make_x(va_list ap, t_info *info)
{
	unsigned int	x;
	char			*str;
	int				idx;

	x = va_arg(ap, unsigned int);
	info->size = cnt_num_len(x, 16);
	str = (char *)malloc(sizeof(char) * (info->size + 1));
	str[info->size] = 0;
	if (x == 0)
		str[0] = '0';
	idx = info->size - 1;
	while (x > 0)
	{
		str[idx] = base_l[x % 16];
		x /= 16;
		idx--;
	}
	write(1, str, info->size);
	free(str);
	return (info->size);
}

int	ft_printf(char *str, ...)
{
	t_info	info;
	va_list ap;
	int		ret;

	va_start(ap, str);
	ret = 0;
	info.spc = 0;
	info.size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			info.spc = *(str + 1);
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
			str++;
		}
		else
		{
			write(1, &(*str), 1);
			str++;
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}

#include <limits.h>
#include <assert.h>
int main()
{
	int	ret1;
	int	ret2;
/*
	ret = printf("abc%dabc\n", INT_MAX);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%dabc\n", INT_MAX);
	ft_printf("%d\n", ret);
	ret = printf("abc%dabc\n", INT_MIN);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%dabc\n", INT_MIN);
	ft_printf("%d\n", ret);
	ret = printf("abc%dabc\n", 0);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%dabc\n", 0);
	ft_printf("%d\n", ret);
	ret = printf("abc%dabc\n", -15);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%dabc\n", -15);
	ft_printf("%d\n", ret);
	ret = printf("abc%dabc\n", -1);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%dabc\n", -1);
	ft_printf("%d\n", ret);
	ret = printf("abc%dabc\n", 1);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%dabc\n", 1);
	ft_printf("%d\n", ret);
	ret = printf("abc%sabc\n", NULL);
	ft_printf("%d\n", ret);
	ret = ft_printf("abc%sabc\n", NULL);
	ft_printf("%d\n", ret);
	ret = printf("%s %s horse\n", "my", "name is");
	ft_printf("%d\n", ret);
	ret = ft_printf("%s %s horse\n", "my", "name is");
	ft_printf("%d\n", ret);
	ret = printf("%x\n", 145);
	ft_printf("%d\n", ret);
	ret = ft_printf("%x\n", 145);
	ft_printf("%d\n", ret);
	ret = printf("%x\n", INT_MAX);
	ft_printf("%d\n", ret);
	ret = ft_printf("%x\n", INT_MAX);
	ft_printf("%d\n", ret);
	ret = printf("%x %d %s\n", -145, -145, "145");
	ft_printf("%d\n", ret);
	ret = ft_printf("%x %d %s\n", -145, -145, "145");
	ft_printf("%d\n", ret);
	ret = printf("%x abc %d abc %s abc\n", -145, -145, "145");
	ft_printf("%d\n", ret);
	ret = ft_printf("%x abc %d abc %s abc\n", -145, -145, "145");
	ft_printf("%d\n", ret);
	ret = printf("%x %d %s\n", INT_MIN, -145, "\t");
	ft_printf("%d\n", ret);
	ret = ft_printf("%x %d %s\n", INT_MIN, -145, "\t");
	ft_printf("%d\n", ret);
*/
	//printf("%%%", 1);
	ft_printf("%s\n", "abc");
	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
}
