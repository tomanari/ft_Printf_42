
#include "ft_printf.h"

int	ft_parser(char spec, va_list *args)
{
	int			i;
	t_dict	dict[] = {
		{'c', h_char},
		{'s', h_str},
	//	{'p', h_ptr},
		{'d', h_nbr},
		{'i', h_nbr},
	//	{'u', h_hex},
	//	{'x', h_hex},
	//	{'X', h_hex},
		{'%', h_percent},
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
