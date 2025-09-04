/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:14:15 by stkabang          #+#    #+#             */
/*   Updated: 2025/08/14 19:45:42 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_words(char const *str, int c)
{
	size_t	i;
	size_t	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == (char)c)
			i++;
		if (str[i] && str[i] != (char)c)
		{
			count++;
			while (str[i] && str[i] != (char)c)
				i++;
		}
	}
	return (count);
}

static	char	**ft_free_split(char **array, int i)
{
	while (i > 0)
		free(array[i--]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	arr = malloc(((ft_words(s, c) + 1) * sizeof(char *)));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < (ft_words(s, c)))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = ft_strndup(&s[start], i - start);
		if (!arr[j++])
			return (ft_free_split(arr, j--));
	}
	arr[j] = NULL;
	return (arr);
}
/*
int main()
{
	char *str  = "can,you,split,this,sentence,with,your,ft_split,?";
	int c = ',';
	size_t	i = 0;
	size_t	j = 0;
	char **arr = ft_split(str, (char)c);
	while (arr && i < ft_words(str, (char)c))
	{
		printf("%s\n", arr[i]);
		i++;
	}
	while (arr && j < ft_words(str, (char)c))
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	return 0;
}*/
