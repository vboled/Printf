/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:11:51 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/23 13:11:52 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

int		inter_spec1u(char *line, t_com *com)
{
	if ((line[0] != 'l' && line[0] != 'h' && line[0] >= 'A' &&
	line[0] <= 'z' && (line[1] == 'd' || line[1] == 'i')))
		com->spec = 4;
	else if ((line[0] != 'l' && line[0] != 'h' && line[0] >= 'A'
	&& line[0] <= 'z' && line[1] == 'x'))
		com->spec = 34;
	else if ((line[0] != 'l' && line[0] >= 'A' && line[0] <= 'z'
	&& (line[1] == 'u' || line[1] == 'U')))
		com->spec = 23;
	else
		return (0);
	return (1);
}

int		inter_spec3u(char *line, t_com *com)
{
	if ((line[1] >= 'A' && line[1] <= 'z'
	&& line[0] >= 'A' && line[0] <= 'z' &&
	(line[2] == 'd' || line[2] == 'i')))
		com->spec = 4;
	else
		return (0);
	return (1);
}

int		inter_spec4u(char *line, t_com *com)
{
	if ((line[2] >= 'A' && line[2] <= 'z' && line[1] >= 'A' &&
	line[1] <= 'z' && line[0] >= 'A' && line[0] <= 'z' &&
	(line[3] == 'd' || line[3] == 'i')))
		com->spec = 4;
	else if ((line[2] == '#' && line[1] >= 'A' &&
	line[1] <= 'z' && line[0] >= 'A' && line[0] <= 'z' &&
	line[3] == 'x'))
	{
		com->sharp = 1;
		com->spec = 33;
	}
	else
		return (0);
	return (1);
}

int		is_flag(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'o' || c == 'X'
	|| c == 'x' || c == 'G' || c == 'g' || c == 'E' || c == 'e' ||
	c == 'f' || c == 's' || c == 'p' || c == 'c')
		return (1);
	else
		return (0);
}

void	len_work(const char *restrict s, int *len)
{
	int		k;

	k = 0;
	if ((*len > 1 && *s == '%') || (*len == 1 &&
		*(s + 1) != '%' && *(s + 1)))
	{
		(*len)++;
		k = 1;
	}
	*len += is_com(s);
	s++;
	while (*s && *s != '%')
	{
		if (is_flag(*s))
			return ;
		s++;
	}
	if (*s && is_flag(*(s + 1)) && k)
		(*len)--;
}
