#include "libftprintf.h"

static	char	*create_space(int size, char space)
{
	char	*result;

	result = malloc(size + 1);
	result[size--] = '\0';
	while (size > -1)
	{
		result[size--] = space;
	}
	return (result);
}

static	void	out(char *help, char *input, int query)
{
	if (!query && help)
	{
		ft_putstr(help);
		free(help);
	}
	ft_putstr(input);
	if (query && help)
	{
		ft_putstr(help);
		free(help);
	}
}

static void	out_count(char *help, char *input, int count)
{
	int	iter;

	iter = 0;
	while (iter < count)
		ft_putchar(input[iter++]);
	ft_putstr(help);
	ft_putstr(input + count);
	free(help);
}

void	output(char *str, char conv, t_settings *setup)
{
	int		len;

	if (conv == 's' && setup->dot)
		str = cut_line(str, setup->precision);
	len = ft_strlen(str);
	if (len < setup->size)
	{
		if (setup->zero && (!setup->dot || conv == 's'))
		{
			if (conv == 'p')
				out_count(create_space(setup->size - len, '0'), str, 2);
			else if (conv == 'd')
				out_count(create_space(setup->size - len, '0'), str, 1);
			else
				out(create_space(setup->size - len, '0'), str, 0);
		}
		else
			out(create_space(setup->size - len, ' '), str, setup->minus);
	}
	else
		out(NULL, str, 0);
	if (conv == 's' && setup->dot)
		free(str);
}
