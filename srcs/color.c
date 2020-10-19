/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:16:23 by bdong             #+#    #+#             */
/*   Updated: 2019/11/20 13:53:27 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "color_functions.h"

int	paint_string(char *str)
{
	int size;

	if (!str)
		return (0);
	size = 0;
	while (*str)
	{
		if (*str == '{')
			size += color(&str);
		else
		{
			write(1, str, 1);
			size++;
			str++;
		}
	}
	return (size);
}
