/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:42:26 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 20:45:03 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
