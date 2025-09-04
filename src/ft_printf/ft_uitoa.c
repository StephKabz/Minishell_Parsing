/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:24:37 by kingstephan       #+#    #+#             */
/*   Updated: 2025/04/21 16:50:51 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_count(unsigned int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	itoa_fill(char *str, unsigned int nb, int index)
{
	while (nb > 0)
	{
		str[index] = (nb % 10) + '0';
		nb = nb / 10;
		index--;
	}
}

char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*str;

	size = num_count(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	else
		itoa_fill(str, n, size - 1);
	return (str);
}
/*
int main()
{
    int n = 545454;
    int n2 = -4000565;
    char *str = ft_itoa(n);
    char *str2 = ft_itoa(n2);
    printf("%s\n", str);
    printf("%s\n", str2);
    free(str);
    free(str2);
    return (0);
}*/
