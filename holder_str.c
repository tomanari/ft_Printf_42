#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (c);
}

int	ft_putstr(char *str)
{
	int count = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

int	hold_str(va_list *args)
{
	return (ft_putstr(va_arg(*args, char *)));
}

