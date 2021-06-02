#include <stdlib.h>
#include "libftprintf.h"

void	ft_putptr(long long num)
{
	char	res[15];
	int		iter;
	int		mod;

	iter = 13;
	res[0] = '0';
	res[1] = 'x';
	while (iter > 1)
	{
		mod = num % 16;
		if (mod > 9)
			res[iter--] = mod % 10 + 97;
		else
			res[iter--] = mod + 48;
		num /= 16;
	}
	res[14] = '\0';
	ft_putstr(res);
}
