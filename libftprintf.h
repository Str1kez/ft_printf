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
	unsigned int	precision;
	int				dot;
	int				minus;
	int				zero;
	size_t			size;
}				t_settings;

int				ft_printf(const char *args, ...);
void			ft_putstr(unsigned char *s);
void			ft_putchar(unsigned char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
size_t			ft_strlen(const unsigned char *str);
unsigned char	*ft_itoa(int n);
unsigned char	*get_ptr(long long num);
unsigned char	*get_uint_base(unsigned int num, char param, int base);
int				get_num_len(int num);
int				get_unum_len(unsigned int num, int base);
int				is_conversion(const char chr);
int				is_flag(const char chr);
void			conversion_handler(char param, va_list ap, t_settings *setup);

#endif
