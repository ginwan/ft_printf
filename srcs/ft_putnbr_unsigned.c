/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 08:16:22 by gelgasim          #+#    #+#             */
/*   Updated: 2026/10/25 12:05:16 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int num)
{
	int			count;

	count = 0;
	if (num < 10)
		count += ft_putchar(num + '0');
	if (num >= 10)
	{
		count += ft_putnbr_unsigned(num / 10);
		count += ft_putnbr_unsigned(num % 10);
	}
	return (count);
}
