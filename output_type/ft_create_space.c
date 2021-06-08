//
// Created by Thao Nessround on 6/8/21.
//

#include "ftoutput_type.h"

unsigned char	*create_space(size_t size, char space)
{
	unsigned char	*result;

	result = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (result)
	{
		result[size--] = '\0';
		while (size > 0)
		{
			result[size--] = space;
		}
		result[0] = space;
		return (result);
	}
	return (NULL);
}
