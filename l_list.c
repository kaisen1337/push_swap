/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:00:28 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/28 21:49:12 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*c_node;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	c_node = *lst;
	while (c_node->next != NULL)
	{
		c_node = c_node->next;
	}
	c_node->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*n_adrs;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		n_adrs = (*lst)->next;
		free(*lst);
		*lst = n_adrs;
	}
	*lst = NULL;
}

int	stack_len(t_list *stack)
{
	int		counter;
	t_list	*ptr;

	counter = 0;
	ptr = NULL;
	ptr = stack;
	while (ptr)
	{
		ptr->index = counter;
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}
