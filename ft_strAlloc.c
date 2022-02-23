/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strAlloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:59:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/23 11:20:20 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*r;

	size = ft_clamp(ft_strlen(&s[start]), 0, len);
	r = (char *) malloc((size + 1) * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, &s[start], size);
	return (r);
}

char	*ft_strdup(const char *s1)
{
	char	*r;

	r = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s1, ft_strlen(s1));
	return (r);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*r;

	len = ft_strlen(s1) + ft_strlen(s2);
	r = (char *) malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s1, len);
	ft_strlcat(r, s2, len);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	char	*r;
	int		y;
	int		i;

	len = ft_strlen(s1);
	len = len - (ft_strlen(set) * ft_strlstr(s1, set, len));
	r = (char *) malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	y = 0;
	while (s1[i])
	{
		if (ft_strnstr(s1, set, ft_strlen(set)))
			i += ft_strlen(set);
		else
			r[y++] = s1[i++];
	}
	r[y] = '\0';
	return (r);
}
