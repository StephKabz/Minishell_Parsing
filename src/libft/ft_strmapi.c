/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:47:45 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 11:05:23 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s) + 1;
	str = malloc((size) * (sizeof(char)));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	ft_touppercase(unsigned int b, char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

int main()
{
	char *str = "Le lapin rouge!";
	char *new_str = ft_strmapi(str, ft_touppercase);
	printf("%s\n", new_str);
	free(new_str);
	return (0);
}*/
