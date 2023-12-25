/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:01:11 by mel-ayou          #+#    #+#             */
/*   Updated: 2023/12/25 18:15:18 by mel-ayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formmated(char specifier, va_list list)
{
	int	counter;

	counter = 0;
	if (specifier == 'd' || specifier == 'i')
		counter += ft_printf_putnbr(va_arg(list, int));
	else if (specifier == 'c')
		counter += ft_printf_putchr((char)va_arg(list, int));
	else if (specifier == 's')
		counter += ft_printf_putstr(va_arg(list, char *));
	else if (specifier == 'u')
		counter += ft_printf_putunbr(va_arg(list, unsigned int));
	else if (specifier == 'x')
		counter += ft_printf_hexa(va_arg(list, unsigned int), 'W');
	else if (specifier == 'X')
		counter += ft_printf_hexa(va_arg(list, unsigned int), '7');
	else if (specifier == 'p')
	{
		counter += ft_printf_putstr("0x");
		counter += ft_printf_pntr(va_arg(list, unsigned long));
	}
	else if (specifier == '%')
		counter += ft_printf_putchr('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(list, str);
	while (str[i] != 0)
	{
		if (str[i] != '%')
			counter += ft_printf_putchr(str[i]);
		if (str[i++] == '%')
		{
			counter += print_formmated(str[i], list);
			i++;
		}
	}
	va_end(list);
	return (counter);
}

int	main(void)
{
	ft_printf("Hello %s", "Moutasim");
	return (0);
}
