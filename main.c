/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:16:45 by gweasley          #+#    #+#             */
/*   Updated: 2019/10/27 16:59:19 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int		count_of_proc(const char *str)
{
	int num;

	num = 0;
	while (*str)
	{
		if (*str == '%')
			num++;
		str++;
	}
	return (num);
}

void	print_int(long int num)
{
	char	c;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num > 10)
		print_int(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	iinb(int num)
{
	int i = 31;

	while (i >= 0)
	{
		if ((num & (1 << (i))) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i--;
	}
	write(1, "\n", 1);
}

void	siinb(short int num)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if ((num & (1 << (i))) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i--;
	}
	write(1, "\n", 1);
}

void	liinb(long int num)
{
	int			i;
	long int	unit;

	unit = 1;
	i = 63;
	while (i >= 0)
	{
		if ((num & (unit << (i))) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		i--;
	}
	write(1, "\n", 1);
}

void	dinb(float num)
{
	int i = 31;
	int *b;

	b = (int *)&num;
	printf("num = %f\n", num);
	while (i >= 0)
	{
		if ((*b & (1 << (i))) == 0)
			write(1, "0", 1);
		else
			write(1, "1", 1);
		if (i == 31)
			write(1, "|", 1);
		if (i == 23)
			write(1, "|", 1);
		i--;
	}
	write(1, "\n", 1);
}

long int		order_float(float num)
{
	int i;
	int *b;
	long int res;

	b = (int*)&num;
	res = 0;
	i = 30;
	while (i >= 23)
	{
		res = res | (*b & (1 << i)) >> 23;
		i--;
	}
	return (labs(res - 127));	
}

long int whole_part(float num, long int order)
{
	long int res;
	int *b;
	int por = 9;
	b = (int *)&num;
//	dinb(num);
	*b = *b >> (23 - order);
//	dinb(num);
	res = 0;
	res = res | ((long int)1 << order);
	while (order >= 0)
	{
		res = res | (*b & (1 << (order - 1)));
		order--;
	}
//	liinb(res);
	return (res);
}

long int frac_part(float num, long int whole, long int order)
{
	int *b;
	int i;

	i = 31;
	b = (int *)&num;
	printf("num = %f\n", num);
	iinb(*b);
	dinb(num);
	return (0);
}

void	print_float(float num)
{
	int i = 31;
	int *b;
	int	j;
	long int res;

	b = (int*)&num;
	if (*b & (1 << i))
	{
		write(1, "-", 1);
		num *= -1;
	}
	j = order_float(num);
	res = whole_part(num, j);
	printf("%ld.\n", res);
	frac_part(num, res, j);
	write(1, "\n", 1);
}

void	ft_printf(const char *restrict format, ...)
{
	va_list list;
	int		i;
	char	c;

	i = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%' && format[i] != 'd' && format[i] != 'c' && format[i] != 'f')
			write(1, &(format[i]), 1);
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(list, int);
			write(1, &(c), 1);
		}
		if (format[i] == '%' && format[i + 1] == 'd')
			print_int(va_arg(list, int));
		if (format[i] == '%' && format[i + 1] == 'f')
			printf("%f ", va_arg(list, double));
		i += 2;	
	}
	printf("\n");
	va_end(list);
}

int		main(void)
{
	print_float(2.125);
	return (0);
}
