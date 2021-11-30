#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(char *str, ...)
{
	va_list ap;

	va_start(ap, str);

	return (0);
}

int main()
{
	ft_printf("abc");
	system("leaks a.out | grep leaked");
}
