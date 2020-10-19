/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:39:41 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:59:20 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"
#include "exp_order.h"
#include "bi.h"

int		calc_len(unsigned long *int_part, int exp_order, unsigned int precision,
		t_size size)
{
	if ((int)precision > exp_order && exp_order >= -4)
		return ((exp_order > -1 ? exp_order + 1 : 1) +
				bi_fraction_part_short_len(int_part, exp_order,
					precision - (exp_order + 1), size.int_size));
	else
		return (3 + bi_fraction_part_short_exp_len(int_part,
					precision, size.int_size) + exp_order_len(exp_order));
}

void	print_last_part_short(char *option, int width, unsigned int len,
		int exp_order)
{
	if (option[3] != 'X')
	{
		write(1, &option[3], 1);
		exp_order < 0 ? write(1, "-", 1) : write(1, "+", 1);
		exp_order / 10 ? 0 : write(1, "0", 1);
		print_exp_order(exp_order, exp_order_len(exp_order));
	}
	option[2] == '0' ? fill_symbol(len, ft_int_abs(width), option[2]) : 0;
	option[2] == ' ' ? fill_symbol(len, -width, option[2]) : 0;
}

char	print_short_not_exp(unsigned long *int_part, int exp_order,
		unsigned int precision, t_size size)
{
	bi_print_int_part(int_part, exp_order + 2);
	bi_print_fraction_part_short(int_part, exp_order,
			precision - (exp_order + 1), size.int_size);
	return ('X');
}

void	fill_zeros_and_spaces_short(int len, int width, char *option)
{
	option[2] == ' ' ? fill_symbol(len, width, option[2]) : 0;
	option[0] == 'X' ? 0 : write(1, option, 1);
	option[2] == '0' ? fill_symbol(len, width, option[2]) : 0;
}
