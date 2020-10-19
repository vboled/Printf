/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:29:59 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:58:58 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "print.h"
#include "ft_printf.h"
#include "exp_order.h"
#include "double_functions.h"
#include "long_double_functions.h"
#include "bi.h"
#include "len.h"
#include "special_case_len.h"
#include "short_functions.h"
#include "special_case_short.h"

int	print_double_short(double dbl, char *option, int width,
		unsigned int precision)
{
	t_size			size;
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				exp_order;
	int				len;

	if (option[1] == '#')
		return (special_case_double_short(dbl, option, width, precision));
	option[2] = width < 0 ? ' ' : option[2];
	determine_sign_double(&dbl, option);
	size.int_size = float_types_len(double_order(dbl));
	int_part = get_double_int_part(dbl, double_order(dbl), size.int_size);
	size.fraction_size = get_double_fraction_part(dbl, &fraction_part);
	precision = !precision ? 1 : precision;
	exp_order = bi_exp_interpr(&int_part, &fraction_part, &size, precision - 1);
	len = calc_len(int_part, exp_order, precision, size) + (option[0] != 'X');
	fill_zeros_and_spaces_short(len, width, option);
	if ((int)precision > exp_order && exp_order >= -4)
		option[3] = print_short_not_exp(int_part, exp_order, precision, size);
	else
		bi_print_exp_short(int_part, size.int_size, option, precision);
	print_last_part_short(option, width, len, exp_order);
	free(int_part);
	return (len > ft_abs(width) ? len : ft_abs(width));
}

int	print_long_double_short(long double ldbl, char *option, int width,
		unsigned int precision)
{
	t_size			size;
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				exp_order;
	int				len;

	if (option[1] == '#')
		return (special_case_long_double_short(ldbl, option, width, precision));
	option[2] = width < 0 ? ' ' : option[2];
	determine_sign_long_double(&ldbl, option);
	size.int_size = float_types_len(long_double_order(ldbl));
	int_part = get_long_double_int_part(ldbl,
		long_double_order(ldbl), size.int_size);
	size.fraction_size = get_long_double_fraction_part(ldbl, &fraction_part);
	precision = !precision ? 1 : precision;
	exp_order = bi_exp_interpr(&int_part, &fraction_part, &size, precision - 1);
	len = calc_len(int_part, exp_order, precision, size) + (option[0] != 'X');
	fill_zeros_and_spaces_short(len, width, option);
	if ((int)precision > exp_order && exp_order >= -4)
		option[3] = print_short_not_exp(int_part, exp_order, precision, size);
	else
		bi_print_exp_short(int_part, size.int_size, option, precision);
	print_last_part_short(option, width, len, exp_order);
	free(int_part);
	return (len > ft_abs(width) ? len : ft_abs(width));
}
