#include "ftoutput_type.h"

static void	pos_screen(unsigned char c, size_t s_size, char space)
{
	while (s_size-- > 1)
		ft_putchar(space);
	ft_putchar(c);
}

static void	neg_screen(unsigned char c, size_t s_size, char space)
{
	ft_putchar(c);
	while (s_size-- > 1)
		ft_putchar(space);
}

void	output_c(unsigned char c, t_settings *setup)
{
	char	space;

	space = ' ';
	if (setup->zero)
		space = '0';
	if (setup->minus)
		neg_screen(c, setup->size, space);
	else
		pos_screen(c, setup->size, space);
}
