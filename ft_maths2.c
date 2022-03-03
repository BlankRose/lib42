/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:06:05 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/03 12:33:36 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen_long(unsigned long long x)
{
	size_t	i;

	i = 1;
	while (x > 9)
	{
		x /= 10;
		i++;
	}
	return (i);
}

size_t	ft_nbrlen_base(unsigned long long x, size_t base)
{
	size_t	i;

	i = 1;
	while (x > base - 1)
	{
		x /= base;
		i++;
	}
	return (i);
}
