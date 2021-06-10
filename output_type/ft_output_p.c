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
						  char space)
{
	size_t	iter;
	size_t	size;

	iter = 0;
	size = max(ft_strlen(str) - 2, setup->precision);
	if (setup->size > size + 2)
		setup->p_count += setup->size - size - 2;
	while (space == ' ' && size + 2 < setup->size--)
		ft_putchar(space);
	ft_putchar(str[0]);
	ft_putchar(str[1]);
	while (space == '0' && size + 2 < setup->size--)
		ft_putchar(space);
	while (iter++ + ft_strlen(str) - 2 < size)
		ft_putchar('0');
	setup->p_count += iter - 1;
	iter = 2;
	while (iter < ft_strlen(str))
		ft_putchar(str[iter++]);
	setup->p_count += iter - 2;
}

static void	neg_screen(unsigned char *str, t_settings *setup,
						  char space)
{
	size_t	iter;
	size_t	size;

	iter = 0;
	size = max(ft_strlen(str) - 2, setup->precision);
	ft_putchar(str[0]);
	ft_putchar(str[1]);
	while (iter++ + ft_strlen(str) - 2 < size)
		ft_putchar('0');
	setup->p_count += iter - 1;
	iter = 2;
	while (iter < ft_strlen(str))
		ft_putchar(str[iter++]);
	setup->p_count += iter - 2;
	while (size++ + 2 < setup->size)
	{
		ft_putchar(space);
		setup->p_count++;
	}
}

static void	output_empty(unsigned char *str, t_settings *setup)
{
	if (setup->size > 2)
		setup->p_count += setup->size - 2;
	if (!setup->minus)
		while (setup->size-- > 2)
			ft_putchar(' ');
	ft_putchar(str[0]);
	ft_putchar(str[1]);
	if (setup->minus)
		while (setup->size-- > 2)
			ft_putchar(' ');
	free(str);
}

void	output_p(unsigned char *str, t_settings *setup)
{
	char	space;

	space = ' ';
	setup->p_count += 2;
	if (setup->dot && !setup->precision && !str[3])
	{
		output_empty(str, setup);
		return ;
	}
	if (setup->zero && !setup->dot)
		space = '0';
	if (setup->minus)
		neg_screen(str, setup, space);
	else
		pos_screen(str, setup, space);
	free(str);
}
