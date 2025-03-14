/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:08:14 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/19 00:43:59 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putadd(unsigned long nb);
int	ft_putnbr(int n);
int	ft_putunsnbr(unsigned int n);
int	ft_put_low_hexa(unsigned int nb);
int	ft_put_up_hexa(unsigned int nb);

#endif