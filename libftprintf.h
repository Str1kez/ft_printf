//
// Created by Thao Nessround on 6/2/21.
//

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>

// precision = any
// dot = true or false
// asterisk = any
// minus = true or false
// zero = true or false
// size = any

typedef struct s_settings
{
	int	precision;
	int	dot;
	int	asterisk;
	int	minus;
	int	zero;
	int	size;
}				t_settings;

int				ft_printf(const char *args, ...);
void			ft_putchar(unsigned char c);
void			ft_putstr(char *s);
char			*get_ptr(long long num);
char			*get_uint_base(unsigned int num, char param, int base);
int				ft_atoi(const char *str);
int				is_conversion(const char chr);
int				is_flag(const char chr);
int				ft_isdigit(int c);
char			*conversion_handler(char param, va_list ap);
char			*char_to_str(unsigned char c);

#endif
