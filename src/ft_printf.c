/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:03:01 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 22:29:06 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This globale variable is create to count all characters printing
*/
int				g_count;
/*
** This globale array is create for apply the good function on the right conv
*/
int		(*g_f[9])() = {charr, string, pointer,
	hexa, hexa, u_num, integer, integer, n_flag};

void	ft_putchar(char c)
{
	g_count += write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	g_count += write(1, str, ft_strlen(str));
}

int		consume_conv(va_list ap, t_content *argu)
{
	int i;
	int	result;

	if (argu->conv)
	{
		i = find_good_index(argu->conv);
		if (i < 0)
			result = invalidconv(argu);
		else
			result = g_f[i](ap, argu);
		clean_struct(argu);
		if (!result)
			return (0);
	}
	return (1);
}

int		parser(va_list ap, char *str)
{
	t_content argu;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			argu = initialise_struct();
			if ((!first_parse(str, &argu, ap)))
				return (0);
			parse_values(&str, argu.end, &argu);
			if (!(consume_conv(ap, &argu)))
				return (0);
		}
		else
		{
			if (*str)
				ft_putchar(*str);
		}
		if (*str)
			str++;
	}
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		result;

	g_count = 0;
	va_start(ap, (char *)str);
	result = parser(ap, (char *)str);
	if (!result)
	{
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	return (g_count);
}

int main(void)
{
	ft_printf(" % 010i ", 0);
}
