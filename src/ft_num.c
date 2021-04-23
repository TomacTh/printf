/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:43:16 by tcharvet          #+#    #+#             */
/*   Updated: 2021/03/30 09:37:09 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size(t_ll n)
{
	int				size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int		unsigned_size(t_ull n, int basemax)
{
	int				size;

	size = 0;
	if (!n)
		size++;
	while (n)
	{
		n /= basemax;
		size++;
	}
	return (size);
}

void	fil_str(char *str, t_ull num, char *base, int max)
{
	while (num >= (t_ull)max)
	{
		*str = base[num % max];
		str--;
		num /= max;
	}
	*str = base[num % max];
}

char	*ft_itoa(t_ll n)
{
	char			*str;
	int				length;
	t_ull			num;

	length = size(n);
	if (!(str = malloc(length + 1)))
		return (0);
	str[length] = '\0';
	num = n;
	if (n < 0)
	{
		num = n * -1;
		str[0] = '-';
	}
	fil_str(&str[length - 1], num, "0123456789", 10);
	return (str);
}

char	*ft_hex_utoa(t_ull n, char c)
{
	char			*str;
	unsigned		length;

	length = unsigned_size(n, 16);
	if (!(str = malloc(length + 1)))
		return (0);
	str[length] = '\0';
	if (c == 'x')
		fil_str(&str[length - 1], n, "0123456789abcdef", 16);
	else
		fil_str(&str[length - 1], n, "0123456789ABCDEF", 16);
	return (str);
}
