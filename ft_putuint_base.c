#include <stdlib.h>
#include "libftprintf.h"

void	ft_putuint_base(unsigned int num, char param, int base)
{
	char			*res;
	int				count;
	int				mod;
	unsigned int	num_cpy;

	count = 0;
	num_cpy = num;
	while (num_cpy)
	{
		count++;
		num_cpy /= base;
	}
	res = malloc(count + 1);
	res[count--] = '\0';
	while (count > -1)
	{
		mod = num % base;
		if (mod > 9)
			res[count--] = mod % 10 + param - 23;
		else
			res[count--] = mod + 48;
		num /= base;
	}
	ft_putstr(res);
	free(res);
}
