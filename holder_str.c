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

int	h_str(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

