/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:48:49 by stkabang          #+#    #+#             */
/*   Updated: 2025/08/14 19:24:20 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strlcat_char(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	if (size > size_dst)
	{
		i = 0;
		while (src[i] && (size_dst + i) < size)
		{
			dst[size_dst + i] = src[i];
			i++;
		}
		dst[size_dst + i] = '\0';
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		size_total;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(size_total * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strlcat_char(str, s1, size_total);
	ft_strlcat_char(str, s2, size_total);
	return (str);
}
/*
int main()
{
	char *str1 = "Tu vois ce ";
	char *str2 = "Lapin dans le jardin!";
	char *new_str = ft_strjoin(str1, str2);
	printf("%s\n", new_str);
	free(new_str);
	return (0);
}*/