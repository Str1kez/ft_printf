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
	// printf("%p\n", NULL);
	// ft_printf("%p\n", NULL);
	// ft_printf("%X\n", 64);
	// printf("%X\n", 64);
	// ft_printf("%u\n", 23423);
	printf("%s%*s%c\n", "abc", 12, "omg", 64);
	ft_printf("%s%*s%c\n", "aaa", 12, "omg", 64);
	// ft_printf("%d\n", is_flag('0'));
	// char *s = "00131233.23213";

	// int n = ft_atoi(s);
	// ft_printf("%d\n", n);
	// ft_printf("%s\n", s + get_num_len(n));

	return (0);
}
