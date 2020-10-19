/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:09:52 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 11:59:56 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

int		ft_atoi(const char *str)
{
	long	number;
	int		sign;

	sign = 1;
	number = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number < 0 && number < number * 10)
			return (0);
		if (number > 0 && number > number * 10)
			return (-1);
		number = number * 10 + sign * (*str - '0');
		str++;
	}
	return (number);
}

void	shift(t_com *com, int *len)
{
	(*len)++;
	if (com->prec <= *len)
	{
		if (com->prec == *len)
			com->prec--;
		(*len)--;
		if (com->prec > com->width && com->sharp)
			com->prec--;
		else if (com->prec < com->width && com->sharp)
			com->width--;
		else if (com->sharp)
			(*len)++;
	}
}

void	shift_x(t_com *com, int *len)
{
	if (com->width || com->prec)
	{
		com->width--;
		com->prec--;
	}
	if (com->prec > com->width && com->sharp)
	{
		(*len)--;
		com->prec--;
	}
	else if (com->prec < com->width && com->sharp)
		com->width -= 2;
	else if (com->sharp)
		(*len) += 1;
}

int		print_str(char *str)
{
	int		res;

	res = 0;
	while (str && *str)
	{
		write(1, str, 1);
		str++;
		res++;
	}
	return (res);
}

void	sharp_work(t_com com, int len, int *size)
{
	if (com.spec > 9 && com.spec < 15 && com.sharp &&
	com.width < len && com.prec < len)
		(*size)++;
	if (com.spec > 25 && com.spec < 45 && com.sharp
	&& com.width < len && com.prec < len)
		*size += 2;
	if (com.spec == 81 && com.sharp)
		*size += 2;
}
