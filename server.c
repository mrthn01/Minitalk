/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:26:49 by murathanelc       #+#    #+#             */
/*   Updated: 2024/03/24 17:23:31 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c = (*c << 1);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static int	pid_id;

	c = 0;
	pid_id = info->si_pid;
	bin_to_char(signal, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid_id, SIGUSR1);
			pid_id = 0;
			return ;
		}
		ft_printf("%c", c);
	}
	kill(pid_id, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	action.sa_sigaction = signal_handler;
	ft_printf("[+]Server PID is: %d\n", getpid());
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	if (sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR1, &action, NULL) == -1)
			ft_error();
	while (1)
		pause();
}
