/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charFind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:32:22 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/21 15:12:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (&str[i]);
}

char	*ft_strrchr(char *str, int c)
{
	char	*y;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			y = &str[i];
		i++;
	}
	if (y)
		return (y);
	return (&str[i]);
}

char	*strnstr(char *str, char *find, int length)
{
	int		i;
	int		y;

	i = 0;
	if (!ft_strlen(find))
		return (str);
	while (str[i] && i < length)
	{
		y = 0;
		while (str[i + y] == find[y])
			if (!find[++y])
				return (&str[i]);
		i++;
	}
	return (0);
}
