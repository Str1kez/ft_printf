#include "libftprintf.h"

static int	is_negative(int n)
{
	return (n < 0);
}

static int	num_len(int n)
{
	int				count;
	unsigned int	help;

	if (is_negative(n))
		help = (n + 1) * (-1) + 1;
	else
		help = n;
	count = 1;
	while (help > 9)
	{
		help /= 10;
		count++;
	}
	return (count);
}

static int	num_on_iter(int n, int iter, int len)
{
	int				i;
	unsigned int	help;

	if (is_negative(n))
		help = (n + 1) * (-1) + 1;
	else
		help = n;
	i = 0;
	while (i < len - iter - 1)
	{
		help /= 10;
		i++;
	}
	return (help % 10);
}

void	ft_putint(int n)
{
	int		len;
	int		negative;
	int		iter;

	iter = 0;
	negative = is_negative(n);
	len = num_len(n);
	if (negative)
		ft_putchar('-');
	while (iter < len)
	{
		ft_putchar(num_on_iter(n, iter, len) + 48);
		iter++;
	}
}
