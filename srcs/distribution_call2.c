/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution_call2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:48:29 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 13:43:42 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

void	clean_fcom(t_com *com, char *str)
{
	if (com->plus)
		str[0] = '+';
	else if (com->space)
		str[0] = ' ';
	else
		str[0] = 'X';
	if (com->sharp)
		str[1] = '#';
	else
		str[1] = 'j';
	if (com->zero)
		str[2] = '0';
	else
		str[2] = ' ';
	if (com->min)
		com->width *= -1;
	if (com->prec == -1)
		com->prec = 6;
}

int		call_f(va_list list, t_com c)
{
	char	str[3];
	int		r;

	r = 0;
	clean_fcom(&c, str);
	if (c.spec == 50)
		r = print_double(va_arg(list, double), str, c.width, c.prec);
	else if (c.spec == 51)
		r = print_long_double(va_arg(list, long double), str, c.width, c.prec);
	else if (c.spec == 52)
		r = print_double(va_arg(list, double), str, c.width, c.prec);
	r += paint_string(c.str);
	return (r);
}

int		call_e(va_list list, t_com c)
{
	char	str[4];
	int		r;

	r = 0;
	clean_fcom(&c, str);
	if (c.spec < 63)
		str[3] = 'e';
	else
		str[3] = 'E';
	if (c.spec == 60 || c.spec == 63)
		r = print_double_exp(va_arg(list, double), str, c.width, c.prec);
	else if (c.spec == 61 || c.spec == 64)
		r = print_long_double_exp(va_arg(list, long double),
		str, c.width, c.prec);
	else if (c.spec == 62 || c.spec == 65)
		r = print_double_exp(va_arg(list, double), str, c.width, c.prec);
	r += paint_string(c.str);
	return (r);
}

int		call_g(va_list list, t_com c)
{
	char	str[4];
	int		r;

	r = 0;
	clean_fcom(&c, str);
	if (c.spec < 73)
		str[3] = 'e';
	else
		str[3] = 'E';
	if (c.spec == 70 || c.spec == 73)
		r = print_double_short(va_arg(list, double),
		str, c.width, c.prec);
	else if (c.spec == 71 || c.spec == 74)
		r = print_double_short(va_arg(list, double),
		str, c.width, c.prec);
	else if (c.spec == 72 || c.spec == 75)
		r = print_long_double_short(va_arg(list, long double), str, c.width,
		c.prec);
	r += paint_string(c.str);
	return (r);
}

int		alt_call(va_list list, t_com com)
{
	int		res;
	char	*str;

	res = 0;
	if (com.spec < 60)
		res = call_f(list, com);
	else if (com.spec < 70)
		res = call_e(list, com);
	else if (com.spec < 80)
		res = call_g(list, com);
	else if (com.spec == 81)
		res = print_bint(va_arg(list, unsigned long long int), &com);
	else if (com.spec == 80)
		res = print_addr(va_arg(list, void *), com);
	if (com.spec == 82)
	{
		str = va_arg(list, char *);
		res = print_string(str, com);
	}
	if (com.spec == 83)
		res = print_char((char)va_arg(list, int), com);
	if (com.spec == 90)
		res = print_proc(com);
	return (res);
}
