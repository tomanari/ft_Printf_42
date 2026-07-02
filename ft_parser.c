#include "ft_printf.h"

int	ft_parser(char specifier, va_list *args)
{
	static int (*table[256])(va_list *args);
	static int init;
	
	init = 0;
	if (!init)
	{
		table['s'] = hold_str;
		table['i'] = hold_str;

		init = 1;
	}
	if (table[(unsigned char)specifier] != NULL)
		return (table[(unsigned char)specifier](args));
	return (table);
}