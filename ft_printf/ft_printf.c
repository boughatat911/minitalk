/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:08:20 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/19 17:24:48 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find(va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (c == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putadd(va_arg(args, unsigned long));
	}
	else if (c == 'i' || c == 'd')
		i = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i = ft_putunsnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		i = ft_put_low_hexa(va_arg(args, unsigned int));
	else if (c == 'X')
		i = ft_put_up_hexa(va_arg(args, unsigned int));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
	return (i);
}

int	ft_printf(const	char *str, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				total += ft_find(args, str[++i]);
		}
		else
			total += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (total);
}
