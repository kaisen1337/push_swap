/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:24:51 by nkasimi           #+#    #+#             */
/*   Updated: 2025/02/02 17:08:37 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_checker(char **s)
{
	if (ch_checker(s))
		return (1);
	else if (sign_checker(s))
		return (1);
	return (0);
}

void	put_in_stack(t_list **stack, int number)
{
	t_list	*node;

	node = ft_lstnew(number);
	ft_lstadd_back(stack, node);
}

t_list	put(t_list **stack, char **av, int number)
{
	int	i;

	i = 0;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		put_in_stack(stack, number);
		i++;
	}
	return (**stack);
}

void	fill_the_stack(t_list **list, char **av)
{
	char	**arr;
	long	number;

	int (i), (j);
	i = 1;
	while (av[i])
	{
		j = 0;
		arr = ft_split(av[i++], ' ');
		if (str_checker(arr))
			exit((ft_printf(2, "Error\n"), ft_lstclear(list), free(arr), 1));
		if (error_checker(arr))
			exit((ft_printf(2, "Error\n"), free_sp(arr), ft_lstclear(list), 1));
		while (arr[j])
		{
			if (check_min_max(arr[j], &number))
				exit((ft_printf(2, "Error\n", 1), free_sp(arr),
						ft_lstclear(list), 1));
			j++;
		}
		put(list, arr, number);
		free_sp(arr);
	}
	if (dup_error(list))
		exit((ft_printf(2, "Error\n", 1), ft_lstclear(list), 1));
}

int	sorted(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
