/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_short.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:46:42 by bdong             #+#    #+#             */
/*   Updated: 2019/11/17 20:59:23 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIAL_CASE_SHORT_H
# define SPECIAL_CASE_SHORT_H

int	special_case_float_short(float flt, char *option, int width,
	unsigned int precision);
int	special_case_double_short(double dbl, char *option, int width,
	unsigned int precision);
int	special_case_long_double_short(long double ldbl, char *option, int width,
	unsigned int precision);
#endif
