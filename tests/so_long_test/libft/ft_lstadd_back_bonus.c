/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:52:54 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/03 22:47:03 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

/*
int main(void)
{
    t_list *head;
    t_list *second;
    t_list *third;
    t_list *new_node;

    
    head = ft_lstnew("first n");
    second = ft_lstnew("second n");
    third = ft_lstnew("third n");

    
    head->next = second;
    second->next = third;

   
    new_node = ft_lstnew("last one");

    
    ft_lstadd_back(&head, new_node);

   
    t_list *current = head;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    return 0;
}
*/
