/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 09:51:54 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*ft_range(int min, int max)
{
	int		*array;
	size_t	i;

	if (min > max)
		return (0);
	i = max - min;
	array = (int *) ft_calloc(i + 1, sizeof(int));
	while (min <= max && i >= 0)
		array[i--] = max--;
	return (array);
}
