//
// Created by Thao Nessround on 6/2/21.
//

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

//# include <stdarg.h>

int		ft_printf(const char *args, ...);
void	ft_putchar(unsigned char c);
void	ft_putint(int n);
void	ft_putstr(char *s);
void	ft_putptr(long long num);
void	ft_putuint_base(unsigned int num, char param, int base);

#endif
