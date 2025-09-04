/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:24:50 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/17 14:54:52 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_count(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = (long)n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static	void	itoa_fill(char *str, long nb, int index)
{
	while (nb > 0)
	{
		str[index] = (nb % 10) + '0';
		nb = nb / 10;
		index--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	long	nb;
	char	*str;

	nb = (long)n;
	size = num_count(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	else
		itoa_fill(str, nb, size - 1);
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
