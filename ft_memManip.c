/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memManip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:15:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/25 11:20:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	y;
	size_t			i;

	i = 0;
	y = c;
	str = (unsigned char *) b;
	while (i < len)
		str[i++] = y;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) dst;
	str2 = (unsigned char *) src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) dst;
	str2 = (unsigned char *) src;
	temp = str2;
	while (i < len)
	{
		str1[i] = temp[i];
		i++;
	}
	return (dst);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	y;
	size_t			i;

	i = 0;
	y = c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == y)
			return ((void *) &str[i]);
		i++;
	}
	return (0);
}
