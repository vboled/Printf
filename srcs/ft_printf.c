/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:46:17 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/03 17:46:19 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		list;
	t_com		*com;
	int			res;

	com = 0;
	va_start(list, format);
	com = ready_command(format, list);
	res = call_func(list, com);
	free_com(com);
	va_end(list);
	return (res);
}
