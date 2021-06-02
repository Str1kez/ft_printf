#include <stdarg.h>
#include "libftprintf.h"

int	output(const char param, va_list ap)
{
	if (param == 's')
		ft_putstr(va_arg(ap, char *));
	if (param == 'd' || param == 'i')
		ft_putint(va_arg(ap, int));
	if (param == 'c')
		ft_putchar(va_arg(ap, int));
	if (param == '%')
		ft_putchar('%');
	if (param == 'p')
		ft_putptr(va_arg(ap, long long));
	if (param == 'x' || param == 'X')
		ft_putuint_base(va_arg(ap, unsigned int), param, 16);
	if (param == 'o')
		ft_putuint_base(va_arg(ap, unsigned int), param, 8);
	if (param == 'u')
		ft_putuint_base(va_arg(ap, unsigned int), param, 10);
	return (2);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;

	va_start(ap, args);
	while (*args)
	{
		if (*args == '%')
			args += output(*(args + 1), ap);
		else
			ft_putchar(*args++);
	}
	va_end(ap);
	return (0);
}
