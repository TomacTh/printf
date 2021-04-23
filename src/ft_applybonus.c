/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applybonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:44:24 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 20:56:09 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ll		long_or_short_int(va_list ap, t_content *argu)
{
	if (argu->longg)
	{
		if (argu->longg == 1)
			return ((long)va_arg(ap, long));
		else if (argu->longg == 2)
			return ((t_ll)va_arg(ap, t_ll));
	}
	else if (argu->shortt)
	{
		if (argu->shortt == 1)
			return ((short int)va_arg(ap, int));
		else if (argu->shortt == 2)
			return ((signed char)va_arg(ap, int));
	}
	return ((int)va_arg(ap, int));
}

void		long_or_short_n(va_list ap, t_content *argu)
{
	if (argu->longg)
	{
		if (argu->longg == 1)
			*(long *)(va_arg(ap, long*)) = g_count;
		else if (argu->longg == 2)
			*(t_ll *)(va_arg(ap, t_ll*)) = g_count;
	}
	else if (argu->shortt)
	{
		if (argu->shortt == 1)
			*(short int *)(va_arg(ap, int*)) = g_count;
		else if (argu->shortt == 2)
			*(signed char *)(va_arg(ap, int*)) = g_count;
	}
	else
		*(int *)(va_arg(ap, int*)) = g_count;
}

t_ull		long_or_short_unsigned(va_list ap, t_content *argu)
{
	if (argu->longg)
	{
		if (argu->longg == 1)
			return ((unsigned long)va_arg(ap, unsigned long));
		else if (argu->longg == 2)
			return ((t_ull)va_arg(ap, t_ull));
	}
	else if (argu->shortt)
	{
		if (argu->shortt == 1)
			return ((unsigned short)va_arg(ap, unsigned int));
		else if (argu->shortt == 2)
			return ((unsigned char)va_arg(ap, unsigned int));
	}
	return ((unsigned int)va_arg(ap, unsigned int));
}

int			space_plus(t_content *argu, int len, char c)
{
	char *str;

	str = malloc(len + 2);
	if (!str)
		return (0);
	str[len + 1] = '\0';
	str[0] = c;
	ft_memmove(&str[1], argu->result, len);
	free(argu->result);
	argu->result = str;
	return (1);
}

int			space_or_plus(t_content *argu, t_ll n)
{
	int		len;

	if ((argu->space || argu->plus) && n >= 0)
	{
		len = ft_strlen(argu->result);
		if (argu->space)
		{
			if (!space_plus(argu, len, ' '))
				return (0);
		}
		else
		{
			if (!space_plus(argu, len, '+'))
				return (0);
		}
	}
	return (1);
}
