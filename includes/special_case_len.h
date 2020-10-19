/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_len.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:30:45 by bdong             #+#    #+#             */
/*   Updated: 2019/11/17 20:31:32 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIAL_CASE_LEN_H
# define SPECIAL_CASE_LEN_H

int special_case_float_len(float flt, char *option, int width);
int special_case_double_len(double dbl, char *option, int width);
int special_case_long_double_len(long double ldbl, char *option, int width);
#endif
