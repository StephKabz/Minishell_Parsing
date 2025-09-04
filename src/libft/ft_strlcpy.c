/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:39:43 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/17 15:07:45 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;

	if (!src || !dst)
		return (0);
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
/*
#include <stdio.h>
int main()
{
    char *src = "Le lapin rouge!";
    char dest[6]; 
    printf("%zu\n", ft_strlcpy(dest, src, sizeof(dest)));
    return (0);
}*/
