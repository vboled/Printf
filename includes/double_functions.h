/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:17:40 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:46:48 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_FUNCTIONS_H
# define DOUBLE_FUNCTIONS_H

unsigned long		*get_double_int_part(double dbl, int order, int size);
int					double_order(double dbl);
unsigned int		double_len(double flt);
double				get_fractional_part_double(double dbl);
int					special_case_double(double dbl, char *option, int width);
void				determine_sign_double(double *dbl, char *option);
void				collect_double(unsigned long *res, unsigned long *step,
					double fraction, int len);
int					get_double_fraction_part(double dbl, unsigned long **res);
#endif
