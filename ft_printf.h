
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		hold_str(va_list *args);
int		(**get_table(void))(va_list *args);
int		ft_parser(char specifier, va_list *args)

#endif