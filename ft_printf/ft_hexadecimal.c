/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:05:58 by melcuman          #+#    #+#             */
/*   Updated: 2023/11/25 18:43:51 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned long nbr, char *s)
{
	int		i;

	i = 0;
	if (nbr > 15)
		i += ft_hexadecimal(nbr / 16, s);
	i += ft_putchar(s[nbr % 16]);
	return (i);
}
