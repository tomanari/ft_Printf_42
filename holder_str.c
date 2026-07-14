#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (c);
}

int	ft_putstr(char *str)
{
	int count;
	
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
	if (!c)
		return(ft_putstr("(null)"));
	return (ft_putchar(c));
}

int	h_str(char spec, va_list *args)
{
	char *str;

	(void)spec;
	str = va_arg(*args, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	h_percent(char spec, va_list *args)
{
	(void)args;
	return (ft_putchar ('%'));
}
