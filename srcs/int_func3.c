/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:36:52 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/20 12:05:39 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_func.h"

int					print_and_free_str(char *str)
{
	int		res;

	if (!str)
		return (0);
	res = write(1, str, str_length(str));
	free(str);
	return (res);
}

char				*put_sign(t_com com, char sign)
{
	char	*str;
	int		size;

	size = 0;
	if (sign == '-')
		size++;
	else if (com.plus)
		size++;
	else if (com.space)
		size++;
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	str[size] = '\0';
	if (sign == '-')
		str[0] = '-';
	else if (com.plus)
		str[0] = '+';
	else if (com.space)
		str[0] = '+';
	return (str);
}

char				*empty_str(void)
{
	char *str;

	if (!(str = (char *)malloc(1)))
		return (0);
	str[0] = '\0';
	return (str);
}

int					print_uint(unsigned long long int num,
					t_com *com, short int is_d)
{
	int						len;
	char					sign;
	int						res;

	sign = '+';
	res = 0;
	len = num_len(num, 10);
	if (is_d)
		ignore_dflag(com);
	else
		ignore_uoflag(com);
	res += print_and_free_str(get_pre_str(*com, len, sign, num));
	res += print_and_free_str(ft_itoa(num, *com, 10, ' '));
	if (com->min)
		res += print_and_free_str(get_post_str(*com, len, sign, num));
	if (com->str)
		res += paint_string(com->str);
	return (res);
}

int					str_length(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
