//
// Created by Thao Nessround on 6/2/21.
//
#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	// ft_printf(
		// "My name is %s, I am %d years old. My favorite letter is '%c' %%\n",
		//  "Ilya", 20, 'm');
	// printf("My name is %s, I am %d years old. My favorite letter is '%c' %%\n",
		//  "Ilya", 20, 'm');
	// int a = 12;
	// void *p = &a;
	// printf("%p\n", p);
	// ft_printf("%p\n", p);
	printf("%s%X%c\n", "aaa", 1123444434, 64);
	ft_printf("%s%X%c\n", "aaa", 1123444434, 64);
	printf("%s%o%c\n", "aaa", 1123444434, 64);
	ft_printf("%s%o%c\n", "aaa", 1123444434, 64);
	printf("%s%u%c\n", "aaa", 32332, 64);
	ft_printf("%s%u%c\n", "aaa", 32332, 64);
	return (0);
}
