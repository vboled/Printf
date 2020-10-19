/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:10:18 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 12:11:04 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

void				change_com(va_list list, char *line, t_com *com, int *j)
{
	int		num;

	num = 0;
	if (line[*j] == '-')
		com->min = 1;
	if (line[*j] == '*')
	{
		num = va_arg(list, int);
		com->width = ft_abs(num);
		if (num < 0)
			com->min = 1;
	}
	if (line[*j] == '.' && line[*j + 1] == '*')
	{
		(*j)++;
		num = 0;
		num = va_arg(list, int);
		if (num >= 0)
			com->prec = num;
	}
}

int					print_bint(unsigned long long int num, t_com *com)
{
	int						len;
	int						res;

	res = 0;
	len = num_len(num, 2);
	ignore_uoflag(com);
	prepare_ocom(num, com, &len);
	res += print_and_free_str(get_pre_str(*com, len, '+', num));
	res += print_and_free_str(ft_itoa(num, *com, 2, ' '));
	if (com->min)
		res += print_and_free_str(get_post_str(*com, len, '+', num));
	if (com->str)
		res += paint_string(com->str);
	return (res);
}

int					inter_spec2_2(char *line, t_com *com)
{
	if (line[0] == 'l' && line[1] == 'f')
		com->spec = 52;
	else if (line[0] == 'l' && line[1] == 'e')
		com->spec = 61;
	else if (line[0] == 'L' && line[1] == 'e')
		com->spec = 62;
	else if (line[0] == 'l' && line[1] == 'E')
		com->spec = 64;
	else if (line[0] == 'L' && line[1] == 'E')
		com->spec = 65;
	else if (line[0] == 'l' && line[1] == 'g')
		com->spec = 71;
	else if (line[0] == 'L' && line[1] == 'g')
		com->spec = 72;
	else if (line[0] == 'l' && line[1] == 'G')
		com->spec = 74;
	else if (line[0] == 'L' && line[1] == 'G')
		com->spec = 75;
	else
		return (0);
	return (1);
}

int					inter_spec1_2(char *line, t_com *com)
{
	if (line[0] == 'E')
		com->spec = 63;
	else if (line[0] == 'e')
		com->spec = 60;
	else if (line[0] == 'U')
		com->spec = 23;
	else if (line[0] == 'G')
		com->spec = 73;
	else if (line[0] == 'g')
		com->spec = 70;
	else if (line[0] == 'b')
		com->spec = 81;
	else if (line[0] == 's')
		com->spec = 82;
	else if (line[0] == 'c')
		com->spec = 83;
	else
		return (0);
	return (1);
}

int					only_proc(char *line, t_com *com)
{
	int		j;

	j = 0;
	if (!is_com(line))
		return (0);
	while (line[j++])
	{
		if (!get_flag(&(line[j]), com))
		{
			if (line[j] == '.')
				get_prec(&line[++j], &(com->prec), &j);
			else if (line[j] >= '0' && line[j] <= '9')
				get_prec(&line[j], &(com->width), &j);
			else if (line[j] >= 'A' && line[j] <= 'z')
				return (0);
		}
	}
	com->spec = 90;
	return (1);
}
