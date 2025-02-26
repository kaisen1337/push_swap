/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:00:50 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/29 09:10:10 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_stack(t_list **stack_2, t_list **stack_1)
{
	t_list	*first_a;
	t_list	*first_b;

	if (!*stack_1)
		return ;
	first_a = *stack_1;
	*stack_1 = first_a->next;
	first_b = *stack_2;
	first_a->next = first_b;
	*stack_2 = first_a;
}

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack)
		return ;
	if (stack_len(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*seconde;

	if (!*stack)
		return ;
	if (stack_len(*stack) < 2)
		return ;
	first = *stack;
	seconde = first->next;
	*stack = seconde;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*new_last;
	t_list	*first;
	t_list	*ptr;
	t_list	*new_first;

	if (!*stack)
		return ;
	if (stack_len(*stack) < 2)
		return ;
	first = *stack;
	new_first = ft_lstlast(*stack);
	ptr = *stack;
	while (ptr->next != new_first)
	{
		ptr = ptr->next;
	}
	new_last = ptr;
	ptr->next = NULL;
	new_first->next = first;
	*stack = new_first;
}

void	rrr(t_list **stack_2, t_list **stack_1)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
	ft_printf(1, "rrr\n");
}
