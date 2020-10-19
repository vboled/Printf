/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:28:02 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 17:17:15 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bi.h"
#include "print.h"
#include "ft_printf.h"

int		bi_is_0_5(unsigned long *bi, unsigned int size, unsigned int precision)
{
	unsigned int	i;

	if (!size || precision > size)
		return (0);
	if (bi[precision] != 5)
		return (0);
	i = precision;
	while (++i < size)
		if (bi[i] != 0)
			return (0);
	return (1);
}

void	bi_print_int_part(unsigned long *bi, int size)
{
	int		i;
	char	digit;

	i = 0;
	while (i < size && !bi[i])
		i++;
	if (i == size)
		write(1, "0", 1);
	while (i < size)
	{
		digit = bi[i] + '0';
		write(1, &digit, 1);
		i++;
	}
}

int		bi_greather_5(unsigned long *bi, int precision, int size)
{
	while (precision < size)
	{
		if (bi[precision] != 0)
			return (1);
		precision++;
	}
	return (0);
}

int		bi_round(unsigned long *int_part, unsigned long *fraction_part,
		t_size size, unsigned int precision)
{
	unsigned int	i;
	int				shift;

	shift = 1;
	if (precision < size.fraction_size)
	{
		if (fraction_part[precision] > 5 ||
		(fraction_part[precision] == 5 && (bi_greather_5(fraction_part,
		precision + 1, size.fraction_size) ||
		(precision ? (fraction_part[precision - 1] % 2) :
		(int_part[size.int_size - 1] % 2)))))
		{
			i = precision - 1;
			while (precision)
			{
				fraction_part[i] = fraction_part[i] + shift;
				shift = fraction_part[i] / 10;
				fraction_part[i] %= 10;
				if (!i--)
					break ;
			}
			return (shift);
		}
	}
	return (0);
}
