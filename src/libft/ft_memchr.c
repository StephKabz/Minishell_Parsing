/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:04:50 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 12:10:38 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		new_c;

	if (!s)
		return (NULL);
	i = 0;
	str = (const unsigned char *)s;
	new_c = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == new_c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
	char *str = "Le Lapin rouge";
	int c = 'n';
	char *str2 = "";
	printf("My function gives 1 : %s\n", (char *)ft_memchr(str, c, 9));
	printf("My function gives 2 : %s\n", (char *)ft_memchr(str2, c, 9));
	printf("The function gives 1 : %s\n", (char *)memchr(str, c, 9));
	printf("The function gives 2 : %s\n", (char *)memchr(str2, c, 9));
	return (0);
}*/