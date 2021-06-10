#include <stdlib.h>

int	get_num_len(int num)
{
	int	size;

	size = 0;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

int	get_unum_len(unsigned int num, int base)
{
	int	size;

	size = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= base;
		size++;
	}
	return (size);
}

size_t	ft_strlen(const unsigned char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
