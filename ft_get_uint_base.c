#include "libftprintf.h"

unsigned char	*get_uint_base(unsigned int num, char param, int base)
{
	unsigned char	*res;
	int				count;
	unsigned int	mod;

	count = get_unum_len(num, base);
	res = (unsigned char *)malloc(count + 1);
	if (res)
	{
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
		return (res);
	}
	return (NULL);
}
