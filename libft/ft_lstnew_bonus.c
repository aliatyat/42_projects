/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:51:56 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/03 19:18:50 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
    int main(void)
{
    int value = 42;

    t_list *node = ft_lstnew(&value);

    if (node)
    {
      
        printf("The content of the new node is: %d\n", *(int *)(node->content));

        
        free(node);
    }
    else
    {
        printf("Failed to allocate memory for the new node.\n");
    }

    return 0;
}
*/
