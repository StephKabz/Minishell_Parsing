/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:45:24 by stkabang          #+#    #+#             */
/*   Updated: 2025/04/16 15:43:03 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main()
{
	char *str = "Hello, World!";
	t_list *new_node = ft_lstnew(str);
	if (new_node)
	{
		printf("%s\n", (char *)new_node->content);
		printf("%p\n", (void *)new_node->next);
	}
	free(new_node);
	return (0);
}*/
