/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkCustom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:59:01 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/15 12:27:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isset(int c, const char *set)
{
	int		i;

	i = 0;
	while (set && set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

int	ft_contains(const char *str, const char *set)
{
	int		i;

	i = 0;
	while (str && str[i])
		if (ft_isset(str[i++], set))
			return (1);
	return (0);
}
