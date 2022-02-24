/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:49:56 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/24 12:03:03 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -sign;
	result = 0;
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

static char	*ft_itoa2(char *str, unsigned int nbr, size_t i)
{
	str[i--] = (nbr % 10) + '0';
	while (nbr > 9)
	{
		nbr /= 10;
		str[i--] = (nbr % 10) + '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			len;
	char			*str;

	len = 0;
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	else
		nbr = n;
	len += ft_nbrlen(nbr);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len--] = '\0';
	return (ft_itoa2(str, nbr, len));
}
