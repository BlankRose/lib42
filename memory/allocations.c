/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:08:02 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:40:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(count * size);
	if (!i)
		return (0);
	ft_bzero(i, count * size);
	return (i);
}

void	*ft_realloc(void *s, size_t size)
{
	void	*new;

	new = ft_calloc(ft_memlen(s) + size, sizeof(char));
	if (!new)
		return (0);
	if (!s)
	{
		ft_memcpy(new, s, ft_memlen(s));
		free (s);
	}
	return (new);
}

char	*ft_release(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (0);
}
