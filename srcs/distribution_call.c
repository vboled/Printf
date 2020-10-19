/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution_call.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:14:16 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 12:05:58 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

int		call_d(va_list list, t_com com)
{
	int res;

	res = 0;
	if (com.spec == 0)
		res += print_int(va_arg(list, int), &(com), 1);
	else if (com.spec == 1)
		res += print_int((signed char)va_arg(list, int), &(com), 1);
	else if (com.spec == 2)
		res += print_int((short)va_arg(list, int), &(com), 1);
	else if (com.spec == 3)
		res += print_int(va_arg(list, long int), &(com), 1);
	else if (com.spec == 4)
		res += print_int(va_arg(list, long long int), &(com), 1);
	return (res);
}

int		call_u(va_list list, t_com com)
{
	int		res;

	res = 0;
	if (com.spec == 20)
		res += print_int(va_arg(list, unsigned int), &(com), 0);
	else if (com.spec == 21)
		res += print_int((unsigned char)va_arg(list, unsigned int), &(com), 0);
	else if (com.spec == 22)
		res += print_int((unsigned short)va_arg(list, unsigned int), &(com), 0);
	else if (com.spec == 23)
		res += print_uint(va_arg(list, unsigned long int), &(com), 0);
	else if (com.spec == 24)
		res += print_uint(va_arg(list, unsigned long long int), &(com), 0);
	return (res);
}

int		call_o(va_list list, t_com com)
{
	int res;

	res = 0;
	if (com.spec == 10)
		res += print_oint(va_arg(list, unsigned int), &(com));
	else if (com.spec == 11)
		res += print_oint((unsigned char)va_arg(list, unsigned int), &(com));
	else if (com.spec == 12)
		res += print_oint((unsigned short)va_arg(list, unsigned int), &(com));
	else if (com.spec == 13)
		res += print_oint(va_arg(list, unsigned long int), &(com));
	else if (com.spec == 14)
		res += print_oint(va_arg(list, unsigned long long int), &(com));
	return (res);
}

int		call_x(va_list list, t_com com, char symb)
{
	int		res;

	res = 0;
	if (com.spec == 30 || com.spec == 40)
		res += print_xint(va_arg(list, unsigned int), &(com), symb);
	if (com.spec == 31 || com.spec == 41)
		res += print_xint((unsigned char)va_arg(list, unsigned int),
		&(com), symb);
	if (com.spec == 32 || com.spec == 42)
		res += print_xint((unsigned short)va_arg(list, unsigned int),
		&(com), symb);
	else if (com.spec == 33 || com.spec == 43)
		res += print_xint(va_arg(list, unsigned long int), &(com), symb);
	else if (com.spec == 34 || com.spec == 44)
		res += print_xint(va_arg(list, unsigned long long int), &(com), symb);
	return (res);
}

int		call_func(va_list list, t_com *com)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (com[i].spec != -2)
	{
		if (!com[i].is_com)
			res += paint_string(com[i].str);
		if (com[i].spec < 10)
			res += call_d(list, com[i]);
		else if (com[i].spec < 20)
			res += call_o(list, com[i]);
		else if (com[i].spec < 30)
			res += call_u(list, com[i]);
		else if (com[i].spec < 40)
			res += call_x(list, com[i], 'x');
		else if (com[i].spec < 50)
			res += call_x(list, com[i], 'X');
		else
			res += alt_call(list, com[i]);
		i++;
	}
	return (res);
}
