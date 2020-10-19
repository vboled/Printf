/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:12:05 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 18:15:20 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bi_divide_2(unsigned long *bi, int size)
{
	int				i;
	unsigned long	shift;

	i = 0;
	shift = bi[0] % 2 ? 10 : 0;
	bi[0] /= 2;
	while (++i < size)
	{
		bi[i] += shift;
		shift = bi[i] % 2 ? 10 : 0;
		bi[i] /= 2;
	}
}

void	bi_multiply(unsigned long *bi, int size, unsigned long num)
{
	int	i;

	i = size;
	while (--i > -1)
		bi[i] *= num;
	i = size;
	while (--i > 0)
	{
		bi[i - 1] += bi[i] / 10;
		bi[i] %= 10;
	}
}

void	bi_pow_2(unsigned long *bi, int pow, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
		bi[i++] = 0;
	bi[i] = 1;
	i = 0;
	while (i < pow)
	{
		if (i + 60 < pow)
		{
			bi_multiply(bi, size, 1152921504606846976);
			i += 59;
		}
		else
			bi_multiply(bi, size, 2);
		i++;
	}
}

void	bi_pow_0_5(unsigned long *bi, int size, int pow)
{
	int	i;

	i = 0;
	while (i < size - 1)
		bi[i++] = 0;
	pow *= -1;
	bi[pow - 1] = 1;
	i = 0;
	while (i < pow)
	{
		if (i + 26 < pow)
		{
			bi_multiply(bi, size, 1490116119384765625);
			i += 25;
		}
		else
			bi_multiply(bi, size, 5);
		i++;
	}
}
