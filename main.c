
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("Olá %s\n","marcella");
	ft_printf("Olá %c %c \n", 'B', 97);
	ft_printf("Olá %i\n", -214748367);
	printf("Olá %d\n", -21474836);
	ft_printf("%%,sera %% que foi?\n");
	printf("%%,sera  %% que foi?\n");
    return 0;
}