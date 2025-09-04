/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:30:01 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/15 18:13:45 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

/*
#include <stdio.h>

int main()
{
    char c = ft_tolower('a');
    char b = ft_tolower('z');
    printf("%c\n", c);
    printf("%c\n", b);
    return (0);
}*/
