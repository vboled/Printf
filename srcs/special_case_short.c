/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:45:30 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 17:03:18 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "bi.h"
#include "special_case_len.h"
#include "double_functions.h"
#include "long_double_functions.h"
#include "len.h"

int	special_case_double_short(double dbl, char *option, int width,
		unsigned int precision)
{
	t_size			size;
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				exp_order;

	if (special_case_double(dbl, option, width))
		return (special_case_double_len(dbl, option, width));
	size.int_size = float_types_len(double_order(dbl));
	int_part = get_double_int_part(dbl, double_order(dbl), size.int_size);
	size.fraction_size = get_double_fraction_part(dbl, &fraction_part);
	precision = !precision ? 1 : precision;
	exp_order = bi_exp_interpr(&int_part, &fraction_part, &size, precision - 1);
	free(int_part);
	if ((int)precision > exp_order && exp_order >= -4)
		return (print_double(dbl, option, width, precision - (exp_order + 1)));
	else
		return (print_double_exp(dbl, option, width, precision - 1));
}

int	special_case_long_double_short(long double ldbl, char *option, int width,
		unsigned int precision)
{
	t_size			size;
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				exp_order;

	if (special_case_long_double(ldbl, option, width))
		return (special_case_long_double_len(ldbl, option, width));
	size.int_size = float_types_len(long_double_order(ldbl));
	int_part = get_long_double_int_part(ldbl,
		long_double_order(ldbl), size.int_size);
	size.fraction_size = get_long_double_fraction_part(ldbl, &fraction_part);
	precision = !precision ? 1 : precision;
	exp_order = bi_exp_interpr(&int_part, &fraction_part, &size, precision - 1);
	free(int_part);
	if ((int)precision > exp_order && exp_order >= -4)
		return (print_long_double(ldbl, option, width,
				precision - (exp_order + 1)));
	else
		return (print_long_double_exp(ldbl, option, width, precision - 1));
}
