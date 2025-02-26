/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:33:44 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/02 17:21:52 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_rank(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		rank;

	current = stack;
	while (current)
	{
		rank = 1;
		compare = stack;
		while (compare)
		{
			if (compare->content < current->content)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

int	count_spleter(t_list *a)
{
	float	spleter;

	spleter = 4.5;
	if (stack_len(a) <= 100)
		spleter = 3.5;
	return (spleter);
}

void	divide(t_list **a, t_list **b)
{
	float	spleter;

	spleter = stack_len(*a) / count_spleter(*a);
	give_rank(*a);
	while (stack_len(*a) > 3 && !sorted(*a))
	{
		if ((*a)->rank <= spleter)
		{
			pb(b, a);
			give_rank(*a);
			spleter = stack_len(*a) / count_spleter(*a);
		}
		else
			ra(a);
	}
}

void	sort_3(t_list **a)
{
	t_list	*x;

	x = NULL;
	x = *a;
	if (x->content > ft_lstlast(x)->content)
	{
		ra(a);
		sort_3(a);
	}
	else if (x->content > x->next->content)
		sa(a);
	else if (x->next->content > ft_lstlast(x)->content)
	{
		sa(a);
		ra(a);
	}
}

void	sort(t_list **a, t_list **b)
{
	divide(a, b);
	sort_3(a);
	while (stack_len(*b) > 0)
	{
		put_data(*b, *a);
		return_to_a(a, b);
		put_data(*b, *a);
	}
	sort_min(a);
}
