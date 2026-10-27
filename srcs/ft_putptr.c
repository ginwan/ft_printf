/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 08:54:57 by gelgasim          #+#    #+#             */
/*   Updated: 2026/10/25 13:25:30 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long num)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (num < 16)
	{
		count += ft_putchar(hex[num]);
		return (count);
	}
	count += ft_puthex(num / 16);
	count += ft_putchar(hex[num % 16]);
	return (count);
}

int	ft_putptr(void *x)
{
	unsigned long	y;
	int				count;

	if (x == NULL)
		return (ft_putstr("(nil)"));
	y = (unsigned long)x;
	count = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_puthex(y);
	return (count);
}
