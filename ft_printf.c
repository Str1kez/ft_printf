#include "libftprintf.h"

static	void	set_asterisk(t_settings *setup, char *key, va_list ap)
{
	int	check;

	check = va_arg(ap, int);
	if (check < 0)
	{
		check = -check;
		if (setup->dot)
			setup->dot = 0;
		else
		{
			*key = '-';
			setup->size = check;
		}
		return ;
	}
	if (setup->dot)
		setup->precision = check;
	else
		setup->size = check;
}

static	void	set_flags(t_settings *setup, char key, va_list ap)
{
	if (key == '*')
		set_asterisk(setup, &key, ap);
	if (key == '.')
		setup->dot = 1;
	if (key == '-')
	{
		if (setup->zero)
			setup->zero = 0;
		setup->minus = 1;
	}
	if (key == '0' && !setup->minus)
		setup->zero = 1;
}

static	int	set_precision_size(const char *args, t_settings *setup)
{
	int	num;
	int	num_size;

	num = ft_atoi(args);
	num_size = get_num_len(num);
	while (*args == '0')
	{
		num_size += 1;
		args++;
	}
	if (setup->dot)
		setup->precision = num;
	else
		setup->size = num;
	return (num_size);
}

static	size_t	take_params(const char *args, va_list ap, t_settings *setup)
{
	size_t			size;

	size = 0;
	if (!args[size] || (!is_flag(args[size]) && !ft_isdigit(args[size])
			&& !is_conversion(args[size])))
		return (1);
	while (!is_conversion(args[size]))
	{
		if (ft_isdigit(args[size])
			&& (args[size] != '0' || setup->zero || setup->minus || setup->dot))
			size += set_precision_size(args + size, setup);
		if (is_flag(args[size]))
			set_flags(setup, args[size++], ap);
	}
	conversion_handler(args[size], ap, setup);
	return (size + 2);
}

int	ft_printf(const char *args, ...)
{
	va_list		ap;
	t_settings	setup;

	va_start(ap, args);
	setup.p_count = 0;
	while (*args)
	{
		if (*args == '%')
		{
			setup.dot = 0;
			setup.minus = 0;
			setup.precision = 0;
			setup.size = 0;
			setup.zero = 0;
			args += take_params(args + 1, ap, &setup);
		}
		else
		{
			ft_putchar(*args++);
			setup.p_count++;
		}
	}
	va_end(ap);
	return (setup.p_count);
}
