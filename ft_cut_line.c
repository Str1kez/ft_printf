//
// Created by Thao Nessround on 6/6/21.
//
#include "libftprintf.h"

unsigned char	*cut_line(const unsigned char *str, int size)
{
	unsigned char	*result;
	int				iter;

	result = malloc(size + 1);
	result[size] = '\0';
	iter = 0;
	while (iter < size)
	{
		result[iter] = str[iter];
		iter++;
	}
	return (result);
}
