/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:37:21 by mel-ayou          #+#    #+#             */
/*   Updated: 2023/12/25 18:07:37 by mel-ayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putunbr(unsigned long number)
{
	int counter;

	counter = 0;
	if (number >= 10)
	{
		counter += ft_printf_putnbr(number / 10);
		counter += ft_printf_putchr((number % 10) + '0');
	}
	else
		counter += ft_printf_putchr(number + '0');
	return (counter);
}