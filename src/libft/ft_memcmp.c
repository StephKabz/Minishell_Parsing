/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:23:17 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 18:16:46 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*src1;
	const unsigned char	*src2;

	if (!s1 && !s2)
		return (0);
	if (!s2)
		return (1);
	if (!s1)
		return (-1);
	if (n == 0)
		return (0);
	src1 = (const unsigned char *)s1;
	src2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char str[50] = "Le lapin mange!";
	char str2[50] = "Le mapin mange!";
	printf("My function gives : %d\n", ft_memcmp(str, str2, INT_MAX + 1000));
	printf("The function gives : %d\n", memcmp(str, str2, INT_MAX + 1000));
	return (0);
}*/