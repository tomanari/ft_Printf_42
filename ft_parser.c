
#include "ft_printf.h"

// int	ft_parser(char specifier, va_list *args)
// {
// 	static int (*table[256])(va_list *args);
// 	static int init;
	
// 	if (!init)
// 	{
// 		table['s'] = h_str;
// 		table['i'] = h_nbr;

// 		init = 1;
// 	}
// 	if (table[(unsigned char)specifier] != NULL)
// 		return (table[(unsigned char)specifier](args));
// 	return (0);
// }

int	ft_parser(char spec, va_list *args)
{
	int	i;
	t_dict dict[] = {
		{'c', h_char},
		{'s', h_str},
		{'d', h_nbr},
		{'i', h_nbr},
		{0, NULL},
	};

	i = 0;
	while (dict[i].specifier != 0)
	{
		if (dict[i].specifier == spec)
			return (dict[i].func(args));
		i++;
	}
	return (0);
}