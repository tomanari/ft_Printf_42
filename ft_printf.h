
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
int	h_str(va_list *args);
int	ft_parser(char specifier, va_list *args);
int	h_nbr(va_list *args);
int	h_char(va_list *args);
typedef int	(*t_prtfunc)(va_list*);
int	h_percent(va_list *args);

typedef struct s_dict
{
	char			specifier;
	t_prtfunc	func;
}							t_dict;


#endif