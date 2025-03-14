/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:07:44 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/19 17:20:09 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long nb)
{
	unsigned long	total;
	char			*base;

	total = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		total += ft_putadd(nb / 16);
		total += ft_putadd(nb % 16);
	}
	else
		total += ft_putchar(base[nb % 16]);
	return (total);
}

int	ft_put_low_hexa(unsigned int nb)
{
	int		total;
	char	*base;

	total = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		total += ft_put_low_hexa(nb / 16);
		total += ft_put_low_hexa(nb % 16);
	}
	else
		total += ft_putchar(base[nb % 16]);
	return (total);
}

int	ft_put_up_hexa(unsigned int nb)
{
	int		total;
	char	*base;

	total = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		total += ft_put_up_hexa(nb / 16);
		total += ft_put_up_hexa(nb % 16);
	}
	else
		total += ft_putchar(base[nb % 16]);
	return (total);
}
