/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:02:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/11/13 13:38:40 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*read_next_line(char *res, int fd)
{
	char		temp[BUFFER_SIZE + 1];
	size_t		y;

	ft_bzero(temp, BUFFER_SIZE + 1);
	y = read(fd, temp, BUFFER_SIZE);
	while (y > 0 && temp[0])
	{
		res = ft_realloc(res, ft_strlen(temp) + 1);
		ft_strlcat(res, temp, ft_strlen(temp) + ft_strlen(res) + 1);
		if (ft_contains(res, "\n"))
			return (res);
		ft_bzero(temp, BUFFER_SIZE + 1);
		y = read(fd, temp, BUFFER_SIZE);
	}
	return (res);
}

static char	*catch_next_line(char *str, int fd)
{
	static char		prev[MAX_FD][BUFFER_SIZE + 1];
	char			*res;
	size_t			y;

	res = 0;
	if (str)
	{
		y = ft_strlenlimit(str, '\n');
		y += ft_contains(str, "\n");
		ft_strlcpy(prev[fd], &str[y], ft_strlen(str) - y + 1);
		res = ft_realloc(res, ft_strlen(str) + 1);
		ft_strlcpy(res, str, y + 1);
		free (str);
	}
	else if (prev[fd][0])
	{
		res = ft_realloc(res, ft_strlen(prev[fd]) + 1);
		ft_strlcat(res, prev[fd], ft_strlen(prev[fd]) + ft_strlen(res) + 1);
		ft_bzero(prev[fd], BUFFER_SIZE + 1);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char		*res;

	res = 0;
	if (fd < 0)
		return (0);
	res = catch_next_line(res, fd);
	if (!ft_contains(res, "\n"))
		res = read_next_line(res, fd);
	res = catch_next_line(res, fd);
	return (res);
}

t_list	*get_all_lines(int fd)
{
	t_list		*list;
	char		*line;

	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	list = 0;
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (list);
}
