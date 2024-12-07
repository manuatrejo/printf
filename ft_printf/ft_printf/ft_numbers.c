/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:53:17 by manguita          #+#    #+#             */
/*   Updated: 2024/12/03 20:38:57 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	unsigned long long	suf;
	int					size;

	size = 0;
	suf = aux(n, 10);
	if (n == 0)
		size += print_char('0');
	while (suf)
	{
		size += print_char((n / suf) + '0');
		n -= (n / suf) * suf;
		suf /= 10;
	}
	return (size);
}

int	print_int(int n)
{
	unsigned long long	suf;
	int					size;

	size = 0;
	if (n == 0)
		size += print_char('0');
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		size += print_char('-');
	}
	suf = aux(n, 10);
	while (suf)
	{
		size += print_char((n / suf) + '0');
		n -= (n / suf) * suf;
		suf /= 10;
	}
	return (size);
}
