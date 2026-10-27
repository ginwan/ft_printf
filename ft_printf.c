/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 12:31:50 by gelgasim          #+#    #+#             */
/*   Updated: 2026/10/26 14:06:31 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

static int	ft_printprecent(void)
{
	write(1, "%", 1);
	return (1);
}

static int	ft_handle_format(va_list arg, char const format)
{
	int		print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(arg, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(arg, char *));
	else if (format == '%')
		print_len += ft_printprecent();
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		print_len += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (format == 'p')
		print_len += ft_putptr(va_arg(arg, void *));
	else if (format == 'x')
		print_len += ft_puthex_lower(va_arg(arg, unsigned int));
	else if (format == 'X')
		print_len += ft_puthex_upper(va_arg(arg, unsigned int));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	va_start(args, str);
	i = 0;
	print_len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_len += ft_handle_format(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// int	main(void)
// {
// 	printf("=== Character ===\n");
// 	printf("printf:    %c\n", 'A');
// 	ft_printf("ft_printf: %c\n", 'A');
// 	printf("\n=== String ===\n");
// 	printf("printf:    %s\n", "Hello");
// 	ft_printf("ft_printf: %s\n", "Hello");
// 	printf("\n=== Percent ===\n");
// 	printf("printf:    %%\n");
// 	ft_printf("ft_printf: %%\n");
// 	printf("\n=== Decimal (d) ===\n");
// 	printf("printf:    %d\n", 42);
// 	ft_printf("ft_printf: %d\n", 42);
// 	printf("\n=== Integer (i) ===\n");
// 	printf("printf:    %i\n", 9);
// 	ft_printf("ft_printf: %i\n", -42);
// 	printf("\n=== Unsigned (u) ===\n");
// 	printf("printf:    %u\n", UINT_MAX);
// 	ft_printf("ft_printf: %u\n", UINT_MAX);
// 	printf("\n=== Pointer (p) ===\n");
// 	int n = 42;
// 	printf("printf:   %p\n", (void *)&n);
// 	ft_printf("ft_printf: %p\n", (void *)&n);
// 	printf("\n=== Hex lowercase (x) ===\n");
// 	printf("printf:   %x\n", -42);
// 	ft_printf("ft_printf: %x\n", -42);
// 	printf("\n=== Hex uppercase (X) ===\n");
// 	printf("printf:   %X\n", 42);
// 	ft_printf("ft_printf: %X\n", 42);
// 	return (0);
// }
