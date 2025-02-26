/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:02:09 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/02 17:09:01 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		fill_the_stack(&a, av);
		if (!sorted(a))
			sort(&a, &b);
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
	return (0);
}
