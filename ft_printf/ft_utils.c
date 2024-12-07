/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by manguita          #+#    #+#             */
/*   Updated: 2024/12/06 20:31:03 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[n])
		n++;
	write(1, s, n);
	return (n);
}

unsigned long long	aux(unsigned long long n, unsigned int m)
{
	unsigned long long	suffix;

	suffix = 1;
	if (n == 0)
		return (0);
	while (n / m)
	{
		n /= m;
		suffix *= m;
	}
	return (suffix);
}

int	print_pointer(void *p)
{
	unsigned long long	suf;
	unsigned long		address;
	int					size;

	if (!p)
		return (write(1, "(nil)", 5));
	address = (unsigned long)p;
	suf = aux(address, 16);
	size = 0;
	size += print_string("0x");
	if (address == 0)
		size += print_char('0');
	while (suf)
	{
		if ((address / suf) < 10)
			size += print_char((address / suf) + '0');
		else
			size += print_char((address / suf) + 'a' - 10);
		address -= (address / suf) * suf;
		suf /= 16;
	}
	return (size);
}

int	print_hexadecimal(unsigned long long n, char c)
{
	unsigned long long	suf;
	int					size;

	suf = aux(n, 16);
	size = 0;
	if (n == 0)
		return (print_char('0'));
	while (suf)
	{
		if ((n / suf) < 10)
			size += print_char((n / suf) + '0');
		else
		{
			if (c == 'x')
				size += print_char((n / suf) + 'a' - 10);
			else
				size += print_char((n / suf) + 'A' - 10);
		}
		n -= (n / suf) * suf;
		suf /= 16;
	}
	return (size);
}
