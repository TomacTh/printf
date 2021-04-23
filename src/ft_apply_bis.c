/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:13:40 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 22:17:43 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_flags(t_content *argu)
{
	int len;

	len = ft_strlen(argu->result);
	if (argu->width > len)
	{
		if (argu->spaceright)
		{
			if (!(allocate_spaceright(len, argu)))
				return (0);
		}
		else if (!argu->spaceright && argu->zero)
		{
			if (!(allocate_flags(len, argu->width, argu, '0')))
				return (0);
		}
		else
		{
			if (!(allocate_flags(len, argu->width, argu, ' ')))
				return (0);
		}
	}
	return (1);
}

int		apply_numflags(t_content *argu)
{
	int len;

	len = ft_strlen(argu->result);
	if (argu->width > len)
	{
		if (argu->spaceright)
		{
			if (!(allocate_spaceright(len, argu)))
				return (0);
		}
		else if (!argu->spaceright && !argu->presence && argu->zero)
		{
			if (!(allocate_flags(len, argu->width, argu, '0')))
				return (0);
		}
		else
		{
			if (!(allocate_flags(len, argu->width, argu, ' ')))
				return (0);
		}
	}
	return (1);
}

int		apply_intflags(t_content *argu, t_ll n)
{
	int len;

	len = ft_strlen(argu->result);
	if (argu->width > len)
	{
		if (argu->spaceright)
		{
			if (!(allocate_spaceright(len, argu)))
				return (0);
		}
		else if (!argu->spaceright && !argu->presence && argu->zero)
		{
			if (!(allocate_zerosint(len, argu, n)))
				return (0);
		}
		else
		{
			if (!(allocate_flags(len, argu->width, argu, ' ')))
				return (0);
		}
	}
	return (1);
}

int		invalidconv(t_content *argu)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[1] = '\0';
	str[0] = argu->conv;
	argu->result = str;
	if (!(apply_flags(argu)))
		return (0);
	ft_putstr(argu->result);
	return (1);
}

int		integer(va_list ap, t_content *argu)
{
	t_ll	n;
	int		len;

	n = long_or_short_int(ap, argu);
	if (!(argu->result = ft_itoa(n)))
		return (0);
	len = ft_strlen(argu->result);
	if (argu->presence)
	{
		if (!n && !argu->precision)
			ft_memset(argu->result, 0, len);
		else if (n < 0 && argu->precision > (len - 1))
			negative_precision(len, argu);
		else if (argu->precision > len)
			allocate_flags(len, argu->precision, argu, '0');
	}
	if (!(space_or_plus(argu, n)))
		return (0);
	if (!(apply_intflags(argu, n)))
		return (0);
	ft_putstr(argu->result);
	return (1);
}
