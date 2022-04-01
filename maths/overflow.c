/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:13:41 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/01 15:34:20 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_overflow(char *n, char *cmp, int sign)
{
	int		i;

	if (!n || !cmp)
		return (0);
	if (ft_strlen(n) < ft_strlen(cmp))
		return (0);
	else if (ft_strlen(n) > ft_strlen(cmp))
		return (1);
	else
	{
		ft_printf(1, "Same Length!\n");
		i = 0;
		while (n[i] && cmp[i] && n[i] == cmp[i])
			i++;
		ft_printf(1, "%c VS %c [%d]\n", n[i], cmp[i], sign);
		if ((sign >= 0 && n[i] <= cmp[i])
			|| (sign < 0 && n[i] >= cmp[i]))
			return (0);
		else
			return (1);
	}
}

int	ft_intoverflow(char *n)
{
	char	*cmp;
	int		sign;
	int		t;

	if (!n)
		return (0);
	sign = ft_issign(n[0]);
	if (sign > 0)
		n++;
	if (sign < 0)
		cmp = ft_itoa(-__INT_MAX__ - 1);
	else
		cmp = ft_itoa(__INT_MAX__);
	t = ft_overflow(n, cmp, sign);
	free (cmp);
	return (t);
}

int	ft_longoverflow(char *n)
{
	char	*cmp;
	int		sign;
	int		t;

	if (!n)
		return (0);
	sign = ft_issign(n[0]);
	if (sign > 0)
		n++;
	if (sign < 0)
		cmp = ft_itoa(-__LONG_MAX__ - 1L);
	else
		cmp = ft_itoa(__LONG_MAX__);
	t = ft_overflow(n, cmp, sign);
	free (cmp);
	return (t);
}
