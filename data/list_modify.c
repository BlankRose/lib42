/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:55:54 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/02 11:17:50 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlocate(t_list *lst, size_t n)
{
	size_t	i;

	i = 0;
	while (lst && i++ < n)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	current = new;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		current->next = tmp;
		current = tmp;
		lst = lst->next;
	}
	return (new);
}
