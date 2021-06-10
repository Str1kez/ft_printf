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

#endif //FT_PRINTF_OUPUT_TYPE_H
