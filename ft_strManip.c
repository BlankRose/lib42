/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strManip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:29:42 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/23 18:16:10 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize - 1 && dstsize > 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	z;

	z = ft_strlen(dst);
	i = 0;
	y = z;
	while (src[i] && z < dstsize - 1 && dstsize > 0)
	{
		dst[y + i] = src[i];
		i++;
		z++;
	}
	dst[y + i] = '\0';
	if (z > dstsize)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + y);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
