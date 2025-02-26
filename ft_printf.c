/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkasimi <nkasimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:50:29 by nkasimi           #+#    #+#             */
/*   Updated: 2025/01/28 17:08:41 by nkasimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c, int *counter, int fd)
{
	write(fd, &c, 1);
	(*counter)++;
}

void	ft_putstr(char *str, int *counter, int fd)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, counter, fd);
		str++;
	}
}

void	ft_putnbr(int nb, int *counter, int fd)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', counter, fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, counter, fd);
	}
	ft_putchar(n % 10 + '0', counter, fd);
}

void	format_specifier(va_list arguements, char specifier, int *counter,
		int fd)
{
	if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(arguements, int), counter, fd);
	else if (specifier == 's')
		ft_putstr((char *)va_arg(arguements, char *), counter, fd);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	arguements;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(arguements, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format_specifier(arguements, str[i], &counter, fd);
		}
		else
			ft_putchar(str[i], &counter, fd);
		i++;
	}
	va_end(arguements);
	return (counter);
}
