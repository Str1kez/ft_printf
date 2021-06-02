//
// Created by Thao Nessround on 6/2/21.
//
#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
//	ft_printf("My name is %s, I am %d years old. My favorite letter is '%c' %%\n", "Ilya", 20, 'm');
//	printf("My name is %s, I am %d years old. My favorite letter is '%c' %%\n", "Ilya", 20, 'm');
	printf("%s%d%c\n", "323", 4343, 64);
	ft_printf("%s%d%c\n", "2332", 4343, 64);
	return (0);
}
