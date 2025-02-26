/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:42:06 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/02 19:27:14 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instraction(t_list **s1, t_list **s2, char *instraction)
{
	if (ft_strcmp(instraction, "sa\n") == 0)
		swap(s1);
	else if (ft_strcmp(instraction, "sb\n") == 0)
		swap(s2);
	else if (ft_strcmp(instraction, "ss\n") == 0)
		double_swap(s1, s2);
	else if (ft_strcmp(instraction, "ra\n") == 0)
		rotate(s1);
	else if (ft_strcmp(instraction, "rb\n") == 0)
		rotate(s2);
	else if (ft_strcmp(instraction, "rr\n") == 0)
		double_rotate(s1, s2);
	else if (ft_strcmp(instraction, "rra\n") == 0)
		reverse_rotate(s1);
	else if (ft_strcmp(instraction, "rrb\n") == 0)
		reverse_rotate(s2);
	else if (ft_strcmp(instraction, "rrr\n") == 0)
		double_re_rotate(s1, s2);
	else if (ft_strcmp(instraction, "pb\n") == 0)
		push_in_stack(s2, s1);
	else if (ft_strcmp(instraction, "pa\n") == 0)
		push_in_stack(s1, s2);
	else
		exit((ft_printf(2, "Error\n"), ft_lstclear(s1), ft_lstclear(s2),
				free(instraction), 1));
}

void	n_checker(t_list **s1, t_list **s2)
{
	char	*instraction;

	instraction = get_next_line(0);
	while (instraction)
	{
		apply_instraction(s1, s2, instraction);
		free(instraction);
		instraction = get_next_line(0);
	}
	free(instraction);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		fill_the_stack(&a, av);
		n_checker(&a, &b);
		if (sorted(a) && stack_len(b) == 0)
			ft_printf(1, "OK\n");
		else if (!sorted(a) || stack_len(b) != 0)
			ft_printf(1, "KO\n");
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
	return (0);
}
