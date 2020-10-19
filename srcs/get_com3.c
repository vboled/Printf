/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_com3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:03:35 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/05 09:03:38 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_com(t_com *com)
{
	int		i;

	i = 0;
	if (!com)
		return ;
	while (com[i].spec != -2)
	{
		free(com[i].str);
		i++;
	}
	free(com);
}

char	*ft_strdup(const char *s1)
{
	size_t		counter;
	char		*res;
	size_t		i;

	i = 0;
	counter = 0;
	while (s1[counter] != '\0')
		counter++;
	if (!(res = (char *)malloc(counter + 1)))
		return (0);
	while (i < counter)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		inter_spec1(char *line, t_com *com)
{
	if (line[0] == 'd' || line[0] == 'i')
		com->spec = 0;
	else if (line[0] == 'o')
		com->spec = 10;
	else if (line[0] == 'u')
		com->spec = 20;
	else if (line[0] == 'x')
		com->spec = 30;
	else if (line[0] == 'X')
		com->spec = 40;
	else if (line[0] == 'f')
		com->spec = 50;
	else if (line[0] == 'p')
		com->spec = 80;
	else
		return (0);
	return (1);
}

int		inter_spec2(char *line, t_com *com)
{
	if (line[0] == 'h' && (line[1] == 'd' || line[1] == 'i'))
		com->spec = 2;
	else if (line[0] == 'l' && (line[1] == 'd' || line[1] == 'i'))
		com->spec = 3;
	else if (line[0] == 'h' && line[1] == 'u')
		com->spec = 22;
	else if (line[0] == 'l' && line[1] == 'u')
		com->spec = 23;
	else if (line[0] == 'h' && line[1] == 'o')
		com->spec = 12;
	else if (line[0] == 'l' && line[1] == 'o')
		com->spec = 13;
	else if (line[0] == 'h' && line[1] == 'x')
		com->spec = 32;
	else if (line[0] == 'l' && line[1] == 'x')
		com->spec = 33;
	else if (line[0] == 'h' && line[1] == 'X')
		com->spec = 42;
	else if (line[0] == 'l' && line[1] == 'X')
		com->spec = 43;
	else if (line[0] == 'L' && line[1] == 'f')
		com->spec = 51;
	else
		return (0);
	return (1);
}

int		inter_spec3(char *line, t_com *com)
{
	if (line[0] == 'h' && line[1] == 'h' && (line[2] == 'd' || line[2] == 'i'))
		com->spec = 1;
	else if (line[0] == 'l' && line[1] == 'l' && (line[2] == 'd' ||
	line[2] == 'i'))
		com->spec = 4;
	else if (line[0] == 'h' && line[1] == 'h' && line[2] == 'o')
		com->spec = 11;
	else if (line[0] == 'l' && line[1] == 'l' && line[2] == 'o')
		com->spec = 14;
	else if (line[0] == 'h' && line[1] == 'h' && line[2] == 'u')
		com->spec = 21;
	else if (line[0] == 'l' && line[1] == 'l' && line[2] == 'u')
		com->spec = 24;
	else if (line[0] == 'h' && line[1] == 'h' && line[2] == 'x')
		com->spec = 31;
	else if (line[0] == 'l' && line[1] == 'l' && line[2] == 'x')
		com->spec = 34;
	else if (line[0] == 'h' && line[1] == 'h' && line[2] == 'X')
		com->spec = 41;
	else if (line[0] == 'l' && line[1] == 'l' && line[2] == 'X')
		com->spec = 44;
	else
		return (0);
	return (1);
}
