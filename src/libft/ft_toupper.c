/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:22:23 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/15 18:13:58 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

/*
#include <stdio.h>

int main()
{
    char c = ft_toupper('a');
    char b = ft_toupper('z');
    printf("%c\n", c);
    printf("%c\n", b);
    return (0);
}*/
