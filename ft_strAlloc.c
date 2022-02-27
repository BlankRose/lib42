/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strAlloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:59:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/25 17:01:05 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;

	r = (char *) malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(r, &s[start], len + 1);
	else
		r[0] = '\0';
	return (r);
}

char	*ft_strdup(const char *s1)
{
	char	*r;

	r = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
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
	ft_strlcpy(r, s1, len + 1);
	ft_strlcat(r, s2, len + 1);
	return (r);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*r;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, len + 1);
	return (r);
}
