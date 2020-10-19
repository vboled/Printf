/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double_functions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:29:13 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 17:04:56 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_DOUBLE_FUNCTIONS_H
# define LONG_DOUBLE_FUNCTIONS_H

unsigned long	*get_long_double_int_part(long double ldbl, int order,
				int size);
int				long_double_order(long double ldbl);
unsigned int	long_double_len(long double ldbl);
long double		get_fractional_part_long_double(long double ldbl);
int				special_case_long_double(long double ldbl, char *option,
				int width);
void			determine_sign_long_double(long double *ldbl,
				char *option);
void			collect_long_double(unsigned long *res,
				unsigned long *step, long double fraction, int len);
int				get_long_double_fraction_part(long double ldbl,
				unsigned long **res);
#endif
