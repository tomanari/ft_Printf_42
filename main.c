/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomanar <mtomanar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:19:18 by mtomanar          #+#    #+#             */
/*   Updated: 2026/07/14 18:03:46 by mtomanar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	int		*ptr;

	a = 42;
	ptr = &a;
	printf("--- Testando %%p ---\n");
	printf("Original: %p\n", ptr);
	ft_printf("Meu: %p\n", ptr);
	printf("--- Testando %%x ---\n");
	printf("Original: %x\n", 3000);
	ft_printf("Meu:%x\n", 3000);
	printf("%u \n", -1);
	ft_printf("%u \n", -1);
	// printf(" %x \n", 9223372036854775807LL);
	// ft_printf(" %x ", 9223372036854775807LL);
	return (0);
}
