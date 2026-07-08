
#include "ft_printf.h"

int	ft_prtunsigned(int nbr)
{
	int				res;
	unsigned int	num;

	if (nbr < 0)
	{
		res += ft_putchar('-');
		num = nbr * -1;
	}
	else
	{
		num = nbr;
	}
	res += ft_putnbr(num);
	return (res);
}

int	ft_putnbr(int nbr)
{
	int	count;
	int	lnbr;

	lnbr = nbr;
	count = 0;
	if (lnbr > 9)
	{
		count += ft_putnbr(lnbr / 10);
		count += ft_putchar(lnbr % 10);
	}
	else
	{
		count += ft_putchar(lnbr + '0');
	}
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