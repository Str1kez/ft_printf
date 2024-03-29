#include "output_type/ftoutput_type.h"

void	conversion_handler(char param, va_list ap, t_settings *setup)
{
	if (param == 's')
		output_s(va_arg(ap, unsigned char *), setup);
	if (param == 'd' || param == 'i')
		output_d(ft_itoa(va_arg(ap, int)), setup);
	if (param == 'c')
		output_c(va_arg(ap, unsigned int), setup);
	if (param == '%')
		output_c('%', setup);
	if (param == 'p')
		output_p(get_ptr(va_arg(ap, unsigned long)), setup);
	if (param == 'x' || param == 'X')
		output_d(get_uint_base(va_arg(ap, unsigned int), param, 16), setup);
	if (param == 'u')
		output_d(get_uint_base(va_arg(ap, unsigned int), param, 10), setup);
}
