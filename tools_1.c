/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:49:08 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/02 16:32:43 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_position(t_list *s)
{
	int	i;
	int	medien;

	i = 0;
	if (!s)
		return ;
	medien = stack_len(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= medien)
			s->above_m = 1;
		else
			s->above_m = 0;
		s = s->next;
		i++;
	}
}

void	get_target(t_list *b, t_list *a)
{
	t_list	*the_target;
	t_list	*x;
	long	index;

	while (b)
	{
		index = LONG_MAX;
		x = a;
		while (x)
		{
			if (b->content < x->content && x->content < index)
			{
				index = x->content;
				the_target = x;
			}
			x = x->next;
		}
		if (index == LONG_MAX)
			b->target = min_n(&a);
		else
			b->target = the_target;
		b = b->next;
	}
}

void	count_price(t_list *b, t_list *a)
{
	int	lena;
	int	lenb;

	lena = stack_len(a);
	lenb = stack_len(b);
	while (a)
	{
		a->n_price = a->index;
		if (!a->above_m)
			a->n_price = lena - (a->index);
		if (a->target->above_m)
			a->ta_price = (a->target->index);
		else
			a->ta_price = lenb - (a->target->index);
		if ((a->above_m && a->target->above_m) || (!a->above_m
				&& !a->target->above_m))
			a->to_price = a->n_price * (a->n_price > a->ta_price) + a->ta_price
				* ((a->n_price <= a->ta_price));
		else
			a->to_price = a->n_price + a->ta_price;
		a = a->next;
	}
}

t_list	*find_best_price(t_list *a)
{
	long	best_price;
	t_list	*node;

	if (!a)
		return (NULL);
	best_price = LONG_MAX;
	while (a)
	{
		if (a->to_price < best_price)
		{
			best_price = a->to_price;
			node = a;
		}
		a = a->next;
	}
	node->best_choice = 1;
	return (node);
}

void	put_data(t_list *b, t_list *a)
{
	number_position(a);
	number_position(b);
	get_target(b, a);
	count_price(a, b);
	find_best_price(b);
}
