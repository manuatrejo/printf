/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:52:48 by manguita          #+#    #+#             */
/*   Updated: 2024/10/21 00:49:08 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_type(va_list argument, const char letter)
{
	int	size;

	size = 0;
	if (letter == 'c')
		size += print_char(va_arg(argument, int));
	else if (letter == 's')
		size += print_string(va_arg(argument, char *));
	else if (letter == 'p')
		size += print_pointer(va_arg(argument, void *));
	else if (letter == 'x' || letter == 'X')
		size += print_hexadecimal(va_arg(argument, unsigned long long), letter);
	else if (letter == 'u')
		size += print_unsigned(va_arg(argument, unsigned int));
	else if (letter == 'd' || letter == 'i')
		size += print_int(va_arg(argument, long));
	else
		size += print_char(letter);
	return (size);
}

int	ft_printf(char *content, ...)
{
	va_list	argument;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(argument, content);
	while (content[i])
	{
		if (content[i] == '%')
		{
			size += format_type(argument, content[1 + i++]);
			i++;
		}
		else
			size += print_char(content[i++]);
	}
	va_end(argument);
	return (size);
}
