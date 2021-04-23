/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:41:48 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/16 14:08:50 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_utoa_adress(t_ull n)
{
	char			*str;
	unsigned		length;

	length = unsigned_size(n, 16) + 2;
	if (!(str = malloc(length + 1)))
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[length] = '\0';
	fil_str(&str[length - 1], n, "0123456789abcdef", 16);
	return (str);
}

char	*ft_utoa(t_ull n)
{
	char			*str;
	int				length;

	length = unsigned_size(n, 10);
	if (!(str = malloc(length + 1)))
		return (0);
	str[length] = '\0';
	fil_str(&str[length - 1], n, "0123456789", 10);
	return (str);
}

int		small_atoi(char **str)
{
	int n;

	n = 0;
	while (**str && ft_isdigit(**str))
	{
		n = n * 10 + (**str - '0');
		(*str)++;
	}
	return (n);
}
