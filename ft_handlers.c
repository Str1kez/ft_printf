#include "libftprintf.h"

char	*conversion_handler(char param, va_list ap)
{
	if (param == 's')
		return (va_arg(ap, char *));
	if (param == 'd')
		return (ft_itoa(va_arg(ap, int)));
	if (param == 'i')
		return (get_uint_base(va_arg(ap, int), param, 10));
	if (param == 'c')
		return (char_to_str(va_arg(ap, unsigned int)));
	if (param == '%')
		return (char_to_str('%'));
	if (param == 'p')
		return (get_ptr(va_arg(ap, long long)));
	if (param == 'x' || param == 'X')
		return (get_uint_base(va_arg(ap, unsigned int), param, 16));
	if (param == 'u')
		return (get_uint_base(va_arg(ap, unsigned int), param, 10));
	return (NULL);
}
