/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:10:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:34 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_getaddress(void *p)
{
	char	*temp;
	char	*str;

	temp = ft_ptr2base(p, HEXA_LOW);
	str = ft_strjoin("0x", temp);
	ft_release(temp, 0);
	return (str);
}

char	*ft_base2base(char *s, char *b1, char *b2)
{
	return (ft_dec2base(ft_base2dec(s, b1), b2));
}

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
