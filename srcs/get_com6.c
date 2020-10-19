/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:05:07 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 13:50:52 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

int		print_proc(t_com com)
{
	int		res;
	char	symb;

	symb = ' ';
	if (com.zero && !com.min)
		symb = '0';
	res = 1;
	if (!com.min)
		res += fill_symbol(1, com.width, symb);
	write(1, "%", 1);
	if (com.min)
		res += fill_symbol(1, com.width, symb);
	res += paint_string(com.str);
	return (res);
}
