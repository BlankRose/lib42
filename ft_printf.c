/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:34:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/03 16:12:32 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_cat(char *res, char *temp)
{
	size_t	len;
	char	*new;

	if (!res)
		len = ft_strlen(temp);
	else
		len = ft_strlen(res) + ft_strlen(temp);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (ft_release(res, temp));
	if (res)
	{
		ft_strlcpy(new, res, ft_strlen(res) + 1);
		ft_strlcat(new, temp, len + 1);
	}
	else
		ft_strlcpy(new, temp, len + 1);
	ft_release(res, temp);
	return (new);
}

static char	*ft_printf_nor(char *res, const char *src, size_t y)
{
	char	*temp;

	if (!src)
		return (ft_release(res, 0));
	else if (y)
	{
		temp = malloc((y + 1) * sizeof(char));
		if (!temp)
			return (ft_release(res, temp));
		ft_strlcpy(temp, src, y + 1);
		res = ft_printf_cat(res, temp);
	}
	return (res);
}

static char	*ft_printf_spe(char *res, const char *src, va_list *args)
{
	char	*str;

	if (src[0] == '%')
		return (ft_printf_nor(res, "%", 1));
	else if (src[0] == 'd' || src[0] == 'i')
		str = ft_itoa(va_arg(*args, int));
	else if (src[0] == 'u')
		str = ft_itoa_unsigned(va_arg(*args, unsigned int));
	else if (src[0] == 's')
		str = ft_strdup(va_arg(*args, char *));
	else if (src[0] == 'c')
		str = ft_ctoa(va_arg(*args, int));
	else if (src[0] == 'p')
		str = ft_getaddress(va_arg(*args, void *));
	else if (src[0] == 'x')
		str = ft_dec2base((long long) va_arg(*args, int), HEXA_LOW);
	else if (src[0] == 'X')
		str = ft_dec2base((long long) va_arg(*args, int), HEXA_UP);
	else if (src[0] == 'o')
		str = ft_dec2base(va_arg(*args, int), OCTAL);
	else
		return (ft_release(res, 0));
	res = ft_printf_nor(res, str, ft_strlen(str));
	ft_release(str, 0);
	return (res);
}

static char	*ft_printf_2(va_list *args, t_vector3 v, const char *s)
{
	char	*res;

	res = 0;
	while (s[v.x])
	{
		v.y = ft_strlenlimit(&s[v.x], '%');
		res = ft_printf_nor(res, &s[v.x], v.y);
		v.x += v.y;
		if (ft_strchr(&s[v.x], '%'))
		{
			res = ft_printf_spe(res, &s[++v.x], args);
			v.x++;
		}
		if (!res)
			return (0);
	}
	return (res);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	size_t		z;
	char		*res;

	if (!s)
		return (-1);
	va_start(args, s);
	res = ft_printf_2(&args, ft_vector3_new(0, 0, 0), s);
	va_end(args);
	if (!res)
		return (-1);
	z = ft_strlen(res);
	ft_putstr_fd(res, 1);
	ft_release(res, 0);
	return (z);
}
