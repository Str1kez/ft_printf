SRCDIR 		= ./
LIST_FILES	= 	ft_atoi.c \
				ft_checkers.c \
				ft_get_len.c \
				ft_get_ptr.c \
				ft_get_uint_base.c \
				ft_handlers.c \
				ft_itoa.c \
				ft_printf.c \
				ft_putstr.c \
				./output_type/ft_create_space.c \
				./output_type/ft_go_out.c \
				./output_type/ft_output_c.c \
				./output_type/ft_output_p.c \
				./output_type/ft_output_s.c \
				./output_type/ft_output_d.c \


GCC 		=	gcc
OBJS		=	$(LIST_FILES:.c=.o)
FLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf

.c.o: 
	${GCC} ${FLAGS} -c $< -o $@

all: $(NAME).a

$(NAME) : all

$(NAME).a: $(OBJS)
	ar rc $(NAME).a $(OBJS)

clean:
	rm -rf $(NAME).a

fclean: clean
	rm -rf $(OBJS) $(BONUS_OBJS)

re: fclean all	

.PHONY: all, re, clean, $(NAME), fclean, bonus
