//
// Created by Thao Nessround on 6/8/21.
//

#include "ftoutput_type.h"

static size_t	max(size_t len, unsigned int precision)
{
	if (len < precision)
		return (precision);
	return (len);
}

static void	pos_screen(unsigned char *str, t_settings *setup,
					   int minus, char space)
{
	size_t	iter;
	size_t	size;

	iter = 0;
	size = max(setup->precision, ft_strlen(str));
	if (space == '0' && minus)
		ft_putchar('-');
	setup->p_count += minus;
	while (setup->size-- > size + minus)
	{
		ft_putchar(space);
		setup->p_count++;
	}
	if (minus && space != '0')
		ft_putchar('-');
	while (iter++ + ft_strlen(str) < size)
	{
		ft_putchar('0');
		setup->p_count++;
	}
	iter = 0;
	while (iter < ft_strlen(str))
		ft_putchar(str[iter++]);
	setup->p_count += ft_strlen(str);
}

static void	neg_screen(unsigned char *str, t_settings *setup,
					   int minus, char space)
{
	size_t	iter;
	size_t	size;

	iter = 0;
	size = max(setup->precision, ft_strlen(str));
	if (minus)
		ft_putchar('-');
	setup->p_count += minus;
	while (iter++ + ft_strlen(str) < size)
		ft_putchar('0');
	setup->p_count += size - ft_strlen(str);
	iter = 0;
	while (iter < ft_strlen(str))
		ft_putchar(str[iter++]);
	setup->p_count += ft_strlen(str);
	if (setup->size > 0 || !minus)
	{
		if (setup->size - minus > size)
			setup->p_count += setup->size - minus - size;
		while (size++ < setup->size - minus)
			ft_putchar(space);
	}
}

void	output_d(unsigned char *str, t_settings *setup)
{
	char	space;
	int		minus;

	space = ' ';
	minus = str[0] == '-';
	if (setup->dot && !setup->precision && str[0] == '0')
	{
		setup->p_count += setup->size;
		while (setup->size--)
			ft_putchar(' ');
		free(str);
		return ;
	}
	if (setup->zero && !setup->dot)
		space = '0';
	if (setup->minus)
		neg_screen(str + minus, setup, minus, space);
	else
		pos_screen(str + minus, setup, minus, space);
	free(str);
}
