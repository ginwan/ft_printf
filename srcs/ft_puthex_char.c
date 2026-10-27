/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:54:38 by gelgasim          #+#    #+#             */
/*   Updated: 2026/10/25 12:16:36 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int num)
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
	count += ft_puthex_lower(num / 16);
	count += ft_putchar(hex[num % 16]);
	return (count);
}

int	ft_puthex_upper(unsigned int num)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (num < 16)
	{
		count += ft_putchar(hex[num]);
		return (count);
	}
	count += ft_puthex_upper(num / 16);
	count += ft_putchar(hex[num % 16]);
	return (count);
}
