//
// Created by Thao Nessround on 6/2/21.
//
#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	// ft_printf(
		// "My name is %s, I am %d years old. My favorite letter is '%c' %%\n",
		//  "Ilya", 20, 'm');
	// printf("My name is %s, I am %d years old. My favorite letter is '%c' %%\n",
		//  "Ilya", 20, 'm');
	 int a = 12;
	 void *p = &a;
	 printf("%021.2p\n", p);
	 ft_printf("%021.2p\n", p);
	 printf("%021.2x\n", 34324);
	 ft_printf("%021.2x\n", 34324);
	 printf("%021.2s\n", "ffefef");
	 ft_printf("%021.2s\n", "ffefef");
	 printf("%-9d\n", -3434);
	 ft_printf("%-9d\n", -3434);
	 printf("%023.2u\n", 23423);
	 ft_printf("%023.2u\n", 23423);
	// ft_printf("%d\n", is_flag('0'));
	// char *s = "00131233.23213";

	// int n = ft_atoi(s);
	// ft_printf("%d\n", n);
	// ft_printf("%s\n", s + get_num_len(n));

	return (0);
}
