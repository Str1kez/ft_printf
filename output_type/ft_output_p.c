//
// Created by Thao Nessround on 6/8/21.
//

#include "ftoutput_type.h"

static unsigned char	*create_ptr_precision(size_t size, unsigned char *str)
{
	unsigned char	*result;
	size_t			len;
	size_t			i;

	len = ft_strlen(str);
	result = (unsigned char *)malloc(sizeof(unsigned char) * (size + 3));
	if (!result)
		return (NULL);
	result[size + 2] = '\0';
	i = 2;
	result[0] = '0';
	result[1] = 'x';
	while (i < size - len + 4)
		result[i++] = '0';
	i = 0;
	while (size - len + i < size)
	{
		result[size - len + i + 4] = str[i + 2];
		i++;
	}
	free(str);
	return (result);
}

static void	out_count(unsigned char *help, unsigned char *input, int count)
{
	int	iter;

	iter = 0;
	while (iter < count)
		ft_putchar(input[iter++]);
	ft_putstr(help);
	ft_putstr(input + count);
	free(help);
	free(input);
}

void	output_p(unsigned char *str, t_settings *setup)
{
	size_t	len;

	len = ft_strlen(str);
	if (setup->dot && setup->precision > len - 2)
	{
		str = create_ptr_precision(setup->precision, str);
		len = ft_strlen(str);
	}
	if (setup->size > len)
	{
		if (setup->zero && !setup->dot)
			out_count(create_space(setup->size - len, '0'), str, 2);
		else
			out(create_space(setup->size - len, ' '), str, setup->minus);
	}
	else
		out(NULL, str, 0);
}
