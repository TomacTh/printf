/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:43:30 by tcharvet          #+#    #+#             */
/*   Updated: 2021/03/30 13:37:56 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_stars(t_content *argu, int count, va_list ap)
{
	int *stars;
	int i;

	i = 0;
	if (count)
	{
		stars = malloc(sizeof(int) * count);
		if (!stars)
			return (0);
		while (count--)
		{
			stars[i] = va_arg(ap, int);
			i++;
		}
		argu->stars = stars;
	}
	return (1);
}

int		first_parse(char *str, t_content *argu, va_list ap)
{
	int count;

	count = 0;
	while (*str && (ft_isdigit(*str) || is_inset(*str, "-*.lh +#")))
	{
		if (*str == '*')
			count++;
		str++;
	}
	if (!(init_stars(argu, count, ap)))
		return (0);
	argu->end = str;
	argu->conv = *str;
	return (1);
}

void	parse_values(char **str, char *end, t_content *argu)
{
	int count;

	count = 0;
	while (*str < end)
	{
		parse_zero(str, argu);
		parse_stars(str, argu, &count);
		parse_spaceright(str, argu);
		parse_precision(str, argu, &count);
		parse_width(str, argu);
		parse_short(str, argu);
		parse_long(str, argu);
		parse_space(str, argu);
		parse_plus(str, argu);
		parse_sharp(str, argu);
	}
}
