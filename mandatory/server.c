/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:33:32 by nbougrin          #+#    #+#             */
/*   Updated: 2025/03/04 16:02:29 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

static int	countptr;

void	signal_handl(int signum, siginfo_t *info, void *vd)
{
	static char		result;
	static pid_t	pid;

	(void)vd;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = 0;
		countptr = 0;
		result = 0;
	}
	if (signum == SIGUSR2)
		result |= (0b10000000 >> countptr);
	if (++countptr == 8)
	{
		countptr = 0;
		if (result == '\0')
			return ;
		write (1, &result, 1);
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	ssignal;

	ft_printf("\n Server PID →  \t%d\n", getpid());
	ssignal.sa_sigaction = signal_handl;
	ssignal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ssignal, 0);
	sigaction(SIGUSR2, &ssignal, 0);
	while (1)
		pause();
	return (0);
}
