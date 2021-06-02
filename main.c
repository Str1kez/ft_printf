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
	int a = 12;
	void *p = &a;
	printf("%p\n", p);
	printf("%s%i%c\n", "aaa", 1123444434, 64);
	ft_printf("%s%i%c\n", "aaa", 1123444434, 64);
	return (0);
}
