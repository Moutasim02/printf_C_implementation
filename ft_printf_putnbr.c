/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:19:34 by mel-ayou          #+#    #+#             */
/*   Updated: 2024/01/02 15:46:44 by mel-ayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnbr(int number)
{
	int	counter;

	counter = 0;
	if (number == -2147483648)
	{
		counter += ft_printf_putnbr(number / 10);
		counter += ft_printf_putchr('8');
	}
	else if (number >= 10)
	{
		counter += ft_printf_putnbr(number / 10);
		counter += ft_printf_putchr((number % 10) + '0');
	}
	else if (number < 0)
	{
		counter += ft_printf_putchr('-');
		counter += ft_printf_putnbr(number / -1);
	}
	else
		counter += ft_printf_putchr(number + '0');
	return (counter);
}
