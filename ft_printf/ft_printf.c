/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melcuman <melcuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:46:18 by melcuman          #+#    #+#             */
/*   Updated: 2023/11/25 18:48:41 by melcuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_hexadecimal(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_hexadecimal(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_hexadecimal(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_type(arg, *(++str));
			str++;
		}
		else
		{
			i += ft_putchar(*str);
			str++;
		}
	}
	va_end(arg);
	return (i);
}
