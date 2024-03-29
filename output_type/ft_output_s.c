//
// Created by Thao Nessround on 6/8/21.
//

#include "ftoutput_type.h"

static size_t	min(size_t len, unsigned int precision)
{
	if (len > precision)
		return (precision);
	return (len);
}

static void	pos_screen(unsigned char *str, size_t size,
					   t_settings *s, char space)
{
	size_t	iter;

	iter = 0;
	while (s->size-- > size)
	{
		ft_putchar(space);
		s->p_count++;
	}
	while (iter < size)
		ft_putchar(str[iter++]);
	s->p_count += size;
}

static void	neg_screen(unsigned char *str, size_t size,
					   t_settings *s, char space)
{
	size_t	iter;

	iter = 0;
	while (iter < size)
		ft_putchar(str[iter++]);
	s->p_count += size;
	while (s->size-- > size)
	{
		ft_putchar(space);
		s->p_count++;
	}
}

static unsigned char	*null_ptr(void)
{
	unsigned char	*str;

	str = malloc(7);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

void	output_s(unsigned char *str, t_settings *setup)
{
	size_t	size;
	char	space;
	int		flag;

	space = ' ';
	flag = 0;
	if (!str)
	{
		flag = 1;
		str = null_ptr();
	}
	if (setup->dot)
		size = min(setup->precision, ft_strlen(str));
	else
		size = ft_strlen(str);
	if (setup->zero)
		space = '0';
	if (setup->minus)
		neg_screen(str, size, setup, space);
	else
		pos_screen(str, size, setup, space);
	if (flag)
		free(str);
}
