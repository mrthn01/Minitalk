/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:26:53 by murathanelc       #+#    #+#             */
/*   Updated: 2024/03/24 23:43:30 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int global_value = 0;

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - 48);
		i++;
	}
	return (sign * result);
}

void	sig_handler(int signumber, siginfo_t *info, void *context)
{
	static int	i;

	(void) context;
	(void) info;
	i = 0;
	global_value = 1;
	if (signumber == SIGUSR2)
		i++;
	else if (signumber == SIGUSR1)
		ft_printf("Bytes: %d\n", i);
	
}

int	char_to_binary(char c, int pid)
{
	int	i;
	int	bit_index;

	bit_index = 8;
	while (bit_index > 0)
	{
		i = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (global_value == 0)
		{
			if (i == 100) // any number
			{
				ft_printf(" ");
				exit(2);
			}
			i++;
			usleep(100);
		}
		global_value = 0;
		bit_index--;
	}
	return (0);
}


int main(int argc, char **argv)
{
	char	*str;
	int		nbr;

	nbr = ft_atoi(argv[1]);
	str = argv[2];
	if (argc == 3)
	{
		struct sigaction sa;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_sigaction = sig_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_error();
		while (str)
		{
			char_to_binary(*str, nbr);
			str++;
		}
	}
	else
		ft_error();
}

