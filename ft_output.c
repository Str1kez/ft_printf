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

void	output(char *conv, t_settings *setup)
{
	int		len;

	len = ft_strlen(conv);
	if (len < setup->size)
	{
		if (setup->zero)
			out(create_space(setup->size - len, '0'), conv, 0);
		else
			out(create_space(setup->size - len, ' '), conv, setup->minus);
	}
	else
		out(NULL, conv, 0);
}
