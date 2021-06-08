//
// Created by Thao Nessround on 6/2/21.
//
#include <stdio.h>
#include "libftprintf.h"

void check_leaks();

int	main(void)
{
	// ft_printf(
		// "My name is %s, I am %d years old. My favorite letter is '%c' %%\n",
		//  "Ilya", 20, 'm');
	// printf("My name is %s, I am %d years old. My favorite letter is '%c' %%\n",
		//  "Ilya", 20, 'm');
//	static int p;
//	printf("%21p\n", &p);
//	ft_printf("%21p\n", &p);
//	printf("%021.2x\n", 34324);
//	ft_printf("%021.2x\n", 34324);
//	printf("%021.2s\n", "ffefef");
//	ft_printf("%021.2s\n", "ffefef");
//	printf("%-9d\n", -3434);
//	ft_printf("%-9d\n", -3434);
//	printf("%023.2u\n", 23423);
//	ft_printf("%023.2u\n", 23423);
//	printf("%22.3c\n", '\0');
//	printf("%22.3c\n", '\0');
//	ft_printf("%05.2c\n", 'a');
	printf("%i",  2147483647);
	ft_printf("%i",  2147483647);
//	printf("%-5c\n", '\0');
//	ft_printf("%-5c\n", '\0');
//	printf("%.8d\n", -34434);
//	ft_printf("%.8d", -34434);
//	printf("%08.5d", 34);
//	ft_printf("%08.5d", 34);
//	printf("%.0d", 0);
//	printf("\n");
//	ft_printf("%.0d", 0);
//	printf("%-12.22s\n", "fsdfsdf");
//	ft_printf("%-12.22s\n", "fsdfsdf");
	check_leaks();

	return (0);
}
