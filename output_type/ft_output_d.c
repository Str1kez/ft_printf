//
// Created by Thao Nessround on 6/8/21.
//

#include "ftoutput_type.h"

//static unsigned char	*create_int_precision(size_t size,
//										   unsigned char *str, int minus)
//{
//	unsigned char	*result;
//	size_t			len;
//	size_t			i;
//
//	len = ft_strlen(str);
//	i = minus;
//	result = (unsigned char *)malloc(sizeof(unsigned char)
//			* (size + 1 + minus));
//	if (!result)
//		return (NULL);
//	if (minus)
//		result[0] = '-';
//	result[size + minus] = '\0';
//	while (i < size - len + minus)
//		result[i++] = '0';
//	i = 0;
//	while (size - len + i + minus < size + minus)
//	{
//		result[size - len + i + minus] = str[i];
//		i++;
//	}
//	free(str - minus);
//	return (result);
//}
//
//static void	neg_out(unsigned char *str, size_t size)
//{
//	str = create_int_precision(size - 1, str + 1, 1);
//	out(NULL, str, 0);
//}
//
//static unsigned char	*create_empty(unsigned char *str)
//{
//	unsigned char	*res;
//
//	res = malloc(1);
//	res[0] = '\0';
//	free(str);
//	return (res);
//}

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
	if (setup->dot)
		size = max(setup->precision, ft_strlen(str));
	else
		size = ft_strlen(str);
	if (space == '0' && minus)
		ft_putchar('-');
	while (setup->size-- > size + minus)
		ft_putchar(space);
	if (minus && space != '0')
		ft_putchar('-');
	while (iter++ + ft_strlen(str) < size)
		ft_putchar('0');
	iter = 0;
	while (iter < ft_strlen(str))
		ft_putchar(str[iter++]);
}

static void	neg_screen(unsigned char *str, t_settings *setup,
					   int minus, char space)
{
	size_t	iter;
	size_t	size;

	iter = 0;
	if (setup->dot)
		size = max(setup->precision, ft_strlen(str));
	else
		size = ft_strlen(str);
	if (minus)
		ft_putchar('-');
	while (iter++ + ft_strlen(str) < size)
		ft_putchar('0');
	iter = 0;
	while (iter < ft_strlen(str))
		ft_putchar(str[iter++]);
	while (size++ < setup->size - minus)
		ft_putchar(space);
}

void	output_d(unsigned char *str, t_settings *setup)
{
	char	space;
	int		minus;

	space = ' ';
	minus = str[0] == '-';
	if (setup->dot && !setup->precision && str[0] == '0')
	{
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

//void	output_d(unsigned char *str, t_settings *setup)
//{
//	size_t	len;
//	int		minus;
//
//	minus = str[0] == '-';
//	if (setup->dot)
//	{
//		if (!setup->precision)
//			str = create_empty(str);
//		else
//			str = create_int_precision(setup->precision, str + minus, minus);
//	}
//	len = ft_strlen(str);
//	if (setup->size > len)
//	{
//		if (setup->zero && !setup->dot)
//		{
//			if (minus)
//				neg_out(str, setup->size);
//			else
//				out(create_space(setup->size - len, '0'), str, 0);
//		}
//		else
//			out(create_space(setup->size - len, ' '), str, setup->minus);
//	}
//	else
//		out(NULL, str, 0);
//}
