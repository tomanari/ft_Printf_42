/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:14:33 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 20:46:14 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(int nbr);
unsigned int	ft_un_putnbr(unsigned int nbr);
int				ft_puthex_base(unsigned long nbr, char *base);
int				ft_parser(char specifier, va_list *args);
int				h_str(char spec, va_list *args);
int				h_nbr(char spec, va_list *args);
int				h_un_nbr(char spec, va_list *args);
int				h_char(char spec, va_list *args);
int				h_percent(char spec, va_list *args);
int				h_hex(char spec, va_list *args);
int				h_ptr(char spec, va_list *args);
typedef int	(*t_prtfunc)(char spec, va_list*);

typedef struct s_dict
{
	char		specifier;
	t_prtfunc	func;
}				t_dict;

#endif