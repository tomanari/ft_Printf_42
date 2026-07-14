
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	h_str(char spec, va_list *args);
int	ft_parser(char specifier, va_list *args);
int	h_nbr(char spec, va_list *args);
int	h_char(char spec, va_list *args);
int	h_percent(char spec, va_list *args);
int	ft_puthex_base(unsigned long nbr, char *base);
int	h_hex(char spec, va_list *args);
int	h_ptr(char spec, va_list *args);
typedef int	(*t_prtfunc)(char spec, va_list*);

typedef struct	s_dict
{
	char			specifier;
	t_prtfunc	func;
}								t_dict;

#endif