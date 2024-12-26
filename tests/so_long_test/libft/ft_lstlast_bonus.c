/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:52:10 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/03 22:59:22 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
int main(void)
{
    t_list *head;
    t_list *second;
    t_list *third;
    t_list *last_node;

    
    head = ft_lstnew("first one");
    second = ft_lstnew("second");
    third = ft_lstnew("third");

    
    head->next = second;
    second->next = third;

    
    last_node = ft_lstlast(head);
    if (last_node)
        printf("the last node have: %s\n", (char *)last_node->content);

    return 0;
}
*/
