//
// Created by Thao Nessround on 6/8/21.
//

#ifndef FTOUTPUT_TYPE_H
# define FTOUTPUT_TYPE_H

# include "../libftprintf.h"

void			output_d(unsigned char *str, t_settings *setup);
void			output_c(unsigned char c, t_settings *setup);
void			output_s(unsigned char *str, t_settings *setup);
void			output_p(unsigned char *str, t_settings *setup);
void			out(unsigned char *help, unsigned char *input, int query);
unsigned char	*create_space(size_t size, char space);

#endif //FT_PRINTF_OUPUT_TYPE_H
