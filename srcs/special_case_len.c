/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:18:07 by bdong             #+#    #+#             */
/*   Updated: 2019/11/17 21:16:13 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	special_case_float_len(float flt, char *option, int width)
{
	int	*ptr;

	ptr = (int*)&flt;
	if (((*ptr & 0b01111111100000000000000000000000) >> 23) == 255)
	{
		if (*ptr & 8388607)
			return (3 < width ? width : 3);
		else
			return (3 + (option[0] != 'X') < width ? width :
					3 + (option[0] != 'X'));
	}
	return (0);
}

int	special_case_double_len(double dbl, char *option, int width)
{
	long	*ptr;

	ptr = (long*)&dbl;
	if (((*ptr & 9218868437227405312) >> 52) == 2047)
	{
		if (*ptr & 9218868437227405312)
			return (3 < width ? width : 3);
		else
			return (3 + (option[0] != 'X') < width ? width :
					3 + (option[0] != 'X'));
	}
	return (0);
}

int	special_case_long_double_len(long double ldbl, char *option, int width)
{
	__int128	*ptr;

	ptr = (__int128*)&ldbl;
	if ((*ptr & ((__int128)32767 << 64)) >> 64 == 32767)
	{
		if (*ptr & 9223372036854775807)
			return (3 < width ? width : 3);
		else
			return (3 + (option[0] != 'X') < width ? width :
					3 + (option[0] != 'X'));
	}
	return (0);
}
