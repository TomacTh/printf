/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:43:58 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 21:48:45 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_content
{
	int				*stars;
	int				zero;
	int				spaceright;
	int				width;
	int				precision;
	int				presence;
	int				longg;
	int				shortt;
	int				space;
	int				plus;
	int				sharp;
	char			conv;
	char			*end;
	char			*result;
}				t_content;

typedef unsigned long long	t_ull;
typedef long long			t_ll;
/*
** This globale variable is create to count all characters printing
*/
extern int		g_count;

void			parse_zero(char **str, t_content *argu);
void			parse_spaceright(char **str, t_content *argu);
void			parse_stars(char **str, t_content *argu, int *count);
void			parse_precision(char **str, t_content *argu, int *count);
void			parse_width(char **str, t_content *argu);
void			parse_short(char **str, t_content *argu);
void			parse_long(char **str, t_content *argu);
void			parse_space(char **str, t_content *argu);
void			parse_plus(char **str, t_content *argu);
void			parse_sharp(char **str, t_content *argu);

t_content		initialise_struct(void);
int				init_stars(t_content *argu, int count, va_list ap);
int				first_parse(char *str, t_content *argu, va_list ap);
int				small_atoi(char **str);
void			parse_values(char **str, char *end, t_content *argu);

int				allocate_spaceright(int len, t_content *argu);
int				allocate_flags(int len, int data, t_content *argu, char c);
int				allocate_zerosint(int len, t_content *argu, t_ll n);
int				negative_precision(int len, t_content *argu);
int				allocate_zero_pointer(int len, int data, t_content *argu);
int				allocate_precision_pointer(int len, int data, t_content *argu);
int				apply_pointerflags(t_content *argu);
int				apply_flags(t_content *argu);
int				apply_numflags(t_content *argu);
int				apply_intflags(t_content *argu, t_ll n);
int				space_or_plus(t_content *argu, t_ll n);
int				space_plus(t_content *argu, int len, char c);
int				sharp_hexa(t_content *argu, t_ull u);

int				string_value(t_content *argu, char *str);
int				string_zeroprecision(t_content *argu);
int				string(va_list ap, t_content *argu);
int				integer(va_list ap, t_content *argu);
int				hexa(va_list ap, t_content *argu);
int				u_num(va_list ap, t_content *argu);
int				pointer(va_list ap, t_content *argu);
int				charr(va_list ap, t_content *argu);
int				invalidconv(t_content *argu);
int				n_flag(va_list ap, t_content *argu);
t_ull			long_or_short_unsigned(va_list ap, t_content *argu);
t_ll			long_or_short_int(va_list ap, t_content *argu);
void			long_or_short_n(va_list ap, t_content *argu);

int				size(t_ll n);
int				unsigned_size(t_ull n, int basemax);
void			fil_str(char *str, t_ull num, char *base, int max);
char			*ft_itoa(t_ll n);
char			*ft_hex_utoa(t_ull n, char c);
char			*ft_hex_utoa_adress(t_ull n);
char			*ft_utoa(t_ull n);

int				is_inset(char c, char *set);
int				ft_isdigit(int c);
int				find_good_index(char c);
void			copy(char *s1, char *s2);

void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *str);

int				consume_conv(va_list ap, t_content *argu);
int				parser(va_list	ap, char *str);
void			clean_struct(t_content *argu);
int				ft_printf(const char *str, ...);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);

#endif
