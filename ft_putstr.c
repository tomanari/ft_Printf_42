
#include "ft_printf.h"

char	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	return (*str);
}

int main(void)
{
	ft_putstr("ola\n");
	return 0;
}