/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:59:47 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/27 11:07:07 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s, char *z)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != z[i])
			return (s[i] - z[i]);
		i++;
	}
	return (0);
}

long	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+')
	{
		i++;
	}
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
