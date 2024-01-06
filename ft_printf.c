/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ayou < mel-ayou@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:01:11 by mel-ayou          #+#    #+#             */
/*   Updated: 2024/01/06 05:15:59 by mel-ayou         ###   ########.fr       */
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
/*
#include <stdio.h>

int	main(void)
{
	unsigned long	ptr_value;

	int result, expected;
	// Test 1: String specifier (%s)
	result = ft_printf("Hello %s\n", "Moutasim");
	expected = printf("Hello %s\n", "Moutasim");
	printf("Test 1 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 2: Integer specifier (%d)
	result = ft_printf("Integer: %d\n", 42);
	expected = printf("Integer: %d\n", 42);
	printf("Test 2 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 3: Character specifier (%c)
	result = ft_printf("Character: %c\n", 'A');
	expected = printf("Character: %c\n", 'A');
	printf("Test 3 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 4: Unsigned integer specifier (%u)
	result = ft_printf("Unsigned Integer: %u\n", 12345);
	expected = printf("Unsigned Integer: %u\n", 12345);
	printf("Test 4 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 5: Hexadecimal specifier (%x)
	result = ft_printf("Hexadecimal: %x\n", 255);
	expected = printf("Hexadecimal: %x\n", 255);
	printf("Test 5 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 6: Pointer specifier (%p)
	ptr_value = (unsigned long)&result;
	result = ft_printf("Pointer: %p\n", (void *)ptr_value);
	expected = printf("Pointer: %p\n", (void *)ptr_value);
	printf("Test 6 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 7: Percentage specifier (%%)
	result = ft_printf("Percentage: %%\n");
	expected = printf("Percentage: %%\n");
	printf("Test 7 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 8: Empty String (%s)
	result = ft_printf("Empty String: %s\n", "");
	expected = printf("Empty String: %s\n", "");
	printf("Test 8 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 9: Negative Integer (%d)
	result = ft_printf("Negative Integer: %d\n", -42);
	expected = printf("Negative Integer: %d\n", -42);
	printf("Test 9 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 10: Large Unsigned Integer (%u)
	result = ft_printf("Large Unsigned Integer: %u\n", 4294967295U);
	expected = printf("Large Unsigned Integer: %u\n", 4294967295U);
	printf("Test 10 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 11: Hexadecimal with 'W' format (%x)
	result = ft_printf("Hexadecimal 'W' Format: %x\n", 255);
	expected = printf("Hexadecimal 'W' Format: %x\n", 255);
	printf("Test 11 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 12: Hexadecimal with '7' format (%X)
	result = ft_printf("Hexadecimal '7' Format: %X\n", 255);
	expected = printf("Hexadecimal '7' Format: %X\n", 255);
	printf("Test 12 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 13: Percentage specifier with extra text (%% Extra)
	result = ft_printf("Percentage with Extra: %% Extra\n");
	expected = printf("Percentage with Extra: %% Extra\n");
	printf("Test 13 - Expected: %d, Actual: %d\n\n", expected, result);
	// Test 14: Pointer with NULL value (%p)
	result = ft_printf("Pointer with NULL Value: %p\n", NULL);
	expected = printf("Pointer with NULL Value: 0x0\n");
	printf("Test 14 - Expected: %d, Actual: %d\n\n", expected, result);
	return (0);
}
*/
