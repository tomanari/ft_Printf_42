
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		a;
	int		*ptr;
	int		*null_ptr;

	a = 42;
	ptr = &a;
	null_ptr = NULL;

	// --- TESTANDO O %p ---
	printf("--- Testando %%p ---\n");
	printf("Original : %p\n", ptr);
	ft_printf("Original : %p\n", ptr);
	
	ft_printf("%c\n", 99);
	ft_printf("%d\n", 3000);
	printf("%d\n", 3000);
  return 0;
}