/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:33:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/03/14 01:33:50 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../ft_printf/ft_printf.h"

int	ft_checkunicode(unsigned char c)
{
		// 0x80 - 0xBF → Used only as continuation bytes (never start a character).
		// 0xC0 - 0xDF → Start of 2-byte UTF-8 characters.
		// 0xE0 - 0xEF → Start of 3-byte UTF-8 characters.
		// 0xF0 - 0xF7 → Start of 4-byte UTF-8 characters.
		// 0xF8 - 0xFF → Invalid in UTF-8, reserved for future use.
	if (c < 0x80) // 0x80 == 128
		return (1);
	else if ((c & 0xe0) == 0xc0) // 0xe0 == 224 || 0xc0 == 192 || 
		return (2);
	else if ((c & 0xf0) == 0xe0) // 0xe0 == 224  || // 0xf0 == 240 
		return (3);
	else if ((c & 0xf8) == 0xf0) // 0xf0 == 240 
		return (4);
	return (0);
}

int	print(int *counter, char *result, int *pid, int *index)
{
	static unsigned char	unicode[8];
	static int				b_nbr;

	if (++(*counter) == 8)
	{
		if (*index == 0)
			b_nbr = ft_checkunicode(*result);
		unicode[(*index)++] = *result;
		if (--b_nbr == 0)
		{
			unicode[*index] = '\0';
			ft_printf("%s", unicode);
			*index = 0;
			kill (*pid, SIGUSR1);
		}
		if (*result == '\0')
		{
			kill (*pid, SIGUSR2);
			write(1, "\n", 1);
		}
		*counter = 0;
		*result = 0;
	}
	return (0);
}

void	signal_handle(int signum, siginfo_t *info, void *vd)
{
	static int			counter;
	static char			result;
	static pid_t		pid;
	static int			index;

	(void)vd;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		counter = 0;
		result = 0;
		index = 0;
	}
	if (signum == SIGUSR2)
		result |= (0b10000000 >> counter);
	if (print(&counter, &result, &pid, &index) == 1)
		return ;
}

int	main(void)
{
	struct sigaction	ssignal;

	ft_printf("\n Server pid ==>  %d\n", getpid());
	ssignal.sa_sigaction = signal_handle;
	ssignal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ssignal, 0);
	sigaction(SIGUSR2, &ssignal, 0);
	while (1)
		pause();
	return (0);
}
