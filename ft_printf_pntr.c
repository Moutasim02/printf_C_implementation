/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pntr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:26:31 by mel-ayou          #+#    #+#             */
/*   Updated: 2023/12/25 17:57:16 by mel-ayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pntr(unsigned long number)
{
	int	tmp;
	int	counter;

	counter = 0;
	if (number > 15)
		counter += ft_printf_pntr(number / 16);
	tmp = number % 16;
	if (tmp < 10)
		counter += ft_printf_putchr(tmp + '0');
	else if (tmp >= 10)
		counter += ft_printf_putchr(tmp + 'W');
	return (counter);
}
