/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:16:42 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/15 19:57:00 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}
/*
int main()
{
	int i = 0;
	int tab[] = {1 , 2, 3, 4, 5, 6, 7};
	char str[] = "Hello, World!";
	printf("Before function : %s\n", str);
	ft_memset(str, 'S', 5);
	printf("After function : %s\n", str);
	printf("With OG function : %s\n", (char *)memset(str, 'S', 5));
	ft_memset(tab, 0, 4 * sizeof(int));
	while (i < 7)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}*/