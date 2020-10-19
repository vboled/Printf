/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:47:02 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 17:01:47 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "print.h"
#include "ft_printf.h"
#include "bi.h"
#include "long_double_functions.h"
#include "len.h"

int			long_double_order(long double ldbl)
{
	__int128	*ptr;

	ptr = (__int128*)&ldbl;
	return (((*ptr >> 64) & 0b0111111111111111) - 16383);
}

long double	get_fractional_part_long_double(long double ldbl)
{
	__int128	*ptr;
	__int128	order;
	__int128	mask;
	__int128	mask2;

	order = long_double_order(ldbl);
	if (order >= 63)
		return (0);
	else if (order < 0)
		return (ldbl < 0 ? -ldbl : ldbl);
	ptr = (__int128*)&ldbl;
	mask = 9223372036854775807;
	*ptr = ((*ptr & mask) << order & mask);
	order = 0;
	mask2 = (__int128)1 << 62;
	while ((--order > -63) && !(mask2 & *ptr))
		mask2 >>= 1;
	*ptr = ((*ptr & mask) << -order) & mask;
	if (order != -63)
		*ptr = ((16383 + order) << 64) | *ptr | (__int128)1 << 63;
	else
		*ptr = (__int128)1 << 63;
	return (ldbl);
}

int			special_case_long_double(long double ldbl, char *option, int width)
{
	__int128	*ptr;

	ptr = (__int128*)&ldbl;
	if ((*ptr & ((__int128)32767 << 64)) >> 64 == 32767)
	{
		if (*ptr & 9223372036854775807)
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

void		determine_sign_long_double(long double *ldbl, char *option)
{
	__int128	**ptr;

	ptr = (__int128**)&ldbl;
	if (**ptr & ((__int128)1 << 79))
	{
		**ptr &= ~((__int128)1 << 79);
		option[0] = '-';
	}
}

int			get_long_double_fraction_part(long double ldbl, unsigned long **res)
{
	unsigned long	*step;
	unsigned int	size;
	int				order;
	long double		fraction;

	fraction = get_fractional_part_long_double(ldbl);
	order = long_double_order(fraction);
	size = -order + 63;
	bi_malloc(res, &step, size);
	if (order != -16383)
	{
		bi_pow_0_5(step, size, long_double_order(fraction) - 1);
		bi_pow_0_5(*res, size, long_double_order(fraction));
	}
	collect_long_double(*res, step, fraction, size);
	free(step);
	return (size);
}
