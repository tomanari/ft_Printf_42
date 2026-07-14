
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

int	h_nbr(char spec, va_list *args)
{
	int	nbr;

	(void)spec;
	nbr = va_arg(*args, int);
	if (!nbr)
		return (ft_putstr("(null)"));
	return (ft_putnbr(nbr));
}

int	ft_puthex_base(unsigned long nbr, char *base)
{
	int	res;

	res = 0;
	if (nbr >= 16)
	{
		res += ft_puthex_base(nbr / 16, base);
		res += ft_puthex_base(nbr % 16, base);
	}
	res += ft_putchar(base[nbr]);
	return (res);
}

int	h_hex(char spec, va_list *args)
{
	unsigned long int	num;
	char							*base;

	num = va_arg(*args, long int);
	if (!spec)
		return (ft_putstr("(null)"));
	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_puthex_base(num, base));
}

int	h_ptr(char spec, va_list *args)
{
	unsigned long	ptr;
	int						res;

	(void)spec;
	res = 0;
	ptr = (unsigned long)va_arg(*args, void *);
	if (ptr == 0)
	{
		res += ft_putstr("(nil)");
		return (res);
	}
	res += ft_putstr("0x");
	res += ft_puthex_base(ptr, "0123456789abcdef");
	return (res);
}
