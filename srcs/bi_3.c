/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:12:09 by bdong             #+#    #+#             */
/*   Updated: 2019/11/20 13:26:25 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "len.h"
#include "bi.h"
#include "double_functions.h"
#include "long_double_functions.h"

void			bi_concat(unsigned long **int_part, int int_part_size,
				unsigned long **fractional_part, int fractional_part_size)
{
	unsigned long	*bi;
	int				i;
	int				zero_start;

	bi = 0;
	zero_start = (*int_part)[0] ? 1 : 0;
	if (!(bi = (unsigned long*)malloc(sizeof(unsigned long) *
					(int_part_size + fractional_part_size + zero_start))))
		return ;
	if (zero_start)
		bi[0] = 0;
	i = -1 + zero_start;
	while (++i < int_part_size + zero_start)
		bi[i] = (*int_part)[i - zero_start];
	i = -1;
	while (++i < fractional_part_size)
		bi[int_part_size + i + zero_start] = (*fractional_part)[i];
	bi_free(int_part, fractional_part);
	*int_part = bi;
}

void			bi_fraction_forwarding(unsigned long **int_part,
				unsigned long **fraction_part, unsigned int *fraction_part_size)
{
	unsigned long	*bi;
	unsigned int	i;
	int				shift;

	bi = 0;
	i = 0;
	while (!(*fraction_part)[i] && i < *fraction_part_size)
		i++;
	*fraction_part_size = (*fraction_part_size - i + 1) ?
		(*fraction_part_size - i + 1) : 1;
	if (!(bi = (unsigned long*)malloc(sizeof(unsigned long) *
					*fraction_part_size)))
		return ;
	bi[0] = 0;
	if (*fraction_part_size != 1)
	{
		shift = i;
		i = 1;
		while (++i < *fraction_part_size)
			bi[i - 1] = (*fraction_part)[shift + i - 2];
	}
	bi_free(int_part, fraction_part);
	*int_part = bi;
}

void			bi_print_exp(unsigned long *bi, unsigned int size, char *option,
				unsigned char precision)
{
	unsigned int	i;
	char			c;
	unsigned int	len;

	i = 0;
	while (!bi[i])
	{
		i++;
		precision++;
	}
	c = bi[i] + '0';
	write(1, &c, 1);
	i++;
	option[1] == '#' || precision - 1 ? write(1, ".", 1) : 0;
	len = precision + 1 < size ? precision + 1 : size;
	while (i < len)
	{
		c = bi[i++] + '0';
		write(1, &c, 1);
	}
	while (len++ < precision)
		write(1, "0", 1);
}

void			bi_print_exp_short(unsigned long *bi, unsigned int size,
				char *option, unsigned int precision)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	unprinted_zeros;
	int				set_point;

	i = 0;
	while (!bi[i] && i < size)
		i++;
	bi_print_digit(bi[i++]);
	option[1] == '#' ? write(1, ".", 1) : 0;
	set_point = option[1] == '#' ? 1 : 0;
	len = precision + 1 < size ? precision + 1 : size;
	unprinted_zeros = 0;
	while (i++ < len)
		if (!bi[i - 1])
			unprinted_zeros++;
		else
		{
			set_point = !set_point ? (int)write(1, ".", 1) : 1;
			while (unprinted_zeros--)
				write(1, "0", 1);
			unprinted_zeros = 0;
			bi_print_digit(bi[i - 1]);
		}
}

int				bi_exp_interpr(unsigned long **int_part,
				unsigned long **fraction_part, t_size *size,
				unsigned int precision)
{
	int				exp_order;

	exp_order = bi_exp_order(*int_part, *fraction_part, *size);
	if (exp_order > -1)
	{
		bi_concat(int_part, size->int_size, fraction_part,
				size->fraction_size);
		size->int_size = size->int_size + size->fraction_size;
	}
	else
	{
		bi_fraction_forwarding(int_part, fraction_part,
				&size->fraction_size);
		size->int_size = size->fraction_size;
	}
	bi_round_exp(int_part, &size->int_size, precision, &exp_order);
	return (exp_order);
}
