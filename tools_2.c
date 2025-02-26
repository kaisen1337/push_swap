/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:46 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/28 17:19:17 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complite_rotation(t_list **a, t_list **b, t_list *best_node)
{
	if (best_node->above_m)
		while (best_node != *b)
			rb(b);
	else if (!best_node->above_m)
		while (best_node != *b)
			rrb(b);
	if (best_node->target->above_m)
		while (best_node->target != *a)
			ra(a);
	else if (!best_node->target->above_m)
		while (best_node->target != *a)
			rra(a);
}

void	return_to_a(t_list **a, t_list **b)
{
	t_list	*best_node;

	best_node = find_best_price(*b);
	if (!best_node)
		return ;
	if (best_node->above_m && best_node->target->above_m)
	{
		while (best_node != *b && best_node->target != *a)
			rr(b, a);
	}
	else if (!best_node->above_m && !best_node->target->above_m)
	{
		while (best_node != *b && best_node->target != *a)
			rrr(b, a);
	}
	number_position(*a);
	number_position(*b);
	complite_rotation(a, b, best_node);
	pa(a, b);
}

t_list	*min_n(t_list **stack)
{
	t_list	*ptr;
	t_list	*small_node;

	ptr = NULL;
	ptr = *stack;
	small_node = ptr;
	while (ptr)
	{
		if (ptr->content < small_node->content)
			small_node = ptr;
		ptr = ptr->next;
	}
	return (small_node);
}

void	sort_min(t_list **a)
{
	while (min_n(a) != (*a))
	{
		if (min_n(a)->above_m)
			ra(a);
		else
			rra(a);
	}
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf(1, "rrb\n");
}
