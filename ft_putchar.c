#include "libftprintf.h"
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}
