
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start (arg, format);
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
