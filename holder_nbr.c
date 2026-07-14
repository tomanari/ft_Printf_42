/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:14:51 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 18:01:22 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		num = nbr * -1;
	}
	else
	{
		num = nbr;
	}
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}

int	h_nbr(char spec, va_list *args)
{
	int	nbr;

	(void)spec;
	nbr = va_arg(*args, int);
	return (ft_putnbr(nbr));
}

unsigned int	ft_un_putnbr(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	h_un_nbr(char spec, va_list *args)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	(void)spec;
	nbr = va_arg(*args, unsigned int);
	if (nbr >= 10)
		count += ft_un_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}