/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:15:00 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 17:34:01 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

int	h_char(char spec, va_list *args)
{
	char	c;

	(void)spec;
	c = va_arg(*args, int);
	return (ft_putchar(c));
}

int	h_str(char spec, va_list *args)
{
	char	*str;

	(void)spec;
	str = va_arg(*args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	h_percent(char spec, va_list *args)
{
	(void)spec;
	(void)args;
	return (ft_putchar ('%'));
}
