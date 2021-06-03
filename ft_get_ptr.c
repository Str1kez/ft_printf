#include <stdlib.h>
#include "libftprintf.h"

char	*get_ptr(long long num)
{
	char	*res;
	int		iter;
	int		mod;
	int		start;

	if (!num)
		start = 2;
	else
		start = 13;
	iter = start;
	res = malloc(start + 2);
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
	res[start + 1] = '\0';
	return (res);
}
