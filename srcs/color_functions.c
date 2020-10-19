/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:21:07 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 20:27:45 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	paint1(char *str, int size)
{
	if (size == 3)
	{
		if (str[0] == 'r' && str[1] == 'e' && str[2] == 'd')
			return (write(1, "\x1b[31m", 5));
		else if (str[0] == 'e' && str[1] == 'o' && str[2] == 'c')
			return (write(1, "\x1b[0m", 5));
	}
	else if (size == 4)
	{
		if (str[0] == 'b' && str[1] == 'l' && str[2] == 'u' && str[3] == 'e')
			return (write(1, "\x1b[34m", 5));
		else if (str[0] == 'c' && str[1] == 'y' && str[2] == 'a' &&
				str[3] == 'n')
			return (write(1, "\x1b[36m", 5));
	}
	else if (size == 5)
	{
		if (str[0] == 'g' && str[1] == 'r' && str[2] == 'e' && str[3] == 'e' &&
				str[4] == 'n')
			return (write(1, "\x1b[32m", 5));
		else if (str[0] == 'b' && str[1] == 'l' && str[2] == 'a' &&
				str[3] == 'c' && str[4] == 'k')
			return (write(1, "\x1b[30m", 5));
	}
	return (0);
}

int	paint2(char *str, int size)
{
	if (size == 6)
	{
		if (str[0] == 'y' && str[1] == 'e' && str[2] == 'l' && str[3] == 'l' &&
				str[4] == 'o' && str[5] == 'w')
			return (write(1, "\x1b[33m", 5));
	}
	else if (size == 7)
	{
		if (str[0] == 'm' && str[1] == 'a' && str[2] == 'g' && str[3] == 'e' &&
				str[4] == 'n' && str[5] == 't' && str[6] == 'a')
			return (write(1, "\x1b[35m", 5));
	}
	return (0);
}

int	paint(char *str, int size)
{
	if (paint1(str, size))
		return (1);
	if (paint2(str, size))
		return (1);
	return (0);
}

int	print_color_string(char **str, int size)
{
	write(1, *str, size);
	*str = *str + size;
	return (size);
}

int	color(char **str)
{
	int		size;
	char	*end;

	end = *str;
	size = 0;
	while (*end && *end != '}')
	{
		end++;
		size++;
	}
	if (!*end)
		return (print_color_string(str, size));
	else
	{
		if (paint(*str + 1, size - 1))
		{
			*str = end + 1;
			return (0);
		}
		else
			return (write(1, (*str)++, 1));
	}
	return (0);
}
