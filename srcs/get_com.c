/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:56:04 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/05 08:56:06 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

int		word_count(const char *restrict str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str != '%')
		{
			while (*str != '%' && *str != '\0')
				str++;
			count++;
			str--;
		}
		else
		{
			str++;
			if (*str != '%')
				str--;
			else
				count++;
		}
		str++;
	}
	return (count);
}

int		word_len(const char *restrict str)
{
	int len;

	len = 0;
	while (*str == '%' && *str)
	{
		len++;
		str++;
		if (len == 2)
			return (1);
	}
	len = 0;
	while (*str != '%' && *str)
	{
		str++;
		len++;
	}
	return (len);
}

void	clean_com(t_com *com)
{
	com->is_com = 1;
	com->min = 0;
	com->spec = -1;
	com->sharp = 0;
	com->zero = 0;
	com->plus = 0;
	com->prec = -1;
	com->space = 0;
	com->width = 0;
	com->str = 0;
}

char	*fill_str(const char *restrict *str, int len, int is_com)
{
	char *ptr;
	char *copy;

	if (!(ptr = (char *)malloc(len + 1)))
		return (0);
	copy = ptr;
	ptr[len] = '\0';
	ptr[len - 1] = '\0';
	while (--len >= 0 && **str != '\0')
		*(ptr++) = *((*str)++);
	if (*(ptr - 1) == '%' && **str != '\0' && !is_com)
		(*str)++;
	return (copy);
}

t_com	*ready_command(const char *restrict str, va_list list)
{
	int		len;
	t_com	*com;
	char	*copy;
	t_com	*c;

	if (!(com = (t_com *)malloc(sizeof(t_com) * (word_count(str) + 1))))
		return (0);
	c = com;
	while (*str != '\0')
	{
		if (!(len = word_len(str)))
			break ;
		len_work(str, &len);
		clean_com(com);
		if (!(copy = fill_str(&str, len, is_com(str))))
			return (0);
		get_com(copy, com, list);
		free(copy);
		com++;
	}
	com->spec = -2;
	return (c);
}
