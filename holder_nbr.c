
#include "ft_printf.h"

void    ft_putnbr(int nbr)
{
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    ft_putchar (nbr % 10 + '0');
}