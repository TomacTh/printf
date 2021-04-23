/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:19:55 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 22:17:25 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	allocate_zerosint(int len, t_content *argu, t_ll n)
{
	int		plus;

	if (!allocate_flags(len, argu->width, argu, '0'))
		return (0);
	if (n < 0 || argu->space || argu->plus)
	{
		plus = argu->width - len;
		argu->result[0] = argu->result[plus];
		argu->result[plus] = '0';
	}
	return (1);
}

int	allocate_flags(int len, int data, t_content *argu, char c)
{
	char	*str;
	int		total;
	int		plus;

	plus = data - len;
	total = plus + len;
	if (!(str = malloc(total + 1)))
		return (0);
	str[total] = '\0';
	ft_memset(str, c, plus);
	ft_memmove(&str[plus], argu->result, len);
	free(argu->result);
	argu->result = str;
	return (1);
}

int	allocate_spaceright(int len, t_content *argu)
{
	char	*str;
	int		total;
	int		plus;
	int		data;

	data = argu->width;
	plus = data - len;
	total = plus + len;
	if (!(str = malloc(total + 1)))
		return (0);
	str[total] = '\0';
	ft_memset(&str[len], ' ', plus);
	ft_memmove(str, argu->result, len);
	free(argu->result);
	argu->result = str;
	return (1);
}

int	negative_precision(int len, t_content *argu)
{
	char	*str;
	int		plus;
	int		total;

	plus = argu->precision - (len - 1);
	total = len + plus;
	if (!(str = malloc(total + 1)))
		return (0);
	str[total] = '\0';
	str[0] = '-';
	ft_memset(&str[1], '0', plus);
	ft_memmove(&str[plus + 1], &argu->result[1], (len - 1));
	free(argu->result);
	argu->result = str;
	return (1);
}
