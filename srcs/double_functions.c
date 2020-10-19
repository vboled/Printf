/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:30:51 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 17:02:18 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "print.h"
#include "bi.h"
#include "double_functions.h"
#include "len.h"

int		double_order(double dbl)
{
	long	*ptr;

	ptr = (long*)&dbl;
	return (((*ptr >> 52) & 0b011111111111) - 1023);
}

double	get_fractional_part_double(double dbl)
{
	long	*ptr;
	long	order;
	long	mask;
	long	mask2;

	order = double_order(dbl);
	if (order >= 52)
		return (0);
	else if (order < 0)
		return (dbl < 0 ? -dbl : dbl);
	ptr = (long*)&dbl;
	mask = 4503599627370495;
	*ptr &= mask;
	*ptr = ((*ptr & mask) << order) & mask;
	order = 0;
	mask2 = (long)1 << 51;
	while ((--order > -52) && !(mask2 & *ptr))
		mask2 >>= 1;
	*ptr = ((*ptr & mask) << -order) & mask;
	if (order != -52)
		*ptr |= ((1023 + order) << 52);
	else
		*ptr &= 0;
	return (dbl);
}

int		special_case_double(double dbl, char *option, int width)
{
	long *ptr;

	ptr = (long*)&dbl;
	if (((*ptr & 9218868437227405312) >> 52) == 2047)
	{
		if (*ptr & 4503599627370495)
		{
			fill_symbol(3, width, ' ');
			write(1, "nan", 3);
			fill_symbol(3, -width, ' ');
		}
		else
		{
			fill_symbol(3 + (option[0] != 'X'), width, ' ');
			option[0] != 'X' ? write(1, &option[0], 1) : 0;
			write(1, "inf", 3);
			fill_symbol(3 + (option[0] != 'X'), -width, ' ');
		}
		return (1);
	}
	return (0);
}

void	determine_sign_double(double *dbl, char *option)
{
	long	**ptr;

	ptr = (long**)&dbl;
	if (**ptr & ((long)1 << 63))
	{
		**ptr &= ~((long)1 << 63);
		option[0] = '-';
	}
}

int		get_double_fraction_part(double dbl, unsigned long **res)
{
	unsigned long	*step;
	unsigned int	size;
	int				order;
	double			fraction;

	fraction = get_fractional_part_double(dbl);
	order = double_order(fraction);
	size = -order + 52;
	bi_malloc(res, &step, size);
	if (order != -1023)
	{
		bi_pow_0_5(step, size, double_order(fraction) - 1);
		bi_pow_0_5(*res, size, double_order(fraction));
	}
	collect_double(*res, step, fraction, size);
	free(step);
	return (size);
}
