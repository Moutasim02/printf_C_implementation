/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:58:20 by mel-ayou          #+#    #+#             */
/*   Updated: 2023/12/25 17:52:17 by mel-ayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printf_putnbr(int number);
int	ft_printf_putstr(char *str);
int	ft_printf_putchr(char chr);
int	ft_printf_hexa(unsigned int number, int base);
int	ft_printf_putunbr(unsigned long number);
int	ft_printf_pntr(unsigned long number);

#endif