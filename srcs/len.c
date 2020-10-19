/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:31:51 by bdong             #+#    #+#             */
/*   Updated: 2019/11/16 16:16:51 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	str_len(char *s)
{
	int	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

unsigned int	hex_len_addr(intptr_t var)
{
	if (var < 16)
		return (1);
	return (1 + (hex_len_addr(var / 16)));
}

unsigned int	float_types_len(int order)
{
	if (order < 0)
		return (1);
	return ((unsigned int)(1 + (order + 1) * 0.301029996));
}
