/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:52:08 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/28 21:43:58 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_w_counter(char const *s, char c)
{
	int	i;
	int	k;
	int	counter;

	i = 0;
	k = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			k = 0;
		}
		else
		{
			if (k == 0)
				counter++;
			k = 1;
		}
		i++;
	}
	return (counter);
}

char	*ft_strdup(const char *s)
{
	char	*a;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	a = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (s[i])
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*a;
	unsigned int	n;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	if (start >= n)
		return (ft_strdup(""));
	if (len > n - start)
		len = n - start;
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	*free_sp(char **a)
{
	int	i;

	i = 0;
	if (!a)
		return (NULL);
	while (a[i])
		free(a[i++]);
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	int (i), (k), (start);
	if (!s)
		return (NULL);
	splitted = malloc((ft_w_counter(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			splitted[k++] = ft_substr(s, start, i - start);
		if (!splitted)
			free_sp(splitted);
	}
	splitted[k] = NULL;
	return (splitted);
}
