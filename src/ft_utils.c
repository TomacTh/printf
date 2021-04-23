/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharvet <tcharvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:44:12 by tcharvet          #+#    #+#             */
/*   Updated: 2021/02/09 19:44:13 by tcharvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	copy(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pdest;

	pdest = dst;
	while (n--)
	{
		*pdest = *(unsigned char *)src;
		src++;
		pdest++;
	}
	return (dst);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = b;
	while (len--)
		*ptr++ = c;
	return (b);
}

void	clean_struct(t_content *argu)
{
	if (argu->stars)
		free(argu->stars);
	if (argu->result)
		free(argu->result);
}
