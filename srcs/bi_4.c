/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:40:13 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:54:07 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bi.h"

void	bi_inc(unsigned long **bi, unsigned int *size)
{
	unsigned long	shift;
	unsigned int	i;

	shift = 1;
	i = *size;
	while (1)
	{
		i--;
		(*bi)[i] += shift;
		shift = (*bi)[i] / 10;
		(*bi)[i] %= 10;
		if (!i)
			break ;
	}
	i = *size;
	while (1)
	{
		if ((*bi)[--i] != 0)
			return ;
		if (!i)
			break ;
	}
}

int		bi_exp_order(unsigned long *int_part, unsigned long *fraction_part,
		t_size size)
{
	int				order;
	unsigned int	i;

	i = 0;
	order = size.int_size - 1;
	while (order - i + 1)
	{
		if (int_part[i])
			return (size.int_size - i - 1);
		i++;
	}
	i = 0;
	order = -1;
	while (i < size.fraction_size)
	{
		if (fraction_part[i])
			return (order);
		order--;
		i++;
	}
	return (0);
}

void	bi_round_exp(unsigned long **bi, unsigned int *size,
		unsigned int precision, int *exp_order)
{
	unsigned int	i;
	unsigned long	shift;

	shift = 1;
	precision++;
	if (precision < *size)
	{
		if ((*bi)[precision + 1] > 5 ||
			((*bi)[precision + 1] == 5 &&
			(bi_greather_5(*bi, precision + 2, *size) ||
			(*bi)[precision] % 2)))
		{
			i = precision + 1;
			while (i--)
			{
				(*bi)[i] += shift;
				shift = (*bi)[i] / 10;
				(*bi)[i] %= 10;
			}
			if (*(bi)[0])
				*exp_order = *exp_order + 1;
		}
	}
}

void	bi_print_digit(unsigned long digit)
{
	char c;

	c = digit + '0';
	write(1, &c, 1);
}
