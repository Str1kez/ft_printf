//
// Created by Thao Nessround on 6/8/21.
//
#include "libftprintf.h"

static unsigned char	*get_null_str(void)
{
	unsigned char	*res;

	res = (unsigned char *)malloc(7);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = '\0';
	return (res);
}

unsigned char	*get_str(const unsigned char *s1)
{
	unsigned char	*res;
	size_t			s1_len;
	size_t			iter;

	if (!s1)
		return (get_null_str());
	s1_len = ft_strlen(s1);
	res = (unsigned char *)malloc(s1_len + 1);
	if (res)
	{
		iter = 0;
		while (iter < s1_len)
		{
			res[iter] = s1[iter];
			iter++;
		}
		res[iter] = '\0';
		return (res);
	}
	return (NULL);
}
