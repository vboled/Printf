/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_func4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:22:20 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 12:06:31 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_func.h"

void				prepare_ocom(unsigned long long int num,
					t_com *com, int *len)
{
	if (com->sharp && !num)
	{
		com->sharp = 0;
		if (!com->prec)
		{
			com->prec--;
			com->width--;
			(*len)--;
		}
	}
	if (com->sharp && com->width > *len)
	{
		com->width--;
		com->prec--;
	}
}

int					print_oint(unsigned long long int num, t_com *com)
{
	int						len;
	int						res;

	res = 0;
	len = num_len(num, 8);
	ignore_uoflag(com);
	prepare_ocom(num, com, &len);
	res += print_and_free_str(get_pre_str(*com, len, '+', num));
	res += print_and_free_str(ft_itoa(num, *com, 8, ' '));
	if (com->min)
		res += print_and_free_str(get_post_str(*com, len, '+', num));
	if (com->str)
		res += paint_string(com->str);
	return (res);
}

char				get_num(unsigned long long int num,
					unsigned base, char symb)
{
	char					c;
	unsigned long long int	n;

	if (base == 10 || base == 8)
		return (num % base + '0');
	n = num % base;
	if (n < 10)
		return (n + '0');
	if (symb == 'x')
		c = 'a';
	else
		c = 'A';
	if (n == 11)
		c += 1;
	else if (n == 12)
		c += 2;
	else if (n == 13)
		c += 3;
	else if (n == 14)
		c += 4;
	else if (n == 15)
		c += 5;
	return (c);
}

void				prepare_xcom(unsigned long long int num,
					t_com *com, int *len)
{
	if (com->sharp && com->prec > *len)
		com->prec += 2;
	if (!num && com->prec && com->sharp)
	{
		com->sharp = 0;
		com->prec -= 2;
	}
	if (!num && !com->prec && com->sharp)
		com->sharp = 0;
	if (com->sharp && com->width > *len && num)
	{
		com->prec -= 2;
		com->width -= 2;
	}
}

int					print_xint(unsigned long long int num,
					t_com *com, char symb)
{
	int						len;
	int						res;

	res = 0;
	len = num_len(num, 16);
	ignore_uoflag(com);
	prepare_xcom(num, com, &len);
	res += print_and_free_str(get_pre_str(*com, len, symb, num));
	res += print_and_free_str(ft_itoa(num, *com, 16, symb));
	if (com->min)
		res += print_and_free_str(get_post_str(*com, len, 'x', num));
	if (com->str)
		res += paint_string(com->str);
	return (res);
}
