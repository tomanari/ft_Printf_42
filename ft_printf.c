
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int 		i;
	int			count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start (arg, format);
	while(*format)
	{
		
	}
	// utilizar va_start, va_arg, va_copy, va_end - para criar os parametros aceitos pela printf
	// ler as flags %
	// diferenciar cada letra de cada flag
	// imprimir va_arg
	return 0;
}