/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:06:53 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/19 17:18:35 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s && s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (n < 0)
	{
		i = ft_putchar ('-');
		n *= -1;
		i += ft_putnbr(n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr (n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	else if (n >= 0 && n < 10)
		i += ft_putchar (n % 10 + '0');
	return (i);
}

int	ft_putunsnbr(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		i = ft_putchar ('-');
		n *= -1;
		i += ft_putnbr(n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr (n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	else if (n >= 0 && n < 10)
		i += ft_putchar (n % 10 + '0');
	return (i);
}
