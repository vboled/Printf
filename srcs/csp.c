/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:36:09 by bdong             #+#    #+#             */
/*   Updated: 2019/11/20 12:01:02 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print.h"
#include "len.h"
#include "ft_printf.h"
#include "int_func.h"

char	*get_null(void)
{
	char *s;

	if (!(s = (char *)malloc(7)))
		return (0);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = '\0';
	return (s);
}

int		print_string(char *s, t_com com)
{
	int print_size;
	int res;
	int flag;

	flag = 0;
	res = 0;
	if (!s && (flag = 1) &&
	!(s = get_null()))
		return (-1);
	print_size = str_len(s);
	if (com.prec < print_size && com.prec != -1)
		print_size = com.prec;
	if (!com.min && !com.zero)
		res += fill_symbol(print_size, com.width, ' ');
	else if (!com.min)
		res += fill_symbol(print_size, com.width, '0');
	res += write(1, s, print_size);
	if (com.min)
		res += fill_symbol(print_size, com.width, ' ');
	res += paint_string(com.str);
	if (flag)
		free(s);
	return (res);
}

int		print_char(char c, t_com com)
{
	int		res;

	res = 1;
	if (!com.min && !com.zero)
		res += fill_symbol(res, com.width, ' ');
	else if (!com.min)
		res += fill_symbol(res, com.width, '0');
	write(1, &c, 1);
	if (com.min)
		res += fill_symbol(1, com.width, ' ');
	res += paint_string(com.str);
	return (res);
}

void	print_hex_addr(intptr_t var)
{
	char c;

	if (var > 15)
		print_hex_addr(var / 16);
	c = var % 16 < 10 ? '0' + var % 16 : 'a' - 10 + var % 16;
	write(1, &c, 1);
}

int		print_addr(void *var, t_com com)
{
	intptr_t	p;
	int			res;

	p = (intptr_t)var;
	res = hex_len_addr(p) + 2;
	if (!p && !com.prec)
		res = 2;
	if (!com.min)
		res += fill_symbol(res, com.width, ' ');
	write(1, "0x", 2);
	if (com.prec > 0)
		res += fill_symbol(hex_len_addr(p), com.prec, '0');
	if (p || com.prec)
		print_hex_addr(p);
	if (com.min)
		res += fill_symbol(res, com.width, ' ');
	res += print_str(com.str);
	return (res);
}
