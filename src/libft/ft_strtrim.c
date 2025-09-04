/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:37:40 by stkabang          #+#    #+#             */
/*   Updated: 2025/08/14 19:44:37 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *sep)
{
	size_t	start;
	size_t	end;

	if (!s1 || !sep)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(sep, s1[start]) != NULL)
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(sep, s1[end]) != NULL)
		end--;
	return (ft_strndup(s1 + start, end - start + 1));
}
/*
int main()
{
	char *str = "XXXXXXXXhello worldXXXXXXXX";
	char *sep = "X";
	char *new_str = ft_strtrim(str, sep); 
	printf("%s\n", new_str);
	free(new_str);
	return 0;
}*/