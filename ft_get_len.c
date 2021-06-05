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

size_t	ft_strlen(const char *str)
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
