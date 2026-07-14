
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		a;
	int		*ptr;
	int		*null_ptr;

	a = 42;
	ptr = &a;
	//null_ptr = NULL;

	// --- TESTANDO O %p ---
	printf("--- Testando %%p ---\n");
	printf("Original: %p\n", ptr);
	ft_printf("Meu: %p\n", ptr);
	
	// --- TESTANDO O %x ---
	printf("--- Testando %%x ---\n");
	printf("Original: %x\n", 3000);
	ft_printf("Meu:%x\n", 3000);
  return 0;
}