/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:15:38 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/10 17:16:27 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_zeroprecision(t_content *argu)
{
	char *str;

	str = (char*)malloc(1);
	if (!str)
		return (0);
	*str = '\0';
	argu->result = str;
	return (1);
}

int		string_value(t_content *argu, char *str)
{
	int len;

	if (!str)
	{
		if (!(argu->result = (char*)malloc(sizeof(char) * 7)))
			return (0);
		copy(argu->result, "(null)");
	}
	else
	{
		len = ft_strlen(str);
		if (!(argu->result = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		argu->result[len] = '\0';
		ft_memmove(argu->result, str, len);
	}
	len = ft_strlen(argu->result);
	if (argu->presence && argu->precision < len)
		argu->result[argu->precision] = '\0';
	return (1);
}
