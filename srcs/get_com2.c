/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:59:47 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/05 08:59:50 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

void	get_prec(char *line, int *prec, int *j)
{
	int k;

	k = 0;
	*prec = ft_atoi(line);
	while (line[k] >= '0' && line[k] <= '9')
		k++;
	k--;
	*j += k;
}

void	get_str(char *line, int *j, t_com *com)
{
	*j = 0;
	com->is_com = 0;
	if (!(com->str = ft_strdup(line)))
		com->is_com = -1;
	while (line[*j])
		(*j)++;
}

int		get_flag(char *line, t_com *com)
{
	if (*line == '-')
		com->min = 1;
	else if (*line == '+')
		com->plus = 1;
	else if (*line == '#')
		com->sharp = 1;
	else if (*line == '0')
		com->zero = 1;
	else if (*line == ' ')
		com->space = 1;
	else
		return (0);
	return (1);
}

void	get_com(char *line, t_com *com, va_list list)
{
	int j;

	if (only_proc(line, com))
		return ;
	j = 0;
	while (line[j++])
	{
		if (line[0] != '%' || (line[0] == '%' && !line[1]))
			get_str(line, &j, com);
		change_com(list, line, com, &j);
		if (!get_flag(&(line[j]), com))
		{
			if (line[j] == '.')
				get_prec(&line[++j], &(com->prec), &j);
			else if (line[j] >= '0' && line[j] <= '9')
				get_prec(&line[j], &(com->width), &j);
			else if (line[j] >= 'A' && line[j] <= 'z')
			{
				get_spec(&(line[j]), com);
				return ;
			}
		}
	}
}

void	get_spec(char *line, t_com *com)
{
	int		len;

	if (inter_spec1(line, com) || inter_spec1_2(line, com))
		com->str = ft_strdup(line + 1);
	else if (inter_spec2(line, com) || inter_spec2_2(line, com) ||
	inter_spec1u(line, com))
		com->str = ft_strdup(line + 2);
	else if (inter_spec3(line, com) || inter_spec3u(line, com))
		com->str = ft_strdup(line + 3);
	else if (inter_spec4u(line, com))
		com->str = ft_strdup(line + 4);
	else
	{
		len = 0;
		get_ustr(line, com);
		com->spec = -1;
	}
}
