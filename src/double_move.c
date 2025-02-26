/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:31:56 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/27 10:42:10 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list **stack_b, t_list **stack_a)
{
	swap(stack_a);
	swap(stack_b);
}

void	double_re_rotate(t_list **stack_2, t_list **stack_1)
{
	reverse_rotate(stack_1);
	reverse_rotate(stack_2);
}

void	double_rotate(t_list **stack_2, t_list **stack_1)
{
	rotate(stack_1);
	rotate(stack_2);
}
