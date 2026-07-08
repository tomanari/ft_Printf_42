
#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;
	long int	lnbr;

	lnbr = nbr;
	count = 0;
	if (lnbr < 0)
	{
		count += ft_putchar('-');
		lnbr *= -1;
	}
	if (lnbr > 9)
	{
		count += ft_putnbr(lnbr / 10);
	}
	count += ft_putchar (lnbr % 10 + '0');
	return (count);
}

int	h_nbr(va_list *args)
{
	char	nbr;

	nbr = va_arg(*args, int);
	if (!nbr)
		return (ft_putstr("(null)"));
	return (ft_putnbr(nbr));
}