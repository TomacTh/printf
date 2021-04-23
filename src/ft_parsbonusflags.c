/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsbonusflags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:56:05 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 21:39:51 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_short(char **str, t_content *argu)
{
	while (**str == 'h')
	{
		if (argu->longg)
			argu->longg = 0;
		if (!argu->shortt)
			argu->shortt = 1;
		if (*(*str - 1) == 'h')
			argu->shortt = 2;
		(*str)++;
	}
}

void	parse_long(char **str, t_content *argu)
{
	while (**str == 'l')
	{
		if (argu->shortt)
			argu->shortt = 0;
		if (!argu->longg)
			argu->longg = 1;
		if (*(*str - 1) == 'l')
			argu->longg = 2;
		(*str)++;
	}
}

void	parse_space(char **str, t_content *argu)
{
	if (**str == ' ')
	{
		if (!argu->plus)
			argu->space = 1;
		(*str)++;
	}
}

void	parse_plus(char **str, t_content *argu)
{
	if (**str == '+')
	{
		argu->plus = 1;
		if (argu->space)
			argu->space = 0;
		(*str)++;
	}
}

void	parse_sharp(char **str, t_content *argu)
{
	if (**str == '#')
	{
		argu->sharp = 1;
		(*str)++;
	}
}
