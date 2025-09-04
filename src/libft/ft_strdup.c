/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:56:28 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 13:03:34 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		dest = malloc(sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
	char *src = "Le Lapin mange!";
	char *src2 = NULL;
	char *dest = ft_strdup(src);
	char *dest2 = ft_strdup(src2);
	printf("Test dest 1 : %s\n", dest);
	printf("Test dest 2 : %s\n", dest2);
	free(dest);
	free(dest2);
	return (0);
}*/