/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:27:55 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/17 15:15:52 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	if (!dst || !src)
		return (0);
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size <= size_dst)
		return (size_src + size);
	i = 0;
	while (src[i] && size_dst + i < size - 1)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}

/*
#include <stdio.h>
int main()
{
    const char *src = "Le lapin rouge!";
    char dest[50] = "Je prend!";
    size_t size = 5;
    printf("%zu\n", ft_strlcat(dest, src, size));
    return (0);
}*/
