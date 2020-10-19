/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_func.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:19:50 by gweasley          #+#    #+#             */
/*   Updated: 2019/11/11 16:19:52 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_FUNC_H
# define INT_FUNC_H
# include "ft_printf.h"

int		num_len(unsigned long long num, unsigned base);
void	put_str(char *str);
char	*ft_itoa(unsigned long long num, t_com com, unsigned base, char sign);
void	reverse(char **str, int size);
char	*get_pre_str(t_com com, int len, char sign, unsigned long long int num);
char	*putin_pre_str(t_com com, int size, char sign, int len);
char	*put_sign(t_com com, char sign);
char	*get_post_str(t_com com, int len, char sign,
		unsigned long long int num);
int		str_length(char *str);
int		print_and_free_str(char *str);
char	*empty_str();
void	ignore_dflag(t_com *com);
char	get_num(unsigned long long int num,
		unsigned base, char symb);
int		full_print_str(char *str);
int		*read_color(const char *restrict str);
int		print_bint(unsigned long long int num, t_com *com);
void	prepare_ocom(unsigned long long int num,
		t_com *com, int *len);
int		is_com(const char *restrict str);
int		fill_symbol(int start, int end, char c);
int		only_proc(char *line, t_com *com);
int		print_proc(t_com com);
int		get_flag(char *line, t_com *com);
void	get_prec(char *line, int *prec, int *j);
void	sharp_work(t_com com, int len, int *size);
int		inter_spec1u(char *line, t_com *com);
int		inter_spec3u(char *line, t_com *com);
int		inter_spec4u(char *line, t_com *com);
void	len_work(const char *restrict s, int *len);
int		is_flag(char c);
void	get_ustr(char *line, t_com *com);
void	take_len_flag(char *line, int *len, int *flag);
#endif
