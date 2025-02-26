/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:55:29 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/28 17:17:33 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	rotate(stack);
	ft_printf(1, "ra\n");
}

void	rb(t_list **stack)
{
	rotate(stack);
	ft_printf(1, "rb\n");
}

void	rr(t_list **stack_2, t_list **stack_1)
{
	rotate(stack_1);
	rotate(stack_2);
	ft_printf(1, "rr\n");
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf(1, "rra\n");
}
