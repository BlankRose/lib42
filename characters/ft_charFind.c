/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charFind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:32:22 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/09 15:41:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a') + 'A');
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A') + 'a');
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*y;
	int			i;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == c)
			y = &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	if (y)
		return ((char *) y);
	return (0);
}

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *) str);
	while (str[i] && i < len)
	{
		y = 0;
		while (str[i + y] == needle[y] && (i + y) < len)
			if (!needle[++y])
				return ((char *) &str[i]);
		i++;
	}
	return (0);
}
