/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:53:11 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/28 17:17:01 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_2, t_list **stack_1)
{
	push_in_stack(stack_2, stack_1);
	ft_printf(1, "pa\n");
}

void	pb(t_list **stack_2, t_list **stack_1)
{
	push_in_stack(stack_2, stack_1);
	ft_printf(1, "pb\n");
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf(1, "sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf(1, "sb\n");
}

void	ss(t_list **stack_b, t_list **stack_a)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf(1, "ss\n");
}
