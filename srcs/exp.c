/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:54:05 by bdong             #+#    #+#             */
/*   Updated: 2019/11/20 13:16:40 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "print.h"
#include "exp_order.h"
#include "double_functions.h"
#include "long_double_functions.h"
#include "bi.h"
#include "len.h"
#include "special_case_len.h"

void	print_last_part_exp(char *option, int width, unsigned int len,
		int exp_order)
{
	write(1, &option[3], 1);
	exp_order < 0 ? write(1, "-", 1) : write(1, "+", 1);
	exp_order / 10 ? 0 : write(1, "0", 1);
	print_exp_order(exp_order, exp_order_len(exp_order));
	option[2] == '0' ? fill_symbol(len, ft_int_abs(width), option[2]) : 0;
	option[2] == ' ' ? fill_symbol(len, -width, option[2]) : 0;
}

int		print_double_exp(double dbl, char *option, int width,
		unsigned int precision)
{
	t_size			size;
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				exp_order;
	int				len;

	option[2] = width < 0 ? ' ' : option[2];
	determine_sign_double(&dbl, option);
	if (special_case_double(dbl, option, width))
		return (special_case_double_len(dbl, option, width));
	size.int_size = float_types_len(double_order(dbl));
	int_part = get_double_int_part(dbl, double_order(dbl), size.int_size);
	size.fraction_size = get_double_fraction_part(dbl, &fraction_part);
	exp_order = bi_exp_interpr(&int_part, &fraction_part, &size, precision + 1);
	len = 3 + (precision || option[1] == '#') + precision +
		(option[0] != 'X') + exp_order_len(exp_order);
	option[2] == ' ' ? fill_symbol(len, width, option[2]) : 0;
	option[0] == 'X' ? 0 : write(1, option, 1);
	bi_print_exp(int_part, size.fraction_size, option, precision);
	print_last_part_exp(option, width, len, exp_order);
	width = width < 0 ? -width : width;
	free(int_part);
	return (len > width ? len : width);
}

int		print_long_double_exp(long double ldbl, char *option, int width,
		unsigned int precision)
{
	t_size			size;
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				exp_order;
	int				len;

	option[2] = width < 0 ? ' ' : option[2];
	determine_sign_long_double(&ldbl, option);
	if (special_case_long_double(ldbl, option, width))
		return (special_case_long_double_len(ldbl, option, width));
	size.int_size = float_types_len(long_double_order(ldbl));
	int_part = get_long_double_int_part(ldbl, long_double_order(ldbl),
	size.int_size);
	size.fraction_size = get_long_double_fraction_part(ldbl, &fraction_part);
	exp_order = bi_exp_interpr(&int_part, &fraction_part, &size, precision + 1);
	len = 3 + (precision || option[1] == '#') + precision +
		(option[0] != 'X') + exp_order_len(exp_order);
	option[2] == ' ' ? fill_symbol(len, width, option[2]) : 0;
	option[0] == 'X' ? 0 : write(1, option, 1);
	bi_print_exp(int_part, size.fraction_size, option, precision);
	print_last_part_exp(option, width, len, exp_order);
	width = width < 0 ? -width : width;
	free(int_part);
	return (len > width ? len : width);
}
