/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:12:17 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/17 11:00:47 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	total_len;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	total_len = (nmemb * size);
	tab = malloc(total_len);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, total_len);
	return ((void *)tab);
}
/*
int main()
{
	int i = 0;
	int *arr = ft_calloc(2, sizeof(int));
	while (i < 2)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/