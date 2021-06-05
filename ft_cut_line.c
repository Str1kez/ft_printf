//
// Created by Thao Nessround on 6/6/21.
//
#include "libftprintf.h"

char	*cut_line(const char *str, int size)
{
	char	*result;
	int		iter;

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
