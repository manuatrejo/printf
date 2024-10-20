/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:53:17 by manguita          #+#    #+#             */
/*   Updated: 2024/10/21 01:10:50 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	aux(unsigned long long n, unsigned int m);

int					print_char(int c);

int	print_unsigned(unsigned int n)
{
	unsigned long long	suf;
	int					size;

	size = 0;
	suf = aux(n, 10);
	while (suf)
	{
		size += print_char((n / suf) + '0');
		n -= (n / suf) * suf;
		suf /= 10;
	}
	return (size);
}

int	print_int(long n)
{
	unsigned long long	suf;
	int					size;

	size = 0;
	suf = aux(n, 10);
	if (n < 0)
	{
		n = -n;
		size += print_char('-');
	}
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
