/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:11:19 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/21 16:50:25 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	int		i;
	char	*str;
	int		len;

	i = va_arg(args, int);
	str = ft_itoa(i);
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	return (len);
}

int	print_unsigned_int(va_list args)
{
	unsigned int	i;
	char			*str;
	int				len;

	i = va_arg(args, unsigned int);
	str = ft_uitoa(i);
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
