/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:15:25 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/11 21:02:30 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_hasbit(t_byte byte, int n)
{
	if ((byte >> n) & 1)
		return (1);
	return (0);
}

t_byte	ft_setbit(t_byte byte, int n)
{
	if (n >= 8)
		return (byte);
	return (byte | (1 << n));
}

t_byte	ft_unsetbit(t_byte byte, int n)
{
	if (ft_hasbit(byte, n))
		return (byte ^ (1 << n));
	return (byte);
}

t_byte	ft_flipbit(t_byte byte, int n)
{
	if (n >= 8)
		return (byte);
	if (ft_hasbit(byte, n))
		return (byte ^ (1 << n));
	return (byte | (1 << n));
}

t_byte		ft_flipbyte(t_byte byte)
{
	t_byte	i;

	i = 0;
	while (i < 8)
		byte = ft_flipbit(byte, i);
	return (byte);
}