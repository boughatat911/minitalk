/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:33:39 by nbougrin          #+#    #+#             */
/*   Updated: 2025/03/15 20:19:09 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

static int	byte;

int	ft_atoi(const char *str)
{
	long	sign;
	long	num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	else if (*str == '-' || *str == '+')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((num * sign) > 2147483647 || (num * sign) <= 0 )
			return (-1);
		str++;
	}
	return (sign * num);
}

void	connect(int sig)
{
	if (sig == SIGUSR2)
	{
		// ft_printf("sig ==> %d\n", sig); //////////////////////////
		write (1, "Done\n", 5);
		ft_printf("Number of bytes recoverd = %d\n", byte);
	}
	else
		byte++;
}

void	ft_send_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (((c >> (7 - j)) & 1) == 1)/// switch 8 to 7 (7 - j)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(500);
		j++;
	}
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	hdl;
	pid_t				pid;

	if (ac != 3 || ft_atoi(av[1]) <= 0)
	{
		ft_printf ("Input not valid\nEnter pid and comment\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (0); /////////////////////////////////////////
	hdl.sa_handler = connect; // you can use this &connect; ****
	signal(SIGUSR1, connect); //////////////////////////////
	signal(SIGUSR2, connect);///////////////////////////////
	while (av[2][i])
	{
		ft_send_signal(pid, av[2][i]);
		usleep(42);
		i++;
	}
	ft_send_signal(pid, '\0');
}
