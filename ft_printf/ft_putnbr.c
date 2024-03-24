/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:49 by melcuman          #+#    #+#             */
/*   Updated: 2023/11/25 18:29:25 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nbr)
{
	long	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		i++;
	}
	if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	else
	{
		i += ft_putchar(nbr + '0');
	}
	return (i);
}
