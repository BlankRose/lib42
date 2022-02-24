/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:09:21 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/24 11:53:54 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split2(const char *s, char c, char **res, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (i < n)
	{
		len = ft_strlenlimit(s, c);
		res[i] = (char *) malloc((len + 1) * sizeof(char));
		if (!res[i])
			return (0);
		ft_strlcpy(res[i], s, len + 1);
		s = &s[len + 1];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	char	**r;

	len = ft_strnchr(s, c) + 1;
	r = (char **) malloc((len + 1) * sizeof(char *));
	if (!r)
		return (0);
	return (ft_split2(s, c, r, len));
}
