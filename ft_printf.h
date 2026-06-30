
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);
int		ft_putchar(int c);
char	ft_putstr(char *str);

#endif