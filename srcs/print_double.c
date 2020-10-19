/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:19:32 by bdong             #+#    #+#             */
/*   Updated: 2019/11/23 15:02:31 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "len.h"
#include "ft_printf.h"
#include "print.h"
#include "bi.h"
#include "double_functions.h"
#include "special_case_len.h"

unsigned long	*get_double_int_part(double dbl, int order, int size)
{
	unsigned long	*res;
	unsigned long	*step;
	int				i;
	long			*ptr;
	int				start;

	if (!bi_malloc(&res, &step, size))
		return (NULL);
	ptr = (long*)&dbl;
	*ptr &= 4503599627370495;
	*ptr = order < 52 ? *ptr >> (52 - order) : *ptr;
	start = order > 52 ? order - 52 : 0;
	if (order >= 0)
		bi_pow_2(step, start, size);
	i = 0;
	while (start++ < order)
	{
		*ptr & ((long)1 << i++) ? bi_sum(res, step, size) : 0;
		bi_sum(step, step, size);
	}
	bi_sum(res, step, size);
	free(step);
	return (res);
}

void			collect_double(unsigned long *res, unsigned long *step,
				double fraction, int len)
{
	long	*ptr;
	int		i;

	i = -1;
	ptr = (long*)&fraction;
	while (++i < 52)
	{
		(*ptr & ((long)1 << (51 - i))) ? bi_sum(res, step, len) : 0;
		bi_divide_2(step, len);
	}
}

t_size			prepare_number_double(double dbl, unsigned long **int_part,
				unsigned long **fraction_part, unsigned int precision)
{
	int		order;
	t_size	size;

	*int_part = 0;
	*fraction_part = 0;
	order = double_order(dbl);
	size.int_size = float_types_len(order);
	*int_part = get_double_int_part(dbl, order, size.int_size);
	size.fraction_size = get_double_fraction_part(dbl, fraction_part);
	if (bi_round(*int_part, *fraction_part, size, precision))
		bi_inc(int_part, &size.int_size);
	return (size);
}

void			print_double_parts(unsigned long **int_part,
				unsigned long **fraction_part, t_size size,
				unsigned int precision)
{
	unsigned int	len;

	bi_print_int_part(*int_part, size.int_size);
	precision ? write(1, ".", 1) : 0;
	len = precision > size.fraction_size ? size.fraction_size : precision;
	bi_print_fraction_part(*fraction_part, len);
	while (len++ < precision)
		write(1, "0", 1);
	bi_free(int_part, fraction_part);
}

int				print_double(double dbl, char *option, int width,
				unsigned int precision)
{
	unsigned long	*int_part;
	unsigned long	*fraction_part;
	int				len;
	t_size			size;

	option[2] = width < 0 ? ' ' : option[2];
	determine_sign_double(&dbl, option);
	if (special_case_double(dbl, option, width))
		return (special_case_double_len(dbl, option, width));
	size = prepare_number_double(dbl, &int_part, &fraction_part, precision);
	len = bi_int_part_len(int_part, size.int_size) +
		(option[1] == '#' && !precision) + (option[0] != 'X') +
		(precision ? precision + 1 : 0);
	option[2] == ' ' ? fill_symbol(len, width, option[2]) : 0;
	option[0] == 'X' ? 0 : write(1, option, 1);
	option[2] == '0' ? fill_symbol(len, width, option[2]) : 0;
	print_double_parts(&int_part, &fraction_part, size, precision);
	!precision && option[1] == '#' ? write(1, ".", 1) : 0;
	option[2] == ' ' ? fill_symbol(len, -width, option[2]) : 0;
	width = width < 0 ? -width : width;
	return (len > width ? len : width);
}
