/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:43:47 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 14:18:35 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc;

	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	if (!dst && !sc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return ((void *)dst);
}

/*
int main()
{
	char str[] = "Hello, World!";
	char *str2 = "Magic, World!";
	printf("Before function : %s\n", str);
	ft_memcpy(str, str2, 13);
	printf("After function : %s\n", str);
	return (0);
}*/
