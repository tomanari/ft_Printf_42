/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:42:26 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 17:42:43 by mtomanar         ###   ########.fr       */
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

	num = va_arg(*args, long int);
	if (!spec)
		return (ft_putstr("(null)"));
	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_puthex_base(num, base));
}

int	h_ptr(char spec, va_list *args)
{
	unsigned long	ptr;
	int				res;

	(void)spec;
	res = 0;
	ptr = (unsigned long)va_arg(*args, void *);
	if (ptr == 0)
	{
		res += ft_putstr("(nil)");
		return (res);
	}
	res += ft_putstr("0x");
	res += ft_puthex_base(ptr, "0123456789abcdef");
	return (res);
}