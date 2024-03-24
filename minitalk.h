/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:31:59 by murathanelc       #+#    #+#             */
/*   Updated: 2024/03/24 17:31:06 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

void	signal_handler(int signal, siginfo_t *info, void *context);
void	bin_to_char(int signum, char *c);
void	sig_handler(int signumber, siginfo_t *info, void *context);
int		char_to_binary(char c, int pid);
int		ft_atoi(const char *s);
void	ft_error(void);

#endif