/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strManip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:29:42 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/21 15:11:28 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dest, char *src, int length)
{
	int		i;

	i = 0;
	while (src[i] && i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	ft_strlcat(char *dest, char *src, int length)
{
	int		i;
	int		y;

	i = 0;
	y = ft_strlen(dest);
	while (src[i] && i < length)
	{
		dest[y + i] = src[i];
		i++;
	}
	dest[y + i] = '\0';
	return (y + i);
}

int	ft_strncmp(char *s1, char *s2, int length)
{
	int		i;

	i = 0;
	while (i < length && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
