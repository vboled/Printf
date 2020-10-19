/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:54:16 by bdong             #+#    #+#             */
/*   Updated: 2019/11/17 21:24:47 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_int_abs(int nbr)
{
	return (nbr > 0 ? nbr : -nbr);
}

int		exp_order_len(int order)
{
	if (order / 1000)
		return (4);
	else if (order / 100)
		return (3);
	else
		return (2);
}

void	print_exp_order(int len, int exp_order_len)
{
	char c;

	if (len < 0)
		len *= -1;
	if (len >= 10)
		print_exp_order(len / 10, exp_order_len);
	c = len % 10 + '0';
	write(1, &c, 1);
}
