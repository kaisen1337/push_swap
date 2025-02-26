/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:02:03 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/30 05:56:53 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_checker(char **s)
{
	if (!s || !s[0])
		return (1);
	return (0);
}

int	ch_checker(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!((s[i][j] >= '0' && s[i][j] <= '9') || s[i][j] == '+'
					|| s[i][j] == '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sign_checker(char **s)
{
	int	i;
	int	j;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '+' || s[i][j] == '-')
			{
				if (s[i][j + 1] == '+' || s[i][j + 1] == '-' || s[i][j
					+ 1] == 32 || s[i][j + 1] == '\0')
					return (1);
				if (j > 0 && s[i][j - 1] >= '0' && s[i][j - 1] <= '9')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_min_max(const char *s, long *number)
{
	*number = ft_atoi(s);
	if (*number < INT_MIN || *number > INT_MAX)
	{
		return (1);
	}
	return (0);
}

int	dup_error(t_list **list)
{
	t_list	*x;
	t_list	*w;
	int		number;
	int		bl;

	x = NULL;
	w = NULL;
	x = *list;
	while (x)
	{
		bl = 0;
		w = *list;
		number = x->content;
		while (w)
		{
			if (w->content == number)
				bl += 1;
			w = w->next;
		}
		if (bl > 1)
			return (1);
		x = x->next;
	}
	return (0);
}
