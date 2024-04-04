/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:26:53 by murathanelc       #+#    #+#             */
/*   Updated: 2024/04/04 13:54:37 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_atoi(const char *s)
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

void	bit_handler(int pid, char str)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((str >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
		
}


int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	if (argc == 3)
	{
		str = argv[2];
		if (!str)
			ft_error();
		pid = ft_atoi(argv[1]);
		if (pid < 0)
			ft_error();
		i = 0;
		while (str[i])
		{
			bit_handler(pid, str[i]);
			i++;
		}
	}
	else
		ft_error();
	return (0);
}
