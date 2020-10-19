/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:43:56 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:59:32 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		fill_symbol(int start, int end, char c)
{
	int res;

	res = 0;
	while (start++ < end)
	{
		write(1, &c, 1);
		res++;
	}
	return (res);
}