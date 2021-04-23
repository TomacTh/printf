/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:44:04 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 20:27:58 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			find_good_index(char c)
{
	char	*str;
	int		i;

	str = "cspxXudin";
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (-1);
	return (i);
}

t_content	initialise_struct(void)
{
	t_content argu;

	argu.conv = 0;
	argu.precision = 0;
	argu.presence = 0;
	argu.zero = 0;
	argu.result = 0;
	argu.spaceright = 0;
	argu.stars = 0;
	argu.width = 0;
	argu.end = 0;
	argu.shortt = 0;
	argu.longg = 0;
	argu.space = 0;
	argu.plus = 0;
	argu.sharp = 0;
	return (argu);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			is_inset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
