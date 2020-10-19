/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:44:40 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/11 17:44:41 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "int_func.h"

char	*new_str(int size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	while (i < size)
	{
		str[i] = '!';
		i++;
	}
	str[size] = '\0';
	return (str);
}

void	get_sign(t_com com, char sign, char *str, int *i)
{
	if (sign == '-')
		str[(*i)++] = '-';
	else if (com.plus)
		str[(*i)++] = '+';
	else if (com.space)
		str[(*i)++] = ' ';
}

void	prepare_com(t_com *com, int len, char sign)
{
	if (com->zero)
		com->prec = com->width;
	com->width++;
	if (com->min)
		com->width = 0;
	if (sign == '-' || com->plus || com->space)
		com->width--;
	if ((sign == '-' || com->plus || com->space) && com->width <= com->prec
	&& com->width && (com->prec - com->width) <= len && !com->zero)
		com->prec++;
}

char	*putin_pre_str(t_com com, int size,
		char sign, int len)
{
	int		i;
	char	*str;

	sharp_work(com, len, &size);
	if (!(str = new_str(size)))
		return (0);
	i = 0;
	prepare_com(&com, len, sign);
	while (--com.width > len && com.width > com.prec)
		str[i++] = ' ';
	if (com.sharp)
		str[i++] = '0';
	if (com.sharp && sign == 'x')
		str[i++] = 'x';
	if (com.sharp && com.spec == 81)
		str[i++] = 'b';
	if (com.sharp && sign == 'X')
		str[i++] = 'X';
	get_sign(com, sign, str, &i);
	while (com.prec-- > len && str[i] != '\0')
		str[i++] = '0';
	if (com.min || str[i] != '\0')
		str[i] = '\0';
	return (str);
}

char	*get_post_str(t_com com, int len, char sign, unsigned long long int num)
{
	char	*str;

	if (num == 0 && !com.prec && com.width)
		com.width++;
	if (sign == '-' || com.plus || com.space)
		com.width--;
	if (com.prec > len)
		com.width = com.width - com.prec;
	else
		com.width -= len;
	if (com.width <= 0)
		com.width = 0;
	if (!(str = (char *)malloc(com.width + 1)))
		return (0);
	str[com.width] = '\0';
	while (com.width > 0)
		str[--com.width] = ' ';
	return (str);
}
