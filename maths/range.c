/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 11:21:41 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_range(int min, int max)
{
	int		*array;
	int		tmp;
	size_t	i;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	i = max - min;
	array = (int *) ft_calloc(i + 1, sizeof(int));
	while (array && min <= max && i >= 0)
		array[i--] = max--;
	return (array);
}

int	*ft_rangerev(int min, int max)
{
	int		*array;
	int		tmp;
	size_t	i;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	i = max - min;
	array = (int *) ft_calloc(i + 1, sizeof(int));
	while (array && min <= max && i >= 0)
		array[i--] = min++;
	return (array);
}
