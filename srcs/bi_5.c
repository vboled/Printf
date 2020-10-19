/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:26:14 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:55:04 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bi_print_fraction_part(unsigned long *bi, int size)
{
	int		i;
	char	digit;

	i = 0;
	while (i < size)
	{
		digit = bi[i] + '0';
		write(1, &digit, 1);
		i++;
	}
}

void	bi_print_fraction_part_short(unsigned long *bi, int exp_order,
		unsigned int precision, int size)
{
	int				i;
	char			digit;
	unsigned int	unprinted_zeros;
	int				set_point;

	i = 0;
	set_point = 0;
	unprinted_zeros = 0;
	size = precision + exp_order + 2 < (unsigned int)size ?
		precision + exp_order + 2 : size;
	while (exp_order-- > -2)
		i++;
	while (i++ < size)
		if (!bi[i - 1])
			unprinted_zeros++;
		else
		{
			set_point = !set_point ? (int)write(1, ".", 1) : 1;
			while (unprinted_zeros--)
				write(1, "0", 1);
			unprinted_zeros = 0;
			digit = bi[i - 1] + '0';
			write(1, &digit, 1);
		}
}

int		bi_int_part_len(unsigned long *bi, int size)
{
	int i;

	i = 0;
	while (i < size && !bi[i])
		i++;
	return (size - i ? size - i : 1);
}

int		bi_fraction_part_short_exp_len(unsigned long *bi,
		unsigned int precision, int size)
{
	int				i;
	unsigned int	unprinted_zeros;
	int				set_point;
	int				len;

	i = 0;
	set_point = 0;
	unprinted_zeros = 0;
	len = 0;
	size = precision + 1 < (unsigned int)size ? precision + 1 : size;
	i = 2;
	while (i < size)
	{
		if (!bi[i])
			unprinted_zeros++;
		else
		{
			set_point = 1;
			len += unprinted_zeros;
			unprinted_zeros = 0;
			len++;
		}
		i++;
	}
	return (len + set_point);
}

int		bi_fraction_part_short_len(unsigned long *bi, int exp_order,
		unsigned int precision, int size)
{
	int				i;
	unsigned int	unprinted_zeros;
	int				set_point;
	int				len;

	i = 0;
	set_point = 0;
	unprinted_zeros = 0;
	len = 0;
	size = precision + exp_order + 2 < (unsigned int)size ?
		precision + exp_order + 2 : size;
	while (exp_order-- > -2)
		i++;
	while (i < size)
		if (!bi[i++])
			unprinted_zeros++;
		else
		{
			set_point = 1;
			len = len + unprinted_zeros + 1;
			unprinted_zeros = 0;
		}
	return (len + set_point);
}
