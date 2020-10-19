/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_u2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:26:22 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/23 14:26:23 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

void	take_len_flag(char *line, int *len, int *flag)
{
	*flag = 0;
	*len = 0;
	while (*line && (*line == ' ' || *line == 'h'))
		line++;
	while (*line && *line != '%')
	{
		(*len)++;
		if (!is_flag(*line) && (*line == 'l' || *line == 'h'))
			*flag = 1;
		line++;
	}
	line -= *len;
	if (*len == 2 && !is_flag(*line) && !is_flag(*(line + 1)) && *line != ' ' &&
	*(line + 1) != ' ' && !(*line == 'l' || *line == 'h'))
		*flag = 1;
}

void	get_ustr(char *line, t_com *com)
{
	int len;
	int	flag;

	take_len_flag(line, &len, &flag);
	if (len != 0 && !flag)
	{
		com->is_com = 0;
		if (!(com->str = (char *)malloc(len + 1)))
			return ;
		(com->str)[len] = '\0';
		len = 0;
		com->spec = -1;
		while (*line && *line != '%')
		{
			if (*line != 'h')
				(com->str)[len++] = *line;
			line++;
		}
		(com->str)[len++] = '\0';
	}
	else
		com->str = 0;
}
