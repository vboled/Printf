/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:41:17 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 16:47:31 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHORT_FUNCTIONS_H
# define SHORT_FUNCTIONS_H

int		calc_len(unsigned long *int_part, int exp_order, unsigned int precision,
		t_size size);
void	print_last_part_short(char *option, int width, unsigned int len,
		int exp_order);
char	print_short_not_exp(unsigned long *int_part, int exp_order,
		unsigned int precision, t_size size);
void	fill_zeros_and_spaces_short(int len, int width, char *option);
#endif
