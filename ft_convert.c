/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:10:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/03 16:10:37 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(int c)
{
	char	*str;

	str = (char *) malloc(2 * sizeof(char));
	str[0] = (unsigned char) c;
	str[1] = '\0';
	return (str);
}

char	*ft_getaddress(void *p)
{
	char	*temp;
	char	*str;

	temp = ft_dec2base((long long) p, "0123456789abcdef");
	str = ft_strjoin("0x", temp);
	ft_release(temp, 0);
	return (str);
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
