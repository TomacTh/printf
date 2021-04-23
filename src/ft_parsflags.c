/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:43:40 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 19:57:03 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_zero(char **str, t_content *argu)
{
	if (**str == '0' &&
	(!(*(*str - 1) >= '1' && *(*str - 1) <= '9') && *(*str - 1) != '.'))
	{
		argu->zero = 1;
		(*str)++;
	}
}

void	parse_spaceright(char **str, t_content *argu)
{
	if (**str == '-')
	{
		argu->spaceright = 1;
		(*str)++;
	}
}

void	parse_stars(char **str, t_content *argu, int *count)
{
	if (**str == '*')
	{
		if (argu->stars[*count] < 0)
		{
			argu->spaceright = 1;
			argu->width = argu->stars[*count] * -1;
		}
		else
			argu->width = argu->stars[*count];
		(*count)++;
		(*str)++;
	}
}

void	parse_precision(char **str, t_content *argu, int *count)
{
	if (**str == '.')
	{
		argu->presence = 1;
		(*str)++;
		if (**str == '*')
		{
			if (argu->stars[*count] <= 0)
			{
				argu->precision = 0;
				if (argu->stars[*count] < 0)
					argu->presence = 0;
			}
			else
				argu->precision = argu->stars[*count];
			(*count)++;
			(*str)++;
		}
		else if (ft_isdigit(**str))
			argu->precision = small_atoi(str);
	}
}

void	parse_width(char **str, t_content *argu)
{
	if (ft_isdigit(**str) && **str != '0')
		argu->width = small_atoi(str);
}
