//
// Created by Thao Nessround on 6/8/21.
//

#include "ftoutput_type.h"

void	out(unsigned char *help, unsigned char *input, int query)
{
	if (!query && help)
	{
		ft_putstr(help);
		free(help);
	}
	ft_putstr(input);
	if (query && help)
	{
		ft_putstr(help);
		free(help);
	}
	free(input);
}
