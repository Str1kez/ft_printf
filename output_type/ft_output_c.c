#include "ftoutput_type.h"

static void	pos_screen(unsigned char c, t_settings *s, char space)
{
	while (s->size-- > 1)
	{
		ft_putchar(space);
		s->p_count++;
	}
	ft_putchar(c);
}

static void	neg_screen(unsigned char c, t_settings *s, char space)
{
	ft_putchar(c);
	while (s->size-- > 1)
	{
		ft_putchar(space);
		s->p_count++;
	}
}

void	output_c(unsigned char c, t_settings *setup)
{
	char	space;

	setup->p_count++;
	space = ' ';
	if (setup->zero)
		space = '0';
	if (setup->minus)
		neg_screen(c, setup, space);
	else
		pos_screen(c, setup, space);
}
