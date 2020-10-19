/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:34:16 by bdong             #+#    #+#             */
/*   Updated: 2019/11/19 20:30:03 by bdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_com
{
	short int			is_com;
	short int			spec;
	short int			sharp;
	short int			zero;
	short int			min;
	short int			plus;
	short int			space;
	int					prec;
	int					width;
	char				*str;
}						t_com;

int						call_bx(va_list list, t_com com);
int						call_f(va_list list, t_com com);
int						ft_printf(const char *restrict format, ...);
int						inter_spec2_2(char *line, t_com *com);
void					ignore_uoflag(t_com *com);
long long				intft_abs(long long int num);
int						print_uint(unsigned long long int num, t_com *com,
						short int is_d);
int						print_oint(unsigned long long int num, t_com *com);
int						print_xint(unsigned long long int num, t_com *com,
						char symb);
int						call_func(va_list list, t_com *com);
int						print_int(long long int num, t_com *com,
						short int is_d);
int						print_str(char *str);
int						interp_spec1(char *line, t_com *com);
int						interp_spec2(char *line, t_com *com);
int						interp_spec3(char *line, t_com *com);
void					get_spec(char *line, t_com *com);
void					get_com(char *line, t_com *com, va_list list);
void					change_com(va_list list, char *line,
						t_com *com, int *j);
int						word_len(const char *restrict str);
int						word_count(const char *restrict str);
int						ft_atoi(const char *str);
char					*ft_strdup(const char *s1);
int						inter_spec1(char *line, t_com *com);
int						inter_spec2(char *line, t_com *com);
int						inter_spec3(char *line, t_com *com);
t_com					*ready_command(const char *restrict str, va_list list);
void					free_com(t_com *com);
int						print_float(float flt, char *option, int width,
						unsigned int precision);
int						print_double(double dbl, char *option, int width,
						unsigned int precision);
int						print_long_double(long double ldbl, char *option,
						int width, unsigned int precision);
int						print_float_exp(float flt, char *option, int width,
						unsigned int precision);
int						print_double_exp(double dbl, char *option, int width,
						unsigned int precision);
int						print_long_double_exp(long double ldbl, char *option,
						int width, unsigned int precision);
int						print_char(char c, t_com com);
int						print_string(char *s, t_com com);
int						print_addr(void *var, t_com com);
int						print_float_short(float flt, char *option,
						int width, unsigned int precision);
int						print_double_short(double dbl, char *option, int width,
						unsigned int precision);
int						print_long_double_short(long double ldbl, char *option,
						int width, unsigned int precision);
long long int			ft_abs(long long int num);
int						inter_spec2_2(char *line, t_com *com);
int						inter_spec1_2(char *line, t_com *com);
int						alt_call(va_list list, t_com com);
int						paint_string(char *str);
#endif
