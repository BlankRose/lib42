/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:43:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/02 17:08:39 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	ft_vector3_new(int x, int y, int z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

int	ft_min(int x, int min)
{
	if (x < min)
		return (min);
	return (x);
}

int	ft_max(int x, int max)
{
	if (x > max)
		return (max);
	return (x);
}

int	ft_clamp(int x, int min, int max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

size_t	ft_nbrlen(unsigned int x)
{
	return (ft_nbrlen_long((unsigned long long) x));
}
