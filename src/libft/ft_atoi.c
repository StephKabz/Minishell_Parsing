/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:59:43 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/17 14:04:01 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (-1);
		if (sign == -1 && - result < INT_MIN)
			return (0);
		i++;
	}
	return ((int)(result * sign));
}
/*
int main()
{
	char *nptr = " 	 9999999";
	char *str2 = "   -+21654";
	printf("%d\n", ft_atoi(nptr));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(nptr));
	printf("%d\n", atoi(str2));
	return (0);
}*/