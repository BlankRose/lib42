/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:55:46 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 20:08:33 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_btree_new(void *content)
{
	t_btree		*tree;

	tree = (t_btree *) malloc(sizeof(t_btree));
	if (!tree)
		return (0);
	tree->content = content;
	tree->left = 0;
	tree->right = 0;
	return (tree);
}
