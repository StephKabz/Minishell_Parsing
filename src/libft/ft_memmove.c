/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:22:10 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 13:29:56 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*sc;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	if ((dst < sc) || (dst >= sc + n))
	{
		i = 0;
		while (i < n)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dst[n] = sc[n];
	}
	return ((void *)dst);
}

/*
int main()
{
	char str[] = "Hello, World!";
	char *str2 = "Magic, World!";
	printf("Before function : %s\n", str);
	ft_memmove(str + 7, str2, 14);
	printf("After function : %s\n", str);
	printf("After function : %s\n", memmove(str + 7, str2, 14));
	return (0);
}*/
