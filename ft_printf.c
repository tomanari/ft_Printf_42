/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:14:41 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 18:04:07 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser(char spec, va_list *args)
{
	int				i;
	const t_dict	dict[] = {
	{'c', h_char},
	{'s', h_str},
	{'p', h_ptr},
	{'d', h_nbr},
	{'i', h_nbr},
	{'u', h_un_nbr},
	{'x', h_hex},
	{'X', h_hex},
	{'%', h_percent},
	{0, NULL},
	};

	i = 0;
	while (dict[i].specifier != 0)
	{
		if (dict[i].specifier == spec)
			return (dict[i].func(spec, args));
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_parser(*format, &arg);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
