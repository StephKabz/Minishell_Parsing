/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 23:41:04 by kingstephan       #+#    #+#             */
/*   Updated: 2025/04/21 16:50:32 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_maj(va_list args)
{
	unsigned int	i;
	int				index;
	char			*hex_maj;
	char			str[50];

	i = va_arg(args, unsigned int);
	hex_maj = "0123456789ABCDEF";
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	index = 0;
	while (i > 0)
	{
		str[index++] = hex_maj[i % 16];
		i /= 16;
	}
	str[index] = '\0';
	reverse_str(str);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_hex(va_list args)
{
	unsigned int	i;
	int				index;
	char			*hex_min;
	char			str[50];

	i = va_arg(args, unsigned int);
	hex_min = "0123456789abcdef";
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	index = 0;
	while (i > 0)
	{
		str[index++] = hex_min[i % 16];
		i /= 16;
	}
	str[index] = '\0';
	reverse_str(str);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_void(va_list args)
{
	char				*hex_adress;
	unsigned long long	i;
	int					index;
	char				str[50];
	void				*ptr;

	ptr = va_arg(args, void *);
	i = (unsigned long long)ptr;
	hex_adress = "0123456789abcdef";
	if (i == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	index = 0;
	while (i > 0)
	{
		str[index++] = hex_adress[i % 16];
		i = i / 16;
	}
	str[index] = '\0';
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(reverse_str(str), 1);
	return (ft_strlen(str) + 2);
}
