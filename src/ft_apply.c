/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:10:51 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 20:52:33 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		charr(va_list ap, t_content *argu)
{
	if (argu->width > 1)
	{
		if (!(argu->result = (char*)malloc(argu->width)))
			return (0);
		argu->result[argu->width - 1] = '\0';
		if (argu->zero && !argu->spaceright)
			ft_memset(argu->result, '0', (argu->width - 1));
		else
			ft_memset(argu->result, ' ', (argu->width - 1));
		if (argu->spaceright)
		{
			ft_putchar(va_arg(ap, int));
			ft_putstr(argu->result);
		}
		else
		{
			ft_putstr(argu->result);
			ft_putchar(va_arg(ap, int));
		}
	}
	else
		ft_putchar(va_arg(ap, int));
	return (1);
}

int		string(va_list ap, t_content *argu)
{
	char	*str;

	str = va_arg(ap, void*);
	if (argu->presence && !argu->precision)
	{
		if (!(string_zeroprecision(argu)))
			return (0);
	}
	else
	{
		if (!(string_value(argu, str)))
			return (0);
	}
	if (!(apply_flags(argu)))
		return (0);
	ft_putstr(argu->result);
	return (1);
}

int		sharp_hexa(t_content *argu, t_ull u)
{
	int		len;
	char	*str;

	if (argu->sharp && u)
	{
		len = ft_strlen(argu->result);
		str = malloc(len + 3);
		if (!str)
			return (0);
		str[len + 2] = '\0';
		str[0] = '0';
		str[1] = argu->conv;
		ft_memmove(&str[2], argu->result, len);
		free(argu->result);
		argu->result = str;
	}
	return (1);
}

int		hexa(va_list ap, t_content *argu)
{
	t_ull	u;
	int		len;

	u = long_or_short_unsigned(ap, argu);
	if (!(argu->result = ft_hex_utoa(u, argu->conv)))
		return (0);
	len = ft_strlen(argu->result);
	if (argu->presence)
	{
		if (!u && !argu->precision)
			ft_memset(argu->result, 0, len);
		else if (argu->precision > len)
		{
			if (!(allocate_flags(len, argu->precision, argu, '0')))
				return (0);
		}
	}
	if (!(sharp_hexa(argu, u)))
		return (0);
	if (!(apply_numflags(argu)))
		return (0);
	ft_putstr(argu->result);
	return (1);
}

int		u_num(va_list ap, t_content *argu)
{
	t_ull		u;
	int			len;

	u = long_or_short_unsigned(ap, argu);
	if (!(argu->result = ft_utoa(u)))
		return (0);
	len = ft_strlen(argu->result);
	if (argu->presence)
	{
		if (!u && !argu->precision)
			ft_memset(argu->result, 0, len);
		else if (argu->precision > len)
		{
			if (!(allocate_flags(len, argu->precision, argu, '0')))
				return (0);
		}
	}
	if (!(apply_numflags(argu)))
		return (0);
	ft_putstr(argu->result);
	return (1);
}
