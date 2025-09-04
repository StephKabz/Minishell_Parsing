/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:57:18 by stkabang          #+#    #+#             */
/*   Updated: 2025/06/23 17:07:04 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int printf_check_sign(char sign, va_list args)
{
	if (sign == 'c')
		return (print_char(args));
	else if (sign == 's')
		return (print_string(args));
	else if (sign == 'i' || sign == 'd')
		return (print_int(args));
	else if (sign == 'x')
		return (print_hex(args));
	else if (sign == 'X')
		return (print_hex_maj(args));
	else if (sign == 'u')
		return (print_unsigned_int(args));
	else if (sign == 'p')
		return (print_void(args));
	else if (sign == '%')
		return (print_percent());
	return (0);
}

int ft_printf(const char *string, ...)
{
	va_list args;
	int i;
	int printed;

	va_start(args, string);
	i = 0;
	printed = 0;
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			printed += printf_check_sign(string[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			printed++;
			i++;
		}
	}
	va_end (args);
	return (printed);
}
