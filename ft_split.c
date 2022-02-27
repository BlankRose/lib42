/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:09:21 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/25 16:44:27 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_error(char **res, size_t i)
{
	while (i)
		free(res[--i]);
	free(res);
	return (0);
}

static size_t	ft_split_size(const char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i++])
	{
		while (s[i] != c && s[i])
			i++;
		len++;
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

static char	**ft_split2(const char *s, char c, char **res)
{
	size_t	len;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s[y])
	{
		len = 0;
		while (s[y] != c && s[y] && ++y)
			len++;
		res[i] = malloc(len + 1);
		if (!res[i])
			return (ft_split_error(res, i));
		ft_strlcpy(res[i++], &s[y - len], len + 1);
		while (s[y] == c && s[y])
			y++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**r;

	if (!s)
		return (0);
	while (*s == c && *s)
		s++;
	r = (char **)malloc(sizeof(char *) * (ft_split_size(s, c) + 1));
	if (!r)
		return (0);
	return (ft_split2(s, c, r));
}
