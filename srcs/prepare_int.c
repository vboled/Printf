/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:14:56 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 12:13:54 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

long long int		ft_abs(long long int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void				ignore_dflag(t_com *com)
{
	com->sharp = 0;
	if (com->plus)
		com->space = 0;
	if (com->min || (com->prec != -1 && com->prec != 0))
		com->zero = 0;
}

int					print_int(long long int num, t_com *com, short int is_d)
{
	unsigned long long		x;
	int						len;
	char					sign;
	int						res;

	sign = '+';
	if (num < 0)
	{
		num *= -1;
		sign = '-';
	}
	x = num;
	res = 0;
	len = num_len(num, 10);
	if (is_d)
		ignore_dflag(com);
	else
		ignore_uoflag(com);
	res += print_and_free_str(get_pre_str(*com, len, sign, num));
	res += print_and_free_str(ft_itoa(num, *com, 10, ' '));
	if (com->min)
		res += print_and_free_str(get_post_str(*com, len, sign, num));
	if (com->str)
		res += paint_string(com->str);
	return (res);
}

void				ignore_uoflag(t_com *com)
{
	com->plus = 0;
	com->space = 0;
	if (com->min || !com->prec || !(com->prec == -1))
		com->zero = 0;
}

int					is_com(const char *restrict str)
{
	int		num;

	num = 0;
	if (*str == '%')
	{
		num++;
		str++;
	}
	while (*str && *str != '%')
	{
		if (*str == 'i' || *str == 'd' || *str == 'f' || *str == 'u'
		|| *str == 'o' || *str == 'x' || *str == 'X' ||
		*str == 'e' || *str == 'E' || *str == 'c'
		|| *str == 's' || *str == 'g' || *str == 'G' || *str == 'p')
			return (0);
		str++;
		if (*str == '%')
			num++;
	}
	if (*str == '\0' || num != 2)
		return (0);
	return (1);
}
