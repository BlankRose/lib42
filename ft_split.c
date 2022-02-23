/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:09:21 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/23 13:01:45 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split2(const char *s, char c, char **r, t_vector3 v)
{
	int		len;

	len = 0;
	while (s[v.x])
	{
		if (v.x == 0 || s[v.x] == c)
		{
			if (v.x != 0)
			{
				r[v.y][v.z] = '\0';
				v.y++;
			}
			v.x++;
			len = 0;
			while (s[v.x] || s[v.x] != c)
				len++;
			r[v.y] = (char *) malloc((len + 1) * sizeof(char));
			if (!r[v.y])
				return (0);
			v.z = 0;
		}
		r[v.y][v.z++] = s[v.x++];
	}
	r[v.y][v.z] = '\0';
	return (r);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	char	**r;

	len = ft_strnchr(s, c) + 1;
	r = (char **) malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	r = ft_split2(s, c, r, ft_vector3_new(0, 0, 0));
	if (!r)
		return (0);
	r[len] = 0;
	return (r);
}
