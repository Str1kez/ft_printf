#include "libftprintf.h"

unsigned char	*char_to_str(unsigned char c)
{
	unsigned char	*res;

	res = malloc(2);
	res[0] = c;
	res[1] = '\0';
	return (res);
}
