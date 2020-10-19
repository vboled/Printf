/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:06:17 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 17:16:20 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

char	bi_malloc(unsigned long **bi1, unsigned long **bi2, unsigned int size)
{
	unsigned int	i;

	*bi1 = 0;
	*bi1 = (unsigned long*)malloc(sizeof(unsigned long) * size);
	if (!*bi1)
		return (0);
	*bi2 = (unsigned long*)malloc(sizeof(unsigned long) * size);
	if (!*bi2)
	{
		free(*bi1);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		(*bi1)[i] = 0;
		(*bi2)[i] = 0;
		i++;
	}
	return (1);
}

void	bi_free(unsigned long **bi1, unsigned long **bi2)
{
	if (*bi1)
		free(*bi1);
	if (*bi2)
		free(*bi2);
}

void	bi_sum(unsigned long *bi1, unsigned long *bi2, int size)
{
	int	i;
	int	shift;

	i = size;
	shift = 0;
	while (--i > -1)
	{
		bi1[i] += bi2[i] + shift;
		shift = bi1[i] / 10;
		bi1[i] %= 10;
	}
}
