/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:28:00 by bdong             #+#    #+#             */
/*   Updated: 2019/11/17 21:25:16 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEN_H
# define LEN_H

# include <unistd.h>

unsigned int	str_len(char *s);
unsigned int	hex_len_addr(intptr_t var);
unsigned int	float_types_len(int order);
int				ft_int_abs(int nbr);
#endif
