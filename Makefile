# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 16:11:47 by bdong             #+#    #+#              #
#    Updated: 2019/11/19 20:30:55 by bdong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = bi_1.c \
	  	bi_2.c \
	  	bi_3.c \
		bi_4.c \
		bi_5.c \
		bi_6.c \
		len.c \
	  	ft_printf.c \
		long_double_functions.c \
		get_com.c \
	   	prepare_int.c \
	   	print_long_double.c \
		csp.c \
	   	get_com2.c \
		distribution_call.c \
		get_com3.c \
	   	double_functions.c \
	   	get_com4.c \
	   	print.c \
		print_double.c \
		distribution_call2.c \
		exp.c \
		exp_order.c \
		short_functions.c \
		short.c \
		special_case_len.c \
		special_case_short.c \
		int_func.c \
		get_com4.c \
		int_func2.c \
		int_func3.c \
		int_func4.c \
		get_com5.c \
		get_com6.c \
		color.c \
		inter_u.c \
		inter_u2.c \
		color_functions.c

OBJ = bi_1.o \
	  	bi_2.o \
	  	bi_3.o \
		bi_4.o \
		bi_5.o \
		bi_6.o \
		len.o \
	  	ft_printf.o \
		long_double_functions.o \
		get_com.o \
	   	prepare_int.o \
	   	print_long_double.o \
		csp.o \
	   	get_com2.o \
		distribution_call.o \
		get_com3.o \
	   	double_functions.o \
	   	print.o \
	   	distribution_call2.o \
		exp.o \
		print_double.o \
		exp_order.o \
		short_functions.o \
		short.o \
		special_case_len.o \
		special_case_short.o \
		int_func.o \
		get_com4.o \
		int_func2.o \
		int_func3.o \
		int_func4.o \
		get_com5.o \
		get_com6.o \
		color.o \
		inter_u.o \
		inter_u2.o \
		color_functions.o

NAME = libftprintf.a
INC = includes
all: $(NAME)
$(NAME): $(OBJ) $(INC)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): %.o : srcs/%.c
	gcc -Wall -Werror -Wextra -I $(INC) -c $<

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
