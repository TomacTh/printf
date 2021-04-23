/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:13:15 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 16:32:45 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		allocate_precision_pointer(int len, int data, t_content *argu)
{
	char	*str;
	int		total;
	int		plus;

	plus = data - len + 2;
	total = plus + len;
	if (!(str = malloc(total + 1)))
		return (0);
	str[total] = '\0';
	ft_memset(&str[2], '0', plus);
	str[0] = '0';
	str[1] = 'x';
	ft_memmove(&str[plus + 2], &argu->result[2], len);
	free(argu->result);
	argu->result = str;
	return (1);
}

int		allocate_zero_pointer(int len, int data, t_content *argu)
{
	char	*str;
	int		total;
	int		plus;

	plus = data - len;
	total = plus + len;
	if (!(str = malloc(total + 1)))
		return (0);
	str[total] = '\0';
	ft_memset(&str[2], '0', plus);
	str[0] = '0';
	str[1] = 'x';
	ft_memmove(&str[plus + 2], &argu->result[2], len - 2);
	free(argu->result);
	argu->result = str;
	return (1);
}

int		apply_pointerflags(t_content *argu)
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
			if (!(allocate_zero_pointer(len, argu->width, argu)))
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

int		pointer(va_list ap, t_content *argu)
{
	unsigned long long	p;
	int					len;

	p = va_arg(ap, t_ull);
	if (!(argu->result = ft_hex_utoa_adress(p)))
		return (0);
	len = ft_strlen(argu->result);
	if (argu->presence)
	{
		if (!p && !argu->precision)
			argu->result[2] = '\0';
		if (argu->precision > len - 2)
		{
			if (!(allocate_precision_pointer(len, argu->precision, argu)))
				return (0);
		}
	}
	apply_pointerflags(argu);
	ft_putstr(argu->result);
	return (1);
}

int		n_flag(va_list ap, t_content *argu)
{
	long_or_short_n(ap, argu);
	return (1);
}
