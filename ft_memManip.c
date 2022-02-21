/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memManip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:15:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/21 18:12:19 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *b, int c, size_t len)
{
	unsigned char	y;
	size_t			i;

	i = 0;
	y = c;
	while (i < len)
		b[i++] = y;
	return (b);
}

void	*memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	*memmove(void *dst, const void *src, size_t len)
{
	void		*temp;
	size_t		i;

	i = 0;
	*temp = *src;
	while (i < len)
	{
		dst[i] = temp[i];
		i++;
	}
	return (dest);
}
