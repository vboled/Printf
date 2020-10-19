/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:11:51 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/11 16:11:56 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_func.h"

int		num_len(unsigned long long num, unsigned base)
{
	int i;

	i = 1;
	while (num >= base)
	{
		i++;
		num /= base;
	}
	return (i);
}

void	put_str(char *str)
{
	if (!str)
	{
		write(1, "ERROR", 5);
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	reverse(char **str, int size)
{
	int		i;
	char	tmp;
	int		s;

	i = 0;
	s = size / 2;
	while (size > s)
	{
		tmp = str[0][i];
		str[0][i] = str[0][size - 1];
		str[0][size - 1] = tmp;
		size--;
		i++;
	}
}

char	*ft_itoa(unsigned long long num, t_com com, unsigned base, char symb)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = num_len(num, base);
	if (num == 0 && (((!com.width && !(com.prec == -1)) ||
	(!com.prec && com.width))) && com.prec < size && !com.sharp
	&& !(base == 16 && !com.width && com.prec == -3))
		return (empty_str());
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	while (num >= base)
	{
		str[i++] = get_num(num, base, symb);
		num /= base;
	}
	str[i] = get_num(num, base, symb);
	if (num == 0 && size == 1 && !com.space && !com.plus &&
	com.width && !com.prec && !(com.prec == -1))
		str[0] = ' ';
	str[i + 1] = '\0';
	reverse(&str, size);
	return (str);
}

char	*get_pre_str(t_com com, int len, char sign, unsigned long long int num)
{
	int		size;

	size = 0;
	if (com.width == 33 && com.prec == 0 && com.zero)
		com.zero = 0;
	if ((sign == '-' || com.plus || com.space) && com.width < len)
		size++;
	if ((sign == '-' || com.plus || com.space) && com.width < com.prec
	&& com.width > len)
		com.prec++;
	if (com.sharp && com.width > len)
		size++;
	if (com.sharp && com.width > len && (sign == 'x' || sign == 'X'))
		size++;
	if (num == 0 && !com.prec && com.width && !com.min)
		com.width++;
	if (com.width > len && com.width > com.prec)
		size += com.width - len;
	else if (com.prec > len && com.width <= com.prec)
		size += com.prec - len;
	if ((sign == '-' || com.plus || com.space) && com.width
	<= com.prec && com.width && (com.prec - com.width) < len && !com.zero)
		size++;
	return (putin_pre_str(com, size, sign, len));
}
