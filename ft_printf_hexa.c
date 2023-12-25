/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:27:42 by mel-ayou          #+#    #+#             */
/*   Updated: 2023/12/25 18:09:32 by mel-ayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(unsigned int number, int base)
{
	int	tmp;
	int	counter;

	counter = 0;
	if (number > 15)
		counter += ft_printf_hexa(number / 16, base);
	tmp = number % 16;
	if (tmp < 10)
		counter += ft_printf_putchr(tmp + '0');
	else if (tmp >= 10)
		counter += ft_printf_putchr(tmp + base);
	return (counter);
}
