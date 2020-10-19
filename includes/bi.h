/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:11:10 by bdong             #+#    #+#             */
/*   Updated: 2019/11/20 13:12:17 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BI_H
# define BI_H

typedef struct		s_size
{
	unsigned int	int_size;
	unsigned int	fraction_size;
}					t_size;

unsigned long		bi_malloc(unsigned long **bi1, unsigned long **bi2,
					unsigned int size);
void				bi_free(unsigned long **bi1, unsigned long **bi2);
void				bi_sum(unsigned long *v1, unsigned long *v2, int size);
void				bi_divide_2(unsigned long *bi, unsigned long size);
void				bi_pow_0_5(unsigned long *bi, int size, int pow);
int					bi_is_0_5(unsigned long	*bi, unsigned int size,
					unsigned int precision);
void				bi_pow_2(unsigned long *bi, int pow, int size);
void				bi_print_int_part(unsigned long *bi, int size);
int					bi_greather_5(unsigned long *bi, int precision, int size);
int					bi_round(unsigned long *int_part,
					unsigned long *fraction_part, t_size size,
					unsigned int precision);
void				bi_concat(unsigned long **int_part, int int_part_size,
					unsigned long **fractional_part, int fractional_part_size);
void				bi_fraction_forwarding(unsigned long **int_part,
					unsigned long **fraction_part,
					unsigned int *fraction_part_size);
void				bi_print_exp(unsigned long *bi, unsigned int size,
					char *option, unsigned char precision);
void				bi_print_exp_short(unsigned long *bi, unsigned int size,
					char *option, unsigned int precision);
int					bi_exp_interpr(unsigned long **int_part,
					unsigned long **fraction_part, t_size *size,
					unsigned int precision);
void				bi_inc(unsigned long **bi, unsigned int *size);
int					bi_exp_order(unsigned long *int_part,
					unsigned long *fraction_part, t_size size);
void				bi_round_exp(unsigned long **bi, unsigned int *size,
					unsigned int precision, int *exp_order);
void				bi_print_digit(unsigned long digit);
void				bi_print_fraction_part(unsigned long *bi, int size);
void				bi_print_fraction_part_short(unsigned long *bi,
					int exp_order, unsigned int precision, int size);
int					bi_int_part_len(unsigned long *bi, int size);
int					bi_fraction_part_short_exp_len(unsigned long *bi,
					unsigned int precision, int size);
int					bi_fraction_part_short_len(unsigned long *bi,
					int exp_order, unsigned int precision, int size);
#endif
