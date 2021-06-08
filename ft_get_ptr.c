#include <stdlib.h>
#include "libftprintf.h"

static void	paste_num(unsigned char *s, long long num, int iter)
{
	int	mod;

	while (iter > 1)
	{
		mod = num % 16;
		if (mod > 9)
			s[iter--] = mod % 10 + 97;
		else
			s[iter--] = mod + 48;
		num /= 16;
	}
}

static int	get_len_ptr(long long num)
{
	int	size;

	size = 0;
	while (num)
	{
		num /= 16;
		size++;
	}
	return (size);
}

unsigned char	*get_ptr(long long num)
{
	unsigned char	*res;
	int				start;

	if (!num)
		start = 1;
	else
		start = get_len_ptr(num);
	res = malloc(start + 3);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	paste_num(res, num, start + 1);
	res[start + 2] = '\0';
	return (res);
}
