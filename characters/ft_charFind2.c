/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charFind2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:30:46 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:02 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlstr(const char *str, const char *needle, size_t len)
{
	size_t	found;
	char	*y;

	found = 0;
	y = ft_strnstr(str, needle, len);
	while (y)
	{
		found++;
		y = ft_strnstr(&y[1], needle, len);
	}
	return (found);
}

size_t	ft_strnchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			len++;
		i++;
	}
	return (len);
}
