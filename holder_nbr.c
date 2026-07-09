
#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		num = nbr * -1;
	}
	else
	{
		num = nbr;
	}
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}

int	h_nbr(va_list *args)
{
	int	nbr;

	nbr = va_arg(*args, int);
	if (!nbr)
		return (ft_putstr("(null)"));
	return (ft_putnbr(nbr));
}
