/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:29:44 by manguita          #+#    #+#             */
/*   Updated: 2024/12/06 18:23:47 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int					format_type(va_list argument, const char letter);
int					ft_printf(const char *content, ...);
int					print_char(int c);
int					print_string(char *s);
int					print_pointer(void *p);
int					print_hexadecimal(unsigned long long n, char c);
int					print_unsigned(unsigned int n);
int					print_int(int num);
unsigned long long	aux(unsigned long long n, unsigned int m);

#endif
