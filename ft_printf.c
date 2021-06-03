#include "libftprintf.h"

static	void	init_settings(t_settings *s)
{
	s->asterisk = 0;
	s->dot = 0;
	s->minus = 0;
	s->precision = 0;
	s->size = 0;
	s->zero = 0;
}

static	void	set_settings(t_settings *setup, char key)
{
	if (key == '*')
		setup->asterisk += 1;
	if (key == '.')
		setup->dot = 1;
	if (key == '-')
		setup->minus = 1;
	if (key == '0')
		setup->zero = 1;
}

static	int	take_params(const char *args, va_list ap, t_settings *setup)
{
	size_t		size;
	char		*res;

	size = 0;
	while (!is_conversion(args[size]))
	{
		if (is_flag(args[size]))
			set_settings(setup, args[size]);
		size++;
	}
	res = conversion_handler(args[size], ap);
	ft_putstr(res);
	if (args[size] != 's')
		free(res);
	return (size + 2);
}

int	ft_printf(const char *args, ...)
{
	va_list		ap;
	t_settings	setup;

	va_start(ap, args);
	while (*args)
	{
		if (*args == '%')
		{
			init_settings(&setup);
			args += take_params(args + 1, ap, &setup);
		}
		else
			ft_putchar(*args++);
	}
	va_end(ap);
	return (0);
}
