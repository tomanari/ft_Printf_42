/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:14:51 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 21:05:25 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nbr)
{
	int				count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	h_nbr(char spec, va_list *args)
{
	int	nbr;

	(void)spec;
	nbr = va_arg(*args, int);
	return (ft_putnbr(nbr));
}

int	h_un_nbr(char spec, va_list *args)
{
	unsigned int	nbr;

	(void)spec;
	nbr = va_arg(*args, unsigned int);
	return (ft_putnbr(nbr));
}

int	ft_puthex_base(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex_base(nbr / 16, base);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	h_hex(char spec, va_list *args)
{
	unsigned long int	num;
	char				*base;
	int					res;
	void				*ptr;

	res = 0;
	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (spec == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
			return (ft_putstr("(nil)"));
		num = (unsigned long int)ptr;
		res += ft_putstr("0x");
		res += ft_puthex_base(num, base);
	}
	else if (spec == 'x' || spec == 'X')
	{
		num = va_arg(*args, unsigned int);
		res += ft_puthex_base(num, base);
	}
	return (res);
}
